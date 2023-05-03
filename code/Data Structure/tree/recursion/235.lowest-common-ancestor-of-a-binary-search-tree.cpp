/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    pair<bool,bool> helper(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (!node) return {false, false};
        auto l =  helper(node->left, p,q,ans);
        if (l.first && l.second) {
            if (!ans) ans = node->left;
            return {1, 1};
        }
        auto r =  helper(node->right, p,q,ans);
        if (r.first && r.second) {
            if (!ans) ans = node->right;
            return {1, 1};
        }
        bool b_p = (node == p), b_q = (node == q);
        b_p = b_p || l.first || r.first;
        b_q = b_q || l.second || r.second;
        return {b_p, b_q};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        helper(root, p, q, ans);
        return ans ? ans: root;
    }
};
// @lc code=end

