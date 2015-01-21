/*************************************************************************
	> File Name: MediaOfTwoArray.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年10月26日 星期日 03时54分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

double findKth(int *a, int m, int *b, int n, int k)
{
	if (m > n)
		return findKth(b, n, a, m, k);
	if (0 == m)
		return *(b + k - 1);
	if (1 == k)
		return min(*a, *b);

	int pa = min(k / 2, m);
	int pb = k - pa;
	if (*(a + pa - 1) < *(b + pb - 1))
		return findKth(a + pa, m - pa, b, n, k - pa);
	else if (*(a + pa - 1) > *(b + pb - 1))
		return findKth(a, m, b + pb, n - pb, k - pb);
	else
		return *(a + pa - 1);
}

class Solution
{
	public:
		double findMedianSortedArrays(int A[], int m, int B[], int n)
		{
			int total = m + n;
			if (total & 0x1)
				return findKth(A, m, B, n, total / 2 + 1);
			else
				return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
		}
};


int main(int argc, char **argv)
{
	int a[] = {1, 3, 5, 7};
	int b[] = {2, 4, 6, 8, 10};
	Solution solution = Solution();
	cout <<"Media:"<<solution.findMedianSortedArrays(a, sizeof(a) / sizeof(int), b, sizeof(b) / sizeof(int))<<endl;
	return 0;
}
