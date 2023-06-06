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

    int maxWidth=0;
	int befKey=-1;
    int angleSum=360;	
	int A[N];
	std::map<int,int> clock;
	std::vector<int> keys;

	for(int i=0;i<N;i++){
		std::cin>>A[i];
	}

	clock[360]++;
	clock[0]++;

	// 切れ込みを入れる
	for(int i=0;i<N;i++){
		angleSum += A[i];
		clock[angleSum % 360]++; // 余りが360(*X)との差分になる
	}

	// clockのkeyをkeysに順番に入れていく
    for (auto it = clock.begin(); it != clock.end(); it++) {
        keys.push_back(it->first);
    }
 
	// 最大幅を取得する
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
