class Solution 
{
    void merge(vector<int>& nums, int start,int end)
    {
        if(start>=end) return ; // base
        int mid = start+(end-start)/2;
        merge(nums,start,mid); // sort left subarray
        merge(nums,mid+1,end); // sort right sunarr

        vector<int> temp1 (mid-start+1),temp2(end-mid);

        for(int i=0,j=start;i<mid-start+1;i++,j++) // copy left sorted arr
            temp1[i]=nums[j];
        for(int i=0,j=mid+1;i<end-mid ; i++,j++) //copy right subarr
            temp2[i]=nums[j];

        int i=0,j=0,k=start;
        while((i<mid-start+1) && (j<end-mid))
        {
            if(temp1[i]<temp2[j])
            {
                nums[k]=temp1[i];
                i++;
            }
            else
            {
                nums[k]=temp2[j];
                j++;
            }
            k++;
        }

        while(i<mid-start+1)
        {
            nums[k]=temp1[i];
            i++;
            k++;
        }

        while(j<end-mid)
        {
            nums[k]=temp2[j];
            j++;
            k++;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        merge(nums,0,nums.size()-1);
        return nums;        
    }
};