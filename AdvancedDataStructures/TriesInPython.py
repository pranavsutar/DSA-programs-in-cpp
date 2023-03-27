# Implementing Tries

class TrieNode:
    def __init__(self):
        self.children = [None]*26
        self.isEndOfWord = False

class Trie:
    def __init__(self):
        self.root = self.getNode()

    def getNode(self):
        return TrieNode()

    def _charToIndex(self,ch:str):
        return ord(ch)-ord('a')

    def insert(self,key:str):
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self._charToIndex(key[level])
            if not pCrawl.children[index]:
                pCrawl.children[index] = self.getNode()
                pCrawl = pCrawl.children[index]
        pCrawl.isEndOfWord = True

    def search(self,key:str):
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self._charToIndex(key[level])
            if not pCrawl.children[index]:
                return False
            pCrawl = pCrawl.children[index]
        return pCrawl != None and pCrawl.isEndOfWord

    def delete(self,key:str):
        if self.search(key):
            self._delete(self.root,key,0)

    def _delete(self,root,key,depth):
        if not root:
            return None
        if depth == len(key):
            if root.isEndOfWord:
                root.isEndOfWord = False
            if self.isEmpty(root): # If the node is empty, delete it. Empty ? No children
                root = None
            return root
        index = self._charToIndex(key[depth])
        root.children[index] = self._delete(root.children[index],key,depth+1)
        if self.isEmpty(root) and root.isEndOfWord == False:
            root = None
        return root

    def isEmpty(self,root):
        for i in range(26):
            if root.children[i]:
                return False
        return True

# Driver Code
keys = ["the","a","there","answer","any","by","bye","their"]
output = ["Not present in trie","Present in trie"]
t = Trie()
for key in keys:
    t.insert(key)
    print(f'{key} inserted')
print(f'{keys[0]}\t-{output[t.search(keys[0])]}')
print(f'{keys[1]}\t-{output[t.search(keys[1])]}')
print(f'{keys[2]}\t-{output[t.search(keys[2])]}')
print(f'{keys[3]}\t-{output[t.search(keys[3])]}')
print(f'{keys[4]}\t-{output[t.search(keys[4])]}')
print(f'{keys[5]}\t-{output[t.search(keys[5])]}')
print(f'{keys[6]}\t-{output[t.search(keys[6])]}')
print(f'{keys[7]}\t-{output[t.search(keys[7])]}')
print()
t.delete(keys[0])
print(f'"{keys[0]}" deleted')
print()
print(f'{keys[0]}\t-{output[t.search(keys[0])]}')
print(f'{keys[1]}\t-{output[t.search(keys[1])]}')


# Question on Tries
# https://www.hackerrank.com/challenges/contacts/problem
