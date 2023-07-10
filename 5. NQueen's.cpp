#include <iostream>
#include <math.h>
using namespace std;

int place(int a[], int k)
{
    int i;
    for (i = 1; i < k; i++)
        if (a[i] == a[k] || (abs(a[i] - a[k])) == abs(i - k))
            return 0;
    return 1;
}

void printsolution(int n, int a[])
{
    int i, j;
    char c[10][10];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            c[i][j] = '-';
    }
    for (i = 1; i <= n; i++)
        c[i][a[i]] = 'Q';
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << c[i][j] << "\t";
        }
        cout << "\n";
    }
}

void nqueens(int n)
{
    int a[10], count = 0, k = 1;
    a[k] = 0;
    while (k != 0)
    {
        a[k]++;
        while (a[k] <= n && (!place(a, k)))
            a[k]++;
        if (a[k] <= n)
        {
            if (k == n)
            {
                count++;
                cout << "\nSolution" << count << "\n";
                printsolution(n, a);
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the no.of queens:";
    cin >> n;
    nqueens(n);
}
