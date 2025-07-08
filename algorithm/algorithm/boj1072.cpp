#include<iostream>
#include<cmath>

using namespace std;

long long findZ(long long x, long long y) {
    long long z = (y * 100) / x;
    long long low = 1, high = 1e9;
    long long result = -1;

    if (z >= 99) return result;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long newZ = ((y + mid) * 100) / (x + mid);

        if (newZ > z) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}


int main() {
    long long x, y;
    cin >> x >> y;

    cout << findZ(x, y);
}

