/*************************************************************************
	> File Name: BinaryTreeInorderTraversal.cpp
	> Author: 9drops
	> Mail: codingnote.net@gmail.com 
	> Created Time: 2014年12月24日 星期三 14时40分45秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 //Definition for binary tree
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	public:
		vector<int> v;
		vector<int> preorderTraversal(TreeNode *root) {
			stack<TreeNode*> s;
			TreeNode *p = root;
			while (p || !s.empty()) {
				while (p) {
					v.push_back(p->val);
					s.push(p);
					p = p->left;
				}

				if (!s.empty()) {
					p = s.top();
					s.pop();
					p = p->right;
				}
			}

			return v;

		}
};


int main()
{
	vector<int>::iterator i;
	struct TreeNode *root;
	root = new TreeNode(1);
	root->left  = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	Solution solution = Solution();
	solution.preorderTraversal(root);
	for (i = solution.v.begin(); i != solution.v.end(); ++i)
		cout<<*i<<" ";
	cout<<endl;
	return 0;

}
