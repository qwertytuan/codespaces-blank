#include <iostream>
using namespace std;

#include "778.hpp"

int main()
  {
  string pwd;
  cout << "Please enter a passcode> ";

  echo( false );
  getline( cin, pwd );
  echo( true );

  cout << "\nYour password is \"" << pwd << "\"\n";
  return 0;
  }