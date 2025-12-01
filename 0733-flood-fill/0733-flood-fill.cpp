class Solution 
{
    void DFS(vector<vector<int>>& image,const int& rows,const int& cols, int sr,int sc,const int& color,const int& original)
    {
        if(sr>=rows || sr<0 || sc>=cols || sc<0)
            return ;
        if(image[sr][sc]==original)
        {
            image[sr][sc]=color; // fill color
            DFS(image,rows,cols,sr+1,sc,color,original); // move to down
            DFS(image,rows,cols,sr-1,sc,color,original); // move to up
            DFS(image,rows,cols,sr,sc+1,color,original); // move to right
            DFS(image,rows,cols,sr,sc-1,color,original); // move to left      
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int original=image[sr][sc];
        if (original == color) 
        {
            return image; // No changes needed
        }
        
        int rows=image.size();
        int cols=image[0].size();

        DFS(image,rows,cols,sr,sc,color,original); // move to down
        return image;
    }
};