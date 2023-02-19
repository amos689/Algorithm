/*
    并查集(能并能查的集合叫并查集)
        1. 将两个集合合并
        2. 询问两个元素是否在一个集合中
        
    基本原理: 每个集合用一棵树来表示. 树根的编号就是整个集合的编号. 
              每个节点存储它的父节点, p[x]表示x的父节点
    
    q1: 判断树根: if(p[x] == x)
    q2: 如何求x的集合编号while(p[x] != x) x = p[x]
    q3: 如何合并两个集合: 假设px是x的编号, py是y的编号, 合并: p[x] = y
    
    对于q2的优化(路径压缩): 将向上找的过程遇到的所有节点全部指向根节点
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]); // 递归, 并完成了路径压缩, 将每一个节点都指向了树根, 一次之后, 第二次速度非常快
    return p[x];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    
    while(m--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        if(*op == 'M') p[find(a)] = find(b); // 将a的头连接到b的头上
        else
        {
            if(find(a) == find(b)) cout << "Yes" << endl; // 如果头一样, 那么就是在一个集合里
            else cout << "No" << endl;
        }
    }
    
    return 0;
}