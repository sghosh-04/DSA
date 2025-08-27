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


    def display(self):
        if self.head is None:
            print("List is empty")
            return
        temp=self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp=temp.next


    def merge(self,ll1,ll2):
        if ll1.head is None:
            return ll2
        if ll2.head is None:
            return ll1
        temp1=ll1.head
        temp2=ll2.head
        while temp1.next is not None:
            temp1=temp1.next
        temp1.next=temp2
        return ll1
    
    def reverse(self):
        prev=None
        temp=self.head
        while temp is not None:
            next=temp.next
            temp.next=prev
            prev=temp
            temp=next
        self.head=prev





ll1=LinkedList()
ll2=LinkedList()
ll1.insert_end(10)
ll1.insert_end(20)
ll1.insert_beginning(5)
ll2.insert_end(30)
ll2.insert_end(40)
ll2.insert_beginning(1)
ll1.merge(ll1,ll2)
ll1.display()
print()
ll1.reverse()
ll1.display()
