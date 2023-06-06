#include<stdio.h>
#include <iostream>
#include <math.h>
#include <map>


int main(void)
{
	int N;
	long W;

	std::cin>>N>>W;
	
	long A[N];
	for(int i=0;i<N;i++){
		std::cin>>A[i];
	}

	std::map<int,int> salary;

	// おもりを一つのみ選択するとき
	for(int i=0;i<N;i++){
		if(A[i]<=W){
			salary[A[i]]++;
		}
	}

	// おもりを二つ選ぶ時
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if((A[i]+A[j])<=W){
				salary[A[i]+A[j]]++;
			}
		}
	}
   
 	// おもりを三つ選ぶ時
     for(int i=0;i<N-2;i++){
                for(int j=i+1;j<N-1;j++){
                	for(int l=j+1;l<N;l++){			
                        	if((A[i]+A[j]+A[l])<=W){
								salary[A[i]+A[j]+A[l]]++;
                        	}
			}
                }
        }               
    // 標準出力
	std::cout<<salary.size()<<std::endl;

	return 0;
}
