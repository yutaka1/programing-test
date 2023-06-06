#include <stdio.h>
#include <iostream>


int main(void)
{
	std::string A;
	std::cin>>A;

	for(int i=0;i<3;i++){
		if(A.substr(i, 3) == "ooo"){
			std::cout<<"o"<<std::endl;
			return 0;
		}
		else if(A.substr(i, 3) == "xxx"){
			std::cout<<"x"<<std::endl;
			return 0;
		}
	}
	std::cout<<"draw"<<std::endl;
	return 0;
}              
