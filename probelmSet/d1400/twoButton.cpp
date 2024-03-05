#include <iostream>
#include <queue>

using namespace std;
#define MAX 10001 * 2
int bfs(int n, int m)
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    bool visited[MAX] = {false};
    visited[n] = true;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        if (current.first == m)
        {
            return current.second;
        }

        int next = current.first * 2;
        if (next < 2 * m && !visited[next])
        {
            visited[next] = true;
            q.push({next, current.second + 1});
        }

        next = current.first - 1;
        if (next > 0 && !visited[next])
        {
            visited[next] = true;
            q.push({next, current.second + 1});
        }
    }

    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int out = bfs(n, m);
    cout << out << endl;
    return 0;
}