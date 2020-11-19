class queue {

    // Desc: starting capacity
    unsigned const STARTING_CAPACITY = 6;

    // Desc: circular array ptr
    int * arr;

    // Desc: num of elements in queue
    unsigned size;

    // Desc: num of spots in array
    unsigned capacity;

    // Desc: index of first element
    unsigned front;
    
    //Desc: index of next element to be added       
    unsigned back;

    public:

        // Desc: Constructor
        queue();

        // Desc: Destructor
        ~queue();

        // Desc: Adds new element at the back  
        void enqueue(int x);

        // Desc: Removes the frontmost element  
        void dequeue();

        // Desc: Returns a copy of the frontmost element
        int peek() const;

        // Desc: Returns true if queue is empty
        bool isEmpty() const;
};