class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);
        
        // Build reverse graph and calculate indegree
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                indegree[i]++;
            }
        }
        
        // Queue for nodes with indegree 0 (terminal nodes in original graph)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<bool> safe(n, false);
        
        // Process nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            
            // Reduce indegree of nodes that point to this node
            for (int prev : reverseGraph[node]) {
                indegree[prev]--;
                if (indegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }
        
        // Collect safe nodes
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};




///.......................wrong understanding...............
// void DFS(int node , vector<vector<int>>& graph, vector<int>& safeNodes,vector<bool>& vis)
//     {
//         vis[node]=true;
//         //check if safe node
//         bool safe=true;
//         int len=graph[node].size();
//         for(int i=0;i<len;i++)
//         {
//             int neighbour=graph[node][i];
//             if( !graph[neighbour].empty()) // if not a termional node
//             {
//                 safe=false;
//                 break;
//             }
//         }
//         if(safe)
//         {
//             safeNodes.push_back(node);
//         }
//         else
//         {
//             for(int i=0;i<len;i++)
//             {
//                 int nbr=graph[node][i];
//                 if( !vis[nbr])
//                     DFS(nbr,graph,safeNodes,vis);
//             }
//         }

//         //vis[node]=false;
//     }
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
//     {
//         vector<int> safeNode;
//         int size=graph.size();
//         vector<bool> vis(size,false);
//         for(int i=0;i<size;i++)
//         {
//             if(!vis[i])
//                 DFS(i,graph,safeNode,vis);
//         }

//         // vector<int> ans;
//         // for(auto x:safeNode)
//         // {
//         //     ans.push_back(x);
//         // }
//         return safeNode;
//     }