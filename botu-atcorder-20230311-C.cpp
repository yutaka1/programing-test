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

int goalH = 0;
int goalW = 0;
int happyTSum = 0;

void TakahashiWay(int *graph, int positionH, int positionW, int value, vector<int> &checkNumber)
{
  if (positionH < 0 || positionW < 0 || positionH > goalH || positionW > goalW || find(checkNumber.begin(), checkNumber.end(), value) != checkNumber.end())
  {
    return;
  }

  if (positionH == goalH && positionW == goalW)
  {
    happyTSum++;
    return;
  }

  checkNumber.push_back(value);

  TakahashiWay(graph, positionH + 1, positionW, graph[positionW * (goalH + 1) + positionH + 1], checkNumber);
  TakahashiWay(graph, positionH, positionW + 1, graph[(positionW + 1) * (goalH + 1) + positionH], checkNumber);

  checkNumber.erase(remove(checkNumber.begin(), checkNumber.end(), value), checkNumber.end());
}

int main(void)
{
  int H, W;
  cin >> H >> W;
  int A[H * W];
  goalH = H - 1;
  goalW = W - 1;
  vector<int> checkNumber;

  for (int j = 0; j < W; j++)
  {
    for (int i = 0; i < H; i++)
    {
      cin >> A[j * H + i];
    }
  }

  TakahashiWay(A, 0, 0, A[0], checkNumber);

  cout << happyTSum << endl;

  return 0;
}