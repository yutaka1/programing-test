#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using std::endl;
using std::map;
using std::string;

int main(void)
{
  string S;
  std::cin >> S;

  int len = S.length();

  for (int i = 0; i < len / 2; i += 1)
  {
    char temp = S[2 * i - 1 + 1];
    S[2 * i - 1 + 1] = S[2 * i + 1];
    S[2 * i + 1] = temp;
  }

  std::cout << S << endl;

  return 0;
}