class Node:
    def __init__(self, x):
        self.data = x
        self.prev = None
        self.next = None
 
def push(head_ref, new_data):
    new_node = Node(new_data)
 
    new_node.data = new_data

    new_node.next = head_ref
    new_node.prev = None
 
    if (head_ref != None):
        head_ref.prev = new_node
 
    head_ref = new_node
 
    return head_ref
 
def insertBefore(head_ref, next_node, new_data):
 
    if (next_node == None):
        print("the given next node cannot be NULL")
        return
 
    new_node = Node(new_data)
 
    new_node.prev = next_node.prev
 
    next_node.prev = new_node
 
    new_node.next = next_node
 
    if (new_node.prev != None):
        new_node.prev.next = new_node

    else:
        head_ref = new_node
 
    return head_ref
 

def printList(node):
    last = None
    print("Traversal in forward direction ")
    while (node != None):
        print(node.data, end=" ")
        last = node
        node = node.next
 
    print("\nTraversal in reverse direction ")
    while (last != None):
        print(last.data, end=" ")
        last = last.prev
 
if __name__ == '__main__':
 
    # /* Start with the empty list */
    head = None
    head = push(head, 7)
 
    head = push(head, 1)
 
    head = push(head, 4)
 
    # Insert 8, before 1. So linked list becomes 4.8.1.7.NULL
    head = insertBefore(head, head.next, 8)
 
    print("Created DLL is: ")
    printList(head)