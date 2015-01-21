#include <iostream>
using namespace std;

#define MIN_INT -MAX_INT - 1
#define MAX_INT 2147483647

class Solution {
public:
    int reverse(int x) {
	long long res = 0;
	while (x) {
		res = 10 * res + x % 10;
		x = x / 10;
	}
	
	if (res > MAX_INT || res < MIN_INT) 
		res = 0;
	return res;
    }
};

int main(int argc, char **argv)
{
	Solution solution = Solution();
	cout<<solution.reverse(-147483647)<<endl;
	return 0;
}
