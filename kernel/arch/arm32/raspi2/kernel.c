#include <devices/uart.h>

void kmain(uint32_t r0, uint32_t r1, uint32_t atags) {
	(void)r0;
	(void)r1;
	(void)atags;

	uart_init();
	uart_puts("Hello world!\r\n");
	while(1)
		uart_putc(uart_getc());
}