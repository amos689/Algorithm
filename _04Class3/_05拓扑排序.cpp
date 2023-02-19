/*
有向图才有拓扑序列, 有向无环图一定存在拓扑序列
无环图一定至少存在一个入度为0的点

解题方法:
    一个有向图，如果图中有入度为 0 的点，就把这个点删掉，同时也删掉这个点所连的边
    一直进行上面出处理，如果所有点都能被删掉，则这个图可以进行拓扑排序
    
    首先记录各个点的入度
    然后将入度为 0 的点放入队列
    将队列里的点依次出队列，然后找出所有出队列这个点发出的边，删除边，同时边的另一侧的点的入度 -1
    如果所有点都进过队列，则可以拓扑排序，输出所有顶点。否则输出-1，代表不可以进行拓扑排序
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
// 模拟邻接表
int h[N], e[N], ne[N], idx;
// q用来模拟队列, d用来存放每个节点的入度
int q[N], d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    
    for(int i = 1; i <= n; i++)
        if(d[i] == 0)
            q[++tt] = i;
    
    while(hh <= tt)
    {
        int a = q[hh++];
        for(int i = h[a]; i != -1; i = ne[i])
        {
            int b = e[i];
            d[b]--;
            if(d[b] == 0) q[++tt] = b;
        }
    }
    
    return tt == n - 1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    
    if(topsort())
    {
        for(int i = 0; i < n; i++) cout << q[i] << ' ';
        cout << endl;
    }
    else cout << -1 << endl;
    
    return 0;
}