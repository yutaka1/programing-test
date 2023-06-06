#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>


int main(void)
{
	int A,B,C,D,E,F,X;
	std::cin>>A>>B>>C>>D>>E>>F>>X;

	int tDis=0;
  int tTime=0;
  bool isTRest = false;
	int aDis=0;
  int aTime=0;
  bool isARest = false;

	for(int i=1;i<=X;i++){
    tTime++;

    if(isTRest){
      if(tTime == C){
        isTRest = false;
        tTime = 0;
      }
      continue;
    }

    if(tTime % A == 0){
      isTRest = true;
      tTime = 0;
    }

    tDis += B;
	}

  for(int i=1;i<=X;i++){
    aTime++;

    if(isARest){
      if(aTime == F){
        isARest = false;
        aTime = 0;
      }
      continue;
    }

    if(aTime % D == 0){
      isARest = true;
      aTime = 0;
    }

    aDis += E;
	}

  if(tDis == aDis) {
    std::cout<<"Draw"<<std::endl;
  }
  else if(tDis > aDis)
  {
    std::cout<<"Takahashi"<<std::endl;
  }
  else{
    std::cout<<"Aoki"<<std::endl;
  }
	
	return 0;
}
