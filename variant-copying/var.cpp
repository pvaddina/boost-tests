#include <iostream>
#include <boost/variant.hpp>
#include <string>

template <typename T>
struct DType
{
  DType() { std::cout << "In default constructor:v=" << v << std::endl; }
  DType(const T& _v) : v(_v) { std::cout << "Constructing with value=" << v << std::endl; }
  ~DType() { std::cout << "Destroying the object with value=" << v << std::endl;  }
  void Print() const 
  { 
    std::cout << "Current Value = " << v << std::endl; 
  }
  void Set(T _v) { v = _v; }
  //private:
    DType(const DType& t)
    {
      std::cout << "Copy an object with value=" << t.v << std::endl;
      v = t.v;
    }
  private:
    T v;
};

typedef DType<int> IntTyp;
typedef DType<std::string> StrTyp;
typedef DType<double> DoubTyp;
typedef boost::variant<IntTyp, StrTyp, DoubTyp> MyTyp;

void IntTypTester(MyTyp& t)
{
  t = IntTyp(456);
  boost::get<IntTyp>(t).Print();
}

void StrTypTester(MyTyp& t)
{
  t = StrTyp("This is a string");
  boost::get<StrTyp>(t).Print();
}

void DoubTypTester(MyTyp& t)
{
  t = DoubTyp(456.435);
  boost::get<DoubTyp>(t).Print();
}

int main()
{
  boost::variant<IntTyp, StrTyp, DoubTyp> t1;
  std::cout << "t1 is initialized" << std::endl;
  IntTypTester(t1);
  std::cout << "####################################################" << std::endl;

  boost::variant<IntTyp, StrTyp, DoubTyp> t2;
  std::cout << "t2 is initialized" << std::endl;
  StrTypTester(t2);
  std::cout << "####################################################" << std::endl;

  boost::variant<IntTyp, StrTyp, DoubTyp> t3;
  std::cout << "t3 is initialized" << std::endl;
  DoubTypTester(t3);
  return 0;
};



