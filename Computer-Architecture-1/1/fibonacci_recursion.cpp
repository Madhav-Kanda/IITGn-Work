#include <iostream>
#include <ctime>
using namespace std;

struct timespec;

time_t clk1;
time_t clk2;

double fibonacci(double n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{

    clk1 = clock();
    for (int i = 0; i <= 40; i++)
    {
        cout << i << " ";
        cout << fibonacci(i) << " ";
        cout << endl;
    }
    clk2 = clock() - clk1;
    float CPU = (float)clk2 / CLOCKS_PER_SEC;
    cout << "The time taken by the program on CPU using timespec is:"
         << " ";
    cout << CPU << endl;
}