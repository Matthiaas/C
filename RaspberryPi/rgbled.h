#include "gpio.h"
#include <stdlib.h>

#ifndef rgbledh
#define rgbledh


typedef struct {
	int r, g, b;
}RGBLed;

inline RGBLed* initRGBLed(int r , int g , int b) {
	RGBLed* l = malloc(sizeof(RGBLed));
	l->r = r;
	l->g = g;
	l->b = b;
	INP_GPIO(r);
	OUT_GPIO(r);
	INP_GPIO(g);
	OUT_GPIO(g);
	INP_GPIO(b);
	OUT_GPIO(b);
	return l;
}
inline void turnOff(RGBLed* l) {
	GPIO_CLR = 1 << (l->r);
	GPIO_CLR = 1 << (l->g);
	GPIO_CLR = 1 << (l->b);

}

inline void setColor(RGBLed *l, bool r, bool g, bool b) {
	turnOff(l);
	if(r)
		GPIO_SET = 1 << (l->r);
	if (g)
		GPIO_SET = 1 << (l->g);
	if (b)
		GPIO_SET = 1 << (l->b);
}





#endif // !led