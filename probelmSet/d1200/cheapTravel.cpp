#include <iostream>
using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    double singlePrice = double(b) / double(m);
    if (singlePrice > a)
    {
        cout << n * a << endl;
        return 0;
    }
    int numTicket = n / m;
    int remainRide = n % m;
    int remainPrice = remainRide * a <= b ? remainRide * a : b;
    cout << numTicket * b + remainPrice << endl;
    return 0 ;
}