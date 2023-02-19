#include <iostream>

using namespace std;
const int N=1e5+10;
int a[N],b[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n; i++) scanf("%d",&a[i]);
    for(int j = 0;j < m; j++) scanf("%d",&b[j]);

    int i = 0;
    for(int j = 0;j < m; j++)
    {
        if(i < n&&a[i] == b[j])  i++;
        if(i == n) break;
    }
    
    if(i == n) puts("Yes");
    else puts("No");
    return 0;
}