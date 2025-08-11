#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<int> st;
void push() {
	int num;
	cin >> num;

	st.push(num);
}

void pop() {
	cout << (st.empty() ? -1 : st.top()) << "\n";
	if (st.empty() == false) st.pop();
}

void size() {
	cout << st.size() << "\n";
}

void empty() {
	cout << (st.empty() ? "1" : "0") << "\n";
}

void top() {
	cout << (st.empty() ? -1 : st.top()) << "\n";
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
		else if (input == "top") top();
	}
}