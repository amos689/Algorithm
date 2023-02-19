#include<bits/stdc++.h>

using namespace std;

vector<int> num;
vector<char> op;

// 设置优先级
unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };

void eval()
{
    int a = num[num.size() - 1];
    num.pop_back();
    
    int b = num[num.size() - 1];
    num.pop_back();
    
    char p = op[op.size() - 1];
    op.pop_back();
    
    int r = 0;
    
    if (p == '+') r = b + a;
    else if (p == '-') r = b - a;
    else if (p == '*') r = b * a;
    else r = b / a;
    
    num.push_back(r);
}

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            int x = 0, j = i;
            while(j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + (s[j] - '0');
                j++;
            }
            num.push_back(x);
            i = --j;
        }
        
        else if(s[i] == '(') op.push_back(s[i]);
        
        else if(s[i] == ')')
        {
            while(op[op.size() - 1] != '(') eval();
            op.pop_back();
        }
        
        else
        {
            while(op.size() && h[op[op.size() - 1]] >= h[s[i]]) eval();
            op.push_back(s[i]);
        }
    }
    while(op.size()) eval();
    cout << num[num.size() - 1];
    return 0;
}