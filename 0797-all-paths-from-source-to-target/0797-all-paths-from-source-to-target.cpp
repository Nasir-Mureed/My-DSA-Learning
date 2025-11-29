class Solution 
{
    vector<vector<int>> res;
    void DFS(vector<vector<int>>& graph,int lvl,vector<int>& path,int target)
    {
            if(lvl==target)
            {
                res.push_back(path);
                return;
            }
        for(auto i:graph[lvl])
        {
            path.push_back(i);
            DFS(graph,i,path,target);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> path;
        path.push_back(0);
        DFS(graph,0,path,n-1);
        return res;        
    }
};