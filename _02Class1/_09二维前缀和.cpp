/*
    子矩阵S[x1, y1, x2, y2] = S[x2, y2] - S[x2, y1 - 1] - S[x1 - 1, y2] + S[x1 - 1, y1 - 1]
    原矩阵S[i, j]的求法: for(i = 1; i <= n; i++) for(j = 1; j <= n; j++)
        S[i, j] = S[i - 1, j] + S[i, j - 1] - S[i - 1, j - 1] + a[i, j];
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            // 求前缀和
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    
    while(q--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        // 算部分和
        printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    }
    return 0;
}