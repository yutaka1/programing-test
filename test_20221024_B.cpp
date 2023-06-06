#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>


int main(void)
{
	int N;
	std::cin>>N;

	int A[N];
	std::map<int,int> count;
	std::vector<int> keys;

	for(int i=0;i<N;i++){
		std::cin>>A[i];
	}


	for(int i=0;i<N;i++){
		count[A[i]]++; // 
	}

 
    // 標準出力
	std::cout<<count.size()<<std::endl;

	return 0;
}
