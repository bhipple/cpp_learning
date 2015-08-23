// Some short notes on C++ type deduction from Scott Meyers' talk
// at cppcon 2014
//
#include <iostream>

template<typename T>
class TD;

template<typename T>
void f(T& param)
{
    TD<T> tType;
    TD<decltype(param)> paramType;
}

int main()
{
  /*
   This template function can be used to determine what Template type
   parameter was deduced during instantiation. It will cause a compiler
   error that displays the deduced types.
  */

  int x = 5;
  const int& rx = x;
  auto y = rx;

  // For example, this displays:
  // error: implicit instantiation of undefined template 'TD<int &>'
  //f(x);

  // Meanwhile, this one shows TD<const int &>
  //f(rx);

  // Displays TD<int> to show the type of an auto variable
  //TD<decltype(y)> yType;

  /* If we need to find the type of something at runtime, we can
     #include <boost/type_index.hpp>
     Do not use the standard's typeid function, as it's required by the C++ standard
     to give you the wrong answwer (it strips off const/volatile/reference)!
  */

}
