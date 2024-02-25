 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <stdint.h>

#define DATA_BYTE_LENGTH (8)        // Classic CAN allows up to 8 bytes
#define TIME_1S (1000)

/*
    Main application
*/

void HeartbeatCallback(void)
{
    HEARTBEAT_LED_Toggle();
}

void OneShotCallback(void)
{
    RX_SUCCESS_SetLow();
    TX_SUCCESS_SetLow();
}

int main(void)
{
    SYSTEM_Initialize();
    
    // Code below was taken from https://onlinedocs.microchip.com/oxy/GUID-420E6AAC-9141-47BF-A4C7-A6EA17246D0D-en-US-20/Chunk1334467806.html#GUID-4B763676-38BF-4A77-85DC-574860F67466
    uint8_t transmitData[DATA_BYTE_LENGTH];
    enum CAN_TX_MSG_REQUEST_STATUS transmitStatus;
    struct CAN_MSG_OBJ transmitMsgObj;
    struct CAN_MSG_OBJ receiveMsgObj;
    
    //Assign values to the data bytes to be transmitted
    for (uint8_t i = 0; i <  DATA_BYTE_LENGTH; i++)
    {
        transmitData [i] = i + 1;
    }
    
    if (CAN_CONFIGURATION_MODE == CAN1.OperationModeGet())
    {
        CAN1.OperationModeSet(CAN_NORMAL_2_0_MODE);
    }
    
    // Create a transmit message object of the required frame consisting of message id, control bits and payload.
    if (CAN_NORMAL_2_0_MODE == CAN1.OperationModeGet())
    {
        transmitMsgObj.msgId = 0x617;
        transmitMsgObj.field.formatType = CAN_2_0_FORMAT;
        transmitMsgObj.field.brs = CAN_NON_BRS_MODE;      // This is not supported in Classic CAN apparently.
        transmitMsgObj.field.frameType = CAN_FRAME_DATA;
        transmitMsgObj.field.idType = CAN_FRAME_STD;
        transmitMsgObj.field.dlc = DLC_8;
        transmitMsgObj.data = transmitData;
    }
    
    // Register callbacks
    Timer0.TimeoutCallbackRegister(HeartbeatCallback);
    Timer2.TimeoutCallbackRegister(OneShotCallback);

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 


    while(1)
    {
        if(!SW3_GetValue() && !TX_SUCCESS_GetValue())
        {
            // Code below was taken from https://onlinedocs.microchip.com/oxy/GUID-420E6AAC-9141-47BF-A4C7-A6EA17246D0D-en-US-20/Chunk1334467806.html#GUID-4B763676-38BF-4A77-85DC-574860F67466
            // Before transmitting any message, the Transmitter FIFO status needs to be checked
            // Writes a message object to CAN TX FIFO and returns the status of CAN transmit message
            if (CAN_TX_FIFO_AVAILABLE == CAN1.TransmitFIFOStatusGet(CAN1_TXQ))
            {
                transmitStatus = CAN1.Transmit(CAN1_TXQ, &transmitMsgObj);
                
                if (CAN_TX_MSG_REQUEST_SUCCESS == transmitStatus)
                {
                    Timer2.Start();
                    TX_SUCCESS_SetHigh();
                }
            }
            
        }

        // Code below taken from "Use Case 3: Receive a CAN FD Message from a Particular FIFO (Polling Method)"
        // https://onlinedocs.microchip.com/oxy/GUID-420E6AAC-9141-47BF-A4C7-A6EA17246D0D-en-US-20/Chunk1334467806.html#GUID-AD9FD0C8-06D0-4C9E-A03F-9B202E20FA44
        //Check if the receive FIFO (FIFO1) is not empty    
        if (CAN_RX_MSG_AVAILABLE == (CAN1.ReceiveFIFOStatusGet(CAN1_FIFO_1) & CAN_RX_MSG_AVAILABLE))
        {
            //Reads the receive message object from the specified CAN Receive FIFO
            CAN1.ReceiveMessageGet(CAN1_FIFO_1, &receiveMsgObj);
 
            // Assumption: If the message is in the FIFO, it means it matched the message filter set in MCC Melody.
            Timer2.Start();
            RX_SUCCESS_SetHigh();
        }
        
        CAN1.Tasks();
    }    
}