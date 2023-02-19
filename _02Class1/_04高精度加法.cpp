// 大数加大数
#include<bits/stdc++.h>

using namespace std;

vector<int> Add(vector<int> &p, vector<int> &q)
{
    vector<int> r;
    int t = 0;
    for(int i = 0; i < p.size() || i < q.size(); i++)
    {
        if(i < p.size()) t += p[i];
        if(i < q.size()) t += q[i];
        r.push_back(t % 10);
        t /= 10;
    }
    if(t) r.push_back(t);
    return r;
}

int main()
{
    string a, b;
    vector<int> p, q;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) p.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) q.push_back(b[i] - '0');
    vector<int> r = Add(p, q);
    for(int i = r.size() - 1; i >= 0; i--) printf("%d", r[i]);
    return 0;
}