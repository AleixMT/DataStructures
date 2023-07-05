#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from ArrayList import ArrayList
from LinkedList import LinkedList
from List import List

if __name__ == '__main__':
    a = ArrayList()
    a.append("a")
    a.append("b")
    a.append("d")
    a.append("c")
    a.sort(List.compareTwoLetters)
    a.printList()


    '''
    print("insert before")
    a.append(0)
    a.append(2)
    a.append(2)
    a.append(1)
    a.append(2)
    a.append(0)
    a.printList()
    print("GET NOSEKE")
    print(a.get(0))
    print(a.get(1))
    print(a.get(2))
    print(a.get(3))
    print(a.get(9))
    '''

