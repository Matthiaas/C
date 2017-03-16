#include "gpio.h"
#include <stdlib.h>

#ifndef ledh
#define ledh

typedef struct {
	int i;
}Led;


inline Led* initLed(int gpio) {
	Led* l = malloc(sizeof(Led));
	l->i = gpio;
	INP_GPIO(gpio);
	OUT_GPIO(gpio);
	return l;
}

inline void switchLed(Led *l, bool on) {
	if (on == HIGH) {
		GPIO_SET = 1 << (l->i);
	}
	else {
		GPIO_CLR = 1 << (l->i);
	}
}



#endif // !led
