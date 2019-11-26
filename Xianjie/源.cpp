#include <stdio.h>
#include <math.h>
double f1(double x) {
	x = x * x * x + 2 * x * x + 10 * x - 20;
	return x;
}
void xianjie(double (*f1)(double)) {
	double x0, x1,x2, e; int k = 0;
	printf("Please input x0 , x1 and e:");
	scanf("%lf%lf%lf", &x0,&x1, &e);
	while (true) {
		x2 = x1 - (*f1)(x1) / ((*f1)(x1) - (*f1)(x0)) * (x1 - x0);
		k++;
		if (fabs(x2 - x1) < e && fabs((*f1)(x2) < e)) {
			printf("x1=%-10.6lf y(x1)=%-10.6lf k=%d\n", x1, (*f1)(x1), k);
			break;
		}
		x0 = x1; x1 = x2;
	}
}
int main() {
	xianjie(f1);
}