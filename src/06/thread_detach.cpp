#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <mutex>

std::mutex mut;
int num = 0;

void threadFunc(int thr) {
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
}

int main() {
    std::thread t[4];
    for (int thr = 0; thr < 4; thr++) {
        t[thr] = std::thread(threadFunc, thr);
    }
    printf("before detach\n");
    for (int thr = 0; thr < 4; thr++) {
        printf("thread %d detached\n", thr);
        t[thr].detach();
    }
    printf("after detach\n");
    return 0;
}
