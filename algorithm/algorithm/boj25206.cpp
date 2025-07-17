#include <iostream>
#include <string>
#include <map>
#include <iomanip> 

using namespace std;

int main() {
	map<string, float> mp =
	{
		{ "A+",	4.5 },
		{ "A0",	4.0 },
		{ "B+",	3.5 },
		{ "B0",	3.0 },
		{ "C+",	2.5 },
		{ "C0",	2.0 },
		{ "D+",	1.5 },
		{ "D0",	1.0 },
		{ "F",	0.0 }
	};
	
	float scoreSum = 0;
	float scoreMul = 0;
	for (int i = 0; i < 20; i++)
	{
		string subjects, grade;
		float score;
		cin >> subjects >> score >> grade;

		if (grade == "P") continue;

		scoreSum += score;
		scoreMul += (score * mp[grade]);
	}

	cout << fixed << setprecision(6) << scoreMul / scoreSum;

}