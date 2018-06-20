#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for(int i = -n + 1; i < n; i++)
	{
		for(int j = 0; j < abs(i); j++)
			cout << " ";
		for(int j = 0; j < 2 * n - 1 - 2 * abs(i); j++)
			cout << "*";
		cout << endl;
	}

	return 0;
}
