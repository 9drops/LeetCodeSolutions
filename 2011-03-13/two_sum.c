/*************************************************************************
	> File Name: two_sum.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年09月29日 星期一 07时08分46秒
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include <string.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int get_priov(int *array, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (array[left] > array[mid])
		swap(&array[left], &array[mid]);
	if (array[left] > array[right])
		swap(&array[left], &array[right]);
	if (array[mid] > array[right])
		swap(&array[mid], &array[right]);
	return array[mid]; 
}

void qsort(int *array, int left, int right)
{
	int i, j, priov;
	i = left;
	j = right;
	priov = get_priov(array, left, right);

	if (i < j) {
		for (;;) {
			while (array[++i] < priov);
			while (array[--j] > priov);
			if (i < j)
				swap(&array[i], &array[j]);
			else
				break;
		}

		qsort(array, left, i - 1);
		qsort(array, i + 1, right);
	}
}


int *two_sum(int *array, int size, int target)
{
	int *res;
	int i, j, k;
	int half_target, num, index1, index2;
	int v1, v2;
	int tmp_array[size];
	
	i = -1;
	half_target = target / 2;
	while (++i < size) tmp_array[i] = array[i];
	qsort(tmp_array, 0, size - 1);
	i = -1;
	j = -1;

	if (tmp_array[size - 1] < half_target) {
		res = (int *)malloc(2 * sizeof(int));
		*res = 0;
		*(res + 1) = 0;
		return res;
	}

	while (tmp_array[++i] < half_target && i < size);

	if (tmp_array[i] == half_target && i < size - 1 && tmp_array[i + 1] == half_target) {
		j = i;
		k = i + 1;
	} else {

		while (++j < i) {
			k = i;
			while (k < size) {
				if (tmp_array[j] + tmp_array[k] == target)
					goto FIND_INDEX;
				k++;
			}
		}
	}
FIND_INDEX:
	v1 = tmp_array[j];
	v2 = tmp_array[k];
	i = -1;
	num = 0;
	while (++i < size) {
		if (array[i] == v1) {
			index1 = i;
			num++;
		}
		if (array[size -1 - i] == v2) {
			index2 = size -1 - i;
			num++;
		}

		if (2 == num)
			break;
	}

	if (index1 > index2) {
		int tmp = index1;
		index1 = index2;
		index2 = tmp;
	}

	res = (int *)malloc(2 * sizeof(int));
	*res = index1 + 1;
	*(res + 1) = index2 + 1;

	return res;
}

int main()
{
	int *res;
	int i, target = 18;
	int array[] = {4, 9, 2, 3, 1, 7, 9};

	res = two_sum(array, 7, target);
	printf("%d %d\n", *res, *(res + 1));
	free(res);
	return 0;
}
