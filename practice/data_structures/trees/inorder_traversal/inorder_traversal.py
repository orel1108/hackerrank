"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.data (the value of the node)
"""

def inOrder(i_root):
    if i_root:
        inOrder(i_root.left)
        print i_root.data,
        inOrder(i_root.right)

