/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL;
    struct ListNode* current = NULL;

    int sum;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {//guaranteed to have one node
        // reset 0 each loop through the list
        sum = 0;
        // could be at end of one list
        if (l1 == NULL) {// test for no l1
          // if so skip the math, just take l2
          sum = l2->val;//must be 0 to 9 incl
          l2 = l2->next;
          sum += carry;
          if (sum > 9) {// carry requires math again tho
              carry = sum / 10;
              sum = sum % 10;
          } else {// still have to reset carry
            carry = 0;
          }
        } else if (l2 == NULL) {// l1 but not l2
          sum = l1->val;
          l1 = l1->next;
          sum += carry;
          if (sum > 9) {
              carry = sum / 10;
              sum = sum % 10;
          } else {
             carry = 0;
          }
        } else {// we have both
            sum += l1->val;
            l1 = l1->next;
            sum += l2->val;
            l2 = l2->next;
            sum += carry;// use carry
            carry = sum / 10;// reset carry
            sum = sum % 10;// avoid use of extra remainder var
        }

        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum;//actually remainder
        newNode->next = NULL;

        if (result != NULL) {
            current->next = newNode;
        } else {
            result = newNode;
        }
        current = newNode;
    }

    //carry might have extra
    if (carry > 0) {
        struct ListNode* lastNode = malloc(sizeof(struct ListNode));
        lastNode->val = carry;//actually remainder
        lastNode->next = NULL;
        // guaranteed to have a result
        current->next = lastNode;
    }

    return result;
}
