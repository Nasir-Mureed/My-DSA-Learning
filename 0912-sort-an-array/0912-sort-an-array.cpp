class Solution 
{

    void merge(vector<int> &nums,int st,int mid,int end)
    {
        int l = st;
        int r = mid+1;
        vector<int> list;
        while(l <= mid && r <= end)
        {
            if(nums[l] <= nums[r]) 
            {
                list.push_back(nums[l++]);
            }
            else
            {
                list.push_back(nums[r++]);
            }
        }
        while(l <= mid) 
        {
            list.push_back(nums[l++]);
        }
        while(r <= end) list.push_back(nums[r++]);

        for(int i = st;i<=end;i++)
        {
            nums[i] = list[i-st];
        }
    }
    void divide(vector<int> &nums,int st,int end)
    {
        if(st >= end) return;
        int mid = (st + end) / 2;
        divide(nums,st,mid);
        divide(nums,mid+1,end);
        merge(nums,st,mid,end);
    }
    public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // atexit([](){ std::ofstream("display_runtime.txt") << "0"; });
        divide(nums,0,n-1);
        return nums;
    }



//     void merge(vector<int>& nums, int start,int end)
//     {
//         if(start>=end) return ; // base
//         int mid = start+(end-start)/2;
//         merge(nums,start,mid); // sort left subarray
//         merge(nums,mid+1,end); // sort right sunarr

//         vector<int> temp1 (mid-start+1),temp2(end-mid);

//         for(int i=0,j=start;i<mid-start+1;i++,j++) // copy left sorted arr
//             temp1[i]=nums[j];
//         for(int i=0,j=mid+1;i<end-mid ; i++,j++) //copy right subarr
//             temp2[i]=nums[j];

//         int i=0,j=0,k=start;
//         while((i<mid-start+1) && (j<end-mid))
//         {
//             if(temp1[i]<temp2[j])
//             {
//                 nums[k]=temp1[i];
//                 i++;
//             }
//             else
//             {
//                 nums[k]=temp2[j];
//                 j++;
//             }
//             k++;
//         }

//         while(i<mid-start+1)
//         {
//             nums[k]=temp1[i];
//             i++;
//             k++;
//         }

//         while(j<end-mid)
//         {
//             nums[k]=temp2[j];
//             j++;
//             k++;
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) 
//     {
//         merge(nums,0,nums.size()-1);
//         return nums;        
//     }
};