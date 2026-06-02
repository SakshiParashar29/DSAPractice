class Solution {
public:
    bool check(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;

        if(!node1 && node2 || node1 && !node2 || node1->val != node2->val) return false;

        bool left = check(node1->left, node2->left);
        bool right = check(node1->right, node2->right);
 
        return left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q)  {
        return check(p, q);
    }
};
