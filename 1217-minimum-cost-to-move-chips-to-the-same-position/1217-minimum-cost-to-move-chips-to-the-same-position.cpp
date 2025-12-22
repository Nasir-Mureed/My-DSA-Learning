class Solution {
public:
    int minCostToMoveChips(vector<int>& position) 
    {
      int size=position.size(),even=0,odd=0;
      for(int i=0;i<size;i++)
      {
        if(position[i]%2==0) even++;
        else odd++;
      }
      return min(even,odd);
    }
};