# Notes

## Logic
- Traverse the string from left to right.
- Compare adjacent characters:
  ```cpp
  s[i] == s[i+1]
  ```
- If both are equal, increment `cnt`.

---

## Condition
- If `cnt > 2`
  - Output: `NO`
- Otherwise
  - Output: `YES`

---

## Example

Input:
```text
aabbcc
```

Adjacent equal pairs:
- `a == a`
- `b == b`
- `c == c`

So:
```text
cnt = 3
```

Output:
```text
NO
```

---

## Time Complexity
- `O(n)`  
  (Single traversal of string)

---

## Space Complexity
- `O(1)`  
  (Constant extra space)