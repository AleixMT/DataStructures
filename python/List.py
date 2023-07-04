#!/usr/bin/env python3
# -*- coding: utf-8 -*-
class List:
    # Reserve memory space for the array
    def __init__(self):
        pass

    # Picks an element from the array for the element passed by parameter
    def get(self, index):
        pass

    # Puts an element to the array in the given value passed by parameter
    def set(self, index, value):
        pass

    # Returns the size of the array
    def size(self):
        pass

    # Prints the list in the screen
    def printList(self):
        pass

    # Reverse the list
    def reverse(self):
        pass

    # Changes two objects from its specific positions
    def swap(self, index1, index2):
        pass

    # Returns true or false dependant if the object is in the list or not.
    def search(self, elem):
        pass

    # Sorts the list
    def sort(self):
        pass

    # Add element to last position of the list
    def append(self, elem):
        pass

    # Decorator of insertBefore in position 0 (First position of the list)
    def appendToBeginning(self, elem):
        pass

    # Recieves list and appends it to the current list
    def extend(self, elem_list):
        pass

    # Recieves list of elements and removes them from the current list
    def substract(self):
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
    def insertAfter(self, index, elem):
        pass

    # Removes one element from the list but return the removed element itself
    def pop(self, index):
        pass

    # Delete all objects in the list matching the object sent by argument
    def remove(self, elem):
        pass

    # Increments the number of elements by one and checks that we are not running out of size from the array.
    # If that's the case make array bigger.
    def incrementElements(self):
        pass
