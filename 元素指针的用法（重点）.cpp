// 元素指针的用法（重点）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void shuru(int *a[]);
void settledata(int *a[]);
void printdata(int *a[]);
int main()
{
	int *a[11];
	shuru(a);
	settledata(a);
	printdata(a);

	//	printf("%d",*(a+1));
}

void shuru(int *a[]) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &*(a + i));
	}
}

void settledata(int *a[]) {
	//int i,bigindex=(int)*a,smallindex=(int)*a;
	int i, big = (int)*a, small = (int)*a, bigindex = 0, smallindex = 0;

	for (i = 0; i < 10; i++) {
		if ((int)*(a + i) > big) {
			big = (int)*(a + i);
			bigindex = i;
		}
		if ((int)*(a + i) < small) {
			small = (int)*(a + i);
			smallindex = i;
		}

	}
	//	printf("%d %d\n",bigindex,smallindex);
	//交换数组值
	*(a + 10) = *(a + bigindex);
	*(a + bigindex) = *(a + 9);
	*(a + 9) = *(a + 10);

	*(a + 10) = *(a + smallindex);
	*(a + smallindex) = *a;
	*a = *(a + 10);
}

void printdata(int *a[]) {
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d ", *(a + i));
	}
}
