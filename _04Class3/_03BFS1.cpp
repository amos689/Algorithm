// 想要搜到最短, 就不能用深度优先, 因为只能保证能搜到, 不能保证是最短
/*
    初始化状态 -> while循环queue不空 -> 取出队头 -> 扩展队头
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
// g数组用于记录迷宫, d数组用来看路径状态
int g[N][N], d[N][N];
queue<pair<int, int>> q;

int bfs()
{
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    q.push({0, 0});
    
    // dx和dy用来合成向量(只有上下左右各1)
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            // 创造向量
            int x = t.first + dx[i], y = t.second + dy[i];
            
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                // 在这里完成答案的累加
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    
    cout << bfs() << endl;
    
    return 0;
}