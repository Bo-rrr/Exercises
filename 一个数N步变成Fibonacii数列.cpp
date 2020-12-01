#include <iostream>
using namespace std;
 
int Fib(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}
 
 
int Min_step_To_Fib(int num) {
	int n = 0;
	int left = 0;
	int right = 0;
	while (1) {
		if (Fib(n) < num) {
			 left = num - Fib(n);
		}
		else {
			 right = Fib(n) - num;
			break;
		}
		n++;
	}
	if (left < right) {
		return left;
	}
	return right;
}
 
int main() {
	int n;
	cin >> n;
	cout << Min_step_To_Fib(n);
	system("pause");
	return 0;
