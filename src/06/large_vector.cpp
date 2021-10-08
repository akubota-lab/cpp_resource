#include <unistd.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::vector<int> vec;
std::mutex mut;
int maxNum = 1000000;

void pushVector(int n) 
{
  int num;
  while (vec.back()<maxNum) 
  {
    mut.lock();
    num = vec.back();
    if (num + 1 > maxNum)
      break;
    vec.push_back(num+1);
    if (num+1 % 100)
      std::cout << n << " " << vec.back() << std::endl;
    mut.unlock();
  }
}

int main()
{
  vec.push_back(0);
  int cnt = 0;
//  while (vec.back()<maxNum) 
//  {
//    vec.push_back(cnt);
//    cnt++;
//    if (num+i % 100)
//      std::cout << n << " " << vec.back() << std::endl;
//  }
  while (vec.back()<maxNum) 
  {
    std::thread t(pushVector, cnt);
    t.detach();
    cnt++;
    if (cnt > 10)
      break;
  }
  while (vec.back()<maxNum)
    sleep(5);
  int num = 0;
  bool flipped = false;
  for (auto v : vec) {
    if (num > v) flipped = true;
    num = v;
  }
  if (flipped) std::cout << "Flipped" << std::endl;
  else std::cout << "No Flipped" << std::endl;
  std::cout << "Done" << std::endl;
  return 0;
}
