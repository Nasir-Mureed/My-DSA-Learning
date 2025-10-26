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
    ListNode* doubleIt(ListNode* head) 
    {
        vector<int> arr;
        int size=0;
        ListNode* curr=head;
        while(curr)
        {
            arr.push_back(curr->val);
            size++;
            curr=curr->next;
        }
        int carry=0;
        for(int i=size-1;i>=0;i--)
        {
            arr[i]=arr[i]*2+carry;
            carry=arr[i]/10;
            if(arr[i]>9)
                arr[i]%=10;
        }
        curr=head;
        while( carry)
        {
            int digit=carry%10;
            carry/=10;
            ListNode* temp=new ListNode(digit,head);
            head=temp;
        }
        for(int i=0;i<size;i++)
        {
             curr->val=arr[i];
            if(!curr->next)
                curr->next=new ListNode();
            curr=curr->next;
        }
        curr=head;
        while(curr->next->next!=nullptr)
        {
            curr=curr->next;
        }
        delete curr->next;
        curr->next=nullptr;
        return head;
    }
};