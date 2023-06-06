#include<stdio.h>
#include <iostream>

int main(void)
{
	int result = 1;
	int N;

	std::cin>>N;
	for(int i=1; i<=N; i++){
		result = result*2;
	}
	std::cout<<result<<std::endl;
}

