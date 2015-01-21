/*************************************************************************
	> File Name: IntersectionOfTwoLinkedLists.cpp
	> Author: 9drops
	> Mail: zhanbz@gmail.com 
	> Created Time: 2014年12月11日 星期四 23时25分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
				ListNode *pA, *pB, *tailA, *tailB;
				pA = headA;
				pB = headB;
				tailA = tailB = NULL;
				if (NULL == headA || NULL == headB)
					return NULL;

				while (true) {
					if (NULL == pA)
						pA = headB;
					if (NULL == pB)
						pB = headA;
					if (NULL == pA->next)
						tailA = pA;
					if (NULL == pB->next)
						tailB = pB;
					if (tailA && tailB && tailA != tailB)
						return NULL;

					if (pA == pB)
						return pA;

					pA = pA->next;
					pB = pB->next;

				}
			}
				        
};


int main(int argc, char **argv)
{
	//{1,3,5,7,9,11,13,15,17,19,21}, {2}
	int i;
	ListNode *node, *headA = NULL, *headB = NULL;
	for (i = 5; i > 0; i -= 2) {
		node = new ListNode(i);
		node->next = headA;
		headA = node;
	}

	headB = new ListNode(7);
	headB->next = headA->next->next;

	Solution solution = Solution();
	node = solution.getIntersectionNode(headA, headB);
	if (node)
		cout<<node->val<<endl;

	//TODO:free memory
	return 0;
}
