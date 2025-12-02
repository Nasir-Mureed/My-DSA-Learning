class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshCount = 0;
        int minutes = 0;
        
        // Find all initially rotten oranges
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (grid[i][j] == 2) 
                {
                    q.push({i, j});  // Push all rotten oranges
                } 
                else if (grid[i][j] == 1) 
                {
                    freshCount++;
                }
            }
        }
        
        // If no fresh oranges initially
        if (freshCount == 0) return 0;
        
        // If no rotten oranges but fresh oranges exist
        if (q.empty()) return -1;
        
        // Directions: down, up, right, left
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // BFS
        while (!q.empty()) 
        {
            int size = q.size();
            bool rottedThisMinute = false;
            
            for (int i = 0; i < size; i++) 
            {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto [dr, dc] : directions) 
                {
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    // Check bounds and if it's a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) 
                    {
                        // Rot the fresh orange
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        freshCount--;
                        rottedThisMinute = true;
                    }
                }
            }
            
            // Increment time only if we rotted any oranges this minute
            if (rottedThisMinute) 
            {
                minutes++;
            }
        }
        
        // Check if any fresh oranges remain
        return (freshCount == 0) ? minutes : -1;
    }
};