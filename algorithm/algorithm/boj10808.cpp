#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main() {
	string str;
	vector<int> v;
	v.resize(26);

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		int value = str[i] - 'a';

		v[value]++;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

}