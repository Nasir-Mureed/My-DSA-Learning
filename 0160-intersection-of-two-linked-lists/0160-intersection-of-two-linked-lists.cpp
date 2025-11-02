/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0,lenB=0;
        ListNode* currA=headA;
        while(currA!=nullptr)
        {
            lenA++;
            currA=currA->next;
        }
        ListNode* currB=headB;
        while(currB!=nullptr)
        {
            lenB++;
            currB=currB->next;
        }
        int skip=0;
        currA=headA;
        currB=headB;
        if(lenA>lenB)
        {
            skip=lenA-lenB;
            currA=headA;
            while(skip!=0 && currA!=nullptr)
            {
                skip--;
                currA=currA->next;
            }
        }
        else
        {
            skip=lenB-lenA;
            currB=headB;
            while(skip!=0 && currB!=nullptr)
            {
                skip--;
                currB=currB->next;
            }
        }
        
        while(currA !=currB)
        {
            currB=currB->next;
            currA=currA->next;
        }
        return currA;
    }
};