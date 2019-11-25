#include <stdio.h>
#define n 11
double x0, y0, h, max;
double x[n], y[n];
double f;
void euler(double x0, double y0, double h, double max) {
	for (int i = 0; i <= n-2; i++) {
		f = y[i] - 2 * x[i] / y[i];
		y[i + 1] = y[i] + h * f;
		x[i + 1] = x[i] + h;
	}
	printf("x   y\n");
	for (int j = 0; j <= n-1; j++) {
		printf("%.1f %lf\n", x[j], y[j]);
	}
}
void improved_euler(double x0, double y0, double h, double max) {
	double yp, yc, f2;
	for (int i = 0; i <= n-2; i++) {
		x[i + 1] = x[i] + h;
		f = y[i] - 2 * x[i] / y[i];
		yp = y[i] + h * f;
		f2 = yp - 2 * x[i + 1] / yp;
		yc = y[i] + h * f2;
		y[i + 1] = (yp + yc) / 2;
	}
	printf("x   y\n");
	for (int j = 0; j <= n-1; j++) {
		printf("%.1f %lf\n", x[j], y[j]);
	}
}
int main() {
	printf("Please enter x0,y0,h,max\n");
	scanf("%lf %lf %lf %lf", &x0, &y0, &h, &max);
	x[0] = x0; y[0] = y0;
	int flag;
	while (1) {
		printf("1.Euler method 2.Improved Euler method\n");
		scanf("%d", &flag);
		if (flag == 1) {
			euler(x0, y0, h, max);
		}
		else if (flag == 2) {
			improved_euler(x0, y0, h, max);
		}
		else {
			printf("Error input!");
			printf("Error input!");
		}
	}
}
