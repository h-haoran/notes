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
        dfs(root, 0, ans);
        return ans;
    }
};
// @lc code=end

