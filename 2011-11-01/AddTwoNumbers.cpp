/*************************************************************************
	> File Name: AddTwoNumbers.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年10月27日 星期一 04时33分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *initLink(int i)
{
	ListNode *node, *head = NULL;
	while (i) {
		node = new struct ListNode(i);
		if (head) 
			node->next = head;
		head = node;
		i--;
	}

	return head;
}

void destroyLink(ListNode *head)
{
	ListNode *cur = head, *next;
	while (cur) {
		next = cur->next;
		delete cur;
		cur = next;
	}
}

void printLink(ListNode *head)
{
	while (head) {
		cout<<head->val<<" ";
		head = head->next;
	}

	cout <<endl;
}

class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			int addcarry = 0, mod;
			ListNode *head = NULL, *node = NULL;
			ListNode *t, *p, *q, *r;
			p = l1;
			q = l2;

			while (p && q) {
				mod = (p->val + q->val + addcarry) % 10;
				node = new struct ListNode(mod);
				addcarry = (p->val + q->val + addcarry) / 10;
				if (NULL == head) 
					head = node;
				else 
					t->next = node;
				t = node;
				p = p->next;
				q = q->next;
			}

			r = node;
			t = (p ? p : q);
		
			/*
			if (addcary) {
				node->next =  new struct ListNode(addcarry);
				node = node->next;
			}
			*/

			while (t) {
				mod = (addcarry + t->val) % 10;
				addcarry = (addcarry + t->val) / 10;
				node = new struct ListNode(mod);
				if (NULL == head)
					r = head = node;

				r->next = node;
				r = node;
				t = t->next;;
			}

			if (addcarry) {
				r->next =  new struct ListNode(addcarry);
				r = r->next;
			}

			return head;	        
		}
};


int main()
{
	ListNode *res;
	ListNode *l1 = initLink(9);
	ListNode *l2 = initLink(9);
	Solution solution = Solution();
	res = solution.addTwoNumbers(l1, l2);
	printLink(res);
	
	//delete links
	destroyLink(l1);
	destroyLink(l2);
	destroyLink(res);
	return 0;
}
