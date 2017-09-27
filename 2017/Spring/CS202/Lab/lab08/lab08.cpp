#include "lab08.h"

int main()
{
  try
  {
    Player player;
  }
  catch(const exception& e)
  {
    cout << e.what() << endl;
  }
  return 0;
}
