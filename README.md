# Numerical Derivative and Integral Calculator

## Overview

This project is a numerical Derivative and Definite Integral Calculator implemented in C++. It allows users to calculate numerically approximated integration and differentiation on elemental functions. The calculator supports linear, quadratic, trigonometric, exponential, and logarithmic functions.

## Features

The calculator performs three main calculations:

1. **Derivative Calculation**: Computes the derivative of a chosen function at a specific point using the finite difference method.
   - Formula: 
   $$
   f'(x) \approx \frac{f(x + h) - f(x - h)}{2h}
   $$

2. **Integral Calculation (Trapezoidal Rule)**: Estimates the area under a curve by dividing the interval into trapezoids.
   - Formula:
   $$
   \int_a^b f(x) \, dx \approx \frac{(f(a) + f(b))}{2} \cdot (b - a) + \sum_{i=1}^{n-1} f(x_i) \cdot dx
   $$
   ![Trapezoidal Rule](trap.png)

3. **Integral Calculation (Simpson's Rule)**: A more accurate method for estimating the area under a curve by using parabolic segments.
   - Formula:
   $$
   \int_a^b f(x) \, dx \approx \frac{h}{3} \left( f(a) + f(b) + 4\sum_{i=1}^{n/2} f(a + (2i - 1)h) + 2\sum_{i=1}^{n/2 - 1} f(a + 2ih) \right)
   $$
   ![Simpson's Rule](simp.png)

## Supported Functions

The calculator supports the following types of functions:

- **Linear Function**: \( ax + b \)
- **Quadratic Function**: \( ax^2 + bx + c \)
- **Trigonometric Functions**: 
  - Sine: \( a \cdot \sin(bx) \)
  - Cosine: \( a \cdot \cos(bx) \)
  - Tangent: \( a \cdot \tan(bx) \)
- **Exponential Function**: \( a \cdot e^{bx} \)
- **Logarithmic Function**: \( a \cdot \ln(bx) \)

## How to Run the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/differential-integral-calculator.git
   cd differential-integral-calculator
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
   
