#include <iostream>

using namespace std;

int factorial(int n) {

  int val = 0;

  if(n == 1 || n == 0) {
    return 1;
  } else {
    val = n*factorial(n-1);
  }

  return val;
};

int fibonaccai(int n) {

  int f0 = 0, f1 = 1;
  int val = 0;

  if( n == 0 ) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  else {
    val = fibonaccai(n-1) + fibonaccai(n-2);
  }

  return val;

};

int main() {
  //
  // int val = 5;
  //
  // cout << factorial(5) << endl;
  // cout << factorial(0) << endl;
  // cout << factorial(1) << endl;


  cout << fibonaccai(5) << endl;
  cout << fibonaccai(0) << endl;
  cout << fibonaccai(1) << endl;
  cout << fibonaccai(12) << endl;

  return 0;
}
