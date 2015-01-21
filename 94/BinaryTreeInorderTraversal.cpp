/*************************************************************************
	> File Name: BinaryTreeInorderTraversal.cpp
	> Author: 9drops
	> Mail: codingnote.net@gmail.com 
	> Created Time: 2014年12月24日 星期三 14时40分45秒
 ************************************************************************/
#include <iostream>
#include <vector>
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
		vector<int>v;
		vector<int> inorderTraversal(TreeNode *root) {
			if (root) {
				inorderTraversal(root->left);
				v.push_back(root->val);
				inorderTraversal(root->right);
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
	solution.inorderTraversal(root);
	for (i = solution.v.begin(); i != solution.v.end(); ++i)
		cout<<*i<<" ";
	cout<<endl;
	return 0;

}
