#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int stk[N], stt;

void push(int x)
{
    stk[++stt] = x;
}

void pop()
{
    stt--;
}

void query()
{
    cout << stk[stt] << endl;
}

void empty()
{
    if(stt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
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