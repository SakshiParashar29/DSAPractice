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
class Solution {
public:
    int res = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int left_right_sum = left + right + root->val;
        int left_or_right = max(left, right) + root->val;
        int only_root = root->val;

        res = max({res, left_right_sum, left_or_right, only_root});

        return max(left_or_right, only_root);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        solve(root);

        return res;
    }
};
