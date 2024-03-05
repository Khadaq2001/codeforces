#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;

bool isGood(string &str)
{
    char firstChar = str[0];
    char lastChar = str.back();
    string tmpstr1 = str.substr(1);
    string tmpstr2 = lastChar + str.substr(0, str.size() - 1);
    tmpstr1.push_back(firstChar);
    return tmpstr1 == tmpstr2;
}
int solve(string &str, int x, int y)
{
    int res = 0;
    for (auto &c : str)
    {
        if (c - '0' == x)
        {
            res++;
            std::swap(x, y);
        }
    }
    if (res % 2 == 1 && x != y)
    {
        res--;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (isGood(str))
        {
            cout << 0 << '\n';
            continue;
        }
        int out = 0;
        for (int x = 0; x<10 ; x++){
            for (int y = 0; y < 10; y++){
                out = max (out, solve(str, x, y));
            }
        }
        cout << int(str.size()) - out << '\n';

    }
    return 0;
}
