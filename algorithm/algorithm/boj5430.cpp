#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        deque<int> dq;
        int n;
        string str, arr, numStr;
        cin >> str >> n >> arr;


        for (char ch : arr) {
            if (isdigit(ch)) {
                numStr += ch;
            }
            else if (!numStr.empty()) {
                dq.push_back(stoi(numStr));
                numStr.clear();
            }
        }

        bool isReversed = false;
        bool isError = false;

        for (char cmd : str) {
            if (cmd == 'R') {
                isReversed = !isReversed;
            }
            else if (cmd == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                }
                if (isReversed) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (isError) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if (isReversed) {
                for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                    cout << *it;
                    if (it + 1 != dq.rend()) cout << ",";
                }
            }
            else {
                for (auto it = dq.begin(); it != dq.end(); ++it) {
                    cout << *it;
                    if (it + 1 != dq.end()) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
}
