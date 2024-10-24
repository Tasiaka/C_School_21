#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_acos(double x) {
  long double acos = 10;
  if (x >= -1 && x <= 1)
    acos = S21_PI_2 - s21_asin(x);
  else
    acos = S21_NAN;
  return acos;
}

long double s21_asin(double x) {
  long double asin;
  if (x >= -1 && x <= 1) {
    asin = s21_atan(x / s21_pow(1 - x * x, 0.5));
  } else {
    asin = S21_NAN;
  }
  return asin;
}

long double s21_atan(double x) {
  int n = 0;
  long double atan;
  if (x < -S21_DBL_MAX) {
    atan = -S21_PI_2;
  } else if (x > S21_DBL_MAX) {
    atan = S21_PI_2;
  } else if (s21_fabs(x - 1) < S21_EPS) {
    atan = 0.7853982;
  } else if (s21_fabs(x + 1) < S21_EPS) {
    atan = -0.7853982;
  } else {
    if (x > -1 && x < 1) atan = 0;
    if (x > 1) atan = S21_PI_2;
    if (x < -1) atan = -S21_PI_2;
    long double term = 1;
    while (s21_fabs(term) > S21_EPS) {
      if ((x > -1 && x < 1)) {
        term = s21_pow(-1, n) / (2 * n + 1) * s21_pow(x, 2 * n + 1);
        atan += term;
      } else {
        term = s21_pow(-1, n) / (2 * n + 1) * s21_pow(x, -2 * n - 1);
        atan -= term;
      }
      n++;
    }
  }
  return atan;
}

long double s21_ceil(double x) {
  long double res;
  if ((x == S21_POS_INF || x == S21_NEG_INF)) {
    res = x;
  } else {
    res = (long long int)x;
    if (s21_fabs(x) > 0 && x != res) {
      if (x != S21_DBL_MAX) {
        if (x > 0) {
          res++;
        }
      } else {
        res = S21_DBL_MAX;
      }
    }
  }
  if (x != x) res = S21_NAN;
  return res;
}

long double s21_cos(double x) {
  long double cos = 0;

  if (s21_fabs(x) == S21_POS_INF || x == S21_NAN) {
    cos = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    int n = 0;
    long double term = 1;
    while (s21_fabs((double)term) > S21_EPS) {
      term = s21_pow(-1, n) / s21_fac(2 * n) * s21_pow(x, 2 * n);
      cos += term;
      n++;
    }
  }
  return cos;
}

long double s21_exp(double x) {
  int x_mod = 0;
  long long int exp_2 = 1;
  long double exp = 1;
  long double term = 1;
  int n = 1;
  if (s21_fabs(x) < S21_EPS) {
    exp = 1;
  } else if (x == S21_NEG_INF) {
    exp = 0;
  } else if (x < -38) {
    exp = 0;
  } else if (x > 308) {
    exp = S21_POS_INF;
  } else {
    if (x < 0) {
      x_mod = 1;
      x = -x;
    }
    long long int x_int = (long long int)(x / S21_LN2);
    long double x_rest = x - x_int * S21_LN2;

    while (s21_fabs(term) > S21_EPS) {
      term *= x_rest / n;
      exp += term;
      n++;
    }
    exp_2 = ((exp_2) << x_int);

    exp *= exp_2;
    if (x_mod == 1) exp = 1. / exp;
  }
  return exp;
}

long double s21_fabs(double x) { return x > 0 ? x : -x; }

long double s21_floor(double x) {
  long double res;
  if ((x == S21_POS_INF || x == S21_NEG_INF)) {
    res = x;
  } else {
    long long int x_int = (long long int)x;
    if (x < 0 && s21_fabs(x - x_int) != 0) x_int--;
    res = (long double)x_int;
  }

  if (res == 0 && x < 0) res = -res;
  if (x != x) res = S21_NAN;
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (s21_fabs(x) < S21_EPS && s21_fabs(y) > S21_EPS)
    res = 0;
  else if (s21_fabs(x) == S21_POS_INF && y != S21_NAN)
    res = S21_NAN;
  else if (s21_fabs(y) < S21_EPS && x != S21_NAN)
    res = S21_NAN;
  else if (s21_fabs(y) == S21_POS_INF && s21_fabs(x) < S21_POS_INF)
    res = x;
  else
    res = x - ((long long int)(x / y)) * y;

  return res;
}

long double s21_log(double x) {
  long double log = 0;
  if (x < 0) {
    log = S21_NAN;
  } else if (x == 0) {
    log = S21_NEG_INF;
  } else if (x > S21_DBL_MAX) {
    log = S21_POS_INF;
  } else {
    int temp_pow = 0;
    long double res = 0;
    for (; x >= S21_E; x /= S21_E) temp_pow++;
    for (int i = 0; i < 500; i++) {
      long double cycle_temp = res;
      res = cycle_temp +
            2 * (x - s21_exp(cycle_temp)) / (x + s21_exp(cycle_temp));
    }
    if (log == 0) log = temp_pow + res;
  }
  return log;
}

long double s21_pow(double base, double exp) {
  long double res;
  if (s21_fabs(exp) < S21_EPS) {
    res = 1;
  } else if (s21_fabs(base - 1) < S21_EPS) {
    res = 1;
  } else if (s21_fabs(base + 1) < S21_EPS && s21_fabs(exp) == S21_POS_INF) {
    res = 1;
  } else if (base < 0 && base > S21_NEG_INF && exp != s21_ceil(exp)) {
    res = S21_NAN;
  } else if (base < 0) {
    base = -base;
    if (exp * s21_log(base) < -16) {
      res = 0;
    } else {
      res = s21_exp(exp * s21_log(base));
      if (s21_fmod(exp, 2.) != 0) res = -res;
    }
  } else {
    if (exp * s21_log(base) < -16)
      res = 0;
    else
      res = s21_exp(exp * s21_log(base));
  }
  if (res == S21_NEG_INF) res = -res;
  return res;
}

long double s21_sin(double x) {
  long double sin;
  if (s21_fabs(x) == S21_POS_INF || x == S21_NAN)
    sin = S21_NAN;
  else
    sin = s21_cos(x - S21_PI_2);
  return sin;
}

long double s21_sqrt(double x) {
  long double res = 0;
  if (x < 0) {
    res = S21_NAN;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}

long double s21_tan(double x) {
  long double tan;
  if (s21_fabs(s21_cos(x)) < S21_EPS && s21_sin(x) > 0)
    tan = S21_POS_INF;
  else if (s21_fabs(s21_cos(x)) < S21_EPS && s21_sin(x) < 0)
    tan = S21_NEG_INF;
  else
    tan = s21_sin(x) / s21_cos(x);
  return tan;
}

long double s21_fac(double x) {
  long double f = 1;
  for (int n = 1; n <= x; n++) f *= n;
  return f;
}
