#include "gpio.h"
#include <stdlib.h>

/*
* Author: Matthias Bun
* File: button.h
* Description: Too Lazy
*/

typedef struct {
	int i;
}Button;


inline Button* initButton(int gpio) {
	Button* l = malloc(sizeof(Button));
	l->i = gpio;
	INP_GPIO(gpio);

	return l;
}



inline bool isButtonDown(Button* b) {
	return GPIO_READ(b->i) != 0;
}

inline bool isButtonUpButton* b) {
	return GPIO_READ(b->i) == 0;
}
