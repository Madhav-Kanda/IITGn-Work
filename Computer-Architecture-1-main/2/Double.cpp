#include <iostream>
#include <ctime>

using namespace std;

struct timespec;

time_t clk1;
time_t clk2;

int main()
{
    int n;
    cin >> n;
    double a[n][n] = {0};
    double b[n][n] = {0};
    double c[n][n] = {0};
    clk1 = clock();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            if ((i + j) % 2 == 0)
            {
                a[i][j] = 2;
                b[i][j] = 3;
            }
            else
            {
                a[i][j] = 3;
                b[i][j] = 2;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[k][i] += a[k][j] * b[j][i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    clk2 = clock() - clk1;
    double CPU = (double)clk2 / CLOCKS_PER_SEC;
    cout << "The time taken by the meat portion of the program is:"
         << " ";
    cout << CPU << endl;
}