#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
  bool isFirst = true;
  int N;
  cin >> N;
  int A[N];
  int calledPlayer[N + 1];
  int callNumber = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];

    if (calledPlayer[i + 1] != -1)
    {
      if (calledPlayer[A[i]] != -1)
      {
        callNumber++;
        calledPlayer[A[i]] = -1;
      }
    }
  }

  cout << N - callNumber << endl;
  for (int i = 1; i <= N; i++)
  {

    if (calledPlayer[i] != -1)
    {
      if (isFirst)
      {
        isFirst = false;
        cout << i;
      }
      else
      {
        cout << " " << i;
      }
    }
  }
  cout << endl;

  return 0;
}