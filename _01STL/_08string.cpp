#include <bits/stdc++.h>

using namespace std;

/*
    ?ַ????Ĳ?????ɾ??
*/
void test01()
{
    string str = "hello";

    // ????
    str.insert(1, "1111");
    cout << str << endl;

    // ɾ??
    str.erase(1, 3); // ??????, ɾ????
}

int main()
{
    test01();
    system("pause");
    return 0;
}