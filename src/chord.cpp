#include "chord.h"
#include <cmath>

double chord_method(double (*f)(double), double a, double b, double tol) {
    double fa = f(a);
    double fb = f(b);
    double c = a;
    while (fabs(b - a) > tol) {
        c = b - fb * (b - a) / (fb - fa);
        a = b;
        fa = fb;
        b = c;
        fb = f(b);
    }
    return c;
}
