#include <math.h>

int pow(double x, unsigned int y) {
	int temp;
	if(y == 0)
		return 1;
	temp = pow(x, y / 2);
	if(y % 2 == 0)
		return temp * temp;
	else
		return x * temp * temp;
}
