
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Def  dy/dx

double A(double x, double y)
{
    double dydx = pow(x, 2) + y;
    return dydx;
}

// Set precision and intedentation
void print_num(float x, int width = 10, int precision = 3)
{
    cout << setw(width) << setprecision(precision) << x;
}

int main()
{
    int i, n;

    // Input Section
    cout << "Enter number of data points: ";
    cin >> n;

    // Allocate the arrays
    float *x = new float[n];
    float *y = new float[n];

    // Get the first x
    cout << "Enter the lowest value of x i.e. x[0]: ";
    cin >> x[0];
    cout << "Enter the lowest value of y i.e. y[0]: ";
    cin >> y[0];

    // And get the spacing
    cout << "Enter the spacing, h: ";
    float h;
    cin >> h;

    // Generate the x values
    for (int i = 1; i < n; i++)
    {
        x[i] = x[0] + i * h;
    }
    // Generate the y values
    for (i = 1; i < n; i++)
    {
        y[(i)] = y[i-1] + h *(A(x[i-1], y[i-1]));
    }

    // Display the header
    cout << endl
         << "**************************";
    cout << endl
         << "Euler's TABLE";
    cout << endl
         << "**************************" << endl;
    cout << endl
         << "" << endl;
    ;
    cout << "-------------------------------------------" << endl;
    cout << "******************************************************" << endl;
    cout << setw(2) << "SNO" << setw(12) << "x[n]" << setw(12) << "y[n]" << setw(12) << "A" << setw(12) << "hA" << endl;
    cout << "******************************************************" << endl;

    for (i = 0; i < n; i++)
    {
        print_num(i, 2);
        print_num(x[i], 12);
        print_num(y[i], 12, 5);
        print_num(A(x[i], y[i]), 12, 5);
        print_num(h * A(x[i], y[i]), 12, 5);
        cout << endl;
    }
    return 0;
}

/*
Enter number of data points: 4
Enter the lowest value of x i.e. x[0]: 0
Enter the lowest value of y i.e. y[0]: 1
Enter the spacing, h: .1
**************************
Euler's TABLE
**************************


-------------------------------------------
******************************************************
SNO        x[n]        y[n]           A          hA
******************************************************
 0           0           1          -1        -0.1
 1         0.1         0.9        -0.8       -0.08
 2         0.2        0.82      -0.632     -0.0632
 3         0.3       0.757      -0.483     -0.0483

 */