#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = n / 5 + n / 25 + n / 125;

	cout << result;

	return 0;
}