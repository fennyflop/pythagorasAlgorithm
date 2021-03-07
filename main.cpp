#include <iostream>
#include <cmath>

using namespace std;

bool isRelative(int x, int y)
{
    x = abs(x);
    y = abs(y);

    while (y)
    {
        int t = y;
        y = x % y;
        x = t;
    }
    if (x == 1)
    {
        return false;
    }
    return true;
}

bool isEven(int x)
{
    if (x % 2 == 0)
    {
        return true;
    }
    return false;
}

bool isPrime(int x)
{
    bool res = true;
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    int maxValue = 50; // Чем больше maxValue, тем больше треугольников
    int k1 = 0, k2 = 0, gyp = 0, counter = 0;
    for (int p = 2; p < maxValue; p++)
    {
        for (int q = 1; q < p; q++)
        {
            if (isEven(p) && !isEven(q) || !isEven(p) && isEven(q))
            {
                if (!isRelative(p, q))
                {
                    counter++;
                    k1 = pow(p, 2) - pow(q, 2);
                    k2 = 2 * p * q;
                    gyp = pow(p, 2) + pow(q, 2);
                    cout << "Counter: " << counter << ", p: " << p << ", q: " << q << ", k1: " << k1 << ", k2: " << k2 << ", gyp: " << gyp << endl;
                }
            }
        }
    }
    return 0;
}
