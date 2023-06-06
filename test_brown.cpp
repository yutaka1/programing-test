#include<stdio.h>
#include <iostream>
#include <math.h>

int main(void)
{
	int N;
	int X;
	int Y;
	long RedStoneNumber = 1;
	long BlueStoneNumber = 0;
	std::cin>>N>>X>>Y;
	
	long NextRedStone=0;
	long NextBlueStone=0;

	for(int i=1;i<N;i++){
		//赤い石の変換
		NextRedStone = RedStoneNumber;
		BlueStoneNumber += (RedStoneNumber * X);

		//青い石の変換
		NextRedStone += BlueStoneNumber;
                NextBlueStone = BlueStoneNumber * Y;
		
		RedStoneNumber = NextRedStone;
		BlueStoneNumber = NextBlueStone;
	}

	std::cout<<BlueStoneNumber<<std::endl;

	return 0;
}
