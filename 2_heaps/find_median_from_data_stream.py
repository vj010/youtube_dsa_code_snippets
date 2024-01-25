from typing import List
import math


class MedianFinder:
    def __init__(self):
        self.smaller_pq = []
        self.greater_pq = []

    def addNum(self, num: int) -> None:
        if len(self.smaller_pq) == 0 or num <= self.smaller_pq[0]:
            self.__push_to_heap(self.smaller_pq, num, False)
        else:
            self.__push_to_heap(self.greater_pq, num, True)

        # print("before balancing", self.smaller_pq, self.greater_pq)
        self.__balance_heaps(self.smaller_pq, self.greater_pq)
        # print("after balancing", self.smaller_pq, self.greater_pq)

    def __push_to_heap(self, pq: List[int], num: int, min_heap: bool):
        pq.append(num)
        i = len(pq) - 1
        while i != 0 and (
            (pq[self.__get_parent(i)] > pq[i] and min_heap)
            or (pq[self.__get_parent(i)] < pq[i] and not min_heap)
        ):
            pq[i], pq[self.__get_parent(i)] = (pq[self.__get_parent(i)], pq[i])
            i = self.__get_parent(i)

    def __balance_heaps(self, smaller_pq: List[int], greater_pq: List[int]):
        smaller_len = len(smaller_pq)
        greater_len = len(greater_pq)
        if abs(smaller_len - greater_len) > 1:
            if smaller_len > greater_len:
                el = self.__pop(smaller_pq, False)
                self.__push_to_heap(greater_pq, el, True)
            else:
                el = self.__pop(greater_pq, True)
                self.__push_to_heap(smaller_pq, el, False)

        # print(self.pq)

    def findMedian(self) -> float:
        if len(self.smaller_pq) == len(self.greater_pq):
            # print("first condition", self.smaller_pq, self.greater_pq)
            return (self.smaller_pq[0] + self.greater_pq[0]) / 2
        elif len(self.smaller_pq) < len(self.greater_pq):
            # print("second condition:", self.smaller_pq, self.greater_pq)
            return float(self.greater_pq[0])
        else:
            # print("third condition", self.smaller_pq, self.greater_pq)
            return float(self.smaller_pq[0])

    def __get_parent(self, i):
        return math.floor((i - 1) / 2)

    def __heapify(self, priority_queue: List[int], i: int, min_heap: bool):
        # print(f"priority_queue[{i}]:{priority_queue[i]}")
        queue_len = len(priority_queue)

        left = 2 * i + 1
        right = 2 * i + 2
        smallest = i
        if left < queue_len and (
            (priority_queue[left] < priority_queue[smallest] and min_heap)
            or (priority_queue[left] > priority_queue[smallest] and not min_heap)
        ):
            smallest = left
        if right < queue_len and (
            (priority_queue[right] < priority_queue[smallest] and min_heap)
            or (priority_queue[right] > priority_queue[smallest] and not min_heap)
        ):
            smallest = right

        if i != smallest:
            priority_queue[i], priority_queue[smallest] = (
                priority_queue[smallest],
                priority_queue[i],
            )
            self.__heapify(priority_queue, smallest, min_heap)

    def __pop(self, pq: List[int], min_heap: bool) -> int:
        el = pq[0]
        pq[0] = pq[-1]
        pq.pop()
        # print(f"__pop before:{pq}")
        self.__heapify(pq, 0, min_heap)
        # print(f"__pop:{pq}")
        return el


medianFinder = MedianFinder()
medianFinder.addNum(6)
medianFinder.addNum(10)
medianFinder.addNum(2)
medianFinder.addNum(6)
medianFinder.addNum(5)
medianFinder.addNum(0)
medianFinder.addNum(6)
# medianFinder.addNum(3)
# medianFinder.addNum(1)
# medianFinder.addNum(0)
# medianFinder.addNum(0)


print(medianFinder.findMedian())
# print(medianFinder.pq)
