#include <iostream>
#include <time.h>

long long factorial(int n) 
{
    long long result = 1;
    for (int i = 1; i <= n; i++) 
    {
        result *= i;
    }
    return result;
}

int main() 
{
    const int iterations = 10000000;
    const int n = 10;

    clock_t start = clock();

    long long total = 0;
    for (int i = 0; i < iterations; i++) 
    {
        total += factorial(n);
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Total: " << total << std::endl;
    std::cout << "Time: " << seconds << " seconds" << std::endl;
    std::cout << "10! = " << factorial(n) << std::endl;

    system("pause");
    return 0;
}