# Notes 1

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



  # Notes 2

## Logic
- Traverse the array from left to right.
- If the element is not `1`, add it to `cnt`.
- If the element is `1`, add it only when it is the last element of the array.

---

## Conditions

```cpp
if(a[i] != 1)
```
- Add all elements except `1`.

```cpp
if(a[i] == 1 && i == n-1)
```
- Add `1` only if it is the last element.

---

## Example

Input:
```text
1 2 1 3 1
```

Processing:
- `1` → ignored
- `2` → added
- `1` → ignored
- `3` → added
- `1` → last element, added

Result:
```text
cnt = 6
```

---

## Time Complexity
- `O(n)`
- Single traversal of array.

---

## Space Complexity
- `O(n)`
- Array storage using vector.