#
# LeetCode
# 622. Design Circular Queue
# https://leetcode.com/problems/design-circular-queue/
#

class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self._storage = [-1] * k
        self._size = k
        self._head = -1
        self._tail = -1


    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isFull():
            return False

        if self.isEmpty():
            self._head = self._tail = 0
        else:
            self._tail = (self._tail + 1) % self._size

        self._storage[self._tail] = value

        return True


    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False

        if self._head == self._tail:
            self._head = self._tail = -1
        else:
            self._head = (self._head + 1) % self._size

        return True


    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.isEmpty():
            return -1
        else:
            return self._storage[self._head]


    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.isEmpty():
            return -1
        else:
            return self._storage[self._tail]


    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self._head == -1


    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return (self._tail + 1) % self._size == self._head
