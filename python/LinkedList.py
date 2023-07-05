#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from List import List
from Node import Node


class LinkedList(List):
    def __init__(self):
        self.first = None
        self.numElements = 0

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

    def length(self):
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

    def sort(self, comparator_function):
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

    def minimumPos(self, compare_two):
        pass

    def minimum(self, compare_two):
        pass

    def extend(self, elem_list):
        pass

    def substract(self):
        pass

    def insertBefore(self, index, elem):
        pass

    def insertAfter(self, index, elem):
        aux = self.first
        for i in range(index):
            aux = aux.getNextNode()

        node = Node(elem, None)
        node.setNextNode(aux.getNextNode())
        aux.setNextNode(node)

    def pop(self, index):
        pass

    def remove(self, elem):
        pass

    def incrementElements(self):
        self.numElements += 1
