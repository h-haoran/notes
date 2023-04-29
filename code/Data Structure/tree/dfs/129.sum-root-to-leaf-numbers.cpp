/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <stack>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void dfs(TreeNode* n, int cur, int& ans) {
        if (n) {
            cur = cur * 10 + n->val;
            if (n->left && n->right) {
                dfs(n->left, cur, ans);
                dfs(n->right, cur, ans);
            } else if (!n->left && !n->right) {
                ans += cur;
            } else if (n->left) {
                dfs(n->left, cur, ans);
            } else {
                dfs(n->right, cur, ans);
            }
        }
        
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;        
        // dfs(root, 0, ans);
        stack<pair<TreeNode*, int>> s;
        if (root) s.push({root, 0});
        while (!s.empty()) {
            auto t = s.top();
            TreeNode* n = t.first;
            int cur = t.second;
            s.pop();
            cur = cur * 10 + n->val;
            if (n->left && n->right) {
                s.push({n->left, cur});
                s.push({n->right, cur});
            } else if (!n->left && !n->right) {
                ans += cur;
            } else if (n->left) {
                s.push({n->left, cur});
            } else {
                s.push({n->right, cur});
            }

        }
        return ans;
    }
};
// @lc code=end

