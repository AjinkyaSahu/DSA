class Node:
    def __init__(self, data):
        self.data = data  # Assign data
        self.next = None  # Initialize next as null
 
class LinkedList:
    def __init__(self):
        self.head = None
 
if __name__=='__main__':
 
    # Start with the empty list
    llist = LinkedList()
 
    llist.head = Node(1)
    second = Node(2)
    third = Node(3)

    llist.head.next = second; # Link first node with second
 
    second.next = third;