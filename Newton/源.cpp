#include <stdio.h>
#include <math.h>
double f1(double x) {
	return x;
}
double f2(double x) {
	return x;
}
void newton(double (*f1)(double), double (*f2)(double)) {
	double x0, x1, e, y; int k = 0, n;
	printf("Please input x0 and e:");
	scanf("%lf%lf", &x0, &e);
	printf("Please input N:");
	scanf("%d", &n);
	while (k <= n) {
		y = (*f2)(x0);
		if (y == 0) { printf("f'(x0)=0\n"); return; }
		x1 = x0 - (*f1)(x0) / y;
		k++;
		if (fabs(x1 - x0) < e && fabs((*f1)(x1) < e)) {
			printf("x1=%-10.5lf y(x1)=%-10.5lf k=%d\n", x1, (*f1)(x1), k);
			break;
		}
		x0=x1;
	}
}
void main() {
	newton(f1,f2);
}