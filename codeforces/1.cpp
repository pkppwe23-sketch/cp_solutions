/*
Explanation:

1. We take the number of test cases t.

2. For every test case:
   - Input a string s.
   - Count how many times two adjacent characters are equal.

3. Example:
      s = "aabbcc"

   Adjacent equal pairs are:
      a == a
      b == b
      c == c

   So count = 3.

4. If count becomes greater than 2:
      print "NO"
   otherwise:
      print "YES"

Time Complexity:
   O(n) for each test case
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        // Stores count of adjacent equal characters
        int cnt = 0;

        // Traverse the string
        for(int i = 0; i < n - 1; i++)
        {
            // Check if current character
            // is same as next character
            if(s[i] == s[i + 1])
            {
                cnt++;
            }
        }

        // If more than 2 equal adjacent pairs exist
        if(cnt > 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
