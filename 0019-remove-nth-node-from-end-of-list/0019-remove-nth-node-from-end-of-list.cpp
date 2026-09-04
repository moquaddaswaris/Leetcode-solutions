/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        if(head==NULL || head->next==NULL) return NULL;

        int length = 0;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        if(n==length) return head->next;

        curr = head;
        length = length-n;
        while(length>1){
            curr = curr->next;
            length--;
        }

        curr->next = curr->next->next;
        return head;
    }
};