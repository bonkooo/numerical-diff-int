#pragma once
#ifndef METHODS_H
#define METHODS_H
#include <functional>
using namespace std;

double differential(function<double(double)>& f, double x, double h);
double integral_trapezoidal(function<double(double)>& f, double a, double b, int n);
double integral_simpson(function<double(double)>& f, double a, double b, int n);

#endif METHODS_H