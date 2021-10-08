#include <thread>
#include <stdio.h>
#include <unistd.h>

int cnt = 0;

void func(int j) {
  for (int i=j; i<3; i++) {
    cnt++;
    std::thread t(func, i+1);
    t.detach();
    sleep(3);
    printf("Thread: This=%d, j=%d, &j=%p, cnt=%d, Parent=%d, i=%d, &i=%p\n", getpid(), j, &j, cnt, getppid(), i, &i);
  }
  sleep(3);
  printf("Done:   This=%d, j=%d, &j=%p, cnt=%d\n", getpid(), j, &j, cnt);
}

int main()
{
  func(0);
  printf("fin.\n");
	
  return 0;
}
