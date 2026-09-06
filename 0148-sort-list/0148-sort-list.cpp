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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        //find the mid of the list
        ListNode* slow = head;
        ListNode*fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;

        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = NULL;

        //merge sort for the left and right sublist.
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // Merge two sorted lists
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(leftHead != NULL && rightHead != NULL){
            if(leftHead->val <= rightHead->val){
                curr->next = leftHead;
                leftHead = leftHead->next;
            }
            else{
                curr->next = rightHead;
                rightHead = rightHead->next;
            }

            curr = curr->next;
        }

        // Attach remaining nodes
        if(leftHead != NULL)
            curr->next = leftHead;

        if(rightHead != NULL)
            curr->next = rightHead;

        return dummy->next;
    }
};