# s21_math  

Implementation of your own version of the math.h library.  

## Preamble  

![s21_math](misc/eng/s21_math.png)

Planet Earth, 1956.

I usually eat crispy toast and juicy sausages with scrambled eggs for breakfast and read the news in the morning. It would have been an ordinary spring morning if I hadn't stumbled across a small column in the newspaper written by a Stanford University professor that caught my attention. William Shockley, known in small circles of the physics community as the inventor of the transistor, had advertised a job opening in a laboratory for the mass production of the latest transistors and dinistors.
Without thinking, I called the number given in the advertisement:

*- Good evening, William, I'm calling about the vacancy you left in the newspaper, do you have a minute?*

*-- Yes, of course, I'm very glad I didn't waste my money for nothing and at least someone called! I must point out right away all the specifics of our future collaboration: production will take place at our site in Mountain View, near Palo Alto, a place with a rural lifestyle, but I hope it’s not a problem, Mr?..*

*- Last, Mr. J. Last from MIT. I am aware of that, and it does not bother me a bit, so when can I come for my interview?*

*-- Good, very good! I don't have time to be constantly in touch and interview people from other cities right now, so send me to the address left in the paper the result of the work, that I'll give you now...*

*- I'm all ears.*

*-- Our case requires powerful mathematical tools that can be described in machine programming language - all sorts of mathematical operations and functions: trigonometric, logarithmic, exponential, and others of your choice. It doesn't matter how, but you have to do it...* \
*Now if you’ll excuse me, I have to say goodbye, I have a second line, I'm waiting for your answer! Thank you!*

*- Have a nice day!*

Well, I have to do it, I feel in my bones that a transistor revolution in mathematical computing is coming and I have to be on the front line!

## Chapter I  

## Introduction

In this project you will develop your own version of the standard math.h library in the C programming language. This library implements basic mathematical operations, which are then used in various algorithms. As part of the project you will learn the basics of computational methods and solidify knowledge of structured programming.

## Chapter II

## Information

C mathematical operations are a group of functions in the standard library of the C programming language implementing basic mathematical functions. All functions use floating-point numbers in one manner or another. Different C standards provide different, albeit backwards-compatible, sets of functions. Any functions that operate on angles use radians as the unit of angle.

### Overview of some "math.h" functions

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | computes absolute value of an integer value |
| 2 | `long double acos(double x)` | computes arc cosine |
| 3 | `long double asin(double x)` | computes arc sine |
| 4 | `long double atan(double x)` | computes arc tangent |
| 5 | `long double ceil(double x)` | returns the nearest integer not less than the given value |
| 6 | `long double cos(double x)` | computes cosine |
| 7 | `long double exp(double x)` | returns e raised to the given power |
| 8 | `long double fabs(double x)` | computes absolute value of a floating-point value |
| 9 | `long double floor(double x)` | returns the nearest integer not greater than the given value |
| 10 | `long double fmod(double x, double y)` | remainder of the floating-point division operation |
| 11 | `long double log(double x)` | computes natural logarithm |
| 12 | `long double pow(double base, double exp)` | raises a number to the given power |
| 13 | `long double sin(double x)` | computes sine |
| 14 | `long double sqrt(double x)` | computes square root |
| 15 | `long double tan(double x)` | computes tangent |  


## Chapter III

## Part 1. Implementing the math.h library functions

The functions of the math.h library must be implemented (only those directly described [above](#overview-of-some-mathh-functions)):

- The library must be developed in C language of C11 standard using gcc compiler;
- The library code must be located in the src folder on the develop branch;
- Do not use outdated and legacy language constructions and library functions. Pay attention to the legacy and obsolete marks in the official documentation on the language and the libraries used. Use the POSIX.1-2017 standard;
- When writing code it is necessary to follow the Google style;
- Make it as a static library named *s21_math.a* (with the s21_math.h header file);
- The library must be developed according to the principles of structured programming; code duplication must be avoided;
- Use prefix s21_ before each function;
- Prepare full coverage of library functions code with unit-tests with the Check library;
- Unit-tests must check the results of your implementation by comparing them with the implementation of the standard math.h library;
- Unit tests must cover at least 80% of each function (checked using gcov);
- Provide a Makefile for building the library and tests (with the targets all, clean, test, s21_math.a, gcov_report);
- The gcov_report target should generate a gcov report in the form of an html page. Unit tests must be run with gcov flags to do this;
- It is forbidden to copy the implementation of the standard math.h library and to use it anywhere, except unit-tests;
- You must follow the logic of the standard library (in terms of checks, working with memory and behavior in emergency situations - tests will help you with that);
- The total verifiable accuracy is 16 significant digits;
- Verifiable accuracy of the fractional part is up to 6 decimal places.
