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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* head = lists[0];

        for(int j = 1; j < lists.size(); j++){
            ListNode* head1 = head;
            ListNode* head2 = lists[j];

            ListNode* dummy = new ListNode(-1);
            ListNode* temp = dummy;

            while(head1 != NULL && head2 != NULL){
                if(head1->val <= head2->val){
                    temp->next = head1;
                    head1 = head1->next;
                }
                else{
                    temp->next = head2;
                    head2 = head2->next;
                }

                temp = temp->next;
            }

            if(head1 == NULL) temp->next = head2;
            else temp->next = head1;

            head = dummy->next;
        }

        return head;
    }
};