#include <bits/stdc++.h>

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
    int getListSize(ListNode *head) const
    {
        int len = 0;
        ListNode *root = head;
        while (root != nullptr)
        {
            len++;
            root = root->next;
        }
        return len;
    }

    ListNode *getNodeAtK(ListNode *root, size_t ind)
    {
        if (root == nullptr)
            return nullptr;

        size_t i = 0;
        ListNode *head = root;
        ListNode *parent = nullptr;
        while (i < ind)
        {
            i++;
            parent = head;
            head = head->next;
        }
        if (parent != nullptr)
        {
            parent->next = nullptr;
            // std::cout << "head is null" << std::endl;
        }
        return head;
    }

    ListNode *mergeSort(ListNode *head, size_t listLen)
    {
        // std::cout << "listLen" << listLen << std::endl;
        // std::cout << "head val" << head->val << std::endl;
        if (listLen <= 1)
        {
            return head;
        }

        ListNode *halfPointNode = getNodeAtK(head, listLen / 2);
        // std::cout << "halfPointNode" << halfPointNode->val << std::endl;
        ListNode *left = mergeSort(head, listLen / 2);
        ListNode *right = mergeSort(halfPointNode, listLen - (listLen / 2));
        if (left == nullptr || right == nullptr)
        {
            // std::cout << "left or right is null" << std::endl;
        }
        return merge(left, right);
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == nullptr)
        {
            return right;
        }

        if (right == nullptr)
        {
            return left;
        }

        ListNode *current = nullptr;
        ListNode *root = nullptr;

        Solution sol;

        while (left != nullptr && right != nullptr)
        {
            // std::cout << "left and right " << left->val << " " << right->val << std::endl;
            if (left->val <= right->val)
            {
                if (current == nullptr)
                {
                    current = left;
                    if (root == nullptr)
                    {
                        root = current;
                    }
                }
                else
                {
                    current->next = left;
                    current = current->next;
                }
                left = left->next;
            }
            else
            {
                if (current == nullptr)
                {
                    current = right;
                    if (root == nullptr)
                    {
                        root = current;
                    }
                }
                else
                {
                    current->next = right;
                    current = current->next;
                }

                right = right->next;
            }

            // std::cout << "root list:" << std::endl;
            // sol.printList(root);
        }
        if (left != nullptr)
        {
            current->next = left;
        }

        if (right != nullptr)
        {
            current->next = right;
        }

        // std::cout << "after merge:" << std::endl;
        // sol.printList(root);

        return root;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        // std::cout << "here" << std::endl;
        size_t len = getListSize(head);
        ListNode *root = mergeSort(head, len);
        return root;
    }
    void printList(ListNode *head)
    {
        while (head != nullptr)
        {
            std::cout << head->val << " ";
            head = head->next;
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
        int n;
        std::cin >> n;
        ListNode *head = new ListNode();
        ListNode *root = head;
        for (size_t i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            head->next = new ListNode(x);
            head = head->next;
        }

        Solution solution;
        ListNode *listHead = solution.sortList(root->next);
        solution.printList(listHead);
    }

    return 0;
}
