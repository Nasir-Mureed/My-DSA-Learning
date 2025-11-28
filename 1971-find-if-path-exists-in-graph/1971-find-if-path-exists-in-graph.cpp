class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if(source==destination) return true;
       vector<vector<int>> adj(n);
        for(auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int size=n;
        bool* visited=new bool[size];
        for(int i=0;i<size;i++)
            visited[i]=false;
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int curr= q.front();
            q.pop();
            for(int i=0;i< adj[curr].size();i++)
            {
                int x=adj[curr][i];
                if(x==destination)
                    return true;
                if( !visited[x])
                {
                    visited[x]=true;
                    q.push(x);                       
                }
            }
        }
        return false;
    }
};