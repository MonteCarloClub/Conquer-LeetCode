//
// Created by Oliver on 2021/4/25.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void dfs(TreeNode *t,TreeNode *root,TreeNode* r)
    {
        if(t!=root)
            return;
        dfs(t->left,root,r);
        dfs(t->right,root,r);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *r = new TreeNode();
        dfs(root,root,r);
        return r->right;
    }
};

int main()
{
    Solution s;
    return 0;
}