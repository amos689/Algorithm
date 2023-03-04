/*
    线性筛法求: 1 ~ n中每一个数的欧拉函数
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000010;

int primes[N], cnt;
bool st[N];
int phi[N]; // 每个数的φ值

LL get_eulers(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            // 质数i的欧拉函数值是前i - 1个数的个数
            phi[i] = i - 1; 
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                // primes[j]是i的最小值因子, 也是primes[j] * i的最小质因子
                // 因此, 在计算phi[i]时, (1 - 1 / primes[j])这一项是被计算过的
                // 所以求primes[j] * i的欧拉函数只需要phi[i]乘primes[j]
                phi[primes[j] * i] = phi[i] * primes[j]; 
                break;
            }
            // 这里primes[j]不是i的质因子, 只是primes[j] * i的最小质因子
            // 因此除了要将phi[i]乘primes[j], 还要再除上(1 - 1 / primes[j])
            // 即让phi[i]乘上(primes[j] - 1)
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    
    LL ans = 0;
    for (int i = 1; i <= n; i++) ans += phi[i];
    
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << get_eulers(n) << endl;

    return 0;
}