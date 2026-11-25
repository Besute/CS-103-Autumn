#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double func(double x) {
    return log((1 + x) / (1 - x));
}

double abs_double(double a) {
    if (a > 0) return a;
    return (double)-1 * a;
}

double f1(double x) {
    return cos(x) - pow(M_E, -x * x / 2.0) + x - 1.0;
}

double f2_fi(double x) {
    return (double) 1.0 + sin(x) - log(1 + x);
}

double second_ans(double epsilon, double goal) {
    double mid = 1, ans = 99, next;

    do {
        ans = mid;
        mid = f2_fi(mid);
    } while (abs_double(ans - goal) > epsilon);
    return ans;
}

double first_ans(double epsilon, double goal) {
    double left = 1, right = 2, mid = 1.5, ans = 99;
    do {
        mid = (double) (right + left) / 2;
        ans = mid;
        if (f1(ans) > 0) {
            right = mid;
        } else if (f1(ans) < 0) {
            left = mid;
        } else {
            return ans;
        }
    } while (abs_double(goal - ans) > epsilon);
    return ans;
}


int main(int argc, char *argv[]) {
    double epsilon, copyepsilon;
    int precision = 0;
    scanf("%lf", &epsilon);
    copyepsilon = epsilon;
    while (copyepsilon < 1) {
        precision += 1;
        copyepsilon *= 10;
    }
    printf("%.*f %.*f", precision, first_ans(epsilon, 1.0894), precision, second_ans(epsilon, 1.1474));
    return 0;
}
