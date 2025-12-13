class Solution {
public:
    bool isBipartite(vector<vector<int>>& grf) 
    {
        int V=grf.size(); 
        vector<int> color(V, 0);  // 0: uncolored, 1: color1, 2: color2
        // Check each component (graph might be disconnected)
        for(int i = 0; i < V; i++) 
        {
            if(color[i] == 0) // Not colored yet
            {  
                queue<int> q;
                q.push(i);
                color[i] = 1;  // Start with color 1
                
                while(!q.empty()) 
                {
                    int vertex = q.front();
                    q.pop();
                    
                    // Color all neighbors with opposite color
                    for(int neighbor : grf[vertex]) 
                    {
                        if(color[neighbor] == 0) 
                        {  // Not colored
                            color[neighbor] = (color[vertex] == 1) ? 2 : 1;
                            q.push(neighbor);
                        } 
                        else if(color[neighbor] == color[vertex]) 
                        {
                            // If neighbor has same color as current vertex
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
        
    }
};