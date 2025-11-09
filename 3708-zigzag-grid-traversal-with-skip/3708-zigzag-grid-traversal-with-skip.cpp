class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) 
    {
        vector<int> res;
        if(grid.empty())
            return res;
        int rows,cols;
        rows=grid.size();
        cols=grid[0].size();
        bool skip=false,LtoR=true;
        for(int i=0;i<rows;i++)
        {
            if(LtoR)
            {
                for(int j=0;j<cols;j++)
                {
                    if(!skip)
                        res.push_back(grid[i][j]);
                    skip=!skip;
                }
            }
            else
            {
                for(int j=cols-1;j>=0;j--)
                {
                    if(!skip)
                        res.push_back(grid[i][j]);
                    skip=!skip;
                }
            }
            LtoR=!LtoR;
        }
        return res;
    }
};