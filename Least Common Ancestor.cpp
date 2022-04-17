#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cstdlib>
#include<ctype.h>
#include<math.h>
#include<cmath>
#include<time.h>
#include<ctime>
#include<string.h>
#include<string>
#include<limits.h>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<complex>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode* left, * right;
	TreeNode(int value)
	{
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};
int getKeysCount(TreeNode* root, vector<int>& keyNodes, int matchingNodes, vector<TreeNode*>& ancestors)
{
	if (root == NULL)
	{
		return 0;
	}
	matchingNodes += getKeysCount(root->left, keyNodes, matchingNodes, ancestors) + getKeysCount(root->right, keyNodes, matchingNodes, ancestors);
	if (find(keyNodes.begin(), keyNodes.end(), root->data) != keyNodes.end())
	{
		matchingNodes++;
	}
	if (matchingNodes == keyNodes.size())
	{
		ancestors.push_back(root);
	}
	return matchingNodes;
}
TreeNode* lcaOfNodes(TreeNode* root, vector<int>& keyNodes)
{
	vector<TreeNode*> ancestors;
	int matchingNodes = 0;
	getKeysCount(root, keyNodes, matchingNodes, ancestors);
	return ancestors[0];
}
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->left->left->left = new TreeNode(8);
	root->left->left->right = new TreeNode(9);
	root->left->right->left = new TreeNode(10);
	root->left->right->right = new TreeNode(11);
	root->right->left->left = new TreeNode(12);
	root->right->left->right = new TreeNode(13);
	root->right->right->left = new TreeNode(14);
	root->right->right->right = new TreeNode(15);
	vector<int> keyNodes;
	keyNodes.push_back(12);
	keyNodes.push_back(14);
	keyNodes.push_back(15);
	cout << lcaOfNodes(root, keyNodes)->data << endl;
}
