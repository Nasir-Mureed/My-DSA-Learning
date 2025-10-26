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
    int  GCD(int i,int j)  //i>j
    {
        if(i==0 || j==0)
            return  i>j?i:j;
        return GCD(j,i%j); 
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* curr=head;
        while(curr && curr->next)
        {
            int i,j;
            if(curr->val>curr->next->val)
            {
                i=curr->val;
                j=curr->next->val;
            }
            else
            {
                i=curr->next->val; 
                j=curr->val;
            }
            int gcd=GCD(i,j);
            ListNode* nxt=curr->next;
            curr->next=new ListNode(gcd,nxt);
            curr=nxt;
        }
        return head;
    }
};