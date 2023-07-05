#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod


class List(ABC):
    # Reserve memory space for the array
    def __init__(self):
        pass

    # Picks an element from the array for the element passed by parameter
    @abstractmethod
    def get(self, index):
        pass

    # Puts an element to the array in the given value passed by parameter
    @abstractmethod
    def set(self, index, value):
        pass

    # Returns the size of the array
    @abstractmethod
    def length(self):
        pass

    # Prints the list in the screen
    @abstractmethod
    def printList(self):
        pass

    # Reverse the list
    @abstractmethod
    def reverse(self):
        pass

    # Changes two objects from its specific positions
    @abstractmethod
    def swap(self, index1, index2):
        pass

    # Returns true or false dependant if the object is in the list or not.
    @abstractmethod
    def search(self, elem):
        pass

    # Sorts the list
    @abstractmethod
    def sort(self, comparator_function):
        pass

    # Add element to last position of the list
    @abstractmethod
    def append(self, elem):
        pass

    # Returns the minimum element of the list
    # Function compare_two compares two elements
    @abstractmethod
    def minimum(self, compare_two):
        pass

    # Returns the the index of the min element
    # Function compare_two compares two elements
    @abstractmethod
    def minimumPos(self, compare_two):
        pass

    # Decorator of insertBefore in position 0 (First position of the list)
    @abstractmethod
    def appendToBeginning(self, elem):
        pass

    # Recieves list and appends it to the current list
    @abstractmethod
    def extend(self, elem_list):
        pass

    # Recieves list of elements and removes them from the current list
    @abstractmethod
    def substract(self, elem_list):
        pass

    # Inserts elem in the given index position
    # State of the list [ 0, 1, 2, 3, 4, 5 ]
    # insertBefore(2, 20)
    # Result of the list after insertBehind operation [ 0, 1, 20, 2, 3, 4, 5 ]
    # insertBefore(0, 20)
    # Result of the list after insertBehind operation [ 20, 0, 1, 2, 3, 4, 5 ]
    # insertBefore(6, 20)
    # Result of the list after insertBehind operation [ 0, 1, 2, 3, 4, 5, 20 ]
    # insertBefore(8, 20)
    # Result of the list after insertBehind operation error array index out of range
    @abstractmethod
    def insertBefore(self, index, elem):
        pass

    # Inserts elem in the given index position
    # State of the list [ 0, 1, 2, 3, 4, 5 ]
    # insertAfter(2, 20)
    # Result of the list after insertAfter operation [ 0, 1, 2, 20, 3, 4 ]
    # insertAfter(0, 20)
    # Result of the list after insertAfter operation [ 0, 20, 1, 2, 3, 4, 5 ]
    # insertAfter(5, 20)
    # Result of the list after insertAfter operation [ 0, 1, 2, 3, 4, 5, 20 ]
    # insertAfter(6, 20)
    # Result of the list after insertAfter operation error array index out of rance (max length is 6)
    # insertAfter(8, 20)
    @abstractmethod
    def insertAfter(self, index, elem):
        pass

    # Removes one element from the list but return the removed element itself
    @abstractmethod
    def pop(self, index):
        pass

    # Delete all objects in the list matching the object sent by argument
    @abstractmethod
    def remove(self, elem):
        pass

    # Increments the number of elements by one and checks that we are not running out of size from the array.
    # If that's the case make array bigger.
    @abstractmethod
    def incrementElements(self):
        pass

    # If the elements are equal return 0, if x < y return 1 else return -1
    @staticmethod
    def compareTwoNumbers(x, y):
        if x == y:
            return 0
        elif x < y:
            return 1
        else:
            return -1

    # If the letters are equal return 0, return 1 if is next in alphabetic order and -1 if is alphabetically before.
    @staticmethod
    def compareTwoLetters(a, b):
        if a == b:
            return 0
        else:
            if ord(a[0]) > ord(b[0]):
                return -1
            else:
                return 1


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


    # a = [ 1, 2, 3, 4, 5]
    # a.insertAfter(2, 0)
    # a = 2 [ 1, 2, 3, 0, 4, 5 ]

    # a = [ 1, 2, 3, 4, 5 ]
    # a.insertAfter(2, 0)
    # a = [ 1, 2, 3, 4, 5, 0]

    # (0)->(1)->(2)->(3)->(4)
    # first -> (0)
    # get(0) -> 0