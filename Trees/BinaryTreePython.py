
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def height(root:TreeNode)->int:
    if root is None:
        return -1
    return 1 + max(height(root.left),height(root.right))
def hp(root:TreeNode,p,h): # Deapth/height of p
    if root is None:
        return False
    if root.val == p:
        return root,h
    sr = hp(root.right,p,h+1)
    sl = hp(root.left,p,h+1)
    if sr != False:
        return sr
    if sl != False:
        return sl
    return False
'''Node* findLCA(Node* root,int l1,int l2 ){
    if(!root) return NULL;
    int key = root->data;
    if(key == l1 || key == l2) return root;

    Node* leftt = findLCA(root->left,l1,l2);
    Node* rightt = findLCA(root->right,l1,l2);

    if(leftt && rightt) return root;
    if((!leftt) && (!rightt)) return NULL;
    if(rightt) return rightt;
    if(leftt) return leftt;
}'''
def findLCA(root:TreeNode,l1,l2):
    if root is None:
        return None
    key = root.val
    if (key == l1) or (key == l2):
        return root
    leftt = findLCA(root.left,l1,l2)
    rightt = findLCA(root.right,l1,l2)
    if leftt and rightt:
        return root
    if (not leftt) and (not rightt):
        return None
    if leftt:
        return leftt
    if rightt:
        return rightt

def lowest(root:TreeNode,d): # Lowest Node
    if not root:
        return None
    if root.left == None :
        if root.right == None:
            return root,d
    rl,l = lowest(root.left,d+1)
    rr,r = lowest(root.right,d+1)
    if l>=r:
        return rl,l
    return rr,r

def MinDist(root:TreeNode, n1, n2):
    lca = findLCA(root, n1, n2)
    print('LCA: ',lca.val)
    d1 = hp(lca, n1, 0)[1]
    d2 = hp(lca, n2, 0)[1]
    return d1 + d2

def MN(root:TreeNode): # Max Node
    if root is None:
        return 0
    return max(root.val,MN(root.left),MN(root.right))
def grap(root:TreeNode,adjl,adjm): # Graphify
    v = root.val
    if root.left:
        adjl[v].append(root.left.val)
        adjl[root.left.val].append(v)
        grap(root.left,adjl,adjm)
    if root.right:
        adjl[v].append(root.right.val)
        adjl[root.right.val].append(v)
        grap(root.right,adjl,adjm)

def treeBFS(adjl,src,parent,dist):
    d = dist
    for child in adjl[src]:
        if child !=parent:
            d = max(d,treeBFS(adjl,child,src,dist+1))
    return d

class Solution:
    def graphify(self,root:TreeNode):
        n = root
        nn = MN(root)
        adjl = [ [] for k in range(nn+1)]
        adjm = [[0 for _ in range(nn+1)] for _ in range(nn+1)]
        grap(root,adjl,adjm)
        return adjl



    def amountOfTime(self, root: TreeNode, start: int) -> int:
        adjl = self.graphify(root)
        return treeBFS(adjl,start,-1,0)
        # n = MN(root)
        # adjl = [ [] for k in range(n+1)]
        # adjm = [[0 for _ in range(n+1)] for _ in range(n+1)]

        
        # if root.val == start:
        #     return 0
        # n,depth = hp(root,start,0)
        # lown, lh = lowest(root,0)
        # cn = findLCA(root, lown.val, start)
        # hn = height(n);hcn = height(cn)
        # hd = depth
        # hr = height(root)
        # return max(hd+hn,hr)

# n = TreeNode(7)
# if n:
#     print(n.val)
# if n.left:
#     print(n.left.val)
# if n.right:
#     print(n.right.val)

'''
     7
    / \
   6   5
  / \   \
 4   3   2
    / \
   1   0
        '''
n = TreeNode(7)
n.left = TreeNode(6)
n.right = TreeNode(5)
n.left.left = TreeNode(4)
n.left.right = TreeNode(3)
n.right.right = TreeNode(2)
n.left.right.left = TreeNode(1)
n.left.right.right = TreeNode(0)

s = Solution()
print(s.amountOfTime(n,0))

print(MinDist(n,0,4),'is the distance between 0 and 4')
