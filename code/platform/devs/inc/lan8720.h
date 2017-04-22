#ifndef __LAN8720_H
#define __LAN8720_H

//#include "sys.h"
#include "stm32f4x7_eth.h"
#include "stm32f4xx_gpio.h"

#define LAN8720_PHY_ADDRESS  	0x00	//LAN8720 PHYоƬ��ַ.	 
#define LAN8720_SET  GPIO_SetBits(GPIOD, GPIO_Pin_3) 	//LAN8720��λ����		
#define LAN8720_RST  GPIO_ResetBits(GPIOD, GPIO_Pin_3) 	//LAN8720��λ����	

extern ETH_DMADESCTypeDef *DMARxDscrTab;			//��̫��DMA�������������ݽṹ��ָ��
extern ETH_DMADESCTypeDef *DMATxDscrTab;			//��̫��DMA�������������ݽṹ��ָ�� 
extern uint8_t *Rx_Buff; 							//��̫���ײ���������buffersָ�� 
extern uint8_t *Tx_Buff; 							//��̫���ײ���������buffersָ��
extern ETH_DMADESCTypeDef  *DMATxDescToSet;			//DMA����������׷��ָ��
extern ETH_DMADESCTypeDef  *DMARxDescToGet; 		//DMA����������׷��ָ�� 
extern ETH_DMA_Rx_Frame_infos *DMA_RX_FRAME_infos;	//DMA�����յ���֡��Ϣָ��

u8 LAN8720_Init(void);
void ETHERNET_NVICConfiguration(void);
u8 LAN8720_Get_Speed(void);
u8 ETH_MACDMA_Config(void);
void ETH_IRQHandler(void);
FrameTypeDef ETH_Rx_Packet(void);
u8 ETH_Tx_Packet(u16 FrameLength);
u32 ETH_GetCurrentTxBuffer(void);
u8 ETH_Mem_Malloc(void);
void ETH_Mem_Free(void);

#endif
