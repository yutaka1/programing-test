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
  int maxNumber = 0;

  cin >> N >> K;
  vector<int> checkNumber;
  vector<int> A(N);
  vector<int> B(K);

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    maxNumber = std::max(maxNumber, A[i]);
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

  bool findDislike = any_of(B.begin(), B.end(), [&](int dislike)
                            { return find(checkNumber.begin(), checkNumber.end(), dislike) != checkNumber.end(); });

  cout << (findDislike ? "Yes" : "No") << endl;

  return 0;
}