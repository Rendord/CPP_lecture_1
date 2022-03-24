#include <iostream>
#include <cstdlib>

int CompareWithoutPointers(int a, int b) {
    if (a > b) {
        return 1;
    }
    else if (a < b) {
        return -1;
    }
    else {
        return 0;
    }
}

int compareChar(const void* a, const void* b)
{
    if (*(char*)a < *(char*)b) return -1;
    else if (*(char*)a == *(char*)b) return 0;
    else return 1;
}

int CompareWithPointers(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int CompareWithIntPointers(int* a, int* b) {
    if (*a == *b)
        return 0;
    else if (*a < *b)
        return -1;
    else
        return  1;
}

int CompareAsPerSlides(const void* pa, const void* pb) {
    int* a = (int*)pa;
    int* b = (int*)pb;

    if (*a == *b)
        return 0;
    else if (*a < *b)
        return -1;
    else
        return  1;
}

void SwapPointers(int** a, int** b) {
	int* swappointer = *a;
	*a = *b;
	*b = swappointer;
}

void PascalsTriangle(int** pointer, int n) {
	pointer = new int* [n];
	for (int i = 0; i < n; i++)
	{
		pointer[i] = new int [i + 1];
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0 || j == i) {
				pointer[i][j] = 1;
				std::cout << pointer[i][j];
				
			}
			else { 
				pointer[i][j] = pointer[i - 1][j - 1] + pointer[i - 1][j];
				std::cout << pointer[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void PrintPascalsTriangle(int** pointer, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			std::cout << pointer[i][j];
		}
		std::cout << std::endl;
	}
}

int main() 
{
    std::cout << "Hello World!" << std::endl;

	int a[] = { 7,1,5,2,3 };
	char works[] = "this does work though?";

	std::cout << a << std::endl;
	std::cout << works << std::endl;
	
	//print header text
	std::cout << "\n" << "Quicksort with method in the slides: " << std::endl;
	//as per slides
	for (int i = 0; i < 5; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	qsort((void*)a, 5, sizeof(int), CompareAsPerSlides);

	for (int i = 0; i < 5; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	//new array
	int b[] = { 7,1,5,2,3 };
	//print header text
	std::cout << "\n" << "Quicksort with c++ reference compare: " << std::endl;
	//as per slides
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;

	qsort((void*)b, 5, sizeof(int), CompareWithPointers);

	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;


	//make character array
	char c[] = { 'z','x','a','f','y' };
	char d[] = "zxafy";
	//print header text
	std::cout << "\n" << "Quicksort with compare characters: " << std::endl;
	//as per slides
	for (int i = 0; i < 5; i++)
	{
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;

	qsort((void*)c, 5, sizeof(char), compareChar);

	for (int i = 0; i < 5; i++)
	{
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;

	int abe = 3;
	int betsy = 4;

	int* patrick = &abe;
	int* queen = &betsy;

	std::cout << "patrick: " << patrick << " queen: " << queen << std::endl;

	
	int* dk = *&queen;
	*&queen = *&patrick;
	*&patrick = dk;

	
	std::cout << dk << std::endl;
	
	std::cout << "patrick: " << patrick << " queen: " << queen << std::endl;

	int* p, *q, *f;

	p = new int();
	q = new int();

	*p = 2;
	*q = 3;

	std::cout << *p << " " << *q << std::endl;

	delete p, q, f;

	
	int* z[5]; 

	int* j;


	int* pascal;
	int depth = 6;

	PascalsTriangle(&pascal, 6);
	PrintPascalsTriangle(&pascal, 6);

	//*j[0] = 5;

	//read access violation
	//std::cout << *p << " " << *q << std::endl;



	////print header text
	//std::cout << "\n" << "Quicksort with int pointers: " << std::endl;
	////as per slides
	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << a[i] << " ";
	//}
	//std::cout << std::endl;

	//qsort((void*)a, 5, sizeof(int), CompareWithIntPointers);

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << a[i] << " ";
	//}
	//std::cout << std::endl;

	////reset list
	//a[0] = 7;
	////print header text
	//std::cout << "\n" << "Quicksort without pointers: " << std::endl;
	////without pointers
	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << a[i] << " ";
	//}
	//std::cout << std::endl;

	//qsort((void*)a, 5, sizeof(int), CompareWithoutPointers);

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << a[i] << " ";
	//}
	//std::cout << std::endl;




}