#ifndef __USART_H
#define __USART_H

#include "base_type.h"

#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	

void usart_init(uint32_t baudrate);
uint8_t usart_sendbyte(int ch);
void usart_putc(uint8_t ch);
void usart_puts(const char *str);


#endif