#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from List import List
from Node import Node


class LinkedList(List):
    def __init__(self):
        self.first = None
        self.numElements = 0

    # (0)->(1)->(2)->(3)->(4)
    # first -> (0)
    # get(0) -> 0

    def get(self, index):
        if self.numElements == 0:
            raise IndexError
        if index == 0:
            return self.first.getValue()
        else:
            current_node = self.first
            c = 0
            while True:
                if c == index:
                    return current_node.getValue()
                c += 1
                current_node = current_node.getNextNode()
                if current_node is None:
                    break

    def set(self, index, value):
        pass

    def size(self):
        pass

    def printList(self):
        if self.numElements == 0:
            return

        current_node = self.first
        while True:
            print(current_node.getValue())
            current_node = current_node.getNextNode()
            if current_node is None:
                break

    def reverse(self):
        pass

    def swap(self, index1, index2):
        pass

    def search(self, elem):
        pass

    def sort(self):
        pass

    def append(self, elem):
        if self.numElements == 0:
            self.first = Node(elem, None)
        else:
            current_node = self.first
            while current_node.getNextNode() is not None:
                current_node = current_node.getNextNode()
            current_node.setNextNode(Node(elem, None))
        self.incrementElements()

    def appendToBeginning(self, elem):
        pass

    def extend(self, elem_list):
        pass

    def substract(self):
        pass

    def insertBefore(self, index, elem):
        pass

    def insertAfter(self, index, elem):
        pass

    def pop(self, index):
        pass

    def remove(self, elem):
        pass

    def incrementElements(self):
        self.numElements += 1

