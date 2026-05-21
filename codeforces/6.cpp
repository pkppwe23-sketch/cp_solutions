#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<int> p(n);

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            int l = 0, r = 0;

            // l = number of elements greater than p[i] on the left side
            // If we keep a[i] = p[i], these pairs become inversions
            for (int j = 0; j < i; j++)
            {
                if (p[j] > p[i])
                {
                    l++;
                }
            }

            // r = number of elements greater than p[i] on the right side
            // If we choose a[i] = 2*n - p[i], these pairs become inversions
            for (int j = i + 1; j < n; j++)
            {
                if (p[j] > p[i])
                {
                    r++;
                }
            }

            // For every position we independently choose the better option:
            // either keep p[i] or mirror it.
            // We add the minimum inversions contributed by this element.
            ans += min(l, r);
        }

        cout << ans << endl;
    }
}