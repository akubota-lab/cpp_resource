#include <unistd.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>

std::vector<int> vec;
int maxNum = 100;
constexpr int sleepTime = 100;

int main()
{
  // Start
  for (int i=0; i<maxNum; i++) 
  {
    // exclusive process
    vec.push_back(i);
    if (i % 10 == 0)
      std::cout << i << std::endl;

    // concurrent process
    usleep(sleepTime * 1000);
  }

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
