#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from Array import Array


class ArrayImpl(Array):
    def __init__(self, size):
        self.size = size
        self.data = [None] * size

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")
        return self.data[index]

    def set(self, index, value):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")
        self.data[index] = value

    def size(self):
        return self.size

    def printArray(self):
        for element in self.data:
            print(element, end=" ")
        print()
