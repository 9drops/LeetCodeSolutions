/*************************************************************************
	> File Name: LinkedListCycle.cpp
	> Author: 9drops
	> Mail: codingnote.net@gmail.com 
	> Created Time: 2014年12月19日 星期五 15时19分06秒
 ************************************************************************/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };


//假设将环劈开，然后用类似求2个链表相交节点的解法
class Solution {
	public:
		//return the node the same arrived
		ListNode *hasCycle(ListNode *head, int *len) 
		{
			int i = 0;
			ListNode *one_step, *two_step;
			one_step = head;
			two_step = head;
			while (two_step && two_step->next) {
				i++;
				two_step = two_step->next->next;
				if (one_step == two_step) {
					*len = i;
					return one_step;
				}
				one_step = one_step->next;
			}
			
			*len = 0;
			return NULL;
		}   

		ListNode *detectCycle(ListNode *head) {
			int i, len, len2 = 1;
			ListNode *end, *start, *p, *q;
			if ((end = hasCycle(head, &len))) {
				start = end->next;
				//list1:head, list2:start, the same end:end
				p = head;
				q = start;
				while (q != end) {
					len2++;
					q = q->next;
				}

				q = start;
				if (len2 > len) {
					i = len2 - len;
					while (i--) {
						q = q->next;
					}
				} else {
					i = len - len2;
					while (i--) {
						p = p->next;
					}
				}

				while (1) {
					if (p == q)
						return p;
					p = p->next;
					q = q->next;
				}


			} else 
				return NULL;
		}
};

int main()
{
	int i;
	ListNode *node, *t, *head = NULL;
	
	for (i = 1; i < 6; i++) {
		node = new ListNode(i);
		if (1 == i)
			t = node;
		if (head) 
			node->next = head;
		head = node;
	}


	//make circle
	t->next = head->next;
	

	Solution solution = Solution();
	node = solution.detectCycle(head);
	if (node) cout<<node->val<<endl;

	return 0;
}
