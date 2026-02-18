#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    set<char> st(s.begin(), s.end());
    vector<char> chars(st.begin(), st.end());
    sort(chars.begin(), chars.end());

    if (k > n) {
        cout << s;
        for (int i = 0; i < k - n; i++)
            cout << chars[0];
        cout << endl;
        return 0;
    }

    string ans = s.substr(0, k);

    for (int i = k - 1; i >= 0; i--) {
        auto it = upper_bound(chars.begin(), chars.end(), ans[i]);

        if (it != chars.end()) {
            ans[i] = *it;
            for (int j = i + 1; j < k; j++)
                ans[j] = chars[0];
            cout << ans << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
