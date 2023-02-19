/*
    差分是前缀和的逆运算
    给定a1, a2, a3 ... an
    构造b1, b2, b3 ... bn
    使得ai = b1 + b2 + b3 + ... + bi
    
    若要使a[l, r]全部在原有基础上+c
    只需要让bl + c, 让b(r + 1) - c即可
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

// 模拟+c
void insert(int l, int r, int c)
{
    // 保证差分数组b[]在操作后的前n位的和是a[i]
    b[l] += c;
    b[r + 1] -= c;
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    // a[i]相当于在[i, i]区间上进行差分插入
    for(int i = 1; i <= n; i++) insert(i, i, a[i]);
    while(m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    
    // 求前缀和并输出, 这里的b[i]就相当于更新后的a[i]
    for(int i = 1; i <= n; i++) b[i] += b[i - 1];
    for(int i = 1; i <= n; i++) printf("%d ", b[i]);
    return 0;
}