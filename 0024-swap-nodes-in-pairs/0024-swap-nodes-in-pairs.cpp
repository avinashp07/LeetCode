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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy =new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* it=head;
        ListNode* next=head;
        while(it!=NULL && it->next!=NULL)
        {
            next=it->next;
            prev->next=next;
            it->next=next->next;
            next->next=it;
            prev=it;
            it=it->next;
        }
        return dummy->next;
    }
};