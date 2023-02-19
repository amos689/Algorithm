/*
    双指针算法核心是能优化朴素算法降低复杂度
    for(int i = 0, j = k; i < n; i++)
    {
        while(i()j && check(i, j)) j++;
        
        // 加具体逻辑
    }
*/

/*
针对本题
    1. 遍历数组a中的每一个元素a[i], 
       对于每一个i，找到j使得双指针[j, i]维护的是以a[i]结尾的最长连续不重复子序列
       长度为i - j + 1, 将这一长度与r的较大者更新给r
    2. 对于每一个i，如何确定j的位置：由于[j, i - 1]是前一步得到的最长连续不重复子序列
       所以如果[j, i]中有重复元素，一定是a[i]，因此右移j直到a[i]不重复为止
       （由于[j, i - 1]已经是前一步的最优解，此时j只可能右移以剔除重复元素a[i]
       而不可能左移增加元素，因此，j具有“单调性”、本题可用双指针降低复杂度）
    3. 用数组s记录子序列a[j ~ i]中各元素出现次数，遍历过程中对于每一个i有四步操作
       cin元素a[i] -> 将a[i]出现次数s[a[i]]加1 -> 若a[i]重复则右移j（s[a[j]]要减1）
       -> 确定j及更新当前长度i - j + 1给r。
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, ans;
// a[N]中放当前数组, s[N]中放每个数出现的次数
int a[N], s[N];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++;
        while(j <= i && s[a[i]] > 1)
        {
            // 当a[i]重复时，先把a[j]次数减1，再右移j
            s[a[j++]]--;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
    return 0;
}