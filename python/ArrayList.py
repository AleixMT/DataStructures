#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from List import List
from ArrayImpl import ArrayImpl
import sys


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

    def length(self):
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

    def minimum(self, compare_two):
        minimum = sys.maxsize
        for i in range(self.numElements):
            if compare_two(self.get(i), minimum) >= 1:
                minimum = self.get(i)
        return minimum

    def minimumPos(self, compare_two):
        index = 0
        minimum = self.get(index)
        for i in range(1, self.numElements):
            if compare_two(self.get(i), minimum) >= 1:
                minimum = self.get(i)
                index = i
        return index

    def sort(self, compare_two):
        auxiliar_list = ArrayList()
        for i in range(self.numElements):
            minimum_index = self.minimumPos(compare_two)
            auxiliar_list.append(self.pop(minimum_index))
        self.extend(auxiliar_list)

    def substract(self, elem_list):
        for i in range(elem_list.length):
            self.remove(elem_list.get(i))

    def append(self, elem):
        self.incrementElements()
        self.array.set(self.numElements - 1, elem)

    def appendToBeginning(self, elem):
        self.insertBefore(0, elem)

    def extend(self, elem_list):
        for i in range(elem_list.length()):
            self.append(elem_list.get(i))

    def insertAfter(self, index, elem):
        self.incrementElements()
        for i in range(self.numElements - 2 - index):
            self.set(self.numElements - 1 - i, self.get(self.numElements - 1 - i - 1))
        self.set(index + 1, elem)

    def insertBefore(self, index, elem):
        self.append(elem)
        for i in range(index, self.numElements):
            self.swap(i, self.numElements - 1)

    def pop(self, index):
        pop_object = self.get(index)
        for i in range(index, self.numElements - 1):
            self.swap(i, i + 1)
        self.numElements -= 1
        return pop_object

    def remove(self, elem):
        for i in range(self.numElements):
            if self.get(i) == elem:
                self.pop(i)

    def incrementElements(self):
        self.numElements += 1
        if self.numElements > self.size:
            old_array = self.array
            self.array = ArrayImpl(self.size * 2)
            self.size = self.size * 2
            for i in range(self.numElements - 1):
                self.set(i, old_array.get(i))
