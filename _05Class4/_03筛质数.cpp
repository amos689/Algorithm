// 线性筛法(速度最快)
#include<bits/stdc++.h>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) primes[cnt++] = i;
        // n只会被最小的质因子筛掉
        for(int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if(!(i % primes[j])) break; // 这句话发生时, primes[j]一定是i的最小质因子
            /*
                对这句话的理解
                    当发现primes[j]是i最小质因子的时候, 如果再继续进行的话
                    我们就把 prime[j+1]*i 这个数筛掉了, 虽然这个数也是合数
                    但是我们筛掉它的时候并不是用它的最小质因数筛掉的, 而是利用 prime[j+1] 和 i 把它删掉的
                    其实这个数的最小质因数是prime[j],
                    如果不在这里退出, 那就会发现有些数是被重复删除的
            */
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    get_primes(n);
    
    cout << cnt << endl;
    
    return 0;
}