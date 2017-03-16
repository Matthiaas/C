#include "gpio.h"
#include "button.h"
#include "led.h"

#define BUTTONGPIO 2
#define LEDGPIO 3


/*
* Author: Matthias Bun
* File: main.c
* Description: Lets the led in GPIO LEDGPIO shine if the button in GPIO BUTTONGPIO is pressed
*/
int main()
{

	if (map_peripheral() == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	Button *but = initButton(BUTTONGPIO);
	Led* led = initLed(LEDGPIO);
		
	bool isOn = false;

	while (1)
	{
		
		if (isButtonDown(but)) {
			switchLed(HIGH);
		}
		else {
			switchLed(LOW);
		}


	}


	return 0;
}



// Exposes the physical address defined in the passed structure using mmap on /dev/mem
int map_peripheral()
{
	struct bcm2835_peripheral *p = &gpio_struct;
	// Open /dev/mem
	if ((p->mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
		printf("Failed to open /dev/mem, try checking permissions.\n");
		return -1;
	}

	p->map = mmap(
		NULL,
		BLOCK_SIZE,
		PROT_READ | PROT_WRITE,
		MAP_SHARED,
		p->mem_fd,      // File descriptor to physical memory virtual file '/dev/mem'
		p->addr_p       // Address in physical map that we want this memory block to expose
	);
	close(p->mem_fd);
	if (p->map == MAP_FAILED) {
		perror("mmap");
		return -1;
	}

	p->addr = (volatile unsigned int *)p->map;
	return 0;
}

void unmap_peripheral(struct bcm2835_peripheral *p) {

	munmap(p->map, BLOCK_SIZE);
	close(p->mem_fd);
}