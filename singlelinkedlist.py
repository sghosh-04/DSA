class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class SingleLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self,data):
        new_node=Node(data)
        new_node.next=self.head
        self.head=new_node
    
    def display(self):
        curr=self.head
        while curr is not None:
            print(curr.data,end="->")
            curr=curr.next
        print("None")

if __name__ == "__main__":
    sll=SingleLinkedList()
    sll.insert_at_beginning(10)
    sll.insert_at_beginning(20)
    sll.insert_at_beginning(30)
    sll.display()

