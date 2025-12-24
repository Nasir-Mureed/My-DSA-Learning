class Solution {
public:
    int findChampion(vector<vector<int>>& grid) 
    {
        int size=grid.size();
        vector<int> stronger(size,0);
        int mostStg=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(grid[i][j]==1)
                {
                    stronger[i]++;
                    if(stronger[mostStg]<stronger[i])
                        mostStg=i;
                }
            }
        }
        return mostStg;
    }
};