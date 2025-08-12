#include<iostream>
#include<string>
#include<queue>

using namespace std;

queue<int> q;
void push() {
	int num;
	cin >> num;

	q.push(num);
}

void pop() {
	cout << (q.empty() ? -1 : q.front()) << "\n";
	if (q.empty() == false) q.pop();
}

void size() {
	cout << q.size() << "\n";
}

void empty() {
	cout << (q.empty() ? "1" : "0") << "\n";
}

void front() {
	cout << (q.empty() ? -1 : q.front()) << "\n";
}

void back() {
	cout << (q.empty() ? -1 : q.back()) << "\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		if (input == "push") push();
		else if (input == "pop") pop();
		else if (input == "size") size();
		else if (input == "empty") empty();
		else if (input == "front") front();
		else if (input == "back") back();
	}
}