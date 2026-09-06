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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr = head;
        if(head==NULL || head->next==NULL) return NULL;

        int length = 0;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }

        int mid  = length/2;
        curr = head;
        while(mid>1){
            curr = curr->next;
            mid--;
        }
        curr->next = curr->next->next;

        return head;
    }
};