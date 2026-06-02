class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
           return {};
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoRight = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;

            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);
                if(node->left)
                   q.push(node->left);
                if(node->right)
                   q.push(node->right);
            }
            if(lefttoRight)
            {
                res.push_back(temp);
                lefttoRight = false;
            }
            else
            {
                reverse(begin(temp), end(temp));
                res.push_back(temp);
                lefttoRight = true;
            }
        }
        return res;
    }
};
