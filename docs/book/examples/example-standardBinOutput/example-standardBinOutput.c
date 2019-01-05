// ****************************************************************************
//   Custom DPA Handler code example - IQRFBB-10 Development Board     *
// ****************************************************************************
// Copyright (c) Logimic, s.r.o.
//
// File:    example-standardBinOutput.c
// Version: Revision: 1.0
// Date:    Date: 2019/01/05
//
// Revision history:
//   2019/01/05  Release for DPA 3.02
//
// *********************************************************************

// Online DPA documentation http://www.iqrf.org/DpaTechGuide/

// This example implements 4 binary outputs according to the IQRF Binary Outputs standard
// Outputs for IQRFBB-10 Development Board
// Index 0: Red LED @ LED3
// Index 1: Green LED @ LED2
// Index 2: Relay #1 @ Bi-stable relay C1
// Index 3: Relay #2 @ Bi-stable relay C2
// Index 4: Relay #2 @ EQ6/SCL out

// Default IQRF include (modify the path according to your setup)
#include "IQRF.h"

// Default DPA header (modify the path according to your setup)
#include "DPA.h"
// Default Custom DPA Handler header (modify the path according to your setup)
#include "DPAcustomHandler.h"
// IQRF standards header (modify the path according to your setup)
#include "IQRFstandard.h"
#include "IQRF_HWPID.h"

#if DPA_VERSION_MASTER	< 0x0301
#error DPA version 3.01++ is required
#endif

//############################################################################################

// Number of implemented binary outputs
#define	OUTPUTS_COUNT 5

// Sets and Gets state of the indexed binary output
void SetOutput( uns8 state, uns8 index );
bit GetOutput( uns8 index );

// DDC-RE-01 relay pins
//  A.0 = C1 = Relay#1
#define	RELAY1_LAT	LATA.0 
#define	RELAY1_TRIS	TRISA.0
//  C.2 = C2 = Relay#2
#define	RELAY2_LAT	LATC.2 
#define	RELAY2_TRIS	TRISC.2
//  C.3 = C6 = Simple DO
#define	RELAY3_LAT	LATC.3 
#define	RELAY3_TRIS	TRISC.3

// Must be the 1st defined function in the source code in order to be placed at the correct FLASH location!
//############################################################################################
bit CustomDpaHandler()
//############################################################################################
{
  // This forces CC5X to wisely use MOVLB instructions (doc says:  The 'default' bank is used by the compiler for loops and labels when the algorithm gives up finding the optimal choice)
#pragma updateBank default = UserBank_01

  // Timers for outputs. The space must be long enough to fit them all. 2 bytes per one binary output.
  static uns16	Timers[OUTPUTS_COUNT];

  // Handler presence mark
  clrwdt();

  // Detect DPA event to handle
  switch ( GetDpaEvent() )
  {
    // -------------------------------------------------
    case DpaEvent_Interrupt:
      // Do an extra quick background interrupt work
      // ! The time spent handling this event is critical.If there is no interrupt to handle return immediately otherwise keep the code as fast as possible.
      // ! Make sure the event is the 1st case in the main switch statement at the handler routine.This ensures that the event is handled as the 1st one.
      // ! It is desirable that this event is handled with immediate return even if it is not used by the custom handler because the Interrupt event is raised on every MCU interrupt and the �empty� return handler ensures the shortest possible interrupt routine response time.
      // ! Only global variables or local ones marked by static keyword can be used to allow reentrancy.
      // ! Make sure race condition does not occur when accessing those variables at other places.
      // ! Make sure( inspect.lst file generated by C compiler ) compiler does not create any hidden temporary local variable( occurs when using division, multiplication or bit shifts ) at the event handler code.The name of such variable is usually Cnumbercnt.
      // ! Do not call any OS functions except setINDFx().
      // ! Do not use any OS variables especially for writing access.
      // ! All above rules apply also to any other function being called from the event handler code, although calling any function from Interrupt event is not recommended because of additional MCU stack usage.

      //  If TMR6 interrupt occurred, every 10 ms
      if ( TMR6IF )
      {
        // Unmask interrupt
        TMR6IF = 0;

        // Count 250 ms from 10 ms micro ticks
        static uns8 count250ms;
        if ( ++count250ms == ( 250 / 10 ) )
        {
          // 250 ms
          count250ms = 0;

          // Pointer to the timers array
          FSR1 = (uns16)&Timers[0];
          // Output index
          static uns8 index;
          index = 0;
          do
          {
            // Is timer running (is non-zero)?
            if ( ( FSR1[1] | INDF1 ) != 0 )
            {
              // Get time
              static uns16 time;
              time.low8 = *FSR1++;
              time.high8 = *FSR1;
              // Is timer over?
              if ( --time == 0 )
                // Set output to OFF
                SetOutput( 0, index );

              // Store new time
              setINDF1( time.high8 );
              FSR1--;
              setINDF1( time.low8 );
            }
            // Next timer
            FSR1 += sizeof( Timers[0] );
            // Next index
          } while ( ++index < OUTPUTS_COUNT );
        }
      }
      return Carry;

      // -------------------------------------------------
    case DpaEvent_DpaRequest:
      // Called to interpret DPA request for peripherals
      // -------------------------------------------------
      // Peripheral enumeration
      if ( IsDpaEnumPeripheralsRequest() )
      {
        // We implement 1 standard peripheral
        _DpaMessage.EnumPeripheralsAnswer.UserPerNr = 1;
        FlagUserPer( _DpaMessage.EnumPeripheralsAnswer.UserPer, PNUM_STD_BINARY_OUTPUTS );
        _DpaMessage.EnumPeripheralsAnswer.HWPID = HWPID_IQRF_TECH__DEMO_BINARY_OUTPUT;
        _DpaMessage.EnumPeripheralsAnswer.HWPIDver = 0x0000;

DpaHandleReturnTRUE:
        return TRUE;
      }
      // -------------------------------------------------
      // Get information about peripheral
      else if ( IsDpaPeripheralInfoRequest() )
      {
        if ( _PNUM == PNUM_STD_BINARY_OUTPUTS )
        {
          _DpaMessage.PeripheralInfoAnswer.PerT = PERIPHERAL_TYPE_STD_BINARY_OUTPUTS;
          _DpaMessage.PeripheralInfoAnswer.PerTE = PERIPHERAL_TYPE_EXTENDED_READ_WRITE;
          // Set standard version
          _DpaMessage.PeripheralInfoAnswer.Par1 = 4;
          goto DpaHandleReturnTRUE;
        }

        break;
      }
      // -------------------------------------------------
      else
      {
        // Handle peripheral command

        // Supported peripheral number?
        if ( _PNUM == PNUM_STD_BINARY_OUTPUTS )
        {
          // Supported commands?
          switch ( _PCMD )
          {
            // Invalid command
            default:
            {
              // Return error
              W = ERROR_PCMD;
ERROR_W:
              DpaApiReturnPeripheralError( W );
            }

            // Outputs enumeration
            case PCMD_STD_ENUMERATE:
              if ( _DpaDataLength != 0 )
                goto _ERROR_DATA_LEN;

              // Return number of outputs
              _DpaMessage.Response.PData[0] = OUTPUTS_COUNT;
              W = 1;
              goto _DpaDataLengthW;

              // Supported commands.
            case PCMD_STD_BINARY_OUTPUTS_SET:
            {
              // Pointers FSR01 to data are already set at the DPA

              // As this template implements < 9 outputs the working bitmap is uns8, if more outputs are implemented then uns16, ..., uns32 must be used
#if OUTPUTS_COUNT < 9
              uns8 inBitmap = *FSR0--;
              uns8 outBitmap @ _DpaMessage.Response.PData[0];
              uns8 bitmapMask = 0b1;
#else
#error Not implemented
#endif

              // Number of selected outputs + bitmap length
              uns8 outputsCount = 4;
              // Loop bitmap
              uns8 index = 4;
              do
              {
                // Count bits of next byte
                uns8 byte = *++FSR0;
                if ( byte != 0 )
                {
                  // Brian Kernighan's Algorithm for counting set bits 
                  do
                  {
                    outputsCount++;
                    byte &= byte - 1;
                  } while ( byte != 0 );
                }

                // Reset bitmap
                setINDF0( 0 );
              } while ( --index != 0 );

              // Check data length
              if ( _DpaDataLength != outputsCount )
              {
_ERROR_DATA_LEN:
                W = ERROR_DATA_LEN;
                goto ERROR_W;
              }

              // Pointer to the timers array
              FSR1 = (uns16)&Timers[0];
              // Output index
              index = 0;
              do
              {
                // Output was set?
                if ( GetOutput( index ) )
                  // Yes, set in the output bitmap
                  outBitmap |= bitmapMask;

                // Implemented output selected? Set the state.
                if ( inBitmap.0 )
                {
                  // Default is timer off
                  uns16 time = 0;
                  // Desired state
                  uns8 state = *++FSR0;
                  if ( state > 1 )
                  {
                    // Get time in units s/min
                    time = state & 0x7F;
                    if ( time == 0 )
                    {
                      // Invalid time
                      W = ERROR_FAIL;
                      goto ERROR_W;
                    }

                    // Conversion coefficient, ready for minutes to 250 ms
                    uns8 coef = 60 * ( 1000 / 250 );
                    if ( state.7 )
                      // Convert from seconds
                      coef = 1000 / 250;

                    // Convert to 250 ms
                    time *= coef;
                    // Set ON
                    state = 1;
                  }

                  // Set output
                  SetOutput( state, index );

                  // Set timer and preserve pointer
                  GIE = FALSE;
                  setINDF1( time.low8 );
                  FSR1++;
                  setINDF1( time.high8 );
                  FSR1--;
                  GIE = TRUE;
                }

                // Next pointer to the timer
                FSR1 += sizeof( Timers[0] );
                // Next bits
                bitmapMask <<= 1;
                inBitmap >>= 1;
                // Next index
              } while ( ++index < OUTPUTS_COUNT );

              // Return bitmap
_DpaDataLength4:
              W = 4;
_DpaDataLengthW:
              _DpaDataLength = W;
              goto DpaHandleReturnTRUE;
            }
          }
        }

        break;
      }

      // -------------------------------------------------
    case DpaEvent_Init:
      // Do a one time initialization work before main loop starts

      // Initialize relays @ DDC-RE
      RELAY1_LAT = 0;
      RELAY2_LAT = 0;
      RELAY3_LAT = 0;
      RELAY1_TRIS = 0;
      RELAY2_TRIS = 0;
      RELAY3_TRIS = 0;

      // Setup TMR6 to generate 10 ms ticks
#if F_OSC == 16000000
      PR6 = 250 - 1;
      T6CON = 0b0.1001.1.10;	// Prescaler 16, Postscaler 10, 16 * 10 * 250 = 40000 = 4MHz * 10ms
#else
#error Unsupported oscillator frequency
#endif

      break;

      // -------------------------------------------------
    case DpaEvent_AfterSleep:
      // Called after woken up after sleep

      TMR6IE = TRUE;
      TMR6ON = TRUE;
      break;

      // -------------------------------------------------
    case DpaEvent_BeforeSleep:
      // Called before going to sleep

      // -------------------------------------------------
    case DpaEvent_DisableInterrupts:
      // Called when device needs all hardware interrupts to be disabled (before Reset, Restart and RFPGM)

      // Must not use TMR6 any more
      TMR6ON = FALSE;
      TMR6IE = FALSE;
      break;
  }
DpaHandleReturnFALSE:
  return FALSE;
}

//############################################################################################
static uns8 _state;
void SetOutput( uns8 state @ _state, uns8 index @ W )
//############################################################################################
{
  // Note: FSRs must not be modified
  // Note: This method is called in the interrupt too!

  skip( index );
#pragma computedGoto 1
  goto set0;
  goto set1;
  goto set2;
  goto set3;
  goto set4;
#pragma computedGoto 0
  ;
  // --------------------------------------
set4:
  if ( !state.0 )
    RELAY3_LAT = 0;
  else
    RELAY3_LAT = 1;

  return;
  // --------------------------------------  
set3:
  if ( !state.0 )
    RELAY2_LAT = 0;
  else
    RELAY2_LAT = 1;

  return;
  // --------------------------------------
set2:
  if ( !state.0 )
    RELAY1_LAT = 0;
  else
    RELAY1_LAT = 1;

  return;
  // --------------------------------------
set1:
  if ( !state.0 )
    _LEDG = 0;
  else
    _LEDG = 1;

  return;
  // --------------------------------------
set0:
  if ( !state.0 )
    _LEDR = 0;
  else
    _LEDR = 1;

  return;
}

//############################################################################################
bit GetOutput( uns8 index @ W )
//############################################################################################
{
  Carry = FALSE; // Note: must not modify W

  // Note: all below must not modify Carry except when needed
  skip( index );
#pragma computedGoto 1
  goto get0;
  goto get1;
  goto get2;
  goto get3;
  goto get4;
#pragma computedGoto 0
  ;
  // --------------------------------------
get4:
  if ( RELAY3_LAT )
    Carry = TRUE;
  goto _return;
  // --------------------------------------  
get3:
  if ( RELAY2_LAT )
    Carry = TRUE;
  goto _return;
  // --------------------------------------
get2:
  if ( RELAY1_LAT )
    Carry = TRUE;
  goto _return;
  // --------------------------------------
get1:
  if ( _LEDG )
    Carry = TRUE;
  goto _return;
  // --------------------------------------
get0:
  if ( _LEDR )
    Carry = TRUE;
  goto _return;
  // --------------------------------------

_return:
  return Carry;
}

//############################################################################################
// Default Custom DPA Handler header; 2nd include to implement Code bumper to detect too long code of the Custom DPA Handler (modify the path according to your setup) 
#include "DPAcustomHandler.h"
//############################################################################################
