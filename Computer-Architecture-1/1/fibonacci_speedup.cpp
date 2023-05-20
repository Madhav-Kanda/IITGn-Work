#include <iostream>
#include <ctime>
using namespace std;

struct timespec;

time_t clk1;
time_t clk2;

double values[1000] = {0};
// 1. BaseCase of fibonacci by recurssion
long long fibonacci_recursion(double n)
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
        return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
    }
}

// 2. Fibonacci by loop
double fibonacci_loop(double n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        double i = 0;
        double prev_value = 0;
        double value = 1;
        while (i < n - 1)
        {
            double temp = value;
            value = value + prev_value;
            prev_value = temp;
            i++;
        }
        return value;
    }
}

// 3. Fibonacci by loop memoisation
double values1[1000] = {0};
double fibonacci_recursion_memoisation(int n)
{
    if (n == 0)
    {
        values1[0] = 0;
        return 0;
    }
    else if (n == 1)
    {
        values1[1] = 1;
        return 1;
    }
    else if (values1[n] != 0)
    {
        return values1[n];
    }
    else
    {
        values1[n] = fibonacci_recursion_memoisation(n - 1) + fibonacci_recursion_memoisation(n - 2);
        return values1[n];
    }
}

// 4. Fibonacci by loop memoisation
double fibonacci_loop_memoisation(int n)
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
        int i = 1;
        double prev_value = 0;
        double value = 1;
        while (i < n + 1)
        {
            while (values[i] != 0)
            {
                prev_value = values[i - 1];
                value = values[i];
                i++;
            }
            double temp = value;
            value = value + prev_value;
            values[i] = value;
            prev_value = temp;
            i++;
        }
        return value;
    }
}

int main()
{
    // initialising the array to store the time of each and every program
    float times[4];
    // Setting the approopriate value for memoisation
    values[0] = 0;
    values[1] = 1;
    values1[0] = 0;
    values1[1] = 1;

    // 1. Time for the basecase that is the case of fibonacci with recurssion
    clk1 = clock();
    for (int i = 0; i <= 100; i++)
    {
        cout << fibonacci_recursion(i) << " ";
    }
    cout << endl;
    clk2 = clock() - clk1;
    times[0] = (float)clk2 / CLOCKS_PER_SEC;

    // 2. Time for the case of fibonacci with loop
    clk1 = clock();
    for (int i = 0; i <= 100; i++)
    {
        cout << fibonacci_loop(i) << " ";
    }
    cout << endl;
    clk2 = clock() - clk1;
    times[1] = (float)clk2 / CLOCKS_PER_SEC;

    // 3. Time for the case of fibonacci with recurssion and memoisation
    clk1 = clock();
    for (int i = 0; i <= 100; i++)
    {
        cout << fibonacci_recursion_memoisation(i) << " ";
    }
    cout << endl;
    clk2 = clock() - clk1;
    times[2] = (float)clk2 / CLOCKS_PER_SEC;

    // 4. Time for the case of fibonacci with loop and memoisation
    clk1 = clock();
    for (int i = 0; i <= 100; i++)
    {
        cout << fibonacci_loop_memoisation(i) << " ";
    }
    cout << endl;
    clk2 = clock() - clk1;
    times[3] = (float)clk2 / CLOCKS_PER_SEC;

    for (int i = 0; i < 4; i++)
    {
        cout << "The speed up for the program incase of "
             << " ";
        if (i == 0)
        {
            cout << "Recursion is: ";
        }
        else if (i == 1)
        {
            cout << "Loop is: ";
        }
        else if (i == 2)
        {
            cout << "Recursion memoisation is: ";
        }
        else
        {
            cout << "Loop memoisation is: ";
        }
        cout << times[0] / times[i] << endl;
    }
}