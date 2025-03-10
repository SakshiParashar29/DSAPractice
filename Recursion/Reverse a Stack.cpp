 void insertAtBottom(stack<int>& St, int top)
    {
        if(St.empty())
        {
            St.push(top);
            return;
        }
           
        int curr_top = St.top();
        St.pop();
        insertAtBottom(St, top);
        St.push(curr_top);
    }
    void Reverse(stack<int> &St){
        if(St.empty())
           return;
           
        int top = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, top);
    }
