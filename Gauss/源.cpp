#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n, i, j;
float** array, * b;
//���������ʾ����
void showarray() {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%lf    ", array[i][j]);
		}
		printf("=%lf\n", b[i]);
	}
}
void showresult() {
	for (i = 0; i < n; i++) {
		printf("b[%d]=%f    ", i, b[i]);
	}
}
//����Ԫ�غ���
void selectmainelement(int k) {
	float d = array[k][k],temp;
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
			for (j = k; j < n; j++) {
				temp = array[l][j]; array[l][j] = array[k][j]; array[k][j] = temp;
			}
			temp = b[k]; b[k] = b[l]; b[l] = temp;
		}
	}
}
void gauss() {
	int flag;
	while (true)//�Ƿ�ʹ������Ԫ��
	{
		printf("1.Use seletionmainelement method 2.Use nothing:");
		scanf("%d",&flag);
		if (flag == 1 || flag == 2) {
			break;
		}
	}
	//��˹��ȥ��
	for (int k = 0; k < n - 1; k++) {
		if (flag == 1) {
			selectmainelement(k);
		}
		//��һ������ϵ����Ϊ1
		for (j = k + 1; j <= n - 1; j++) {
			array[k][j] = array[k][j] / array[k][k];
		}
		b[k] = b[k] / array[k][k];
		//����ʣ�µķ���
		array[k][k] = 1;
		for (i = k + 1; i <= n - 1; i++) {
			for (j = k + 1; j <= n-1; j++) {
				array[i][j] = array[i][j] - array[i][k] * array[k][j];
			}
			b[i] = b[i] - array[i][k] * b[k];
			array[i][k] = 0;
		}
	}
	//�ش���������
	float sum;
	//�������һ������
	b[n-1] = b[n-1] / array[n-1][n-1];
	array[n - 1][n - 1] = 1;
	for (i = n - 2; i >= 0; i--) {
		sum = 0;
		for (j = i + 1; j <= n - 1; j++) {
			sum = sum + array[i][j] * b[j];
		}
		b[i] = b[i] - sum;
	}
	showarray();
	showresult();
}
int main() {
	//�������Է�����
	printf("Please enter the dimension of linear equation system:");
	scanf("%d",&n);
	array = (float**)calloc(n, sizeof(float));
	b = (float*)calloc(n, sizeof(float));
	for (i = 0; i < n; i++) {
		array[i] = (float*)calloc(n, sizeof(float));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("Please enter value of (%d,%d):", i, j);
			scanf("%f", &array[i][j]);
		}
		printf("Please enter right const result of row %d:",i+1);
		scanf("%f", &b[i]);
	}
	gauss();
}