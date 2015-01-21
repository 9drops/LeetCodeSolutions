/*************************************************************************
	> File Name: two_sum.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年09月30日 星期二 01时30分43秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			int i, j, k;
			int half_target, num, index1, index2;
			int v1, v2, size;
			vector<int> res;
			size = numbers.size();
			half_target = target / 2;
			i = -1;
			j = -1;

			vector<int> tmp_numbers(numbers);
			sort(tmp_numbers.begin(), tmp_numbers.end());

			if (tmp_numbers[size - 1] < half_target) {
				res.push_back(0);
				res.push_back(0);
				return res;
			}

			while (tmp_numbers[++i] < half_target && i < size);

			if (tmp_numbers[i] == half_target && i < size - 1 && tmp_numbers[i + 1] == half_target) {
				j = i;
				k = i + 1;
			} else {
				while (++j < i) {
					k = i;
					while (k < size) {
						if (tmp_numbers[j] + tmp_numbers[k] == target)
							goto FIND_INDEX;
						k++;
					}
				}	
			}

			FIND_INDEX:
				v1 = tmp_numbers[j];
				v2 = tmp_numbers[k];
				i = -1;
				num = 0;
				while (++i < size) {
					if (numbers[i] == v1) {
						index1 = i;
						num++;
					}
					if (numbers[size -1 - i] == v2) {
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

				res.push_back(index1 + 1);
				res.push_back(index2 + 1);
				cout<<res[0]<<","<<res[1]<<endl;
				return res;
		}


};


int main(int argc, char **argv)
{
	int size, target = 0;
	int numbers [] = {0, 4, 3, 0};
	size = sizeof(numbers) / sizeof(int);
	vector<int> vect(size);

	copy(numbers, numbers + size, vect.begin());

	Solution solution = Solution();
	solution.twoSum(vect, target);
	return 0;
}


