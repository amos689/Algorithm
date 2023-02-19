#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

/*
    vector容量和大小
    - empty(); 判断容器是否为空
    - capacity(); 返回容器的容量(capacity >= size)容量大于等于大小
    - size(); 返回容器中元素的个数
    - resize(int num); 重新指定容器的长度为num, 若容器变长, 则默认值填充新的位置
      若容器变短, 则末尾超出容器的长度的元素将被删除
    - resize(int num, elem); 重新指定容器的长度为num, 若容器变长, 则以elem值填充新的位置
      如果容器变短, 则末尾超出容器长度的元素会被删除
*/
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量是: " << v1.capacity() << endl;
    }

    // 重新指定大小
    v1.resize(15, 100);
    printVector(v1); // 如果重新指定的比原来长, 以默认值/参数值代替
    v1.resize(5);
    printVector(v1); // 重新指定的比以前短了, 超出的部分会删除
}

int main()
{
    test01();
    system("pause");
    return 0;
}