#ifndef S21_MATH
#define S21_MATH

#define S21_E 2.7182818284590452354
#define S21_PI 3.14159265358979323846
#define S21_PI_2 1.57079632679489661923
#define S21_EPS 1E-14
#define S21_EPS_TEST 1E-6
#define S21_NAN 0.0 / 0.0
#define S21_POS_INF 1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0
#define S21_DBL_MAX 1.79769E+308
#define S21_LN2 0.693147180559945309417232

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_fac(double x);

#endif