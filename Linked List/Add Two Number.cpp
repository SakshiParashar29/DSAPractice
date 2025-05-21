class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;

        ListNode* res = new ListNode(-1);
        ListNode* dummy = res;

        int carry = 0;
        while(h1 || h2 || carry)
        {
            int sum = carry;
            sum += h1 ? h1->val : 0;
            sum += h2 ? h2->val : 0;

            carry = sum / 10;

            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;

            if(h1)
               h1 = h1->next;
            if(h2)
              h2 = h2->next;
        }
        return res->next;
    }
};
