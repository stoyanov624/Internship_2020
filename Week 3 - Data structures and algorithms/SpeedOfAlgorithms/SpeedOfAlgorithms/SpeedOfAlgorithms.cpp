

#include <iostream>

void f1 (size_t n) { // t: 0(n)
	for (size_t i = 0; i < n; i++)
	{
		std::cout << i;
	}
}

void f2 (size_t n) { // 0(n^2)
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			std::cout << "J";
		}
	}
}

void f3(size_t n) { // 0(n^2)
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < n; j++) {
			std::cout << "J";
		}
	}
}

bool isPrime(size_t n) {
	for (size_t i = 2; i*i < n; i++)
	{
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int fac(int n) { // t: O(n), m: O(n)
	if (n == 0) return 1;
	return n * fac(n - 1);
}

int facMem[1024] = {};
int fac1(int n) { // t: O(1), m: O(n)
	if (n == 0) return 1;
	if (facMem[n] != 0) return facMem[n];
	return facMem[n] = n * fac(n - 1);
}

int fibMem[1024] = { 0 }; //memoization
int fib(int n) {
	if (n == 0 || n == 1) return n;
	if (fibMem[n] != 0) return fibMem[n];
	return fibMem[n] = fib(n - 1) + fib(n - 2);
}




int main()
{
	std::cout << fib(23);
}
