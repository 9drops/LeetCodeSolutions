/*************************************************************************
	> File Name: atoi.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年09月30日 星期二 23时35分18秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define INT_MIN   (-INT_MAX - 1)                                                                                              
#define INT_MAX   2147483647

class Solution {
	public:
		int atoi(const char *str) {
			int sign = 1;
			long long result = 0;
			char out_of_bands = 0;

			if (NULL == str)
				return 0;

			/*trim blank space*/
			while (str && *str == ' ')
				str++;
			if (!(*str >= '0' && *str <= '9' || *str == '+' || *str == '-')) 
				return 0;

			if (*str == '+'|| *str == '-') { 
				if (*str == '+') 
					sign = 1;
				else 
					sign = -1;
				str++;
			}

			while (*str != '\0' && (*str >= '0' && *str <= '9')) { 
				result = (10 * result + *str - '0');

				/*out of max int*/
				if (result > INT_MAX) {
					out_of_bands = 1;
					break;
				}

				str++;
			}

		
			if (out_of_bands) {
				if (-1 == sign) 
					result = INT_MIN;
				else
					result = INT_MAX;
			} else 
					result *= sign;

			return result;
		}
};


int main(int argc, char **argv)
{
	Solution solution = Solution();
	cout <<"atoi(argv[1]) = "<<solution.atoi(argv[1])<<endl;
	return 0;
}
