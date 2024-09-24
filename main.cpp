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
    switch (option) {
    case 'm':
        double a, b;
        cout << "Linear function - ax + b: \n";
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        return [a, b](double x) { return a * x + b; };
    case 'q':
        double a, b, c;
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
        double a, b;
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
        double a, b;
        cout << "Exponential function - a * e^(b*x) : \n";
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        return [a, b](double x) { return a * exp(b * x); };
    case 'l':
        double a, b;
        cout << "Logarithmic function a * ln(bx) : \n";
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        return [a, b](double x) { return a * log(b * x); };
    }
    default:
        cerr <<""
}

void read_config(string& filename, double& step_size, int& n) {
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
    char option;

    do {
        option = show_menu();
        if (option == 'e') {
            cout << "Exiting the program...\n";
                break;
        }
        auto f = get_function(option);

        
    }