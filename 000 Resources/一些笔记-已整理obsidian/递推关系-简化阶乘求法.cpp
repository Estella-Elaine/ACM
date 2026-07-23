#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    
    return 0;
}

/* 你的代码将被嵌在这里 */

double funcos(double e, double x) {
    double sum = 1.0;       // 第0项：1
    double term = 1.0;      // 当前项
    int n = 1;
    
    do {
        // 计算新项：(-1)^n * x^(2n) / (2n)!
        term = term * (-1) * x * x / ((2*n-1) * (2*n));
        sum += term;
        n++;
    } while (fabs(term) >= e);
    
    return sum;
}
