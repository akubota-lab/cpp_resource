#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <mutex>

int main() {
    std::thread th1([&](int a, int b) {
      printf("th1: a = %d, b = %d\n", a, b);
      sleep(2);
      a += 1;
      b += 1;
      printf("th1: a = %d, b = %d\n", a, b);
    }, 1, 2
    );

    std::thread th2([&](int a, int b) {
      printf("th2: a = %d, b = %d\n", a, b);
      sleep(2);
      a += 2;
      b += 2;
      printf("th2: a = %d, b = %d\n", a, b);
    }, 0, 3
    );

    th1.join();
    th2.join();

    return 0;
}
