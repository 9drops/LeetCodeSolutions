/*************************************************************************
	> File Name: merge_sort.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年10月27日 星期一 00时02分39秒
 ************************************************************************/

#include<stdio.h>
#define INT_MAX 2147483647

/*index included p and r */
void merge(int *a, int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int l[n1 + 1];
	int m[n2 + 1];
	
	for (i = 0; i < n1; i++)
		l[i] = a[p + i];
	for (i = 0; i < n2; i++)
		m[i] = a[q + i + 1];
	/*set MAX abore comparing every time*/
	l[n1] = INT_MAX;
	m[n2] = INT_MAX;
	j = 0;
	k = 0;

	for (i = p; i <= r; i++) {
		if (l[j] <= m[k]) {
			a[i] = l[j];
			j++;
		} else {
			a[i] = m[k];
			k++;
		}
	}

}

void merge_sort(int *a, int p, int r)
{
	int q;
	if (p < r) {
		q = p + (r - p) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main(int argc, char **argv)
{
	int a[] = {7, 6, 5, 4, 3};
	merge_sort(a, 0, (sizeof(a) / sizeof(int)) - 1);
	return 0;
}
