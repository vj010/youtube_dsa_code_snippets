#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *reverseList(ListNode *root)
    {
        ListNode *prevNode = nullptr;
        while (root != nullptr)
        {
            ListNode *next = root->next;
            root->next = prevNode;
            prevNode = root;
            root = next;
        }

        return prevNode;
    }

    int getListSize(ListNode *root)
    {
        int len = 0;
        ListNode *localRoot = root;
        while (localRoot != nullptr)
        {
            len++;
            localRoot = localRoot->next;
        }
        return len;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int len1 = getListSize(l1);
        int len2 = getListSize(l2);

        ListNode *left = nullptr;
        ListNode *right = nullptr;
        ListNode *sum = nullptr;
        ListNode *currentNode = nullptr;
        ListNode *node = nullptr;
        if (len1 >= len2)
        {
            left = l1;
            right = l2;
        }
        else
        {
            left = l2;
            right = l1;
        }

        // std::cout << "left and right " << left->val << " " << right->val << std::endl;
        while (left != nullptr)
        {
            // std::cout << "starting while" << std::endl;
            // std::cout << "inside while left and right " << left->val << " " << right->val << std::endl;
            int val = left->val + carry;
            if (right != nullptr)
            {
                val += right->val;
            }
            int lastDigit = val % 10;
            if (val > lastDigit)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            node = new ListNode(lastDigit);
            if (sum == nullptr)
            {
                sum = node;
            }
            if (currentNode == nullptr)
            {
                currentNode = node;
            }
            else
            {
                currentNode->next = node;
                currentNode = currentNode->next;
            }
            left = left->next;
            if (right != nullptr)
                right = right->next;
        }

        if (carry)
        {
            // std::cout << "inside second while" << std::endl;
            int val = carry;
            ListNode *node = new ListNode(val);
            carry = 0;
            currentNode->next = node;
            currentNode = currentNode->next;
        }
        return sum;
        // ListNode *orderdSum = reverseList(sum);
        // return orderdSum;
    }
    void printList(ListNode *root)
    {
        while (root != nullptr)
        {
            std::cout << root->val << " ";
            root = root->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    freopen("./input.txt", "r", stdin);
    int t;
    std::cin >> t;

    while (t--)
    {
        ListNode *root1 = nullptr;
        ListNode *root2 = nullptr;
        int x;
        std::cin >> x;
        ListNode *currentNode = nullptr;
        for (size_t i = 0; i < x; i++)
        {
            int digit;
            std::cin >> digit;
            ListNode *node = new ListNode(digit);
            if (root1 == nullptr)
            {
                root1 = node;
            }
            if (currentNode == nullptr)
            {
                currentNode = node;
            }
            else
            {
                currentNode->next = node;
                currentNode = currentNode->next;
            }
        }

        std::cin >> x;
        currentNode = nullptr;
        for (size_t i = 0; i < x; i++)
        {
            int digit;
            std::cin >> digit;
            ListNode *node = new ListNode(digit);
            if (root2 == nullptr)
            {
                root2 = node;
            }
            if (currentNode == nullptr)
            {
                currentNode = node;
            }
            else
            {
                currentNode->next = node;
                currentNode = currentNode->next;
            }
        }
        Solution sol;
        // std::cout << "list1:" << std::endl;
        // sol.printList(root1);

        // std::cout << "list2:" << std::endl;
        // sol.printList(root2);

        ListNode *ans = sol.addTwoNumbers(root1, root2);
        sol.printList(ans);
    }
}
