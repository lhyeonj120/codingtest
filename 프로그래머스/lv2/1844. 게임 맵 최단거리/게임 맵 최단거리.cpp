#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int dist[101][101] = {0,};
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    queue<pair<int, int>> q;
    int n = maps.size(), m = maps[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] == 0)
                dist[i][j] = -1;
        }
    }
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(dist[nx][ny] != 0)
                continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    
    if(dist[n - 1][m - 1] == 0)
        return -1;
    
    return dist[n - 1][m - 1];
}