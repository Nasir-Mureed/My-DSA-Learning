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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* resHead=new ListNode(0);
        ListNode* resTail=resHead;
        ListNode* curr=head->next;
        int sum=0;
        while(curr)
        {
            if(curr->val==0)
            {
                resTail->next=new ListNode(sum);
                resTail=resTail->next;
                sum=0;
            }
            else
            {
                sum+=curr->val;
            }
            curr=curr->next;
        }
        
        return resHead->next;
    }
};