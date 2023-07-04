#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from List import List
from ArrayImpl import ArrayImpl


class ArrayList(List):
    def __init__(self):
        self.size = 5
        self.array = ArrayImpl(self.size)
        self.numElements = 0

    def get(self, index):
        if index >= self.numElements:
            raise IndexError
        return self.array.get(index)

    def set(self, index, value):
        if index >= self.numElements:
            raise IndexError
        return self.array.set(index, value)

    def size(self):
        return self.numElements

    def printList(self):
        for i in range(self.numElements):
            print(self.array.get(i))

    def reverse(self):
        for i in range(int(self.numElements / 2)):
            self.swap(i, self.numElements - 1 - i)

    def swap(self, index1, index2):
        index_position = self.get(index1)
        self.set(index1, self.get(index2))
        self.set(index2, index_position)

    def search(self, elem):
        for i in range(self.numElements):
            if self.get(i) == elem:
                return True
        return False

    def sort(self):
        pass

    def append(self, elem):
        self.incrementElements()
        self.array.set(self.numElements - 1, elem)

    def appendToBeginning(self, elem):
        self.insertBefore(0, elem)

    def extend(self, elem_list):
        for i in range(elem_list.size()):
            self.append(elem_list.get(i))

    def insertAfter(self, index, elem):
        pass

    # a = [ 1, 2, 3, 4, 5]
    # a.insertAfter(2, 0)
    # a = 2 [ 1, 2, 3, 0, 4, 5 ]

    # a = [ 1, 2, 3, 4, 5 ]
    # a.insertAfter(2, 0)
    # a = [ 1, 2, 3, 4, 5, 0]

    def insertBefore(self, index, elem):
        self.append(elem)
        for i in range(index, self.numElements):
            self.swap(i, self.numElements - 1)


    # a = [ 1, 2, 3, 4, 5]
    # a.pop(1)
    # a = 2 [ 1, 3, 4, 5 ]

    # a = [ 1, 2, 3, 4, 5 ]
    # a = [ 1, 3, 2, 4, 5 ]
    # a = [ 1, 3, 4, 2, 5 ]
    # a = [ 1, 3, 4, 5, 2 ]
    # a = [ 1, 3, 4, 5 ] => return 2

    # a = [ 1, 2, 3, 4, 5 ]
    # a = [ 1, 3, 3, 4, 5 ]
    # a = [ 1, 3, 4, 4, 5 ]
    # a = [ 1, 3, 4, 5, 5 ]
    # a = [ 1, 3, 4, 5 ] => return 2

    def pop(self, index):
        pop_object = self.get(index)
        for i in range(index, self.numElements - 1):
            self.swap(i, i + 1)
        self.numElements -= 1
        return pop_object

    def remove(self, elem):
        pass

    def incrementElements(self):
        self.numElements += 1
        if self.numElements > self.size:
            old_array = self.array
            self.array = ArrayImpl(self.size * 2)
            self.size = self.size * 2
            for i in range(self.numElements - 1):
                self.set(i, old_array.get(i))
