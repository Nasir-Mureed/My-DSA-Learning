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
    void reorderList(ListNode* head) 
    {
        if(!head || !head->next || !head->next->next ) //nothing for 2 or less nodes 
            return ;
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        bool isEvenLen;
        if(!fast) 
            isEvenLen=true;
        else
            isEvenLen=false;
        slow=slow->next;  // one step forward from middle
        stack<ListNode*> st;
        while(slow)
        {
            st.push(slow);
            slow=slow->next;
        }
        slow=head;
        while(!st.empty())
        {
            if(!isEvenLen && st.size()==1)
            {
                break;
            }
            ListNode* save=slow->next;
            slow->next=st.top();
            st.pop();
            slow->next->next=save;
            slow=save;
        }
        
        slow->next=nullptr;
        //return head;


    }
};