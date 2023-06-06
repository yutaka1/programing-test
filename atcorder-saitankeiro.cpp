#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
constexpr long long INF = (1LL << 60);

struct Edge
{
  // 行先
  int to;

  // コスト
  int cost;
};

using Graph = vector<vector<Edge>>;
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph &graph, std::vector<long long> &distances, int startIndex)
{
  // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
  // デフォルトの priority_queue は降順に取り出すため std::greater を使う
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
  q.emplace((distances[startIndex] = 0), startIndex);

  while (!q.empty())
  {
    const long long distance = q.top().first;
    const int from = q.top().second;
    q.pop();

    // 最短距離でなければ処理しない
    // 同じ出発地点から考えた時に最短の経路以外は弾くようにする
    if (distances[from] < distance)
    {
      continue;
    }

    // 現在の頂点からの各辺について
    for (const auto &edge : graph[from])
    {
      // to までの新しい距離
      const long long d = (distances[from] + edge.cost);

      // d が現在の記録より小さければ更新
      // 同じ経路の行き先に別の角度から行く時に、コストが大きくなるなら処理しない
      if (d < distances[edge.to])
      {
        q.emplace((distances[edge.to] = d), edge.to);
      }
    }
  }
}

int main(void)
{
  int N, M;
  int StartIndex = 0;
  std::cin >> N >> M;
  Graph graph(N);

  while (M--)
  {
    int s, t, d;
    std::cin >> s >> t >> d;
    graph[s].push_back({t, d});
  }
  vector<long long> distances(N, INF);

  Dijkstra(graph, distances, StartIndex);

  cout << distances.back() << endl;

  // for (const auto &distance : distances)
  // {
  //   if (distance == INF)
  //   {
  //     std::cout << "INF\n";
  //   }
  //   else
  //   {
  //     std::cout << distance << '\n';
  //   }
  // }

  // dst[0] = 0;

  // for (int i = 0; i < M; i++)
  // {
  //   std::cin >> es[i].from >> es[i].to >> es[i].cost;
  // }
}