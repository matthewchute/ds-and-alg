class node:
    def __init__(self, data):
        self.data = data
        self.next = None 

class linkedlist:
    def __init__(self):
        self.head = None 
    
    def __repr__(self):
        curr = self.head
        nodes = []
        while curr is not None:
            nodes.append(curr.data)
            curr = curr.next 
        nodes.append("None")
        return " -> ".join(nodes)
    
    def push(self, data):
        """append to tail"""
        if self.head is None:
            self.head = node(data)
            self.head.next = None 
        else:
            curr = self.head
            prev = self.head
            while curr is not None:
                prev = curr
                curr = curr.next
            curr = node(data)
            prev.next = curr
            curr.next = None

    def pop(self):
        """pop from the head"""
        if self.head is not None:
            prev = self.head
            curr = prev.next 
            self.head = curr
                
if __name__ == "__main__":
    ll = linkedlist()
    print ll
    for i in range(5):
        ll.push(str(i))
        print ll
    for i in range(5):
        ll.pop()
        print ll

