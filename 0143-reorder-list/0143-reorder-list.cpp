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
    ListNode* reverse(ListNode* node){
        ListNode* temp=NULL;
        ListNode* next=node;
        while(next!=NULL)
        {
            next=node->next;
            node->next=temp;
            temp=node;
            node=next;
        }
        return temp;
    }
    ListNode* mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head->next==NULL) return;
        ListNode* midd=mid(head);
        stack<ListNode*> stk;
        ListNode* lastNode=head;
        while(lastNode->next!=midd)
        {
            lastNode=lastNode->next;
        }
        lastNode->next=NULL;
        while(midd!=NULL)
        {
            ListNode* node=new ListNode(midd->val);
            stk.push(node);
            midd=midd->next;
        }
        ListNode* it=head;
        while(!stk.empty())
        {
            if(it->next==NULL)
            {
                it->next=stk.top();
                it=it->next;
                stk.pop();
            }
            else
            {
                stk.top()->next=it->next;
                it->next=stk.top();
                stk.pop();
                if(it->next->next==NULL)
                {
                    it=it->next;
                }
                else
                {
                    it=it->next->next;
                }
            }
            
        }
        
    }
};