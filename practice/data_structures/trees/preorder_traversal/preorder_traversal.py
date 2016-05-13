"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.data (the value of the node)
"""

def preOrder(i_root):
    if i_root:
        print i_root.data,
        preOrder(i_root.left)
        preOrder(i_root.right)

