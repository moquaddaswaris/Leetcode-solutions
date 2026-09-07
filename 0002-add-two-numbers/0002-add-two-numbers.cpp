class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(-1);
        ListNode* curr = sum;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry){
            int val1 = 0;
            int val2 = 0;

            if(l1 != NULL){
                val1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                val2 = l2->val;
                l2 = l2->next;
            }

            int total = val1 + val2 + carry;
            carry = total / 10;

            curr->next = new ListNode(total % 10);
            curr = curr->next;
        }

        sum = sum->next;
        return sum;
    }
};