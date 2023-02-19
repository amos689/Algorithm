#include<bits/stdc++.h>

using namespace std;

// 因为是无向图, 所以有N * 2个边的信息
const int N = 100010, M = N * 2;

int n;
// 模拟邻接表, h存储每个链表头的信息, e存放每个节点的值, ne存放下一个节点
int h[N], e[M], ne[M], idx, ans = N;
// st判断每个节点是否已经被遍历到了
bool st[N];

void add(int a, int b)
{
    // 同链表的头插
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int mdfs(int u)
{
    st[u] = true;
    
    // size是删掉某个节点u后, 最大的连通图节点数
    // sum是存储包括u的以u为根节点的节点数
    int size = 0, sum = 1;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = mdfs(j);
            size = max(s, size);
            sum += s;
        }
    }
    
    // 这里n - sum的意思是size只是u下方的最大树的大小, 它的上面还是一个连通图, 也要进行比较
    size = max(size, n - sum);
    ans = min(size, ans);
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    // 其实从哪个点开始搜索都一样, 因为是无向图两边都一样, 并不存在孤立的点
    mdfs(1);
    
    cout << ans << endl;
    
    return 0;
}