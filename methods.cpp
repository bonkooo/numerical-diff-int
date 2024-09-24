#include "methods.h"

double differential(function<double(double)>& f, double x, double h)
{
    return (f(x + h) - f (x - h)) / (2 * h);
}

double integral_trapezoidal(function<double(double)>& f, double a, double b, int n)
{
    double dx = (b - a) / n; //odredjivanje koraka dx
    double sum = (f(a) + f(b)) * 0.5 * dx; //prva i poslednja povrsina su pravougli trouglovi

    for (int i = 1; i < n; i++) {
        sum += f(a + i * dx) * dx; //suma pravougaonika
    }
    return sum; //vrati procenjenu povrsinu ispod grafika
}

double integral_simpson(function<double(double)>& f, double a, double b, int n)
{
    if (n % 2 != 0) n++; //n mora biti parno
    double dx = (b - a) / n;
    double sum = (f(a) + f(b)) * (dx / 3);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * dx) * (dx / 3);
        }
        else {
            sum += 4 * f(a + i * dx) * (dx / 3);
        }
    }

    return sum;
}
