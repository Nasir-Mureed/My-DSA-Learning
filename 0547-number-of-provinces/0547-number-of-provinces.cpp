class Solution 
{
    void DFS(int node,vector<vector<int>>& mat,int size,bool* vst)
    {
        vst[node]=true; // marked visited;
        for(int i=0;i<size;i++)
        {
            if(mat[node][i]==1)
            {
                if( !vst[i])
                    DFS(i,mat,size,vst);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n= isConnected.size(); // number of vertices
        bool* vst= new bool[n+1];
        for(int i=0;i<=n;i++)
        {
            vst[i]=false;
        }
        int provinces=0; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 )
                {
                    if(!vst[i]) // if not visited
                    {
                        provinces++; // new provinces
                        DFS(i,isConnected,n,vst);
                    }
                    if(!vst[j]) // if not visited
                    {
                        provinces++;
                        DFS(j,isConnected,n,vst);
                    }
                }
            }
        }

        return provinces;      
    }
};