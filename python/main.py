#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from ArrayList import ArrayList
from LinkedList import LinkedList

if __name__ == '__main__':
    a = LinkedList()
    a.append(1)
    a.append(2)
    a.append(3)
    a.append(4)

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


