/*
    数组: a1, a2, a3 ... an
    前缀和: Si = a1 + a2 + a3 + ... + ai
    1. 如何求Si: 
        S[0] = 0
        for(i = 1; i <= n; i++) S[i] = S[i - 1] + a[i];
    2. Si的作用
        求a[l, r]的和: Sr - S(l - 1)
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N], S[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i++) S[i] = a[i] + S[i - 1]; //初始化前缀和
    
    while(m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", S[r] - S[l - 1]); //输出前缀和
    }
    return 0;
}