#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0;
    long long mx = 0;

    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    if(sum % 2 == 0 && mx <= sum / 2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
