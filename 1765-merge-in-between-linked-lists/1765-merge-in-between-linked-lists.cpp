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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* curr=list1;
        while(curr->next)
        {
            if(a==1)
            {
                ListNode* temp=curr;
                curr=curr->next;
                temp->next=list2; //connection establish
                break;
            }
            a--;
            b--;
            curr=curr->next;
        }
        ListNode* endConection=nullptr;
        while(curr && curr->next)
        {
            if(b==1)
            {
                endConection=curr->next;
                curr->next=nullptr;
            }
            b--;
            ListNode* toDelete=curr;
            curr=curr->next;
            delete toDelete;
        }
        ListNode* curr2=list2;
        while(curr2->next)
        {
            curr2=curr2->next;
        }
        curr2->next=endConection;
        return list1;
    }
};