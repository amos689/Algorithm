#include <bits/stdc++.h>

using namespace std;

// string子串
// string substr(int pos, int n) //从哪开始截取几个
void test01()
{
    string str = "abcdef";
    string sub = str.substr(1, 3);
    cout << sub << endl;

    // 从邮件中获取字符串信息
    string email = "amos@gmail.com";
    int pos = email.find("@");
    cout << email.substr(0, pos) << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}