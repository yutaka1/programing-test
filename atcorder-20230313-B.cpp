#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(void)
{
  int N, K;
  int A[100];
  int B[100];
  int maxNumber = 0;
  bool findDislike = false;
  vector<int> checkNumber;

  cin >> N >> K;

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    if (A[i] > maxNumber)
    {
      maxNumber = A[i];
    }
  }

  for (int i = 0; i < K; i++)
  {
    cin >> B[i];
  }

  for (int i = 0; i < N; i++)
  {
    if (A[i] == maxNumber)
    {
      checkNumber.push_back(i + 1);
    }
  }

  for (int i = 0; i < K; i++)
  {
    if (find(checkNumber.begin(), checkNumber.end(), B[i]) != checkNumber.end())
    {
      findDislike = true;
    }
  }

  if (findDislike)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}