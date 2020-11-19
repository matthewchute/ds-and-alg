class array():
    """
    Integer array and its methods.
    """
    def __init__(self, CAPACITY = 10):
        self._arr = [0 for i in range(CAPACITY)]
        self._size = 0

    def __str__(self):
        return " ".join(str(self._arr[i]) for i in range(self._size))

    def appendElement(self, ele):
        """ 
        Add element to end of array if space available 
        """
        if self._size < len(self._arr):
            self._arr[self._size] = ele
            self._size += 1

    def prependElement(self, ele):
        """ 
        Add element to front of array if space available 
        """
        if self._size < len(self._arr):
            self._size += 1
            j = self._size - 1
            while j > 0:
                self._arr[j] = self._arr[j - 1]
                j -= 1
            self._arr[0] = ele

    def addElementAtIndex(self, ind, ele):
        """ 
        Add element at index and push down rest, 
        if space available and index is within size
        """
        if self._size < len(self._arr) and ind < self._size:
            j = self._size - ind
            while j > 0:
                self._arr[j + ind] = self._arr[j + ind - 1]
                j -= 1
            self._arr[ind] = ele
            self._size += 1

    def replaceElementAtIndex(self, ind, ele):
        """
        Replace element at index if index is within size 
        """
        if ind < self._size:
            self._arr[ind] = ele

    def findMax(self):
        """ 
        Return max value of array 
        """
        max = 0
        for i in range(self._size):
            if self._arr[i] > max:
                max = self._arr[i]
        return max

    def findSum(self):
        """ 
        Return sum of array 
        """
        sum = 0
        for i in range(self._size):
            sum += self._arr[i]
        return sum 

if __name__ == "__main__":
    arr = array()
    arr.appendElement(12)
    print(arr)
    arr.appendElement(24)
    print(arr)
    arr.appendElement(36)
    print(arr)
    arr.appendElement(48)
    print(arr)
    arr.addElementAtIndex(1, 99)
    print(arr)
    arr.replaceElementAtIndex(2, 88)
    print(arr)
    arr.prependElement(13)
    print(arr)
    arr.prependElement(26)
    print(arr)
    arr.prependElement(39)
    print(arr)
    arr.prependElement(52)
    print(arr)
    arr.addElementAtIndex(3, 77)
    print(arr)
    arr.replaceElementAtIndex(4, 66)
    print(arr)
    print(arr.findMax())
    print(arr.findSum())
