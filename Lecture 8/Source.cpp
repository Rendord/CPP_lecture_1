#include <iostream>
#include <cstdlib>
#include "time.h"


 
int* randomnumbers(int n)
{

	time_t seconds = time(0);
	srand(seconds);
	int* randomnumbers = new int[n];
	for (int i = 0; i < n; i++)
	{
		randomnumbers[i] = (rand() % n) + 1;
	}
	return randomnumbers;

}

int main()
{
	int* randomnumberlist = randomnumbers(8);
	for (int i = 0; i < 8; i++) {
		std::cout << randomnumberlist[i] << " ";
	}
	std::cout << std::endl;

	
	
}