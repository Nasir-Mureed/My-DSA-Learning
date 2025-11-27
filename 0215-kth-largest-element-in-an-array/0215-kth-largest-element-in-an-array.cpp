class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Build max-heap
        make_heap(nums.begin(), nums.end());
        
        // Extract k-1 largest elements
        for (int i = 0; i < k - 1; i++) {
            pop_heap(nums.begin(), nums.end() - i);
        }
        
        // The k-th largest is at the beginning
        return nums[0];
    }
};