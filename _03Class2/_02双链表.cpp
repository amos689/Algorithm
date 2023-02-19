#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx; //idx保存每个节点都是第几次插入的

void init()
{
    r[0] = 1; //初始化头结点
    l[1] = 0; //初始化尾节点
    idx = 2; //前两个都被占用了, idx从2开始
}

void add(int k, int x)
{
    // 如果是左插入, 那就相当于是那个节点的左边节点的右插入
    e[idx] = x; //保存x的值
    l[idx] = k; //新节点左边连插入节点
    r[idx] = r[k]; //新节点右边连插入节点指向的右节点
    l[r[k]] = idx; //插入节点的原右节点左边连新节点
    r[k] = idx++; //插入节点右边连接新节点, 同时idx进行自增到下一个可用节点处
    
}

void del(int k)
{
    // 相当于跳过了第k个节点, 让k节点前后彼此相连
    r[l[k]] = r[k]; //第k个数的左节点的右边连接第k个节点本来指向的右边
    l[r[k]] = l[k]; //第k个数的右节点的左边连接第k个节点本来指向的左边
}

int main()
{
    cin >> m;
    init();
    while(m--)
    {
        string op;
        cin >> op;
        if(op == "L")
        {
            int x;
            cin >> x;
            // 因为传入的是第几个数, 所以0就是在左端点右边插入数
            add(0, x);
        }
        else if(op == "R")
        {
            int x;
            cin >> x;
            // 1是右端点, l[1]就是在l[1]右边插入
            add(l[1], x);
        }
        else if(op == "IL")
        {
            int k, x;
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if(op == "IR")
        {
            int k, x;
            cin >> k >> x;
            add(k + 1, x);
        }
        else if(op == "D")
        {
            int k;
            cin >> k;
            del(k + 1);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    return 0;
}