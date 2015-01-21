/*************************************************************************
	> File Name: RemoveNthNodeFromEndOfList.cpp
	> Author: 9drops
	> Mail: zhanbz@gmail.com 
	> Created Time: 2014年12月11日 星期四 22时10分15秒
 ************************************************************************/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			ListNode *prev = NULL, *cur, *nNext;
			nNext = cur = head;
			while (n && nNext) {
				nNext = nNext->next;
				n--;
			}

			if (n > 0) 
				return NULL;

			while (nNext) {
				prev = cur;
				cur = cur->next;
				nNext = nNext->next;
			}

			if (cur == head)
				return head->next;
			else {
				prev->next = cur->next;
				return head;
			}

		}
};


int main()
{

	struct ListNode *list = new ListNode(1);
	struct ListNode *next = new ListNode(2);
	list->next = next;
	Solution solution = Solution();
	solution.removeNthFromEnd(list, 1);

	delete list;
	delete next;
	return 0;
}
