/*************************************************************************
	> File Name: RomanToInteger.cpp
	> Author: 9drops
	> Mail: zhanbz@gmail.com 
	> Created Time: 2014年12月10日 星期三 19时00分25秒
 ************************************************************************/

#include <iostream>
using namespace std;

int romanToNum(char c) {
	switch (c) {
		case 'i':
		case 'I':
			return 1;
		case 'v':
		case 'V':
			return 5;
		case 'x':
		case 'X':
			return 10;
		case 'l':
		case 'L':
			return 50;
		case 'c':
		case 'C':
			return 100;
		case 'd':
		case 'D':
			return 500;
		case 'm':
		case 'M':
			return 1000;
	}
		return 0;
}

class Solution {
	public:
		int romanToInt(string s) {
			int i, res = 0;
			int iCur, iNext;
			int size = s.size();

			for (i = 0; i < size; i++) {
				iCur = romanToNum(s[i]);
				iNext = romanToNum(s[i + 1]);

				if (iCur < iNext) 
					res += -1 * iCur;
				else 
					res += iCur;
				return res;
			}
};


int main(int argc, char **argv)
{
	Solution solution = Solution();
	string s = argv[1];
	cout<<solution.romanToInt(s)<<endl;
	return 0;
}
