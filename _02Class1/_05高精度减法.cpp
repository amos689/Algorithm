#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
    // 先比较长度, 长度相同从高位比到低位, 如果都相同就是相等, 也返回true
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i--)
    {
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        // 通过+10, 可以回避t的符号带来的困扰
        // 即当t是负数时, 相当于高位借10, 当t是[0, 9]时通过%运算能消掉10的影响
        C.push_back((t + 10) % 10); // 这里不是t的赋值操作(没有出现'=')
        // 判断是否向高位借位
        if(t < 0) t = 1;
        else t = 0;
    }
    
    // 去除前导零
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B, C;
    
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    // 判断两数的大小, 根据情况进行相减操作
    if(cmp(A, B)) C = sub(A, B);
    else
    {
        C = sub(B, A);
        cout << '-';
    }
    
    // 输出C
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}