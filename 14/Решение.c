#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define N 100
#define XMAX 100
#define XMIN 1
double* full_elements(double *ptr_array, int size, int x)
{
	double *temp_ptr = ptr_array;
	for (int i = 0; i < size; i++)
	{
		*temp_ptr += abs(exp(1) - 2) - pow(x + i, 2);
		temp_ptr++;
	}
	return ptr_array;
}

int put_elements(double* ptr_array, int size)//Рабочее вроде
{
	for (int i = 0; i < size;i++)
	{
		printf("\nФункция вывода значений %.2lf", *ptr_array);
		ptr_array+=8;
	}
}

double* calc_elements(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++, ptr_array++)
	{
		*ptr_array = (int)*ptr_array;
	}
	return ptr_array;
}

void main()
{
	setlocale(LC_CTYPE , "RUS");
	double array[N];
	int size, x;

	printf("Введите размер массива > ");
	scanf_s("%d", &size);
	printf("Введите значение Х для заполнения массива >");
	scanf_s("%d", &x);

	double *ptr_array;
	ptr_array = &array[0];

	full_elements(array, size,x);
	put_elements(array, size);

	return 0;
}