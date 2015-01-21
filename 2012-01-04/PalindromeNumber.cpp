#include <iostream>
using namespace std;

#define MIN_INT -MAX_INT - 1
#define MAX_INT 2147483647

int reverse(int x) 
{
       	long long res = 0;
        while (x) {
                res = 10 * res + x % 10;
                x = x / 10;
        }

        if (res > MAX_INT || res < MIN_INT)
                res = 0;
        return res;
}

class Solution {
public:
    bool isPalindrome(int x) {
	if (x < 0)
		return false;
	else
		return x == reverse(x);        
    }
};

int main(int argc, char **argv)
{
	Solution solution = Solution();
	cout<<solution.isPalindrome(-2147447412)<<endl;
	return 0;
}
