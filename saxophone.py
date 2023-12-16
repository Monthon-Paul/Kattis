# https://open.kattis.com/problems/saxophone
sax = {
    'c': [0, 1, 1, 1, 0, 0, 1, 1, 1, 1],
    'd': [0, 1, 1, 1, 0, 0, 1, 1, 1, 0],
    'e': [0, 1, 1, 1, 0, 0, 1, 1, 0, 0],
    'f': [0, 1, 1, 1, 0, 0, 1, 0, 0, 0],
    'g': [0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    'a': [0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
    'b': [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    'C': [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    'D': [1, 1, 1, 1, 0, 0, 1, 1, 1, 0],
    'E': [1, 1, 1, 1, 0, 0, 1, 1, 0, 0],
    'F': [1, 1, 1, 1, 0, 0, 1, 0, 0, 0],
    'G': [1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    'A': [1, 1, 1, 0, 0, 0, 0, 0, 0, 0],
    'B': [1, 1, 0, 0, 0, 0, 0, 0, 0, 0]
}

def recordFinger(notes):
    presentNote = [0 for _ in range(10)]
    counter = [0 for _ in range(10)]
    for note in notes:
        for i in range(len(counter)):
            if presentNote[i] == 0 and sax[note][i]==1:
                counter[i] += 1
            presentNote[i] = sax[note][i]
    return counter

t = int(input())
for i in range(t):
    music = input()
    print(" ".join(str(i) for i in recordFinger(music)))