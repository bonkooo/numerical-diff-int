#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include "methods.h"

using namespace std;

int show_menu() {
    char option;
    cout << "Choose a function to work with:\n";
    cout << "m - Linear Function (ax + b)\n";
    cout << "q - Quadratic Function (ax^2 + bx + c)\n";
    cout << "t - Trigonometric Function (a * sin(bx))\n";
    cout << "x - Exponential Function (a * e^bx)\n";
    cout << "l - Logarithmic Function (ln(x))\n";
    cout << "e - Exit\n";
    cout << "Enter your choice: ";
    cin >> option;
    return option;
}

function<double(double)> get_function(int option) {
    double a, b, c;
    switch (option) {
    case 'm':
        cout << "Linear function - ax + b: \n";
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        return [a, b](double x) { return a * x + b; };
    case 'q':
        cout << "Quadratic function - ax^2 + bx + c: \n";
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        cout << "Enter value of c: ";
        cin >> c;
        return [a, b, c](double x) { return a * x * x + b * x + c; };
    case 't':
        char trigOption;
        cout << "Choose a trigonometric function to work with\n";
        cout << "s - Sine : a * sin(bx)\n";
        cout << "c - Cosine : a * cos(bx)\n";
        cout << "t - Tangent : a * tg(bx)\n";
        cout << "d - Contangent : a * ctg(bx)\n";
        cout << "Your choice: ";
        cin >> trigOption;
        switch (trigOption) {
        case 's':
            cout << "Enter value of a: ";
            cin >> a;
            cout << "Enter value of b: ";
            cin >> b;
            return [a, b](double x) {return a * sin(b * x);};
        case 'c':
            cout << "Enter value of a: ";
            cin >> a;
            cout << "Enter value of b: ";
            cin >> b;
            return [a, b](double x) {return a * cos(b * x);};
        case 't':
            cout << "Enter value of a: ";
            cin >> a;
            cout << "Enter value of b: ";
            cin >> b;
            return [a, b](double x) {return a * tan(b * x);};
        case 'g':
            cout << "Enter value of a: ";
            cin >> a;
            cout << "Enter value of b: ";
            cin >> b;
            return [a, b](double x) {return 1 / (a * tan(b * x));};
        }
        
    case 'x':
        cout << "Exponential function - a * e^(b*x) : \n";
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        return [a, b](double x) { return a * exp(b * x); };
    case 'l':
        cout << "Logarithmic function a * ln(bx) : \n";
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        return [a, b](double x) { return a * log(b * x); };
    default:
        cerr << "Wrong option\n";
    }
    
}

void read_config(const string& filename, double& step_size, int& n) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> step_size;
        file >> n;
        file.close();
    }
    else {
        cout << "Error while loading file\n";
        step_size = 1e-5;
        n = 100;
    }
}

int main() {
    double step_size;
    int n;
    read_config("config.txt", step_size, n);
    char option, select;
    double x, a, b;

    do {
        option = show_menu();
        if (option == 'e') {
            cout << "Exiting the program...\n";
            break;
        }
        auto f = get_function(option);
        cout << "Do you want to calculate the derivative or the integral of this function?\n";
        cout << "d - Derivative\n";
        cout << "i - Integral\n";
        cin >> select;
        double derivative, integral_trap, integral_simp;
        switch (select) {
        case 'd':
            cout << "At which point x do you want to calculate the derivative? ";
            cin >> x;
            derivative = differential(f, x, step_size);
            cout << "Derivative at x = " << x << " is: " << derivative << "\n";
            break;
        case 'i':
            cout << "Enter the integration limits a and b:\n";
            cout << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;
            integral_trap = integral_trapezoidal(f, a, b, n);
            integral_simp = integral_simpson(f, a, b, n);
            cout << "Area under the function from point " << a << " to " << b << ": " << integral_trap << " according to the Trapezodial method\n";
            cout << "Area under the function from point " << a << " to " << b << ": " << integral_simp << " according to Simpsons method\n";
            break;
        default:
            cerr << "Wrong option\n";
            break;
        }

    } while (option != 'e');
}