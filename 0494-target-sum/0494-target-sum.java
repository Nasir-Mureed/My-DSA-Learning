class Solution {

    static int countWays(int[] nums,int i,int target)
    {
        if(i==nums.length)
        {
            if(target==0)
                return 1;
            return 0;
        }
        int count=0;
        count+=countWays(nums,i+1,target+nums[i]);
        count+=countWays(nums,i+1,target-nums[i]);
        return count;
    }
    public int findTargetSumWays(int[] nums, int target) 
    {
        return countWays(nums,0,target);
        
    }
}