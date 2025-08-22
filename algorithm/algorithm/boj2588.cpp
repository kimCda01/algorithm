#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int m100, m10, m1;
	m100 = m / 100;
	m10 = (m % 100) / 10;
	m1 = (m % 10);

	cout << n * m1 << "\n";
	cout << n * m10 << "\n";
	cout << n * m100 << "\n";
	cout << n * m;

}