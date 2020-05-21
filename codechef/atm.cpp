#include <iostream>
using namespace std;
float acc(float w, float &bal)
{
    float av = bal - 0.05;
    if (w%5 = 0 && w <= av)
    {
        return (av - w);
    }
    else
    {
        return bal;
    }
}
int main()
{
    float x, y;
    cin >> x >> y;
    cout << acc(x, y);
}