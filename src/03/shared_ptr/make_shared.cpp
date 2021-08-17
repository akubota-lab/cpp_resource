#include <stdlib.h>
#include <memory>
#include <iostream>

static const char *log_title = nullptr ;

void *operator new (std::size_t size)
{
  void *ptr = malloc(size) ;
  if (log_title) std::cout << log_title << ": new " << ptr << "(" << size << "bytes)" << std::endl ;
  return ptr ;
}

void operator delete(void *ptr)
{
  if (log_title) std::cout << log_title << ": delete " << ptr << std::endl ;
  free(ptr) ;
}

int main()
{
  log_title = "std::shared_ptr<int>(new int())" ;
  {
    auto ptr = std::shared_ptr<int>(new int()) ;
  }

  log_title = "std::make_shared<int>()" ;
  {
    auto ptr = std::make_shared<int>() ;
  }
  log_title = nullptr ;
  return 0 ;
}