
# Two Sum

```c++
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap; // Lưu {giá trị: chỉ số}
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Kiểm tra xem số còn thiếu có trong map chưa
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Lưu số hiện tại vào map để các số sau có thể tìm thấy
            numMap[nums[i]] = i;
        }
        
        return {}; // Trường hợp không tìm thấy (theo đề bài là luôn có 1 đáp án)
    }
```
