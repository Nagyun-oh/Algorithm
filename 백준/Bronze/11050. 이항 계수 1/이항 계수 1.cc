#include <iostream>

int Factorial(int n)
{
	int rec = 1;
	for (int i = n; i >= 1; i--)
	{
		rec *= i;
	}
	return rec;
}

int main()
{	
	int n, k;
	std::cin >> n >> k; // nCk

	int result = 0;

	int n_Factorial = Factorial(n); //n!
	int n_k_Factorial = Factorial(n - k); // (n-k)!
	int k_Factorial = Factorial(k);  // k!

	// n!/(n-k)!*k!
	result = n_Factorial / (n_k_Factorial * k_Factorial);
	std::cout << result;


	
	return 0;
}