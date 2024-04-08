

#include <stdint.h>
#define RCC_BASEADDR 			0x40023800U
#define RCC_AHB1ENR_OFF  		0x30
#define RCC_AHB1ENR 		    (RCC_BASEADDR + RCC_AHB1ENR_OFF)
#define GPIOD_BASEADDR 			0x40020C00U
#define GPIOx_MODER_OFFSET 		0x00U
#define GPIOD_MODER   			(GPIOD_BASEADDR + GPIOx_MODER_OFFSET)
#define GPIOx_ODR_OFFSET        0x14
#define GPIOD_ODR               (GPIOD_BASEADDR  + GPIOx_ODR_OFFSET)
int main(void)
{
	 volatile uint32_t i = 0;
	 uint32_t * clk = (uint32_t *)RCC_AHB1ENR ;
	 * clk = 0x08;
	 uint32_t *mode_reg = (uint32_t *)GPIOD_MODER;
	 *mode_reg = 0x1000000;
	 uint32_t *odr_reg = (uint32_t *)GPIOD_ODR;
	 while(1)
	 {
	 *odr_reg = 0x1000;
	 for ( i = 0; i<100000; i++);
	 *odr_reg = 0x00;
	 for ( i = 0; i<100000; i++);
	 }
}
