// *********************************************************************
//      				   IQRF OS functions						   *
// *********************************************************************
// Intended for:
//    OS: v4.03D
//
// Online IQRF OS Reference Guide: http://www.iqrf.org/IQRF-OS-Reference-guide/
//
// Copyright (c) IQRF Tech s.r.o.
//
// File:    IQRF-functions.h
// Version: v1.00                                   Revision: 27/06/2018
//
// Revision history:
//   v1.00: 27/06/2018  First release for OS 4.03D.
//
// *********************************************************************
 
#pragma optimize 0
#pragma update_PAGE 0
#pragma update_RP 0

#define	dummy_address	0x3810
#pragma origin dummy_address
void dummy()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	iqrfSleep_address	0x3816
#pragma origin iqrfSleep_address
void iqrfSleep()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	_debug_address	0x3819
#pragma origin _debug_address
void _debug()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define debug()	    \
	do {			\
		_debug();	\
        nop();      \
	} while (0)

#define	moduleInfo_address	0x381c
#pragma origin moduleInfo_address
void moduleInfo()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	pulsingLEDR_address	0x3822
#pragma origin pulsingLEDR_address
void pulsingLEDR()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	pulseLEDR_address	0x3825
#pragma origin pulseLEDR_address
void pulseLEDR()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	stopLEDR_address	0x3828
#pragma origin stopLEDR_address
void stopLEDR()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	pulsingLEDG_address	0x382b
#pragma origin pulsingLEDG_address
void pulsingLEDG()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	pulseLEDG_address	0x382e
#pragma origin pulseLEDG_address
void pulseLEDG()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	stopLEDG_address	0x3831
#pragma origin stopLEDG_address
void stopLEDG()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setOnPulsingLED_address	0x3834
#pragma origin setOnPulsingLED_address
void setOnPulsingLED(uns8 ticks @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setOffPulsingLED_address	0x3837
#pragma origin setOffPulsingLED_address
void setOffPulsingLED(uns8 ticks @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	eeReadByte_address	0x383a
#pragma origin eeReadByte_address
uns8 eeReadByte(uns8 address @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	eeReadData_address	0x383d
#pragma origin eeReadData_address
bit eeReadData(uns8 address @ param2, uns8 length @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	eeWriteByte_address	0x3840
#pragma origin eeWriteByte_address
void eeWriteByte(uns8 address @ param2, uns8 data @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	eeWriteData_address	0x3843
#pragma origin eeWriteData_address
void eeWriteData(uns8 address @ param2, uns8 length @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	readFromRAM_address	0x3846
#pragma origin readFromRAM_address
uns8 readFromRAM(uns16 address @ FSR0)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	clearBufferINFO_address	0x384c
#pragma origin clearBufferINFO_address
void clearBufferINFO()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	swapBufferINFO_address	0x384f
#pragma origin swapBufferINFO_address
void swapBufferINFO()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	compareBufferINFO2RF_address	0x3852
#pragma origin compareBufferINFO2RF_address
bit compareBufferINFO2RF(uns8 length @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	copyBufferINFO2COM_address	0x3855
#pragma origin copyBufferINFO2COM_address
void copyBufferINFO2COM()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	copyBufferINFO2RF_address	0x3858
#pragma origin copyBufferINFO2RF_address
void copyBufferINFO2RF()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	copyBufferRF2COM_address	0x385b
#pragma origin copyBufferRF2COM_address
void copyBufferRF2COM()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	copyBufferRF2INFO_address	0x385e
#pragma origin copyBufferRF2INFO_address
void copyBufferRF2INFO()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	copyBufferCOM2RF_address	0x3861
#pragma origin copyBufferCOM2RF_address
void copyBufferCOM2RF()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	copyBufferCOM2INFO_address	0x3864
#pragma origin copyBufferCOM2INFO_address
void copyBufferCOM2INFO()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	copyMemoryBlock_address	0x3867
#pragma origin copyMemoryBlock_address
void copyMemoryBlock(uns16 from @ FSR0, uns16 to @ FSR1, uns8 length @ W)
{
  #asm
    DW 0x2000
  #endasm
 #pragma updateBank exit=UserBank_01
}

#define	startDelay_address	0x386a
#pragma origin startDelay_address
void startDelay(uns8 ticks @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	startLongDelay_address	0x386d
#pragma origin startLongDelay_address
void startLongDelay(uns16 ticks @ param3)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	isDelay_address	0x3870
#pragma origin isDelay_address
bit isDelay()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	waitDelay_address	0x3873
#pragma origin waitDelay_address
void waitDelay(uns8 ticks @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	waitMS_address	0x3876
#pragma origin waitMS_address
void waitMS(uns8 ms @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	startCapture_address	0x3879
#pragma origin startCapture_address
void startCapture()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	captureTicks_address	0x387c
#pragma origin captureTicks_address
void captureTicks()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	waitNewTick_address	0x3882
#pragma origin waitNewTick_address
void waitNewTick()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	enableSPI_address	0x3885
#pragma origin enableSPI_address
void enableSPI()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	disableSPI_address	0x3888
#pragma origin disableSPI_address
void disableSPI()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	startSPI_address	0x388b
#pragma origin startSPI_address
void startSPI(uns8 length @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	stopSPI_address	0x388e
#pragma origin stopSPI_address
void stopSPI()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	restartSPI_address	0x3891
#pragma origin restartSPI_address
void restartSPI()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	getStatusSPI_address	0x3894
#pragma origin getStatusSPI_address
bit getStatusSPI()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	setRFpower_address	0x3897
#pragma origin setRFpower_address
void setRFpower(uns8 level @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setLEDG_address	0x389a
#pragma origin setLEDG_address
void setLEDG()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setRFchannel_address	0x389d
#pragma origin setRFchannel_address
void setRFchannel(uns8 channel @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setRFmode_address	0x38a0
#pragma origin setRFmode_address
void setRFmode(uns8 mode @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setRFspeed_address	0x38a3
#pragma origin setRFspeed_address
void setRFspeed(uns8 speed @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setRFsleep_address	0x38a6
#pragma origin setRFsleep_address
void setRFsleep()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setRFready_address	0x38a9
#pragma origin setRFready_address
void setRFready()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	RFTXpacket_address	0x38ac
#pragma origin RFTXpacket_address
void RFTXpacket()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	RFRXpacket_address	0x38af
#pragma origin RFRXpacket_address
bit RFRXpacket()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	checkRF_address	0x38b2
#pragma origin checkRF_address
bit checkRF(uns8 level @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	amIBonded_address	0x38b8
#pragma origin amIBonded_address
bit amIBonded()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	removeBond_address	0x38bb
#pragma origin removeBond_address
void removeBond()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	bondNewNode_address	0x38be
#pragma origin bondNewNode_address
bit bondNewNode(uns8 address @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	isBondedNode_address	0x38c1
#pragma origin isBondedNode_address
bit isBondedNode(uns8 node @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	removeBondedNode_address	0x38c4
#pragma origin removeBondedNode_address
void removeBondedNode(uns8 node @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	rebondNode_address	0x38c7
#pragma origin rebondNode_address
bit rebondNode(uns8 node @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	clearAllBonds_address	0x38ca
#pragma origin clearAllBonds_address
void clearAllBonds()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setNonetMode_address	0x38cd
#pragma origin setNonetMode_address
void setNonetMode()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setCoordinatorMode_address	0x38d0
#pragma origin setCoordinatorMode_address
void setCoordinatorMode()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setNodeMode_address	0x38d3
#pragma origin setNodeMode_address
void setNodeMode()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setNetworkFilteringOn_address	0x38d6
#pragma origin setNetworkFilteringOn_address
void setNetworkFilteringOn()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setNetworkFilteringOff_address	0x38d9
#pragma origin setNetworkFilteringOff_address
void setNetworkFilteringOff()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	getNetworkParams_address	0x38dc
#pragma origin getNetworkParams_address
uns8 getNetworkParams()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	setRoutingOn_address	0x38df
#pragma origin setRoutingOn_address
void setRoutingOn()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setRoutingOff_address	0x38e2
#pragma origin setRoutingOff_address
void setRoutingOff()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	answerSystemPacket_address	0x38e8
#pragma origin answerSystemPacket_address
void answerSystemPacket()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	discovery_address	0x38eb
#pragma origin discovery_address
uns8 discovery(uns8 MaxNodeAddress @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	wasRouted_address	0x38ee
#pragma origin wasRouted_address
bit wasRouted()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	optimizeHops_address	0x38f1
#pragma origin optimizeHops_address
bit optimizeHops(uns8 method @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	getSupplyVoltage_address	0x38f4
#pragma origin getSupplyVoltage_address
uns8 getSupplyVoltage()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	getTemperature_address	0x38f7
#pragma origin getTemperature_address
int8 getTemperature()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return W;
}

#define	clearBufferRF_address	0x38fa
#pragma origin clearBufferRF_address
void clearBufferRF()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	isDiscoveredNode_address	0x3910
#pragma origin isDiscoveredNode_address
bit isDiscoveredNode(uns8 address @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	enableRFPGM_address	0x3913
#pragma origin enableRFPGM_address
void enableRFPGM()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	disableRFPGM_address	0x3916
#pragma origin disableRFPGM_address
void disableRFPGM()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setupRFPGM_address	0x3919
#pragma origin setupRFPGM_address
void setupRFPGM(uns8 x @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	runRFPGM_address	0x391c
#pragma origin runRFPGM_address
void runRFPGM()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	iqrfDeepSleep_address	0x391f
#pragma origin iqrfDeepSleep_address
void iqrfDeepSleep()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	wasRFICrestarted_address	0x3922
#pragma origin wasRFICrestarted_address
uns8 wasRFICrestarted()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	eeeWriteData_address	0x3925
#pragma origin eeeWriteData_address
bit eeeWriteData(uns16 address @ param3)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	eeeReadData_address	0x3928
#pragma origin eeeReadData_address
bit eeeReadData(uns16 address @ param3)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	setINDF0_address	0x3931
#pragma origin setINDF0_address
void setINDF0(uns8 value @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setINDF1_address	0x3934
#pragma origin setINDF1_address
void setINDF1(uns8 value @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	getRSSI_address	0x3937
#pragma origin getRSSI_address
uns8 getRSSI()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	removeBondAddress_address	0x393a
#pragma origin removeBondAddress_address
void removeBondAddress()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	sendFRC_address	0x393d
#pragma origin sendFRC_address
uns8 sendFRC(uns8 command @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	responseFRC_address	0x3940
#pragma origin responseFRC_address
void responseFRC()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	bondRequestAdvanced_address	0x3943
#pragma origin bondRequestAdvanced_address
bit bondRequestAdvanced()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	prebondNodeAtNode_address	0x3946
#pragma origin prebondNodeAtNode_address
bit prebondNodeAtNode()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	nodeAuthorization_address	0x3949
#pragma origin nodeAuthorization_address
bit nodeAuthorization(uns8 address @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	dummy01_address	0x394c
#pragma origin dummy01_address
void dummy01()
{
  #asm
  DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setAccessPassword_address	0x3958
#pragma origin setAccessPassword_address
void setAccessPassword()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	setUserKey_address	0x395b
#pragma origin setUserKey_address
void setUserKey()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	amIRecipientOfFRC_address	0x3961
#pragma origin amIRecipientOfFRC_address
bit amIRecipientOfFRC()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	setLEDR_address	0x3964
#pragma origin setLEDR_address
void setLEDR()
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	encryptBufferRF_address	0x3967
#pragma origin encryptBufferRF_address
void encryptBufferRF(uns8 blocks @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	decryptBufferRF_address	0x396a
#pragma origin decryptBufferRF_address
void decryptBufferRF(uns8 blocks @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	prebondNodeAtCoordinator_address	0x396d
#pragma origin prebondNodeAtCoordinator_address
bit prebondNodeAtCoordinator(uns8 address @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	setFSRs_address	0x3970
#pragma origin setFSRs_address
uns8 setFSRs(uns8 fsrs @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

// For internal usage only
#define	updateCRC16_address	0x3973
#pragma origin updateCRC16_address
void updateCRC16(uns8 value @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
}

#define	smartConnect_address	0x3976
#pragma origin smartConnect_address
bit smartConnect(uns8 address @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return Carry;
}

#define	addressBitmap_address	0x3979
#pragma origin addressBitmap_address
uns8 addressBitmap(uns8 bitIndex @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#define	setServiceChannel_address	0x397c
#pragma origin setServiceChannel_address
bit setServiceChannel(uns8 channelNumber @ W)
{
  #asm
    DW 0x2000
  #endasm
  #pragma updateBank exit=UserBank_01
  return 1;
}

#pragma optimize 1
#pragma update_RP 1
#pragma update_PAGE 1
#pragma origin __APPLICATION_ADDRESS
