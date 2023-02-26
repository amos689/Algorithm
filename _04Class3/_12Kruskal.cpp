/*
    Kruskal算法
        将所有边按权重从小到大排序
        枚举每一条边a, b和权重c
            如果a, b目前不连通, 那将这条边加入集合中(类似并查集)
        直到具有n个顶点的连通网筛选出n - 1条边为止
        
    使用并查集来避免产生回路
*/
#include<bits/stdc++.h>

using namespace std;

// 这里N是边数相关
const int N = 200010;

int n, m;
int p[N]; // 保存并查集

struct Edge
{ 
    int a, b, w;
    
    /*
        结构体运算符的重载
            bool operator 运算符 (const 结构体名称 b) const
            {
                return(什么时候这个运算符对结构体成立);
            }
    */
    // 按照变长进行排序
    bool operator < (const Edge &W) const
    {
        return this->w < W.w;
    }
}edges[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);
    
    // 初始化并查集
    for(int i = 1; i <= n; i++) p[i] = i;
    
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        
        // 并查集中两个集合的连接
        a = find(a), b = find(b);
        if(a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    
    if(cnt < n - 1) return 0x3f3f3f3f;
    else return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    
    int t = kruskal();
    
    if(t == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << t << endl;
    
    return 0;
}