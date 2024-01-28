# Definition for singly-linked list.
from typing import Optional, List, Union


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        root_node: Union[ListNode, None] = None
        current_root: Union[ListNode, None] = None
        used_root = -1
        while True:
            all_none = True
            current_node: Union[ListNode, None] = None
            for i in range(0, len(lists)):
                if lists[i] is None:
                    continue
                if current_node is None or (
                    current_node.val > lists[i].val  # type:ignore
                ):
                    current_node = lists[i]
                    used_root = i
                    all_none = False

            if all_none or used_root < 0:
                break

            lists[used_root] = lists[used_root].next  # type:ignore
            if root_node is None:
                root_node = current_node  # type:ignore
                current_root = root_node
            else:
                if current_root is not None:
                    current_root.next = current_node  # type:ignore
                    current_root = current_root.next  # type:ignore

        # node = ListNode()
        return root_node


list1_root = ListNode(1)
list1_root.next = ListNode(4)
list1_root.next.next = ListNode(5)

list2_root = ListNode(1)
list2_root.next = ListNode(3)
list2_root.next.next = ListNode(4)

list3_root = ListNode(2)
list3_root.next = ListNode(6)


sorted_root = Solution().mergeKLists([list1_root, list2_root, list3_root])
while sorted_root is not None:
    if sorted_root is not None:
        print("sorted_root", sorted_root.val)
        sorted_root = sorted_root.next
