#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int m, n, i, j;
double** array, * b;
void showarray() {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("%lf    ", array[i][j]);
		}
		printf("=%lf\n", b[i]);
	}
}
//列主元素函数
void selectmainelement(int k) {
	double d = array[k][k],temp;
	int l = k;
	for (i = k + 1; i < n - 1; i++) {
		if (fabs(array[i][k]) > fabs(d)) {
			d = array[i][k];
			l = i;
		}
		if (d == 0) {
			exit(0);
		}
		if (l != k) {
			for (j = k; j < n - 1; j++) {
				temp = array[l][j]; array[l][j] = array[k][j]; array[k][j] = temp;
			}
			temp = b[k]; b[k] = b[l]; b[l] = temp;
		}
	}
}
void gauss() {
	int flag;
	while (true)//是否使用列主元素
	{
		printf("1.Use:");
		scanf("%d",&flag);
		if (flag == 1 || flag == 2) {
			break;
		}
	}
	//高斯消去法
	for (int k = 0; k < n - 1; k++) {
		if (flag == 1) {
			selectmainelement(k);
		}
		//第一条方程系数化为1
		for (j = k + 1; j <= n - 1; j++) {
			array[k][j] = array[k][j] / array[k][k];
		}
		b[k] = b[k] / array[k][k];
		//处理剩下的方程
		array[k][k] = 1;
		for (i = k + 1; i <= n - 1; i++) {
			for (j = k + 1; j <= n; j++) {
				array[i][j] = array[i][j] - array[i][k] * array[k][j];
			}
			b[i] = b[i] - array[i][k] * b[k];
			array[i][k] = 0;
		}
	}
	//回代结果，输出
	double sum;
	//处理最后一条方程
	b[n-1] = b[n-1] / array[m-1][n-1];
	array[m - 1][n - 1] = 1;
	for (i = n - 2; i >= 0; i--) {
		sum = 0;
		for (j = i + 1; j <= n - 1; j++) {
			sum = sum + array[i][j] * b[j];
		}
		b[i] = b[i] - sum;
	}
	showarray();
}
int main() {
	//输入线性方程组
	printf("Please enter rows and cols:");
	scanf("%d%d", &m,&n);
	array = (double**)calloc(m, sizeof(double));
	b = (double*)calloc(n, sizeof(double));
	for (i = 0; i < m; i++) {
		array[i] = (double*)calloc(n, sizeof(double));
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("Please enter value of (%d,%d):", i, j);
			scanf("%lf", &array[i][j]);
		}
		printf("Please enter right const result of row %d:",i+1);
		scanf("%lf", &b[i]);
	}
	gauss();
}