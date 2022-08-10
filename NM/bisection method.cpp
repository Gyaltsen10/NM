#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (x*x*x - 4*x - 9);
}
void bisection (float *x, float a, float b, int *itr)

{
    *x=(a+b)/2;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}
int main ()
{
    int itr = 0, maxmitr;
    float x, a, b, err, x1;
    printf("Enter the values of a:");
    scanf("%f" , &a);
    printf("enter the vlaues of b:");
    scanf("%f",&b);
    printf("enter the values of allowed error:");
    scanf("%f",&err);
    printf("Enter the values of maximum iterations:");
    scanf("%d",&maxmitr);
    bisection (&x, a, b, &itr);
    do
    {
        if (f(a)*f(x) < 0)
            b=x;
        else
            a=x;
        bisection (&x1, a, b, &itr);
        if (fabs(x1-x) < err)
        {
            printf("After %d iterations, root = %6.4f\n", itr, x1);
            return 0;
        }
        x=x1;
    }
    while (itr < maxmitr);
    printf("The solution does not converge or iterations are not sufficient");
    return 1;
}
