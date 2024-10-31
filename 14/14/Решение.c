#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES 
#define CRT_SECURE_NO_DEPRECATE
#define N 100
#define XMAX 100
#define XMIN 1

double* full_elements(double* ptr_array, int size)//��������� �������
{
	for (int i = 0; i < size; i++)
	{
		*ptr_array = XMIN + 1 * (XMAX - XMIN) * rand() / RAND_MAX;
		ptr_array++;
	}
	return ptr_array;
}

int put_elements(double* ptr_array, int size)//����� ��-��
{
	for (int i = 0; i < size; i++)
	{
		printf("\n������� ������ �������� %.2lf", *ptr_array);
		ptr_array++;
	}
	return 0;
}

double* calc_elements(double* ptr_array, int size)//������������ ����.�����
{
	for (int i = 0; i < size; i++, ptr_array++)
	{
		*ptr_array = (int)*ptr_array;
	}
	return ptr_array;
}
int find_element(double* ptr_array, int size, double element)//����� �������
{
	int ind = 0;
	for (int i = 0; i < N; i++)
	{
		int shtch = 0;
		if (element == *ptr_array)
		{
			ind = i;
			shtch += 1;
		}
		ptr_array++;
	}
	if (ind != 0)
	{
		return ind;
	}
	
	if (ind == 0)
	{
		return -1; 
	}
}

int funmax(double* ptr_array, int size, int ka)
{
	int ind = 0;
	double max = 0.;
	for (int i = ka; i < N; i++)
	{
		if  (*ptr_array>max)
		{
			ind = i;
			max = *ptr_array;
		}
		ptr_array++;
	}
	return ind;
}

void main()
{
	setlocale(LC_CTYPE , "RUS");
	double array[N];
	int size, ka, l;
	double element;

	printf("������� ������ ������� > ");
	scanf_s("%d", &size);

	double *ptr_array;
	ptr_array = &array[0];

	full_elements(array, size);
	do
	{
		printf("\n����\n1.����� ��������\n2.����� ���� ���������\n3.����� ��������� ������ ������������� ��������\n0.����� > ");
		scanf_s("%d", &l);
		switch (l)
		{
		case 1:
		{
			printf("\n������� ������� �������� > ");
			scanf_s("%lf", &element);
			printf("\n������� ��-� ��� �������� > %d", find_element(array, size, element));
			break;
		}
		case 2:
		{
			put_elements(array, size);
			break;
		}
		case 3:
		{
			printf("\n������� ������ � ������ ������ ��-� > ");
			scanf_s("%d", &ka);

			printf("\n������ ��-� > %d", funmax(array, size, ka));
			break;
		}
		default:
			printf("\n�������� ��-�");
			break;
		}
	} while (l != 0);
	//��
}