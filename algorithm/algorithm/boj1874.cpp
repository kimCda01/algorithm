#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;
    vector<int> data;
    vector<char> res;
    int n;

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        data.push_back(value);
    }

    int curValue = 1;
    bool isClear = true;
    for (int i = 0; i < n; i++) 
    {
        int target = data[i];
        while (curValue <= target) 
        {
            st.push(curValue++);
            res.push_back('+');
        }

        if (!st.empty() && st.top() == target) 
        {
            st.pop();
            res.push_back('-');
        }
        else 
        {
            isClear = false;
            break;
        }
    }

    if (!isClear) 
    {
        cout << "NO";
    }
    else 
    {
        for (char val : res) 
        {
            cout << val << "\n";
        }
    }
}
