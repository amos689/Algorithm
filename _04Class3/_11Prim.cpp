/*
    最小生成树
        Prim算法: 朴素版Prim(稠密图)(O(n^2)) / (不常用)堆优化版Prim(稀疏图)(O(mlogn))
        Kruskal算法(稀疏图)(O(mlogm))
    
    二分图
        染色法(O(n + m))
        匈牙利算法(最坏O(mn))
*/
/*
    朴素版Prim
        dist[i] <- 正无穷
        for(int i = 0; i < n; i++)
            t <- 找到集合(在连通块中的点)外距离最近的点
            用t更新其他点到集合的距离
            把t加到集合中: st[t] = ture
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], dist[N];
bool st[N];

void prim()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
            // 将t更新为不在树中且到树的距离最短的点
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        // 判断是否为孤立的点, 必须在第一次循环之后
        if(i && dist[t] == INF)
        {
            cout << "impossible" << endl;
            return;
        }
        // res应该在这里加上, 防止负权自环产生的影响
        res += dist[t];
        st[t] = true;
        
        // 更新生成树外的点到生成树集合的距离
        // 这里的for和dijkstra的区别就是g不需要再加上distance, 因为是到集合的距离
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[j][t]);
    }
    
    cout << res << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    memset(g, 0x3f, sizeof g);
    
    cin >> n >> m;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    prim();
    
    return 0;
}