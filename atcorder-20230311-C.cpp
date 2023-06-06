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

int A[15][15];
int goalH = 0;
int goalW = 0;
int happyTSum = 0;
set<int> vis;

void TakahashiWay(int h, int w)
{
  if (h > goalH || w > goalW || vis.count(A[h][w]))
  {
    return;
  }

  if (h == goalH && w == goalW)
  {
    happyTSum++;
    return;
  }

  vis.insert(A[h][w]);
  TakahashiWay(h + 1, w);
  TakahashiWay(h, w + 1);
  vis.erase(A[h][w]);
}

int main(void)
{
  int H, W;
  int maxRoad = 0;
  cin >> H >> W;
  goalH = H;
  goalW = W;
  vector<int> checkNumber;
  vector<pair<int, int>> rememberHW;

  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      cin >> A[i][j];
    }
  }

  TakahashiWay(1, 1);

  cout << happyTSum << endl;

  return 0;
}