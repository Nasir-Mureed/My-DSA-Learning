class Solution {
    public int maximumCount(int[] nums) 
    {
        int n=0,p=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]<0) n++;
            if(nums[i]>0) p++;
        }
        return n>p?n:p;
        
    }
}


// if((nums[0]<0 && nums[nums.length-1]<0) || (nums[0]>0)) return nums.length;
//         if(nums[0]==0)
//         {
//             int i=0,cnt=0;
//             while(i<nums.length &&nums[i]==0)
//             {
//                 cnt++;
//                 i++;
//             }
//             return nums.length-cnt;
//         }
//         int start=0,end=nums.length-1,mid;
//         while(start<=end)
//         {
//             mid=start+(end-start)/2;
//             if(nums[mid]>=0 && nums[mid-1]<0)
//             {
//                 if(nums[mid]==0)
//                 {
//                     int i=mid,cnt=0;
//                      while(i<nums.length &&nums[i]==0)
//                     {
//                         cnt++;
//                         i++;
//                     }
//                      return nums.length-cnt-(mid);
//                 }
//                 return nums.length-(mid);
//             }
//             else if(nums[mid]<0)
//             {
//                 start=mid+1;
//             }
//             else
//             {
//                 int cnt=0,j=mid;
//                 while(nums[j]==0)
//                 {
//                     cnt++;
//                     j++;
//                 }
//                 int i=mid-1;
//                 while(nums[i]==0)
//                 {
//                     cnt++;
//                     i--;
//                 }
//                 return (nums.length-cnt)-(i+1)>i+1? nums.length-cnt-(i+1):i+1;
//             }
//         }
//         return 0;