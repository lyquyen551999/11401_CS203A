# Add Two Numbers

```c++
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode* dummyHead = new ListNode(0); // Nút giả để giữ gốc
          ListNode* curr = dummyHead;           // Con trỏ để xây dựng danh sách mới
          int carry = 0;                        // Biến nhớ
  
          while (l1 != nullptr || l2 != nullptr || carry != 0) {
              // Lấy giá trị từ l1 và l2, nếu danh sách đã hết thì lấy 0
              int x = (l1 != nullptr) ? l1->val : 0;
              int y = (l2 != nullptr) ? l2->val : 0;
              
              // Tính tổng và biến nhớ
              int sum = x + y + carry;
              carry = sum / 10;
              
              // Tạo nút mới với chữ số hàng đơn vị
              curr->next = new ListNode(sum % 10);
              curr = curr->next;
              
              // Di chuyển sang nút tiếp theo trong l1 và l2
              if (l1 != nullptr) l1 = l1->next;
              if (l2 != nullptr) l2 = l2->next;
          }
          
          return dummyHead->next; // Trả về nút sau nút giả
      }
```
