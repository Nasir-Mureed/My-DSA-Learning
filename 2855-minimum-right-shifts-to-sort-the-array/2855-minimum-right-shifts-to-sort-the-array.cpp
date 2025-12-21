class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int dipIndex = -1;
        
        // Find the dip (point where array breaks increasing order)
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                if (dipIndex != -1) return -1;  // Multiple dips
                dipIndex = i;
            }
        }
        
        // If no dip, array is already sorted
        if (dipIndex == -1) return 0;
        
        // Check if array after dip is sorted and last element ≤ first element
        for (int i = dipIndex + 1; i < n; i++) {
            if (nums[i] < nums[i-1]) return -1;
        }
        
        // Check if we can rotate to get sorted array
        if (nums[n-1] > nums[0]) return -1;
        
        // Minimum shifts = n - dipIndex
        return n - dipIndex;
    }
};