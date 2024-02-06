#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define CAPACITY 100001

int n;
vector<long long> a(CAPACITY, 0);
vector<long long> b(CAPACITY, 0);
vector<string> names;
vector<long long> scores;

unsigned long long hashing(const string str)
{
    unsigned long long i = 0;
    for (int j = 0; str[j]; j++)
        i = (i * 256 + str[j]) % CAPACITY;
    return i ;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        names.push_back(name);
        scores.push_back(score);
        int index = hashing(name);
        a[index] += score;
    }
    long long max = 0;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    for (int i =0; i< n; i++){
        long long index = hashing(names[i]);
        b[index] += scores[i];
        if (b[index] >= max && a[index] == max){
            cout << names[i] << endl;
            return 0;
        }
    }
}