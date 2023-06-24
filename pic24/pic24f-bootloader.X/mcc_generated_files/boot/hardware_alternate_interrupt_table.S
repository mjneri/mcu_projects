/**
  @Generated 16-bit Bootloader Source File

  @Company:
    Microchip Technology Inc.

  @File Name: 
    hardware_alternate_interrupt_table.S

  @Summary:
    This is the hardware_alternate_interrupt_table.S file generated using 16-bit Bootloader

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  16-bit Bootloader - 1.19.1
        Device            :  PIC24FJ64GB002
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB             :  MPLAB X v5.15
*/
/*
Copyright (c) [2012-2022] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/
/* This file remaps the names used by the Alternate Interrupt Vector
 * table from __AltInterruptName() to __InterruptName().  Currently
 * MCC will only generate code for the main interrupt name (not the
 * alternate name).  So if a boot loader wants to utilize the altnerate
 * interrupts to let the main code use the interrupts, the names have
 * to be remapped.
 */

#include "boot_config.h"
    	     
__bootloader_DefaultInterrupt:
    goto __DefaultInterrupt
    
    .equ remap_offset, 4
    
    .macro remap_to_application NAME
    .weak __\NAME
    .global __\NAME
    .equiv __\NAME, __bootloader_DefaultInterrupt
    .pword __\NAME
    .endm

    
    .macro keep_in_bootloader NAME
    .weak __\NAME
    .global __\NAME
    .equiv __\NAME, __bootloader_DefaultInterrupt
    .pword __\NAME
    .endm
    
    .macro remap_to_application_default NAME
    .weak __\NAME
    .global __\NAME
    .equiv __\NAME, __bootloader_DefaultInterrupt
    .pword __\NAME
    .endm

    
/*
 * AIVT section information.
 */
    .section .aivt, code, address(0x100), keep

    /* Reserved memory */    
    .pword 0x0
    .pword 0x0

/* Alternate interrupt table */
KEEP_IN_BOOTLOADER   ReservedTrap0       
KEEP_IN_BOOTLOADER   OscillatorFail       
KEEP_IN_BOOTLOADER   AddressError       
KEEP_IN_BOOTLOADER   StackError       
KEEP_IN_BOOTLOADER   MathError       
KEEP_IN_BOOTLOADER   ReservedTrap5       
KEEP_IN_BOOTLOADER   ReservedTrap6       
KEEP_IN_BOOTLOADER   ReservedTrap7       
KEEP_IN_BOOTLOADER   INT0Interrupt       
KEEP_IN_BOOTLOADER   IC1Interrupt       
KEEP_IN_BOOTLOADER   OC1Interrupt       
KEEP_IN_BOOTLOADER   T1Interrupt       
KEEP_IN_BOOTLOADER   Interrupt4       
KEEP_IN_BOOTLOADER   IC2Interrupt       
KEEP_IN_BOOTLOADER   OC2Interrupt       
KEEP_IN_BOOTLOADER   T2Interrupt       
KEEP_IN_BOOTLOADER   T3Interrupt       
KEEP_IN_BOOTLOADER   SPI1ErrInterrupt       
KEEP_IN_BOOTLOADER   SPI1Interrupt       
KEEP_IN_BOOTLOADER   U1RXInterrupt       
KEEP_IN_BOOTLOADER   U1TXInterrupt       
KEEP_IN_BOOTLOADER   ADC1Interrupt       
KEEP_IN_BOOTLOADER   Interrupt14       
KEEP_IN_BOOTLOADER   Interrupt15       
KEEP_IN_BOOTLOADER   SI2C1Interrupt       
KEEP_IN_BOOTLOADER   MI2C1Interrupt       
KEEP_IN_BOOTLOADER   CompInterrupt       
KEEP_IN_BOOTLOADER   CNInterrupt       
KEEP_IN_BOOTLOADER   INT1Interrupt       
KEEP_IN_BOOTLOADER   Interrupt21       
KEEP_IN_BOOTLOADER   Interrupt22       
KEEP_IN_BOOTLOADER   Interrupt23       
KEEP_IN_BOOTLOADER   Interrupt24       
KEEP_IN_BOOTLOADER   OC3Interrupt       
KEEP_IN_BOOTLOADER   OC4Interrupt       
KEEP_IN_BOOTLOADER   T4Interrupt       
KEEP_IN_BOOTLOADER   T5Interrupt       
KEEP_IN_BOOTLOADER   INT2Interrupt       
KEEP_IN_BOOTLOADER   U2RXInterrupt       
KEEP_IN_BOOTLOADER   U2TXInterrupt       
KEEP_IN_BOOTLOADER   SPI2ErrInterrupt       
KEEP_IN_BOOTLOADER   SPI2Interrupt       
KEEP_IN_BOOTLOADER   Interrupt34       
KEEP_IN_BOOTLOADER   Interrupt35       
KEEP_IN_BOOTLOADER   Interrupt36       
KEEP_IN_BOOTLOADER   IC3Interrupt       
KEEP_IN_BOOTLOADER   IC4Interrupt       
KEEP_IN_BOOTLOADER   IC5Interrupt       
KEEP_IN_BOOTLOADER   Interrupt40       
KEEP_IN_BOOTLOADER   OC5Interrupt       
KEEP_IN_BOOTLOADER   Interrupt42       
KEEP_IN_BOOTLOADER   Interrupt43       
KEEP_IN_BOOTLOADER   Interrupt44       
KEEP_IN_BOOTLOADER   PMPInterrupt       
KEEP_IN_BOOTLOADER   Interrupt46       
KEEP_IN_BOOTLOADER   Interrupt47       
KEEP_IN_BOOTLOADER   Interrupt48       
KEEP_IN_BOOTLOADER   SI2C2Interrupt       
KEEP_IN_BOOTLOADER   MI2C2Interrupt       
KEEP_IN_BOOTLOADER   Interrupt51       
KEEP_IN_BOOTLOADER   Interrupt52       
KEEP_IN_BOOTLOADER   Interrupt53       
KEEP_IN_BOOTLOADER   Interrupt54       
KEEP_IN_BOOTLOADER   Interrupt55       
KEEP_IN_BOOTLOADER   Interrupt56       
KEEP_IN_BOOTLOADER   Interrupt57       
KEEP_IN_BOOTLOADER   Interrupt58       
KEEP_IN_BOOTLOADER   Interrupt59       
KEEP_IN_BOOTLOADER   Interrupt60       
KEEP_IN_BOOTLOADER   Interrupt61       
KEEP_IN_BOOTLOADER   RTCCInterrupt       
KEEP_IN_BOOTLOADER   Interrupt63       
KEEP_IN_BOOTLOADER   Interrupt64       
KEEP_IN_BOOTLOADER   U1ErrInterrupt       
KEEP_IN_BOOTLOADER   U2ErrInterrupt       
KEEP_IN_BOOTLOADER   CRCInterrupt       
KEEP_IN_BOOTLOADER   Interrupt68       
KEEP_IN_BOOTLOADER   Interrupt69       
KEEP_IN_BOOTLOADER   Interrupt70       
KEEP_IN_BOOTLOADER   Interrupt71       
KEEP_IN_BOOTLOADER   LVDInterrupt       
KEEP_IN_BOOTLOADER   Interrupt73       
KEEP_IN_BOOTLOADER   Interrupt74       
KEEP_IN_BOOTLOADER   Interrupt75       
KEEP_IN_BOOTLOADER   Interrupt76       
KEEP_IN_BOOTLOADER   CTMUInterrupt       
KEEP_IN_BOOTLOADER   Interrupt78       
KEEP_IN_BOOTLOADER   Interrupt79       
KEEP_IN_BOOTLOADER   Interrupt80       
KEEP_IN_BOOTLOADER   Interrupt81       
KEEP_IN_BOOTLOADER   Interrupt82       
KEEP_IN_BOOTLOADER   Interrupt83       
KEEP_IN_BOOTLOADER   Interrupt84       
KEEP_IN_BOOTLOADER   Interrupt85       
KEEP_IN_BOOTLOADER   USB1Interrupt       
KEEP_IN_BOOTLOADER   Interrupt87       
KEEP_IN_BOOTLOADER   Interrupt88       
KEEP_IN_BOOTLOADER   Interrupt89       
KEEP_IN_BOOTLOADER   Interrupt90       
KEEP_IN_BOOTLOADER   Interrupt91       
KEEP_IN_BOOTLOADER   Interrupt92       
KEEP_IN_BOOTLOADER   Interrupt93       
KEEP_IN_BOOTLOADER   Interrupt94       
KEEP_IN_BOOTLOADER   Interrupt95       
KEEP_IN_BOOTLOADER   Interrupt96       
KEEP_IN_BOOTLOADER   Interrupt97       
KEEP_IN_BOOTLOADER   Interrupt98       
KEEP_IN_BOOTLOADER   Interrupt99       
KEEP_IN_BOOTLOADER   Interrupt100       
KEEP_IN_BOOTLOADER   Interrupt101       
KEEP_IN_BOOTLOADER   Interrupt102       
KEEP_IN_BOOTLOADER   Interrupt103       
KEEP_IN_BOOTLOADER   Interrupt104       
KEEP_IN_BOOTLOADER   Interrupt105       
KEEP_IN_BOOTLOADER   Interrupt106       
KEEP_IN_BOOTLOADER   Interrupt107       
KEEP_IN_BOOTLOADER   Interrupt108       
KEEP_IN_BOOTLOADER   Interrupt109       
KEEP_IN_BOOTLOADER   Interrupt110       
KEEP_IN_BOOTLOADER   Interrupt111       
KEEP_IN_BOOTLOADER   Interrupt112       
KEEP_IN_BOOTLOADER   Interrupt113       
KEEP_IN_BOOTLOADER   Interrupt114       
KEEP_IN_BOOTLOADER   Interrupt115       
KEEP_IN_BOOTLOADER   Interrupt116       
KEEP_IN_BOOTLOADER   Interrupt117       
