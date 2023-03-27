
class Node:
    def __init__(self, data):
        self.key = data
        self.left = None
        self.right = None
        self.graph = dict()
    def __str__(self):
        return str(self.key)
    def Printinorder(self):
        if self.left:
            self.left.Printinorder()
        print(self.key, end=' ')
        if self.right:
            self.right.Printinorder()
    def inorder(self):
        print('Inorder: ', end='')
        self.Printinorder()
        print()
    def Printpreorder(self):
        print(self.key, end=' ')
        if self.left:
            self.left.Printpreorder()
        if self.right:
            self.right.Printpreorder()
    def preorder(self):
        print('Preorder: ', end='')
        self.Printpreorder()
        print()
    def Printpostorder(self):
        if self.left:
            self.left.Printpostorder()
        if self.right:
            self.right.Printpostorder()
        print(self.key, end=' ')
    def postorder(self):
        print('Postorder: ', end='')
        self.Printpostorder()
        print()

    def ReturnGraph(self):
        graph = {}
        graph[self.key] = []
        if self.left:
            graph[self.key].append(self.left.key)
            graph.update(self.left.ReturnGraph())
        if self.right:
            graph[self.key].append(self.right.key)
            graph.update(self.right.ReturnGraph())
        return graph

def use(d:dict, key, value):
    if key in d:
        d[key].append(value)
    else:
        d[key] = [value]

adjl = dict() # Adjacency List

def TreeToGraph(root):
    if root:
        if root.left:
            use(adjl, root.key, root.left.key)
            TreeToGraph(root.left)
        if root.right:
            use(adjl, root.key, root.right.key)
            TreeToGraph(root.right)
def TreeToUndirectedGraph(root):
    if root:
        if root.left:
            use(adjl, root.key, root.left.key)
            use(adjl, root.left.key, root.key)
            TreeToUndirectedGraph(root.left)
        if root.right:
            use(adjl, root.key, root.right.key)
            use(adjl, root.right.key, root.key)
            TreeToUndirectedGraph(root.right)

def PrintGraph():
    print('Adjacency List:')
    for i in adjl:
        print(i, '->', adjl[i])
def FarestDistance(source):
    dist = dict()
    dist[source] = 0
    q = [source]
    while q:
        u = q.pop(0)
        for v in adjl[u]:
            if v not in dist:
                dist[v] = dist[u]+1
                q.append(v)
    return max(dist.values())

if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.left.left.left = Node(8)
    root.left.left.right = Node(9)
    root.left.right.left = Node(10)
    root.left.right.right = Node(11)
    root.right.left.left = Node(12)
    root.inorder()
    root.preorder()
    root.postorder()
    # TreeToGraph(root)
    TreeToUndirectedGraph(root)
    PrintGraph()
    print(1,':',FarestDistance(1))
    print(6,':',FarestDistance(6))
    print(11,':',FarestDistance(11))

