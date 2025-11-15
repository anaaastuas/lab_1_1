#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <time.h>

std::mutex cout_mutex;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void Func(std::string name, int iterations) {
    long long total = 0;
    for (int i = 0; i < iterations; i++) {
        total += factorial(10);
    }

    cout_mutex.lock();
    std::cout << "Thread " << name << " finished. Total: " << total << std::endl;
    cout_mutex.unlock();
}

int main() {
    const int iterations = 5000000; // 5 млн на каждый поток

    // Замер времени для параллельных потоков
    clock_t start_parallel = clock();

    std::thread thread1(Func, "t1", iterations);
    std::thread thread2(Func, "t2", iterations);

    thread1.join();
    thread2.join();

    clock_t end_parallel = clock();
    double parallel_time = (double)(end_parallel - start_parallel) / CLOCKS_PER_SEC;

    std::cout << "Parallel time: " << parallel_time << " seconds" << std::endl;

    // Замер времени для последовательного выполнения
    clock_t start_sequential = clock();

    Func("sequential1", iterations);
    Func("sequential2", iterations);

    clock_t end_sequential = clock();
    double sequential_time = (double)(end_sequential - start_sequential) / CLOCKS_PER_SEC;

    std::cout << "Sequential time: " << sequential_time << " seconds" << std::endl;
    std::cout << "Speedup: " << sequential_time / parallel_time << "x" << std::endl;

    system("pause");
    return 0;
}