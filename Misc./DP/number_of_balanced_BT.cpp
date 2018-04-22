// Given an integer h, find the possible number of 
// balanced binary trees of height h. You just need
// to return the count of possible binary trees which 
// are balanced.

// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315


// Recursive Solution ( Time:O(2^n) )

#include <iostream>
#include <cmath>
using namespace std;

int balancedBTs(int h) {

	// Base Case
	if(h <= 1){
		return 1;
	}

	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);

	int temp1 = x*x % mod;
	int temp2 = 2*x*y % mod;
	int ans = (temp1 + temp2) % mod;

	return ans;
}

// Using Bottom-down approach ( Time:O(n) )

int binaryTreesOfHeightH(int h) {
	int *a = new int[h + 1];
	if(h == 0) {
		return 1;
	}

	if(h == 1) {
		return 1;
	}
	a[0] = 1;
	a[1] = 1;

	int mod = (int) (pow(10, 9)) + 7;
	for(int i=2; i<=h; i++) {
		long temp1 = ((long)(a[i-1]) * a[i-1]) % mod;
		long temp2 = (2 * (long)(a[i-1]) * a[i-2]) % mod;

		a[i] = (temp1 + temp2) % mod;
	}

	int ans = a[h];

	delete [] a;

	return ans;
}