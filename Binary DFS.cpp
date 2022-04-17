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
struct node
{
    int data;
    struct node* left, * right;
};
int max(int a, int b) { return (a > b) ? a : b; }
int height(struct node* node)
{
	if (node == NULL) return 0;
	return 1 + max(height(node->left), height(node->right));
}
int diameter(struct node* tree)
{
    if (tree == NULL) return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int findDepth(struct node* root, int x)
{
    if (root == NULL) return -1;
    int dist = -1;
    if ((root->data == x) || (dist = findDepth(root->left, x)) >= 0 || (dist = findDepth(root->right, x)) >= 0) return dist + 1;
    return dist;
}
int findSubtree(struct node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + findSubtree(root->left) + findSubtree(root->right);
	}
}
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
	printf("Depth: %d\n", findDepth(root, 5));
	printf("Subtree Size: %d\n", findSubtree(root->right));
    printf("Diameter: %d", diameter(root));
}
