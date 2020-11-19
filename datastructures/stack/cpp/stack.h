class stack {

    // Desc: node for linked list
    struct node {
        int data;
        node * next;
    };

    // Desc: ptr to the first node (NULL if empty)
    node * head;

    // Desc: ptr to the last node (NULL if empty)
    node * tail;

    public:

        // Desc: Constructor
        stack();

        // Desc: Destructor
        ~stack();

        // Desc: Adds new element to the top
        void push(int x);

        // Desc: Removes the top element
        void pop();

        // Desc: Returns a copy of the topmost element
        int peek() const;

        // Desc: Returns true if stack is empty
        bool isEmpty() const;
};