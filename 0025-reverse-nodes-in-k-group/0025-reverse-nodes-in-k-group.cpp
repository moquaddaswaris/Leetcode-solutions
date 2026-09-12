/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* right = head;
        ListNode* left = head;

        ListNode* prevGroup = NULL;
        ListNode* newHead = head;

        while (right != NULL) {
            // Check if k nodes are available
            ListNode* temp = right;

            for (int i = 0; i < k; i++) {
                if (temp == NULL) return newHead;
                temp = temp->next;
            }

            // right = first node of current group
            // temp = first node after current group
            ListNode* prev = temp;
            ListNode* curr = right;

            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous group to current reversed group
            if (prevGroup != NULL) {
                prevGroup->next = prev;
            } else {
                newHead = prev;
            }

            // right was the first node before reversal,
            // so now it is the last node of this group
            prevGroup = right;
            right = curr;
        }

        return newHead;
    }
};