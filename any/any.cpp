#include <iostream>
#include <boost/any.hpp>

int main()
{
  boost::any ptr;
  ptr = 3;
  std::cout << ptr.type().name() << std::endl;
  ptr = std::string("Test string");
  std::cout << ptr.type().name() << std::endl;

  try
  {
	  int i = boost::any_cast<int>(ptr);
  }
  catch (const boost::bad_any_cast e)
  {
	  std::cout << e.what() << std::endl;
  }

  return 0;
}



