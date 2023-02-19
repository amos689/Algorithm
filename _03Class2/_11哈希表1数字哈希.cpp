// 拉链法: 链表和数组的结合
#include<bits/stdc++.h>

using namespace std;

// N开到大于要求的第一个质数
const int N = 100003;

int n;
// h是每个链的头, 指向第一个元素, e来存放元素, ne表示下一个地址
int h[N], e[N], ne[N], idx;

void ins(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i])
    {
        if(e[i] == x) return true;
    }
    return false;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof(h));
    
    while(n--)
    {
        char op[2];
        int x;
        cin >> op >> x;
        if(*op == 'I') ins(x);
        else
        {
            if(find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}

/*
开放寻址法
#include<bits/stdc++.h>

using namespace std;

// N开到第一个大于两倍大小的质数
const int N = 200003, null = 0x3f3f3f3f;

int n;
int h[N];

int find(int x)
{
    int t = (x % N + N) % N;
    while(h[t] != null && h[t] != x)
    {
        t++;
        if(t == N) t = 0;
    }
    return t;
}

int main()
{
    cin >> n;
    memset(h, 0x3f, sizeof(h));
    
    while(n--)
    {
        char op[2];
        int x;
        cin >> op >> x;
        if(*op == 'I') h[find(x)] = x;
        else
        {
            if(h[find(x)] != null) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}
*/