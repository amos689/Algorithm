#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main()
{
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    
    for(int i = n - 1, j = 0; i >= 0; i--)
    {
        // 这里a[i] + b[j]不能是小于等于x, 因为如果条件符合j会自增1, 导致无法取到正确的数
        while(a[i] + b[j] < x && j < m) j++;
        if(a[i] + b[j] == x)
        {
            cout << i << ' ' << j << endl;
            break;
        }
    }
    return 0;
}