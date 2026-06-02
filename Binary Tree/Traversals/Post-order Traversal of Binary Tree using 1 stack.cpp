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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> res;

        stack<TreeNode*> st;

        TreeNode* lastVisited = NULL;
        TreeNode* curr = root;

        while(curr || !st.empty()){

            while(curr){
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* node = st.top();

            if(node->right && lastVisited != node->right){
                curr = node->right;
            } else {
                res.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }
        return res;
    }
};
