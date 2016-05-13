"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.data (the value of the node)
"""

def postOrder(i_root):
    if i_root:
        postOrder(i_root.left)
        postOrder(i_root.right)
        print i_root.data,

