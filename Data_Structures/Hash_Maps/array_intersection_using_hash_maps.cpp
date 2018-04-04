/// Given two random integer arrays, print their intersection

/// Input:
/// 6
/// 2 6 8 5 4 3 
/// 4
/// 2 3 4 7

/// Output:
/// 2
/// 4
/// 3

/// Complexity : O(n)

/// NOTE : order of printed elements should align with their occurances
///        in first array. NO repeated elements

# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

vector<int> intersection(int *a, int *b, int size1, int size2) {
	vector<int> output;
	unordered_map<int, bool> seen;

	for(int i=0; i<size2; i++)
	{
		seen[b[i]] = false;
	}

	for(int i=0; i<size1; i++)
	{
		if(seen.count(a[i]) > 0)
		{
			output.push_back(a[i]);
		}
		
	}

	return output;

}

int main()
{
	int a[] = {2, 6, 8, 5, 4, 3};
	int b[] = {2, 3, 4, 7};

	vector<int> output = intersection(a, b, 6, 4);

	for(int i =0; i< output.size(); i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}