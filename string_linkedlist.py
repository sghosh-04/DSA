class Node:
    def __init__(self,data):
        self.data=data
        self.next=None


def string_linkedlist(str):
    if not str:
        return None

    head=Node(str[0])
    current=head

    for ch in str[1:]:
        current.next=Node(ch)
        current=current.next

    return head

def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")

if __name__=='__main__':
    head=string_linkedlist("Hello World")
    print_linked_list(head)