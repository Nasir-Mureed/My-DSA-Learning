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

 #include<ctime>
class Solution {
    ListNode* myHead;
    int len;
public:
    Solution(ListNode* head): myHead(head)
    {
        len=0;
        while(head)  //length
        {
            len++;
            head=head->next;
        }
        srand(time(0));
    }
    
    int getRandom() 
    {
        int x= rand()%len;
        ListNode* curr=myHead;
        while(curr)
        {
            if(x==0)
                return curr->val;
            x--;
            curr=curr->next;
        }
        return myHead->val; // syntax correction
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */