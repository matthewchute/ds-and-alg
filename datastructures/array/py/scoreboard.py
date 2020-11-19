class scoreboard():
    """
    Top 5 scoreboard implemented using an array.
    """
    def __init__(self, CAPACITY = 5):
        self._arr = [("", 0) for i in range(CAPACITY)]
        self._size = 0
    
    def __str__(self):
        return "\n".join(str(self._arr[i]) for i in range(self._size))

    def addScore(self, name, score):
        if self._size < len(self._arr) or self._arr[-1][1] < score:
            if self._size < len(self._arr):
                self._size += 1
            temp = self._size - 1
            while temp > 0 and self._arr[temp - 1][1] < score:
                self._arr[temp] = self._arr[temp - 1]
                temp -= 1
            self._arr[temp] = (name, score)

if __name__ == "__main__":
    from random import randint as rand
    names = ["Matthew", "Michelle", "Hannah", "Heather", "Carey"]
    s = scoreboard()
    for _ in range(7):
        s.addScore(names[rand(0,4)], rand(0,100))
        print(s)
        print("")
