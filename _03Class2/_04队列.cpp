#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int q[N], qt = -1, qh;

void push(int x)
{
    q[++qt] = x;
}

void pop()
{
    qh++;
}

void query()
{
    cout << q[qh] << endl;
}

void empty()
{
    if(qh <= qt) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    cin >> n;
    while(n--)
    {
        char op[10];
        cin >> op;
        
        if(!strcmp(op, "push"))
        {
            int x;
            cin >> x;
            push(x);
        }
        else if(!strcmp(op, "pop")) pop();
        else if(!strcmp(op, "query")) query();
        else empty();
    }
    
    return 0;
}