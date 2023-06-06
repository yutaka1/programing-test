#include<stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

struct edge {
	int to;
	int cost;
}


int main(void)
{
	int N;
	int M;

	std::cin>>N>>M;
	
	int u;
	int v;
	int c;

	vector<int> dist(N,INF);
	dist[0] = 0;    

                     
	for(int i=0;i<M;i++){
		cin>>u>>v>>c;
		dist[u].push_back(edge(v,c));
	}

	

	
    // 標準出力
	std::cout<<salary.size()<<std::endl;

	return 0;
}
