/**
 * @brief: uart_polling.c, polling UART to send and receive data
 * @author: Yiqing Huang
 * @date: 2013/01/06
 * NOTE: the code only handles UART0 for now. 
 */

#include <LPC17xx.h>
#include "uart_polling.h"


/**
 * @brief: initialize the n_uart
 * NOTES: only supports uart0 so far, but can be easily extended to other uarts.
 */
int uart_init(int n_uart) {

  LPC_UART_TypeDef *pUart;  /* ptr to memory mapped device UART, check         */
                            /* LPC17xx.h for UART register C structure overlay */

  if (n_uart ==0 ) {
    /*
    Step 1: system control configuration
     
    step 1a: power control configuration, table 46 pg63
    enable UART0 power, this is the default setting
    also already done in system_LPC17xx.c
    enclose the code below for reference 
    LPC_SC->PCONP |= BIT(3);
  
    
    step 1b: select the clock source, default PCLK=CCLK/4 , where CCLK = 100MHZ.
    tables 40 and 42  on pg56 and pg57
    Check the PLL0 configuration to see how XTAL=12.0MHZ gets to CCLK=100MHZ
    in system_LPC17xx.c file
    enclose code below for reference
    LPC_SC->PCLKSEL0 &= ~(BIT(7)|BIT(6));  // PCLK = CCLK/4, default setting after reset  

    Step 2: Pin Ctrl Block configuration for TXD and RXD
    Listed as item #5 in LPC_17xxum UART0/2/3 manual pag298
    */
    LPC_PINCON->PINSEL0 |= (1 << 4);    /* Pin P0.2 used as TXD0 (Com0) */
    LPC_PINCON->PINSEL0 |= (1 << 6);    /* Pin P0.3 used as RXD0 (Com0) */

    pUart = (LPC_UART_TypeDef *) LPC_UART0;
    
  } else if (n_uart == 1) {
    LPC_PINCON->PINSEL4 |= (2 << 0);    /* Pin P2.0 used as TXD1 (Com1) */
    LPC_PINCON->PINSEL4 |= (2 << 2);    /* Pin P2.1 used as RXD1 (Com1) */

    pUart = (LPC_UART_TypeDef *) LPC_UART1;

  } else {
    return 1;   /* not supported yet */
  } 

  /* Step 3: Transmission Configuration */
  
  /* step 3a: DLAB=1, 8N1 */
  pUart->LCR    = UART_8N1;

  /* step 3b: 115200 baud rate @ 25.0 MHZ PCLK */
  pUart->DLM = 0;
  pUart->DLL = 9;
  pUart->FDR = 0x21;        /* FR = 1.507 ~ 1/2, DivAddVal = 1, MulVal = 2  */
                            /* FR = 1.507 = 25MHZ/(16*9*115200)             */
  pUart->LCR &= ~(BIT(7));  /* disable the Divisior Latch Access Bit DLAB=0 */

  return 0;
}


/**
 * @brief: read a char from the n_uart, blocking read
 */
     
int uart_get_char(int n_uart)
{
  LPC_UART_TypeDef *pUart;

  if (n_uart == 0) {
    pUart = (LPC_UART_TypeDef *) LPC_UART0;
  } else if (n_uart == 1) {
    pUart = (LPC_UART_TypeDef *) LPC_UART1;
  } else {
    return 1;  /* UART1,2,3 not supported yet */
  }

  /* polling the LSR RDR (Receiver Data Ready) bit to wait it is not empty */
  while (!(pUart->LSR & LSR_RDR)); 
  return (pUart->RBR); 
}

/**
 * @brief: write a char c to the n_uart
 */
  
int uart_put_char(int n_uart, unsigned char c)
{
  LPC_UART_TypeDef *pUart;

  if (n_uart == 0) {
    pUart = (LPC_UART_TypeDef *)LPC_UART0;
  } else if (n_uart == 1) {
    pUart = (LPC_UART_TypeDef *)LPC_UART1;
  } else {
    return 1;  // UART 1,2,3 not supported
  }

  /* polling LSR THRE bit to wait it is empty */

  while (!(pUart->LSR & LSR_THRE)); 
  return (pUart->THR = c);  /* write c to the THR */
}

/**
 * @brief write a string to UART
 */
int uart_put_string(int n_uart, unsigned char *s)
{
  if (n_uart >1 ) return -1;    /* only uart0 is supported for now      */
  while (*s !=0) {              /* loop through each char in the string */
    uart_put_char(n_uart, *s++);/* print the char, then ptr increments  */
  }
  return 0;
}
