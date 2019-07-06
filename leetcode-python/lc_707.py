#
# LeetCode
# 707. Design Linked List
# https://leetcode.com/problems/design-linked-list/
#

class MyLinkedList:

    class _Node:
        def __init__(self, value, next=None):
            self._value = value
            self._next = next

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._head = None
        self._size = 0


    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index < 0 or index >= self._size:
            return -1

        dummy_node = self._head
        for _ in range(index):
            dummy_node = dummy_node._next

        return dummy_node._value


    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self._head = self._Node(val, self._head)
        self._size += 1


    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        self.addAtIndex(self._size, val)


    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index > self._size:
            return

        if index <= 0:
            self.addAtHead(val)
        else:
            dummy_node = self._Node(0, self._head)
            for _ in range(index):
                dummy_node = dummy_node._next

            dummy_node._next = self._Node(val, dummy_node._next)
            self._size += 1


    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if self._size == 0 or index < 0 or index >= self._size:
            return

        dummy_node = self._Node(0, self._head)
        for _ in range(index):
            dummy_node = dummy_node._next

        if index == 0:
            self._head = self._head._next
        else:
            dummy_node._next = dummy_node._next._next

        self._size -= 1
