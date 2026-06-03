/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
        vector<int> res;
    void left_node(Node* root){
        if(!root || !root->left && !root->right) return;
        
        res.push_back(root->data);
        
        if(!root->left) left_node(root->right);
        else left_node(root->left);
    }
    void right_node(Node* root){
        if(!root || !root->left && !root->right) return;
        
        if(!root->right) right_node(root->left);
        else right_node(root->right);
        
        res.push_back(root->data);
    }
    void leaf_node(Node* root){
        if(!root) return;
        
        if(!root->left && !root->right) res.push_back(root->data);
        leaf_node(root->left);
        leaf_node(root->right);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(!root->left && !root->right) return {root->data};
        
        res.push_back(root->data);
        
        left_node(root->left);
        
        leaf_node(root);
        
        right_node(root->right);
        
        return res;
    }
};
