/*
    有边数限制的最短路算法使用Bellman-Ford算法, 其他使用SPFA
    如果一个图中存在负权回路的话, 那么这个图的最短路不一定存在
    当第n次循环过之后如果再次循环还会被更新, 则存在负权回路
    Bellman-Ford算法(处理有负权边的图)
        for循环n次, 每次for循环所有边a, b, w(从a到b的边, 权重是w)
        防止串联: 由于是每个点同时向外出发, 因此需要对 dist[] 数组进行备份, 防止串联现象
        更新: dist[b] = min(dist[b], dist[a] + w)
              看看从1走到a再走到b是不是比原来到b的距离短
        循环完n次之后一定满足三角不等式: dist[b] <= dist[a] + w
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N]; // 备份防止串联

struct Edge
{
    int a, b, w;
}edges[M]; // 保存每一条边

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for(int i = 0; i < k; i++) // 因为有边数限制, 相当于限制了经过的点数, 所以第一层循环k
    {
        memcpy(backup, dist, sizeof dist);
        
        for(int j = 0; j < m; j++) // 每次遍历所有边进行向下延伸1个
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            // 使用backup数组避免a更新后立马更新给b, 导致串联
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    
    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else cout << dist[n] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    
    bellman_ford();
    
    return 0;
}