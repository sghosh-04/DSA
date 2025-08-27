class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=None

    def insert_end(self,data):
        new_node=Node(data)
        if self.head is None:
            self.head=new_node
            return
        temp=self.head
        while temp.next is not None:
           temp=temp.next
        temp.next=new_node
    
    def insert_beginning(self,data):
        new_node=Node(data)
        new_node.next=self.head
        self.head=new_node
    
    def delete_beginning(self):
        if self.head is None:
            print("List is empty")
            return
        temp=self.head
        print(f"Deleted element is {temp.data}")
        self.head=self.head.next
        del(temp)

    def delete_end(self):
        if self.head is None:
            print("List is empty")
            return
        if self.head.next is None:
            print(f"Deleted element is {self.head.data}")
            del(self.head)
            self.head=None
            return
        temp=self.head
        while temp.next.next is not None:
            temp=temp.next
        print(f"Deleted element is {temp.next.data}")
        del(temp.next)
        temp.next=None

    def display(self):
        if self.head is None:
            print("List is empty")
            return
        temp=self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp=temp.next

ll=LinkedList()
ll.insert_end(10)
ll.insert_end(20)
ll.insert_beginning(5)
ll.display()
print()
ll.delete_beginning()
ll.display()
print()
ll.delete_end()
ll.display()