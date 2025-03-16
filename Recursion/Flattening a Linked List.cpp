class Solution {
  public:
   Node* merge(Node* head1, Node* head2)
   {
       Node dummy(-1);
       Node* tail = &dummy;
       
       while(head1 && head2)
       {
           if(head1->data <= head2->data)
           {
               tail->bottom = head1;
               head1 = head1->bottom;
           }
           else
           {
               tail->bottom = head2;
               head2 = head2->bottom;
           }
           tail = tail->bottom;
       }
       if(!head1)
       {
            tail->bottom = head2;
       }
       else
           tail->bottom = head1;
       return dummy.bottom;
   }
    Node *flatten(Node *root) {
        if(root == NULL)
           return NULL;
           
        Node* head = flatten(root->next);
        
        root = merge(root, root->next);
        
        return root;
    }
};
