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

    ListNode* insertionSortList(ListNode* head) 
    {
        if(!head)
            return head;
       
        
        while(head->next)
        {
            ListNode* s=head;
            ListNode* f=head->next;
            ListNode* prev=nullptr;
            bool isSorted=true;
            while(f)
            {
                if(f->val < s->val )
                {
                    if(s==head)
                        head=f;                    
                    s->next=f->next;
                    f->next=s;
                    if(prev)
                        prev->next=f;
                    f=s->next;
                    if(prev)
                        prev=prev->next;
                    else
                        prev=head;
                    isSorted=false;
                }
                else
                {
                    f=f->next;
                    s=s->next;
                    if(prev)
                        prev=prev->next;
                    else
                        prev=head;
                }
            }
            if(isSorted)
                return head;

        }
        return head;
    }
};