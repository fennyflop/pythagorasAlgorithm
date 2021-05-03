#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

bool isRelative(int x, int y)
{
    // No negative integers in geometry

    // x = abs(x);
    // y = abs(y);

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

bool isEven(const int x)
{
    if (x % 2 == 0)
    {
        return true;
    }
    return false;
}

bool isPrime(const int x)
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

// Generate a vector about triangles with counter, k1, k2, gyp.
vector<map<string, int>> GeneratePythagorasTriads(const int &maxValue)
{
    vector<map<string, int>> PythagorasTriads;

    int counter = 0;

    for (int p = 2; p < maxValue; p++)
    {
        for (int q = 1; q < p; q++)
        {
            if (isEven(p) && !isEven(q) || !isEven(p) && isEven(q))
            {
                if (!isRelative(p, q))
                {
                    map<string, int> PythagorasTriad;
                    ++counter;
                    PythagorasTriad["counter"] = counter;
                    PythagorasTriad["k1"] = pow(p, 2) - pow(q, 2);  // k1
                    PythagorasTriad["k2"] = 2 * p * q;              // k2
                    PythagorasTriad["gyp"] = pow(p, 2) + pow(q, 2); // gyp
                    PythagorasTriads.push_back(PythagorasTriad);
                }
            }
        }
    }

    return PythagorasTriads;
}

void DisplayPythagorasTriads(const vector < map<string, int> PythagorasTriads)
{

    for (const map<string, int> triangle : PythagorasTriads)
    {
        cout << "=> Triangle : " << triangle.at("counter") << endl;
        cout << "K1 : " << triangle.at("k1") << endl;
        cout << "K2 : " << triangle.at("k2") << endl;
        cout << "GYP : " << triangle.at("gyp") << endl;
        cout << "----------------------------------------" << endl;
    }
}

int main()
{

    DisplayPythagorasTriads(GeneratePythagorasTriads(50));

    return 0;
}
