#include "BoxV2.h"

int main()
{
  Box a(2,3,Box::Filled);
  cout << a.print(std::cout) << endl;
  return 0;
}
