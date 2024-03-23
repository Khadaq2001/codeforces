#include <iostream>
#include <vector>
#include <string>
using namespace std;
int m, s;
// refine with dp
bool can(int m, int s)
{
    return (s >= 0 && s <= m * 9);
}
int main()
{
    cin >> m >> s;
    if ((s==0 && m!=1) || s > m*9){
        cout << "-1 -1" << endl;
        return 0;
    }
    string ansMin(m, '0'), ansMax(m, '0');
    int sum1 = s;
    int sum2 = s;
    for (int i = 0; i < m; i++)
    {
        for (int d = 0; d < 10; d++)
        {
            if ((i > 0 || d > 0 || (m == 1 && d == 0) )&& can(m - i - 1, sum1 - d))
            {
                ansMin[i] = char('0' + d);
                sum1 -= d;
                break;
            }
        }

        for (int d = 9; d >= 0; d--)
        {
            if ((i > 0 || d > 0 || (m == 1 && d == 0) )&& can(m - i - 1, sum2 - d))
            {
                ansMax[i] = char('0' + d);
                sum2 -= d;
                break;
            }
        }
    }
    cout << ansMin << ' ' << ansMax << endl;

    return 0;
}