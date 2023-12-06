# How are you ?

import sys


class Node():
    def __init__(self, val):
        self.key = val
        self.left = None
        self.right = None

    def inorder(self):
        if self.left:
            self.left.inorder()
        print(self.key, end=' ')
        if self.right:
            self.right.inorder()

    def preorder(self):
        print(self.key, end=' ')
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()

    def postorder(self):
        if self.left:
            self.left.postorder()
        if self.right:
            self.right.postorder()
        print(self.key, end=' ')

# dottify
def dottify(s):
    if s == '':
        return s
    t = s[0]; n = len(s)
    for i in range(1,n):
        if (s[i-1] in '(|.') :
                t += s[i]
        elif (s[i] in ')|*?+.') :
                t += s[i]
        else:
            t += '.' + s[i]
    return t

def buildTree(s):
    if len(s) == 0:
        return None
    root = Node(s[0])
    if len(s) == 1:
        return root
    if s.count('(') > 0:
        i = 1
        count = 0
        while i < len(s):
            if s[i] == '(':
                count += 1
            elif s[i] == ')':
                count -= 1
            if count == 0 and s[i] == '|':
                break
            i += 1
        if i == len(s):
            root.left = buildTree(s[1:-1])
        else:
            root.left = buildTree(s[1:i])
            root.right = buildTree(s[i + 1:-1])
    else:
        # search for the first operator |
        i = 1
        while i < len(s):
            if s[i] == '|':
                break
            i += 1
        if i != len(s):
            # now make | as root and recursively build left and right subtrees
            root = Node('|')
            root.left = buildTree(s[:i])
            root.right = buildTree(s[i + 1:])
        else:
            # search for the first operator .
            i = 1
            while i < len(s):
                if s[i] == '.':
                    break
                i += 1
            if i != len(s):
                # now make . as root and recursively build left and right subtrees
                root = Node('.')
                root.left = buildTree(s[:i])
                root.right = buildTree(s[i + 1:])
            else:
                # search for the first operator *
                i = 1
                while i < len(s):
                    if s[i] == '*':
                        break
                    i += 1
                if i != len(s):
                    # now make * as root and recursively build left and right subtrees
                    root = Node('*')
                    root.left = buildTree(s[:i])
                    root.right = buildTree(s[i + 1:])
                else:
                    # search for the first operator ?
                    i = 1
                    while i < len(s):
                        if s[i] == '?':
                            break
                        i += 1
                    if i != len(s):
                        # now make ? as root and recursively build left and right subtrees
                        root = Node('?')
                        root.left = buildTree(s[:i])
                        root.right = buildTree(s[i + 1:])
                    else:
                        # search for the first operator +
                        i = 1
                        while i < len(s):
                            if s[i] == '+':
                                break
                            i += 1
                        if i != len(s):
                            # now make + as root and recursively build left and right subtrees
                            root = Node('+')
                            root.left = buildTree(s[:i])
                            root.right = buildTree(s[i + 1:])
                        else:
                            # search for the first operator ^
                            i = 1
                            while i < len(s):
                                if s[i] == '^':
                                    break
                                i += 1
                            if i != len(s):
                                # now make ^ as root and recursively build left and right subtrees
                                root = Node('^')
                                root.left = buildTree(s[:i])
                                root.right = buildTree(s[i + 1:])
                            else:
                                # search for the first operator $
                                i = 1
                                while i < len(s):
                                    if s[i] == '$':
                                        break
                                    i += 1
                                if i != len(s):
                                    # now make $ as root and recursively build left and right subtrees
                                    root = Node('$')
                                    root.left = buildTree(s[:i])
                                    root.right = buildTree(s[i + 1:])
                                else:
                                    # search for the first operator {
                                    i = 1
                                    while i < len(s):
                                        if s[i] == '{':
                                            break
                                        i += 1
                                    if i != len(s):
                                        # now make { as root and recursively build left and right subtrees
                                        root = Node('{')
                                        root.left = buildTree(s[:i])
                                        root.right = buildTree(s[i + 1:])
                                    else:
                                        # search for the first operator }
                                        i = 1
                                        while i < len(s):
                                            if s[i] == '}':
                                                break
                                            i += 1
                                        if i != len(s):
                                            # now make } as root and recursively build left and right subtrees
                                            root = Node('}')
                                            root.left = buildTree(s[:i])
                                            root.right = buildTree(s[i + 1:])
                                        else:
                                            # search for the first operator [
                                            i = 1
                                            while i < len(s):
                                                if s[i] == '[':
                                                    break
                                                i += 1
                                            if i != len(s):                                       
                                                # now make [ as root and recursively build left and right subtrees
                                                root = Node('[')
                                                root.left = buildTree(s[:i])
                                                root.right = buildTree(s[i + 1:])
                                            else:
                                                # search for the first operator ]
                                                i = 1
                                                while i < len(s):
                                                    if s[i] == ']':
                                                        break
                                                    i += 1
                                                if i != len(s):
                                                    # now make ] as root and recursively build left and right subtrees
                                                    root = Node(']')
                                                    root.left = buildTree(s[:i])
                                                    root.right = buildTree(s[i + 1:])
                                                else:
                                                    # search for the first operator (
                                                    i = 1
                                                    while i < len(s):
                                                        if s[i] == '(':
                                                            break
                                                        i += 1
                                                    if i != len(s):
                                                        # now make ( as root and recursively build left and right subtrees
                                                        root = Node('(')
                                                        root.left = buildTree(s[:i])
                                                        root.right = buildTree(s[i + 1:])
                                                    else:
                                                        # search for the first operator )
                                                        i = 1
                                                        while i < len(s):
                                                            if s[i] == ')':
                                                                break
                                                            i += 1
                                                        if i != len(s):
                                                            # now make ) as root and recursively build left and right subtrees
                                                            root = Node(')')
                                                            root.left = buildTree(s[:i])
                                                            root.right = buildTree(s[i + 1:])
                                                        else:
                                                            # search for the first operator \
                                                            i = 1
                                                            while i < len(s):
                                                                if s[i] == '\\':
                                                                    break
                                                                i += 1
                                                            if i != len(s):
                                                                # now make \ as root and recursively build left and right subtrees
                                                                root = Node('\\')
                                                                root.left = buildTree(s[:i])
                                                                root.right = buildTree(s[i + 1:])
                                                            else:
                                                                # search for the first operator /
                                                                i = 1
                                                                while i < len(s):
                                                                    if s[i] == '/':
                                                                        break
                                                                    i += 1
                                                                if i != len(s):
                                                                    # now make / as root and recursively build left and right subtrees
                                                                    root = Node('/')
                                                                    root.left = buildTree(s[:i])
                                                                    root.right = buildTree(s[i + 1:])
                                                                # return root node
    return root 

# building DFA from the tree
def buildDFA(root):
    # if root is a leaf node
    if root.left is None and root.right is None:
        # create a new DFA
        dfa = DFA()
        # add a new state
        dfa.addState()
        # add a new transition
        dfa.addTransition(0, root.key, 1)
        # add a new state
        dfa.addState()
        # return DFA
        return dfa
    # if root is an operator
    else:
        # get the left and right subtrees
        left = root.left
        right = root.right
        # build DFA from left subtree
        leftDFA = buildDFA(left)
        # build DFA from right subtree
        rightDFA = buildDFA(right)
        # if root is an operator *
        if root.key == '*':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', 1)
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        # if root is an operator ?
        elif root.key == '?':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', 1)
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        # if root is an operator +
        elif root.key == '+':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        # if root is an operator |
        elif root.key == '|':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(0, '', rightDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', dfa.finalState)
            # add a new transition
            dfa.addTransition(rightDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        # if root is an operator .
        elif root.key == '.':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', rightDFA.startState)
            # add a new transition
            dfa.addTransition(rightDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        # if root is an operator )
        elif root.key == ')':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', rightDFA.startState)
            # add a new transition
            dfa.addTransition(rightDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        # if root is an operator (
        elif root.key == '(':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', rightDFA.startState)
            # add a new transition
            dfa.addTransition(rightDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        # if root is an operator /
        elif root.key == '/':
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', rightDFA.startState)
            # add a new transition
            dfa.addTransition(rightDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
        else:
            # create a new DFA
            dfa = DFA()
            # add a new state
            dfa.addState()
            # add a new transition
            dfa.addTransition(0, '', leftDFA.startState)
            # add a new transition
            dfa.addTransition(leftDFA.finalState, '', rightDFA.startState)
            # add a new transition
            dfa.addTransition(rightDFA.finalState, '', dfa.finalState)
            # add a new state
            dfa.addState()
            # return DFA
            return dfa
class DFA:
    def __init__(self):
        self.states = []
        self.startState = None
        self.finalState = None
        self.transitions = {}
    def addState(self):
        self.states.append(len(self.states))
        return len(self.states) - 1
    def addTransition(self, fromState, symbol, toState):
        if fromState not in self.transitions:
            self.transitions[fromState] = {}
        self.transitions[fromState][symbol] = toState
    def setStartState(self, state):
        self.startState = state
    def setFinalState(self, state):
        self.finalState = state
    def getStates(self):
        return self.states
    def getStartState(self):
        return self.startState
    def getFinalState(self):
        return self.finalState
    def getTransitions(self):
        return self.transitions
    def getTransition(self, fromState, symbol):
        if fromState in self.transitions:
            if symbol in self.transitions[fromState]:
                return self.transitions[fromState][symbol]
        return None
    def __str__(self):
        return "States: " + str(self.states) + "\nStart State: " + str(self.startState) + "\nFinal State: " + str(self.finalState) + "\nTransitions: " + str(self.transitions)

    # check if the string is accepted by the DFA
    def accepts(self, string):
        # current state
        state = self.startState
        # for each character in the string
        for c in string:
            # get the next state
            state = self.getTransition(state, c)
            # if there is no transition for the current character
            if state is None:
                # return False
                return False
        # if the final state is the current state
        if state == self.finalState:
            # return True
            return True
        # return False
        return False




# main function
if __name__ == '__main__':
    
    s = dottify(input('String: '))
    # build tree
    
    root = buildTree(s)
    root.preorder(); print()
    root.inorder(); print()
    root.postorder(); print()
    # build DFA
    dfa = buildDFA(root)
    # print DFA
    print(dfa)
    # get string
    string = input('String: ')
    # check if the string is accepted by the DFA
    if dfa.accepts(string):
        print('Accepted')
    else:
        print('Rejected')
