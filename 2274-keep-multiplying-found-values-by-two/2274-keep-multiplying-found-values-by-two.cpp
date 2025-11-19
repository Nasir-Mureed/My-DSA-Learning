class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        sort(nums.begin(),nums.end());
        while(true)
        {
            if(std::binary_search(nums.begin(),nums.end(),original))
                original*=2;
            else
                return original;
        }
        return original;
    }
};