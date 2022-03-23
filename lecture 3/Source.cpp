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

int main() 
{
    std::cout << "Hello World!" << std::endl;
}