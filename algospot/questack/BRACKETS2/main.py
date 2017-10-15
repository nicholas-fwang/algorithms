class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def top(self):
        return self.items[len(self.items)-1]

def isOpen(c) :
    if c == '(' or c == '[' or c == '{' :
        return True
    return False

def isMatched(opened, closed) :
    if opened == '(' and closed == ')' : return True
    if opened == '{' and closed == '}' : return True
    if opened == '[' and closed == ']' : return True
    return False

if __name__ == '__main__':
    testCase = int(input())
    for i in range(testCase):
        str = input()
        st = Stack()
        result = True
        for c in str:
            if isOpen(c) :
                st.push(c)
            else :
                if st.isEmpty() :
                    result = False
                    break;
                opened = st.top()
                st.pop()
                if isMatched(opened, c) == False :
                    result = False
                    break;
        if st.isEmpty() == False : result = False
        if result : print("YES")
        else : print("NO")
