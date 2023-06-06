#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>


int main(void)
{
	int N;
    int maxWidth=0;
	int befKey=-1;
	std::cin>>N;
	
	int A[N];
	for(int i=0;i<N;i++){
		std::cin>>A[i];
	}


    int angleSum=360;
	std::map<int,int> clock;
	std::vector<int> keys;
	clock[360]++;
	clock[0]++;
	// 切れ込みを入れる
	for(int i=0;i<N;i++){
		angleSum += A[i]; 
		if(angleSum<=360){
			clock[angleSum]++;
		}
		else{
        	angleSum = angleSum - 360;
			clock[angleSum]++;
		}
	}
    for (auto it = clock.begin(); it != clock.end(); it++) {
        keys.push_back(it->first);
    }
 
    for (const auto &key: keys) {
		if(befKey >= 0 && maxWidth <= (key - befKey)){
			maxWidth = key - befKey;
		}
		befKey = key;
    }

    // 標準出力
	std::cout<<maxWidth<<std::endl;

	return 0;
}
