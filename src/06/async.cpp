#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <future>

std::mutex mut;
int num = 0;

int threadFunc(int thr) {
    while (true) {
        mut.lock();
        if (num > 10) {
            mut.unlock();
            break;
        }
        printf("thread = %d, i = %2d\n", thr, num);
        num++;
        mut.unlock();
        sleep(2);
    }
    return 1;
}

int main() {
    std::future<int> a[4];
    for (int thr = 0; thr < 4; thr++) {
        a[thr] = std::async(threadFunc, thr);
    }
    for (int thr = 0; thr < 4; thr++) {
        printf("result = %d\n", a[thr].get());
    }
    return 0;
}
