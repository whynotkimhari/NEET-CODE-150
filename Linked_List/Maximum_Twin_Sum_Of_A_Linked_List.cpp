/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        int maxSum = 0, sum, n;

        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }

        n = arr.size();

        for(int i = 0; i <= (n / 2) - 1; i++) {
            sum = arr[i] + arr[n - 1 - i];
            maxSum = (maxSum > sum) ? maxSum : sum;
        }

        return maxSum;
    }
};
