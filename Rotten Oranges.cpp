class Solution 
{
public:
    // Function to find the minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;  
        int seconds = 0;  
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;  
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); 
                } else if (grid[i][j] == 1) {
                    fresh++;  
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int size = q.size(); // Number of rotten oranges in the current round.
            for (int i = 0; i < size; i++) {
                pair<int, int> current = q.front();
                q.pop();
                
                int x = current.first;
                int y = current.second;
                
                // Spread the rot to adjacent cells.
                for (const auto& direction : directions) {
                    int newX = x + direction.first;
                    int newY = y + direction.second;
                    
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; // Rot the fresh orange.
                        fresh--;  // Decrease the count of fresh oranges.
                        q.push({newX, newY}); // Add the newly rotten orange to the queue.
                    }
                }
            }
            seconds++; 
        }
        
        return fresh > 0 ? -1 : seconds;
    }
};
