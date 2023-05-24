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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL) 
        {
            temp=temp->next;
            n++;
        }
        int N=floor((float)n/k);
        cout<<N<<endl;
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        int j=0;
        while(j!=N)
        {
            j++;
            for(int i=0;i<k-1;i++)
            {
                ListNode* next=curr->next;
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
            }
            prev=curr;
            curr=prev->next;
        }
        return dummy->next;
    }
};