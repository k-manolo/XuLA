//*********************************************************************
// Copyright (C) 2010 Dave Vanden Bout / XESS Corp. / www.xess.com
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
//
//====================================================================
//
// Module Description:
//  This module maps pins to their functions.  This provides a layer
//  of abstraction.
//
//********************************************************************

#ifndef IO_CFG_H
#define IO_CFG_H

#include "autofiles\usbcfg.h"

#define INPUT_PIN           1
#define OUTPUT_PIN          0

/** Pin definition macros *******************************************/
#define TRIS(P,B)           (TRIS ## P ## bits.TRIS ## P ## B)
#define PORT(P,B)           (PORT ## P ## bits.R ## P ## B)
#define PORT_ASM(P,B)       PORT ## P ## ,B,ACCESS
#define LATCH(P,B)          (LAT ## P ## bits.LAT ## P ## B)

/** Sense presence of USB bus (not used) *****************************/
#if defined(USE_USB_BUS_SENSE_IO)
#define tris_usb_bus_sense  TRIS(A,1)
#define usb_bus_sense       PORT(A,1)
#else
#define usb_bus_sense       1
#endif

/** Sense presence of external power (not used) *********************/
#if defined(USE_SELF_POWER_SENSE_IO)
#define tris_self_power     TRIS(A,2)
#define self_power          PORT(A,2)
#else
#define self_power          1
#endif

/** TDO *************************************************************/
#define TDO_PORT            B
#define TDO_BIT             4
#define TDO_MASK            (1<<TDO_BIT)
#define TDO_TRIS            TRIS(B,4)
#define TDO                 LATCH(B,4)
#define TDO_ASM             PORT_ASM(B,4)
#define INIT_TDO()          TDO_TRIS = INPUT_PIN

/** TMS *************************************************************/
#define TMS_PORT            B
#define TMS_BIT             5
#define TMS_MASK            (1<<TMS_BIT)
#define TMS_TRIS            TRIS(B,5)
#define TMS                 LATCH(B,5)
#define TMS_ASM             PORT_ASM(B,5)
#define INIT_TMS()          TMS = 0, TMS_TRIS = OUTPUT_PIN

/** TCK *************************************************************/
#define TCK_PORT            B
#define TCK_BIT             6
#define TCK_MASK            (1<<TCK_BIT)
#define TCK_TRIS            TRIS(B,6)
#define TCK                 LATCH(B,6)
#define TCK_ASM             PORT_ASM(B,6)
#define INIT_TCK()          TCK = 0, TCK_TRIS = OUTPUT_PIN

/** Firmware update jumper sense ************************************/
#define FMWB_PORT           B
#define FMWB_BIT            7
#define FMWB_MASK           (1<<FMWB_BIT)
#define FMWB_TRIS           TRIS(B,7)
#define FMWB                PORT(B,7)
#define FMWB_ASM            PORT_ASM(B,7)
#define INIT_FMWB()         LATCH(B,7) = 1, FMWB_TRIS = INPUT_PIN, INTCON2bits.NOT_RABPU = 0

/** FPGA DONE pin***************************************************/
#define DONE_PORT           C
#define DONE_BIT            0
#define DONE_MASK           (1<<DONE_BIT)
#define DONE_TRIS           TRIS(C,0)
#define DONE                PORT(C,0)
#define DONE_ASM            PORT_ASM(C,0)
#define INIT_DONE()         DONE_TRIS = INPUT_PIN

/** SRQ input pin***************************************************/
#define SRQ_IN_PORT         C
#define SRQ_IN_BIT          1
#define SRQ_IN_MASK         (1<<SRQ_IN_BIT)
#define SRQ_IN_TRIS         TRIS(C,1)
#define SRQ_IN              PORT(C,1)
#define SRQ_IN_ASM          PORT_ASM(C,1)
#define INIT_SRQ_IN()       SRQ_IN_TRIS = INPUT_PIN

/** 1.2V sense pin***************************************************/
#define SENSE_1V_PORT       C
#define SENSE_1V_BIT        2
#define SENSE_1V_MASK       (1<<SENSE_1V_BIT)
#define SENSE_1V_TRIS       TRIS(C,2)
#define SENSE_1V            PORT(C,2)
#define SENSE_1V_ASM        PORT_ASM(C,2)
#define INIT_SENSE_1V()     SENSE_1V_TRIS = INPUT_PIN

/** FPGA PROG# pin control ******************************************/
#define PROGB_PORT          C
#define PROGB_BIT           3
#define PROGB_MASK          (1<<PROGB_BIT)
#define PROGB_TRIS          TRIS(C,3)
#define PROGB               LATCH(C,3)
#define PROGB_ASM           PORT_ASM(C,3)
#define INIT_PROGB()        PROGB = 0, PROGB_TRIS = OUTPUT_PIN

/** FPGA clock pin control ******************************************/
#define FPGACLK_PORT        C
#define FPGACLK_BIT         4
#define FPGACLK_MASK        (1<<FPGACLK_BIT)
#define FPGACLK_TRIS        TRIS(C,4)
#define FPGACLK             LATCH(C,4)
#define FPGACLK_ASM         PORT_ASM(C,4)
#define INIT_FPGACLK()      FPGACLK = 0, FPGACLK_TRIS = OUTPUT_PIN
#define FPGACLK_ON()        SRCON0 = 0b10001000, SRCON1 = 0b10000100
#define FPGACLK_OFF()       SRCON0 = 0b10001000, SRCON1 = 0b10001000

/** LED *************************************************************/
#define LED_PORT            C
#define LED_BIT             5
#define LED_MASK            (1<<LED_BIT)
#define LED_TRIS            TRIS(C,5)
#define LED                 LATCH(C,5)
#define LED_ASM             PORT_ASM(C,5)
#define LED_OFF()           LED = 0
#define LED_ON()            LED = 1
#define LED_TOGGLE()        LED = !LED
#define INIT_LED()          LED_OFF(), LED_TRIS = OUTPUT_PIN

/** 3.3V sense pin***************************************************/
#define SENSE_3V_PORT       C
#define SENSE_3V_BIT        6
#define SENSE_3V_MASK       (1<<SENSE_3V_BIT)
#define SENSE_3V_TRIS       TRIS(C,6)
#define SENSE_3V            PORT(C,6)
#define SENSE_3V_ASM        PORT_ASM(C,6)
#define INIT_SENSE_3V()     SENSE_3V_TRIS = INPUT_PIN

/** TDI *************************************************************/
#define TDI_PORT            C
#define TDI_BIT             7
#define TDI_MASK            (1<<TDI_BIT)
#define TDI_TRIS            TRIS(C,7)
#define TDI                 LATCH(C,7)
#define TDI_ASM             PORT_ASM(C,7)
#define INIT_TDI()          TDI = 0, TDI_TRIS = OUTPUT_PIN

/** Default configuration of I/O pins ******************************/
#define DEFAULT_IO_CFG()    ANSEL=0, ANSELH=0, INIT_SENSE_1V(), INIT_SENSE_3V(),\
                            INIT_TDO(), INIT_TMS(), INIT_TCK(), INIT_FMWB(),\
                            INIT_DONE(), INIT_SRQ_IN(), INIT_PROGB(), INIT_FPGACLK(),\
                            INIT_LED(), INIT_TDI()

#endif //IO_CFG_H
