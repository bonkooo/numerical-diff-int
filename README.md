# Numerical Derivative and Integral Calculator

## Overview

This project is a numerical Derivative and Definite Integral Calculator implemented in C++. It allows users to calculate numerically approximated integration and differentiation on elemental functions. The calculator supports linear, quadratic, trigonometric, exponential, and logarithmic functions.

## Features

The calculator performs three main calculations:

1. **Derivative Calculation**: Computes the derivative of a chosen function at a specific point using the finite difference method.
   <div>
       <img src="deriv_form.png" alt="Derivative Formula" width="300"/>
   </div>

2. **Integral Calculation (Trapezoidal Rule)**: Estimates the area under a curve by dividing the interval into trapezoids.
   <div>
       <img src="trap_form.png" alt="Trapezoidal Rule Formula" width="300"/>
   </div>
   <div>
       <img src="trap.png" alt="Trapezoidal Rule" width="300"/>
   </div>

3. **Integral Calculation (Simpson's Rule)**: A more accurate method for estimating the area under a curve by using parabolic segments.
   <div>
       <img src="simp_form.png" alt="Simpson's Rule Formula" width="400"/>
   </div>
   <div>
       <img src="simp.png" alt="Simpson's Rule" width="350"/>
   </div>

   

## Supported Functions

The calculator supports the following types of functions:

- **Linear Function**: ax + b
- **Quadratic Function**: ax^2 + bx + c
- **Trigonometric Functions**: 
  - Sine:  a * sin(bx) 
  - Cosine: a * cos(bx)
  - Tangent: a * tg(bx) 
- **Exponential Function**: a * e^(b*x)
- **Logarithmic Function**: a * log(bx)
## How to Run the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/bonkooo/numerical-diff-int.git
   cd numerical-diff-int
   ```
2. **Compile the Code**
  ```bash
  g++ main.cpp methods.cpp -o calculator -std=c++11
  ```
3. **Edit the config.txt file**
2. **Run the program**
  ```bash
  ./calculator
  ```
   
