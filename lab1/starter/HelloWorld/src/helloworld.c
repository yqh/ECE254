#include <LPC17xx.h>
#include "uart_polling.h"

int main()
{
  SystemInit();
  uart0_init();
  uart0_put_string("Hello World!\n\r");
  return 0;
}
