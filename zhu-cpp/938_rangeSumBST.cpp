//
// Created by Oliver on 2021/4/27.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        stack<TreeNode*>stk;
        TreeNode *t;
        stk.push(root);
        while(!stk.empty()) {
            t = stk.top();
            stk.pop();
            if(t->val<=high&&t->val>=low)
                sum+=t->val;
            if(t->left != nullptr&&t->val>low)
                stk.push(t->left);
            if(t->right != nullptr&&t->val<high)
                stk.push(t->right);
        }
        return sum;
    }
};

int main()
{
    Solution s;
    return 0;
}