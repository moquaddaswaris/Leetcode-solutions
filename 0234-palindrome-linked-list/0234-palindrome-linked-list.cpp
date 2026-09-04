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
    bool isPalindrome(ListNode* head) {
        //find the middle
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the next half list which head is slow;
        ListNode* curr = slow;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *rightCurr = prev;
        ListNode *leftCurr = head;
        while(rightCurr != NULL){
            if(rightCurr->val != leftCurr->val) return false;
            rightCurr = rightCurr->next;
            leftCurr = leftCurr->next;
        }

        return true;
    }
};