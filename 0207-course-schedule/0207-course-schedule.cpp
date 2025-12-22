class Solution 
{
    bool DFS(int node , vector<vector<int>>& grp, vector<bool>& mark,vector<bool>& vis)
    {
        mark[node]=true;
        vis[node]=true;
        int size=grp[node].size();
        for(int i=0;i<size;i++)
        {
            if(mark[ grp[node][i] ]) return false;
            if(!vis[ grp[node][i] ])
                if( !DFS(grp[node][i],grp,mark,vis)) return false;
        }
        mark[node]=false;

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {

        //adjancency list.......
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites)
        {
            adj[ edge[1] ].push_back(edge[0]);
        }
        vector<bool> mark(numCourses,false);
        vector<bool> vis(numCourses,false);

        for(int i=0;i<numCourses;i++)
        {
            if( !vis[i])
            {
                if( !DFS(i,adj,mark,vis)) return false;
            }
        }
        return true;
        //

    }
};