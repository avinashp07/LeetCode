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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        int n=0;
        while(n!=k-1)
        {
            temp1=temp1->next;
            n++;
        }
        ListNode* split=temp1;
        while(split->next!=NULL)
        {
            split=split->next;
            temp2=temp2->next;
        }
        int t=temp1->val;
        temp1->val=temp2->val;
        temp2->val=t;
        return head;
    }
};