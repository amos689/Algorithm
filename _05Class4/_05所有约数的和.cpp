/*
    约数的个数
        把一个数N写成：N = (p1^x1)(p^x2)(p3^x3)…(pk^xk)，其中pi为质数
        则N的约数的和为：(p1^0 + p1^1 + ... + p1^x1) * ... * (pk^0 + pk^1 + ... + pk^xk)
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    
    unordered_map<int, int> primes;
    
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
    for(auto prime : primes)
    {
        int p = prime.first, a = prime.second;
        LL t = 1;
        while(a--) t = (t * p + 1) % mod;
        ans = ans * t % mod;
    }
    
    cout << ans << endl;
    
    return 0;
}