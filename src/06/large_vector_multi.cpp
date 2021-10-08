#include <unistd.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>

std::vector<int> vec;
std::mutex mut;
int maxNum = 100;
int num = 0;
constexpr int sleepTime = 100;

// Thread Function
void threadFunc(int n) 
{
  while (true) 
  {
    // exclusive process
    mut.lock();
    if (num > maxNum)
      break;
    vec.push_back(num);
    if (num % 10 == 0)
      std::cout << n << " " << num << std::endl;
    num++;
    mut.unlock();

    // concurrent process
    usleep(sleepTime * 1000);
  }
}

int main()
{
  vec.push_back(0);
  int numThread = 10;

  // Start Thread
  for (int i=0; i<numThread; i++) 
  {
    std::thread t(threadFunc, i);
    t.detach();
  }

  // Wait
  while (vec.back()<maxNum)
    sleep(1);

  // Confirm
  int num = 0;
  bool flipped = false;
  for (auto v : vec) {
    if (num > v) flipped = true;
    num = v;
  }

  // Terminate
  if (flipped) std::cout << "Flipped" << std::endl;
  else std::cout << "No Flipped" << std::endl;
  std::cout << "Done" << std::endl;

  return 0;
}
