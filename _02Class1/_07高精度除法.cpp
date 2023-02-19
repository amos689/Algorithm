#include<bits/stdc++.h>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    // 注意在使用除法时不同于加减乘, 是从高位开始的, 使用在循环之后数字时颠倒的
    for(int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r = r % b;
    }
    // 将数字按位由低到高排列
    reverse(C.begin(), C.end()); //C++特有, 传入首末两个iterator, 用于容器
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b, r;
    vector<int> A, C;
    
    cin >> a >> b;
    
    for(int i = a.size() - 1; i >= 0 ; i--) A.push_back(a[i] - '0');
    
    C = div(A, b, r);
    
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    cout << endl << r << endl;
    return 0;
}