#include <iostream>

using namespace std;

void hanoi(int N, int start, int mid, int end) {
    if (N == 1)
        cout << start << " " << end << "\n";
    else {
        hanoi(N - 1, start, end, mid);
        cout << start << " " << end << "\n";
        hanoi(N - 1, mid, start, end);
    }
}

int main() {
    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";
    hanoi(N, 1, 2, 3);

    return 0;
}