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
  int T;

  std::cin >> T;

  int N;
  string S;
  int count;

  for (int l = 0; l < T; l++)
  {
    std::cin >> N >> S;

    count = 0;
    int countSize = std::count(S.begin(), S.end(), '1');

    if (countSize % 2 == 1)
    {
      std::cout << -1 << std::endl;
      continue;
    }

    count = countSize / 2;
    if (countSize == 2 && S.find("11") != string::npos)
    {
      if (N == 3)
      {
        count = -1;
      }
      else if (N == 4 && S.find("0110") != string::npos)
      {
        count += 2;
      }
      else
      {
        count += 1;
      }
    }
    std::cout << count << std::endl;
  }

  return 0;
}