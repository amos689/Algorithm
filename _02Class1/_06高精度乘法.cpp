#include<bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0; //保存进位
    
    // 需要同时考虑i和进位t两个变量
    // 因为t可能不止一位数, 所以必须要等t的每一位数完全插入C中才能结束循环
    for(int i = 0; i < A.size() || t; i++)
    {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    
    // 去除前导零
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    vector<int> A, C;
    
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    
    C = mul(A, b);
    
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}