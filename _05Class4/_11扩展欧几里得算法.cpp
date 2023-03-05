/*
    裴蜀定理: 对于任意正整数a, b, 一定存在整数x, y, 使得ax + by = gcd(a, b)
    
    扩展欧几里得算法
        当b = 0时, ax + by = a因此x = 1, y = 0是解
        当b != 0时
            因为
                gcd(a, b)=gcd(b, a % b)
            而
                bx′ + (a % b)y′ = gcd(b, a % b)
                bx′ + (a ? ?a / b? ? b)y′ = gcd(b, a % b)
                ay′ + b(x′ ? ?a / b? ? y′) = gcd(b, a % b) = gcd(a, b)
            所以
                x = y′,y = x′ ? ?a / b? ? y′
*/
#include<bits/stdc++.h>

using namespace std;

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
        int a, b;
        cin >> a >> b;
        
        int x, y;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
    
    return 0;
}