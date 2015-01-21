/*************************************************************************
	> File Name: strstr.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年10月04日 星期六 00时54分17秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
	public:
		void getNext(char *p, int next[]) {
			int k = -1;
			int j = 0;
			next[0] = -1;
			while (*(p + j) != '\0') {
				if (-1 == k || p[j] == p[k]) {
					++j;
					++k;
					if (p[j] != p[k]) 
						next[j] = k;
					else
						next[j] = next[k];
				} else {
					k = next[k];
				}
			}

			return;
			
		}

		//Brute Force
		int strStr2(char *haystack, char *needle) {
			int i;
			int j;
			for (i = 0; ;i++) {
				for (j = 0; ;j++) {
					if (needle[j] == '\0') return i;
					if (haystack[i + j] == '\0') return -1;
					if (needle[j] != haystack[i + j]) break;
				}
			}
		}

		//KMP
		int strStr(char *haystack, char *needle) {
			int i = 0;
			int j = 0;
			int pLen = 0;
			char *p = needle;
			while (*p++) pLen++;
			int next[pLen];
			getNext(needle, next);

			while (haystack[i] && j < pLen) {
				if (-1 == j || haystack[i] == needle[j]) {
					i++;
					j++;
				} else {
					j = next[j];
				}
			}

			if (j == pLen)
				return i - j;
			else
				return -1;
		}									
};

int main(int argc, char **argv)
{
	Solution solution = Solution();
	cout<<solution.strStr2(argv[1], argv[2])<<endl;
	return 0;
}
