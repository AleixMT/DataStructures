class Node:
    def __init__(self, value, next_node):
        self.nextNode = next_node
        self.value = value

    def setNextNode(self, node):
        self.nextNode = node

    def getNextNode(self):
        return self.nextNode

    def setValue(self, value):
        self.value = value

    def getValue(self):
        return self.value


