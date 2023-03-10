/*
    约数的个数
        把一个数N写成：N = (p1^x1)(p^x2)(p3^x3)…(pk^xk)，其中pi为质数
        则N的约数个数为：(x1+1)(x2+1)(x3+1)…(xk+1)
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    unordered_map<int, int> primes;
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int x;
        cin >> x;
        
        for(int i = 2; i <= x / i; i++)
        {
            while(x % i == 0)
            {
                x /= i;
                primes[i]++;
            }
        }
        if(x > 1) primes[x]++;
    }
    
    LL ans = 1;
    
    for(auto p : primes) ans = ans * (p.second + 1) % mod;
    
    cout << ans << endl;
    
    return 0;
}