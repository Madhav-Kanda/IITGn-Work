#include <iostream>
#include <ctime>
using namespace std;

struct timespec;

time_t clk1;
time_t clk2;

double values[1000] = {0};

double fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (values[n] != 0)
    {
        return values[n];
    }
    else
    {
        values[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return values[n];
    }
}

int main()
{
    clk1 = clock();
    for (int i = 0; i <= 100; i++)
    {
        cout << i << " ";
        cout << fibonacci(i) << " ";
        cout << endl;
    }
    cout << endl;
    clk2 = clock() - clk1;
    float CPU = (float)clk2 / CLOCKS_PER_SEC;
    cout << "The time taken by the program on CPU using recursion memoisation is:"
         << " ";
    cout << CPU << endl;
}