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
    int pairSum(ListNode* head) 
    {
        int maxSum=0,sum=0,size=0;
        vector<int> arr;   // access in constant time;
        while(head)
        {
            arr.push_back(head->val);
            size++;
            head=head->next;
        }

        for(int i=0;i<=(size/2)-1;i++)
        {
            int twin=size-1-i;
            sum=arr[i]+arr[twin];
            maxSum=maxSum>sum?maxSum:sum;
        }
        return maxSum;
    }
};