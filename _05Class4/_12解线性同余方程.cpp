/*
    1. 因为a * x ≡ b(mod m)等价于a * x - b是m的倍数, 因此线性同余方程组等价为
       a * x + m * y = b
    2. 根据裴蜀定理, 上述等式有解当且仅当gcd(a, m) | b
    3. 先用扩展欧几里得算法求出一组整数x0, y0, 使得a * x0 + m * y0 = gcd(a, m)
       左右同乘b / gcd(a, m), 使得等式右边变成1.中的b
       然后左边x = x0 * b / gcd(a, m) % m即是所求
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int a, b, m;
        cin >> a >> b >> m;
        
        int x, y;
        int d = exgcd(a, m, x, y);
        
        if(b % d) cout << "impossible" << endl;
        else cout << (LL)x * b / d % m << endl;
    }
    
    return 0;
}