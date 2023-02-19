/*
    字符串哈希方式: 字符串前缀哈希法
    把字符串变成一个p进制数字(哈希值), 实现不同的字符串映射到不同的数字
    P取131或者13331, Q取1e64
    从L到R的哈希值公式: h[R] - h[L - 1] * P^(R - L + 1);
    预处理时: h[i] = h[i - 1] * P + str[i];
    
    区间和公式的理解: ABCDE 与 ABC 的前三个字符值是一样，只差两位，
    乘上 P2^2把 ABC 变为 ABC00，再用 ABCDE - ABC00 得到 DE 的哈希值
*/

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

int n, m;
char str[N + 10];
// h[i] 存的是长度为 i 的前缀子字符串 的哈希值, p[i]存的是 P^i
ULL h[N], p[N];

ULL find(int l, int r)
{
    // 在后面补0
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m >> str + 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    
    while(m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        if(find(l1, r1) == find(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}