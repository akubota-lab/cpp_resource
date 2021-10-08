#include <stdio.h>
#include <omp.h> 
#include <unistd.h>

int main() {
    printf("Threads: %d\n", omp_get_max_threads());

#pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        printf("thread = %d, i = %2d\n", omp_get_thread_num(), i);
        sleep(2);
    }
    return 0;
}
