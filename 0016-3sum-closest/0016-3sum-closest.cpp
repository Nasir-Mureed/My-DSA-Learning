class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort first
        
        int closestSum = nums[0] + nums[1] + nums[2];  // Initialize with first triplet
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum if current is closer to target
                if (abs(target - currentSum) < abs(target - closestSum)) 
                {
                    closestSum = currentSum;
                }
                
                // Move pointers based on comparison with target
                if (currentSum < target) 
                {
                    left++;  // Need larger sum
                } 
                else if (currentSum > target) 
                {
                    right--; // Need smaller sum
                } 
                else 
                {
                    return currentSum;  // Exact match found
                }
            }
        }
        
        return closestSum;
    }
};