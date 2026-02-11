# Longest Substring Without Repeating Characters

```c++
    int lengthOfLongestSubstring(string s) {
    // Mảng lưu vị trí cuối cùng của mỗi ký tự, khởi tạo là -1
        vector<int> charIndex(128, -1);
        
        int maxLength = 0;
        int left = 0; // Cạnh trái của cửa sổ
        
        for (int right = 0; right < s.length(); right++) {
            // Nếu ký tự này đã xuất hiện, nhảy 'left' tới vị trí sau lần xuất hiện trước đó
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            
            // Cập nhật vị trí mới nhất của ký tự
            charIndex[s[right]] = right;
            
            // Tính độ dài cửa sổ hiện tại (right - left + 1) và cập nhật maxLength
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
```
