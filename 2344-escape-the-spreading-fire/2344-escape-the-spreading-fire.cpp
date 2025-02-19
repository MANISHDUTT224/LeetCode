class Solution {
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    int manWalk(vector<vector<int>>& grid, int m, int n) {
        // also start time at 3
        int time_man = 3;
        vector<vector<int>> visited(m, vector<int>(n, 6000));
        queue<pair<int, int>> man;
        man.push({0, 0});
        visited[0][0] = time_man;
        while(!man.empty()) {
            int q_size = man.size();
            time_man++;
            for (int i = 0; i < q_size; i++) {
                auto [x, y] = man.front();
                man.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < m && ny >=0 && ny < n && grid[nx][ny] != 2 && visited[nx][ny] == 6000) {
                        man.push({nx, ny});
                        visited[nx][ny] = time_man;
                    }
                }
            }
        }
    // man can never reach safehouse 
    if (visited[m-1][n-1] == 6000) return -1;
    // fire can never reach safehouse
    if (grid[m-1][n-1] == 0) return 1e9;
    // man reach safehouse latter than fire
    if (grid[m-1][n-1] - visited[m-1][n-1] < 0) return -1;
    int diff = grid[m - 1][n - 1] - visited[m - 1][n - 1];
    bool fire_from_top = (grid[m - 1][n - 1] - grid[m - 2][n - 1] == 1);
    bool fire_from_left = (grid[m - 1][n - 1] - grid[m - 1][n - 2] == 1);
    bool man_from_top = (visited[m - 1][n - 1] - visited[m - 2][n - 1] == 1);
    bool man_from_left = (visited[m - 1][n - 1] - visited[m - 1][n - 2] == 1);
    // fire can reach safehouse from upper and left
    if(fire_from_top && fire_from_left) return diff - 1;
    // fire can'n reach safehouse from upper and left, but man can
    else if(man_from_top && man_from_left) return diff;
    // fire and man reach safehouse same from upper or left
    else if(fire_from_top && man_from_top || fire_from_left && man_from_left) return diff - 1;
    // not same
    else return diff;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        // put fire into queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }
        // BFS where fire can reach, start time at 3
        int time = 3;
        while(!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                auto [x, y] = q.front();
                grid[x][y] = time;
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < m && ny >=0 && ny < n && grid[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }
        return manWalk(grid, m, n);
    }
};