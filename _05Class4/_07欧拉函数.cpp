/*
    公因数只有1的两个非零自然数叫做互质数
    对于正整数n, 欧拉函数是小于等于n的所有整数里面所有与n互质数的数目, 记作φ(n)
    
    如果把一个数N分解质因数写成：N = (p1^x1)(p2^x2)(p3^x3)…(pk^xk)，其中pi为质数
    φ(n) = N(1 - 1 / p1)(1 - 1 / p2)...(1 - 1 / pk)
    
    基本方法: 
        1. 从1 ~ n中去掉p1, p2, ... , pk的所有倍数
        2. 加上所有从pi * pj的倍数
        3. 减去所有pi * pj * pk的倍数
        4. 加上...
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int x;
        cin >> x;
        int ans = x;
        
        for(int i = 2; i <= x / i; i++)
        {
            if(x % i == 0)
            {
                // 等价于ans = ans * (1 - 1 / i);
                ans = ans / i * (i - 1);
                while(x % i == 0) x /= i;
            }
        }
        
        if(x > 1) ans = ans / x * (x - 1);
        
        cout << ans << endl;
    }
    
    return 0;
}