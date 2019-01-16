// *********************************************************************
// *                   IQRF OS basic include file                      *
// *********************************************************************
//
// Online IQRF OS Reference Guide: http://www.iqrf.org/IQRF-OS-Reference-guide/
//
// Copyright (c) IQRF Tech s.r.o.
//
// Intended for:
//	 HW: TR-72D, TR-76D, TR-77D, TR-78D, TR-75D
//   OS: v4.03D
//
// File:    IQRF.h
// Version: v1.00                                   Revision: 10/05/2018
//
// Revision history:
//	 v1.00: 10/05/2018 	First release for OS 4.03D.
//
// *********************************************************************

#if IQRFOS != 403
    #error Invalid IQRF OS version, V4.03 is expected. Make sure matching header files and project IQRF OS version setting are used.
#endif

#if defined TR72D
    #message Compilation for TR-72D modules (PIC16LF1938) and IQRF OS 4.03D.
    #define TR7xD
#elif defined TR76D
    #message Compilation for TR-76D modules (PIC16LF1938) and IQRF OS 4.03D.
    #define TR7xD
#elif defined TR77D
    #message Compilation for TR-77D modules (PIC16LF1938) and IQRF OS 4.03D.
    #define TR7xD
#elif defined TR78D
    #message Compilation for TR-78D modules (PIC16LF1938) and IQRF OS 4.03D.
    #define TR7xD
#elif defined TR75D
    #message Compilation for TR-75D modules (PIC16LF1938) and IQRF OS 4.03D.
    #define TR7xD
#else
    #error Unsupported TR module type.
#endif

#pragma chip PIC16F1938

#if __CC5X__ < 3701
    #warning Insufficient CC5X compiler version, V3.7A is recommended.
#endif

#pragma origin 0x100
#pragma update_RP 0

void APPLICATION();

void main()                                	// Skipped during Upload
{
    APPLICATION();
}

#include "IQRF-memory.h"             		// Memory definitions
#include "IQRF-functions.h"    			    // Functions definitions
#include "IQRF-macros.h"

// *********************************************************************

