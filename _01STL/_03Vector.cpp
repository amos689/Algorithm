#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

// 容器中嵌套容器
void test1()
{
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 向小容器中添加数据
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器将所有数据遍历一遍
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it) -------- 就是一个容器, 是一个vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << endl;
        }
        cout << endl;
    }
}

int main()
{

    system("pause");
    return 0;
}