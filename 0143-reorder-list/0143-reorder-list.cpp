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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        //find the middle
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //separate second half
        ListNode* rightHead = slow->next;
        slow->next = NULL;

        //reverse second half
        ListNode* prev = NULL;
        ListNode* curr = rightHead;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* leftHead = head;
        rightHead = prev;
        while(rightHead != NULL){
            ListNode* leftNext = leftHead->next;
            ListNode* rightNext = rightHead->next;

            leftHead->next = rightHead;
            rightHead->next = leftNext;

            leftHead = leftNext;
            rightHead = rightNext;
        }
    }
};