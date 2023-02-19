// 单调队列
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N], q[N]; // 队列q不是滑动窗口！只是在实际窗口向右滑动时维护的一个单调队列。队列q的放置方式：hh队头在左端，tt队尾在右端

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // 找窗口中的最小值
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        // 其中i表示滑动窗口的右端点位置，所以当前实际窗口的左端点位置应为i-k+1
        // 而队列q[hh]存的则为窗口中数值最小的元素的位置，姑且记为pos，
        // 则必有pos>=i-k+1，反之(即i-k+1>pos)，则pos位置已经从左边移出窗口，
        // 而位置pos即为q[hh]，故若i-k+1>pos,则hh++；
        // 如果窗口末尾的下标比q[hh]指向的下标大, 说明要出队
        if (i - k + 1 > q[hh])
            hh++;

        // 若队尾元素的值a[q[tt]]>=滑动窗口的右端点a[i]，则为了维护队列q单调，需要删除队尾
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        // 直到队尾元素比窗口右端点的值小a[q[tt]]<a[i]，将位置i入队
        q[++tt] = i;

        // 窗口是从数组a中第一个元素a[0]开始吞入，故要等到窗口中的元素满了才可以输出。
        // i + 1是窗口长度, k是窗口大小
        if (i + 1 >= k)
            printf("%d ", a[q[hh]]);
    }
    printf("\n");

    // 找窗口中的最大值
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--; // 只需要修改这里的, 将单增队列改成单减队列
        q[++tt] = i;
        if (i + 1 >= k)
            printf("%d ", a[q[hh]]);
    }

    return 0;
}