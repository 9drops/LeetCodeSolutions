/*************************************************************************
	> File Name: IntegerToRoman.cpp
	> Author: 9drops
	> Mail: zhanbz@gmail.com 
	> Created Time: 2014年12月10日 星期三 19时45分12秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


const char *romanStr[][10] = {
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"", "M", "MM", "MMM"}
	};




class Solution {
	public:
		string intToRoman(int num) {
			int i = 0;
			string sRoman = string();
			if (num > 3999 || num < 1)
				return sRoman;

			while (num) {
				sRoman.insert(0, romanStr[i++][num % 10]);
				num = num / 10;
			}

			return sRoman;

		}
};


int main(int argc, char **argv)
{
	Solution solution = Solution();
	cout<<solution.intToRoman(atoi(argv[1]))<<endl;
	return 0;
}
