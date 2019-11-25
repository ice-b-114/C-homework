#include <stdio.h>
#define n 9
int main() {
	double x[n] = { -1.00,-0.75,-0.5,-0.25,0,0.25,0.5,0.75,1.00 };
	double y[n] = { -0.2209,0.3295,0.8826,1.4392,2.0003,2.5645,3.1334,3.7061,4.2836 };
	double a = 0, b = 0, c = 0;
	double sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumxy = 0, sumy = 0, sumx2y = 0;
	double d, da, db, dc;
	for (int i = 0; i < n; i++) {
		sumx += x[i];
		sumx2 += x[i] * x[i];
		sumx3 += x[i] * x[i] * x[i];
		sumx4 += x[i] * x[i] * x[i] * x[i];
		sumy += y[i];
		sumxy += y[i] * x[i];
		sumx2y += x[i] * x[i] * y[i];
	}
	d = n * sumx2 * sumx4 + sumx * sumx2 * sumx3 + sumx * sumx2 * sumx3
		- sumx2 * sumx2 * sumx2 - sumx * sumx * sumx4 - n * sumx3 * sumx3;
	da = sumx2 * sumx4 * sumy + sumx * sumx3 * sumx2y + sumx2 * sumx3 * sumxy
		- sumx2 * sumx2 * sumx2y - sumx * sumx4 * sumxy - sumx3 * sumx3 * sumy;
	db = n * sumx4 * sumxy + sumx2 * sumx3 * sumy + sumx * sumx2 * sumx2y
		- sumx2 * sumx2 * sumxy - sumx * sumx4 * sumy - n * sumx2 * sumx3;
	dc = n * sumx2 * sumx2y + sumx * sumx2 * sumxy + sumx * sumx3 * sumy
		- sumx2 * sumx2 * sumy - sumx * sumx * sumx2y - n * sumx3 * sumxy;
	a = da / d; b = db / d; c = dc / d;
	printf("拟合方程为   y=%9.6fx*x+%9.6fx+%9.6f", a, b, c);

}