#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>


int main(void)
{
	int N,K,X;
	std::cin>>N>>K>>X;

	int A[N];
	int minMoney=0;
	int posiMoney=0;
	int sum = 0;

	for(int i=0;i<N;i++){
		std::cin>>A[i];
	}


	for(int i=1;i<=K;i++){
        minMoney = A[0] - X;
		posiMoney = 0;
		for(int j=0;j<N;j++){
			if((minMoney < 0 && ((A[j] - X) < 0) && (minMoney < (A[j] - X))) 
				|| (minMoney < 0 && ((A[j] - X) > 0))){
           		minMoney = A[j] - X;
				posiMoney = j;
			}
		}
		A[posiMoney] = A[posiMoney] - X;
		if(A[posiMoney] < 0) A[posiMoney] = 0;
	}

	
	for(int j=0;j<N;j++){
       sum += A[j];
	}	


 
    // 標準出力
	std::cout<<sum<<std::endl;

	return 0;
}
