/*************************************************************************
	> File Name: LinkedListCycle.cpp
	> Author: 9drops
	> Mail: codingnote.net@gmail.com 
	> Created Time: 2014��12��19�� ������ 15ʱ03��38��
 ************************************************************************/


 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		bool hasCycle(ListNode *head) {
			ListNode *one_step, *two_step;
			one_step = head;
			two_step = head;
			while (two_step && two_step->next) {
				two_step = two_step->next->next;
				if (one_step == two_step)
					return true;
				one_step = one_step->next;
			}

			return false;
		}
};
