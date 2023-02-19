// 整数二分(数的范围)
/*
    整数二分
      看当true的情况是l = mid还是r = mid, l = mid时要 + 1
        1. 二分左边边界时
          mid = (l + r + 1) / 2
          if(check(mid))
          (1) true: 边界在[mid, r]之间, l = mid
          (2) false: 边界在[l, mid - 1]之间, r = mid - 1
        2. 二分右边边界时
          mid = (l + r) / 2
          if(check(mid))
          (1) true: 边界在[l, mid]之间, r = mid
          (2) false: 边界在[mid + 1, r]之间, l = mid + 1
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int m, n;
int q[N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    while (m--)
    {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;

        // 找左边界, 因为>=时会一直将l赋值为mid, 所以l最终会是左边界
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }

        // 如果找不到左边界, 那么就是没有, 直接输出-1 -1
        if (q[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << " ";
            int l = 0, r = n - 1;

            // 找右边界, 因为<=时会一直将l赋值为mid, 所以l最终会是右边界
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
}