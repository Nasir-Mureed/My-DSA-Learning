class Solution 
{
    bool DFS(int node , vector<vector<int>>& grp, vector<bool>& mark,vector<bool>& vis,stack<int>& st)
    {
        mark[node]=true;
        vis[node]=true;
        int size=grp[node].size();
        for(int i=0;i<size;i++)
        {
            if(mark[ grp[node][i] ]) return false;
            if(!vis[ grp[node][i] ])
                if( !DFS(grp[node][i],grp,mark,vis,st)) return false;
        }
        mark[node]=false;
        st.push(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //adjancency list.......
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites)
        {
            adj[ edge[1] ].push_back(edge[0]);
        }
        vector<bool> mark(numCourses,false);
        vector<bool> vis(numCourses,false);
        stack<int> st;
        vector<int> res;
        for(int i=0;i<numCourses;i++)
        {
            if( !vis[i])
            {
                if( !DFS(i,adj,mark,vis,st)) 
                    return res; // return empty
            }
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
        
    }
};