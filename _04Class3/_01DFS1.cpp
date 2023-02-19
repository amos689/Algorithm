/*
    DFS(重点是顺序): 数据结构: stack, 空间: O(h)
    BFS: 数据结构: queue, 空间: O(2 ^ h)
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 10;

// 用 path 数组保存排列，当排列的长度为 n 时，是一种方案，输出
// 用 con 数组表示数字是否用过, true代表被标记, false代表没被标记
int n;
int path[N];
bool con[N];

void dfs(int x)
{
    // 递归出口, 输出并结束
    if(x == n)
    {
        for(int i = 0; i < n; i++) cout << path[i] << " ";
        cout << endl;
        return;
    }
    
    // 这个for循环保证了树枝的展开过程(画图)
    for(int i = 1; i <= n; i++)
    {
        if(!con[i])
        {
            path[x] = i;
            con[i] = true;
            dfs(x + 1);
            // 干完事情一定要恢复现场, 要不然就要寄咯
            con[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    
    dfs(0);
    
    return 0;
}