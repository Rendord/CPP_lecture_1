#include <iostream>

int add(int x, int y) {
	return x + y;
}

void evenuneven(int x) {
	if (x % 2 == 0) {
		std::cout << "even" << std::endl;
	}
	else {
		std::cout << "uneven" << std::endl;
	}
}

int square(int base, int exponent) {
	if (exponent != 0) {
		return base * square(base, exponent - 1);
	}
	else {
		return 1;
	}
}

bool isPrime(int number) {
	if (number == 2 || number == 3)
		return true;

	if (number <= 1 || number % 2 == 0 || number % 3 == 0)
		return false;

	for (int i = 5; i * i <= number; i += 6)
	{
		if (number % i == 0 || number % (i + 2) == 0)
			return false;
	}

	return true;
}

int search(int arr[], int length, int value) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}

void bubblesort(int arr[], int size) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < size; i++) {
			if (arr[i] > arr[i + 1]) {
				int swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				swapped = true;
			}
		}
	} while (swapped == true);
}

int GCD(int left, int right) {
	if (left % right != 0) {
		 return GCD(right, (left % right));
	}
	else {
		return right;
	}
	
}

int LCM(int left, int right) {
	int quotient = left * right;
	int divisor = GCD(left,right);
	return quotient / divisor;
}

//int main() {
//	int x[8] = { 1,2,17,4,23,47,88,9 };
//	int y[5] = { 4,3,2,8,1 };
//	std::cout << "Hello world!" << std::endl;
//	std::cout << add(4, 5) << std::endl;
//	evenuneven(5);
//	evenuneven(6);
//	std::cout << square(4, 4) << std::endl;
//	std::cout << isPrime(2011) << std::endl;
//	std::cout << search(x, 8, 10) << std::endl;
//	bubblesort(y, 4);
//	for (int n : y) {
//		std::cout << n << std::endl;
//	}
//	std::cout << GCD(160,16) << std::endl;
//	return 0;
//}