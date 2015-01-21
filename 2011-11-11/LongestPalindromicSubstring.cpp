/*************************************************************************
	> File Name: LongestPalindromicSubstring.cpp
	> Author: 9drops
	> Mail: codingnote.net@gmail.com 
	> Created Time: 2014年12月05日 星期五 09时57分52秒
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;


class Solution {
	public:
		string longestPalindrome(string s) {
			int len;
			int i, low, high;
			int max_size  = 0;
			int start = 0;
			len = s.size();

			if (len <= 1)
				return s;

			for (i = 1; i < len; i++) {
				low  = i - 1;
				high = i + 1;
				//奇数长度回文
				while (low >= 0 && high < len && s[low] == s[high]) {
					low--;
					high++;
				}

				if (max_size < high - low - 1) {
					max_size  = high - low - 1;
					start = low + 1;
				}

				//偶数长度回文
				low = i - 1;
				high = i;
				while (low >=0 && high < len && s[low] == s[high]) {
					low--;
					high++;
				}

				if (max_size < high - low - 1) {
					max_size  = high - low - 1;
					start = low + 1;
				}

			}

			cout <<start<<","<<max_size<<endl;
			return s.substr(start, max_size);
		}
};


int main(int argc, char **argv)
{
	Solution solution = Solution();
	string s(argv[1]); 
	cout<<solution.longestPalindrome(s)<<endl;
	return 0;
}
