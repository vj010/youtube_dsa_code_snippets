from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 1:
            return [TreeNode(1)]
        if n == 0:
            return []
        tree_roots: List[TreeNode] = []
        return self.__get_all_Trees(1, n)

    def __get_all_Trees(self, start, end):
        if end < start:
            return []
        final_tree_roots = []
        for i in range(start, end + 1):
            left_tree_roots = self.__get_all_Trees(start, i - 1)
            right_tree_roots = self.__get_all_Trees(i + 1, end)
            if len(left_tree_roots) > 0 and len(right_tree_roots) > 0:
                tree_roots = self.__get_tree_with_both_children(
                    i, left_tree_roots, right_tree_roots
                )
            elif len(left_tree_roots) > 0:
                tree_roots = self.__get_tree_with_left_child(i, left_tree_roots)
            elif len(right_tree_roots) > 0:
                tree_roots = self.__get_tree_with_right_child(i, right_tree_roots)
            else:
                tree_roots = [TreeNode(i)]
            if len(tree_roots) > 0:
                final_tree_roots.extend(tree_roots)

        return final_tree_roots

    def __get_tree_with_both_children(
        self, root_val, left_tree_roots, right_tree_roots
    ):
        tree_roots = []
        for left_root in left_tree_roots:
            for right_root in right_tree_roots:
                root = TreeNode(root_val)
                root.left = left_root
                root.right = right_root
                tree_roots.append(root)
        return tree_roots

    def __get_tree_with_left_child(self, root_val, left_tree_roots):
        tree_roots = []
        for left_tree in left_tree_roots:
            root = TreeNode(root_val)
            root.left = left_tree
            tree_roots.append(root)
        return tree_roots

    def __get_tree_with_right_child(self, root_val, right_tree_roots):
        tree_roots = []
        for right_tree in right_tree_roots:
            root = TreeNode(root_val)
            root.right = right_tree
            tree_roots.append(root)
        return tree_roots
