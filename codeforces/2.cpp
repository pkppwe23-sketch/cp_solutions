/*
Explanation:

1. The program processes multiple test cases.

2. For each test case:
   - Input the size of array n.
   - Input n integers into vector a.

3. Logic:
   - Traverse the array.
   - If element is NOT equal to 1:
         add it to cnt.
   - If element is 1 and it is the LAST element:
         add it to cnt.

4. All 1's except the last element are ignored.

Example:
   Input:
      1 2 1 3 1

   Processing:
      1  -> ignored
      2  -> added
      1  -> ignored
      3  -> added
      1  -> last element, added

   Result:
      cnt = 2 + 3 + 1 = 6

Time Complexity:
   O(n)

Space Complexity:
   O(n)
*/

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

        // Input array elements
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int cnt = 0;

        // Traverse the array
        for (int i = 0; i < n; i++)
        {
            // Add element if it is not 1
            if (a[i] != 1)
            {
                cnt += a[i];
            }

            // Add 1 only if it is the last element
            if (a[i] == 1 && i == n - 1)
            {
                cnt += a[i];
            }
        }

        cout << cnt << endl;
    }
}