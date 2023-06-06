#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>

using std::endl;
using std::map;
using std::string;

string *compare(int x, int N, string S[], map<char, int> alpahebetMap)
{
  string tmp;
  int sizeA;
  int sizeB;
  int size;

  // 文字の種類の分だけ回す
  for (int i = 0; i < N - 1; i++)
  {

    sizeA = S[i].length();
    sizeB = S[i + 1].length();
    if (sizeA >= sizeB)
      size = sizeB;
    else
      size = sizeA;
    // 　文字の場所の比較
    for (int j = 0; j <= size; j++)
    {
      if (j == size && size == sizeB)
      {
        tmp = S[i];
        S[i] = S[i + 1];
        S[i + 1] = tmp;
        break;
      }

      if (alpahebetMap[S[i][j]] > alpahebetMap[S[i + 1][j]])
      {
        tmp = S[i];
        S[i] = S[i + 1];
        S[i + 1] = tmp;
        break;
      }
      else if (alpahebetMap[S[i][j]] == alpahebetMap[S[i + 1][j]])
      {
        continue;
      }
      else
      {
        break;
      }
    }
  }

  if (x < N - 1)
    compare(x + 1, N, S, alpahebetMap);

  return S;
}

int main(void)
{
  char X[26];
  int N;
  std::cin >> X >> N;

  string S[N];
  map<char, int> alpahebetMap;

  for (int i = 0; i < N; i++)
  {
    std::cin >> S[i];
  }

  for (int i = 0; i < 26; i++)
  {
    alpahebetMap.insert(std::make_pair(X[i], i));
  }

  string *Answer = compare(0, N, S, alpahebetMap);
  // 標準出力
  for (int i = 0; i < N; i++)
  {
    std::cout << Answer[i] << std::endl;
  }

  return 0;
}
