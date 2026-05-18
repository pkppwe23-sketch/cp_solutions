#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        // INPUT ARRAY
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        /*
        ---------------------------------------------------
        STEP 1 : SORT ARRAY
        ---------------------------------------------------

        Example:
        1 1 1 4 4 5
        */

        sort(a.begin(), a.end());

        /*
        ---------------------------------------------------
        STEP 2 : MOVE LARGEST ELEMENT TO FRONT
        ---------------------------------------------------

        Why?

        Prefix maximum contributes in EVERY prefix.

        So if largest element appears early,
        max(prefix) becomes large immediately.

        Example:
        5 1 1 4 4 1
        */

        swap(a[n - 1], a[0]);

        /*
        Sort remaining elements again.

        Final:
        5 1 1 1 4 4
        */

        sort(a.begin() + 1, a.end());

        /*
        ---------------------------------------------------
        STEP 3 : SEPARATE UNIQUE AND DUPLICATE ELEMENTS
        ---------------------------------------------------

        v1 -> stores first occurrence of each value
        v2 -> stores duplicate values

        Why?

        Distinct values help increase MEX.
        Duplicates do NOT help MEX.

        So:
        - put distinct values early
        - put duplicates later
        */

        vector<int> v1, v2;

        for (int i = 1; i < n; i++)
        {
            // duplicate element
            if (!v1.empty() && v1.back() == a[i])
            {
                v2.push_back(a[i]);
            }

            // first occurrence
            else
            {
                v1.push_back(a[i]);
            }
        }

        /*
        ---------------------------------------------------
        STEP 4 : REBUILD ARRAY
        ---------------------------------------------------

        Final structure becomes:

        [largest] [unique elements] [duplicates]

        Example:
        5 1 4 1 1 4
        */

        int l = 0;

        // place unique elements first
        for (int i = 0; i < v1.size(); i++)
        {
            a[++l] = v1[i];
        }

        // place duplicates later
        for (int i = 0; i < v2.size(); i++)
        {
            a[++l] = v2[i];
        }

        /*
        ---------------------------------------------------
        STEP 5 : CALCULATE ANSWER
        ---------------------------------------------------

        For every prefix:

        contribution =
        mex(prefix) + max(prefix)
        */

        map<int, int> mn;

        int ans = 0;

        // current mex
        int mex = 0;

        // current prefix maximum
        int mx = 0;

        for (int i = 0; i < n; i++)
        {
            // add current element into frequency map
            mn[a[i]]++;

            // update maximum
            mx = max(mx, a[i]);

            /*
            Find mex.

            mex = smallest non-present integer
            */

            while (mn[mex])
            {
                mex++;
            }

            // add contribution of this prefix
            ans += mex + mx;
        }

        cout << ans << endl;
    }
}