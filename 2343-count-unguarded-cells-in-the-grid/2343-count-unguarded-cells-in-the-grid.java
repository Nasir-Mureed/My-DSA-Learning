class Solution {
   public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
    int[][] grid = new int[m][n]; // 0: empty, 1: guard, 2: wall, 3: guarded
    
    // Mark guards and walls
    for (int[] guard : guards) {
        grid[guard[0]][guard[1]] = 1;
    }
    for (int[] wall : walls) {
        grid[wall[0]][wall[1]] = 2;
    }
    
    // Direction vectors: up, right, down, left
    int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    // Process each guard
    for (int[] guard : guards) {
        int r = guard[0], c = guard[1];
        
        // Explore all 4 directions
        for (int[] dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            // Keep moving in this direction until we hit boundary, wall, or guard
            while (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 2 && grid[nr][nc] != 1) {
                grid[nr][nc] = 3; // Mark as guarded
                nr += dir[0];
                nc += dir[1];
            }
        }
    }
    
    // Count unguarded cells (cells that are still 0)
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                count++;
            }
        }
    }
    
    return count;
}
}