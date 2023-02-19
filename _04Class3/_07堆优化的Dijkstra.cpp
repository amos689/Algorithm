#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 1000010;

int n, m;
// 稀疏图使用邻接表存储
int h[N], w[N], e[N], ne[N], idx; // w来存储权重
int dist[N]; // 存1到x的距离
bool st[N];

void add(int a, int b, int c)
{
    // 有重边也不要紧，假设1->2有权重为2和3的边，再遍历到点1的时候2号点的距离会更新两次放入堆中
    // 这样堆中会有很多冗余的点，但是在弹出的时候还是会弹出最小值2+x（x为之前确定的最短路径），
    // 并标记st为true，所以下一次弹出3+x会continue不会向下执行。
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // 这里要根据距离进行排序, 因此顺序不能颠倒成{1, 0}
    heap.push({0, 1});
    
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > w[i] + distance)
            {
                dist[j] = w[i] + distance;
                heap.push({dist[j], j});
            }
        }
    }
    
    if(dist[n] == 0x3f3f3f3f) cout << -1 << endl;
    else cout << dist[n] << endl;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    dijkstra();
    
    return 0;
}