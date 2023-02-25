/*
最短路问题
    单源最短路
        所有边权都是正数: 朴素dijkstra算法(稠密图)(邻接矩阵) / 堆优化版dijkstra(稀疏图)(邻接表)
        存在负权边: Bellman-Ford / SPFA
    多源汇最短路
        Floyd算法
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; //为稠密阵所以用邻接矩阵存储(g[a][b]表示ab间的距离)
int dist[N]; //用于记录每一个点距离第一个点的距离(dist[x]表示1号点到x号点的距离)
bool st[N]; //用于记录该点的最短距离是否已经确定

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for(int i = 1; i <= n; i++)
    {
        int t = -1;
        
        // 找出没有确定最短路径的节点中距离源点最近的点
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        st[t] = true;
        
        for(int j = 0; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    if(dist[n] == 0x3f3f3f3f) cout << -1 << endl;
    else cout << dist[n] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    
    dijkstra();
    
    return 0;
}