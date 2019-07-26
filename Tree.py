# -*- coding: utf-8 -*-
"""
Created on Sat Jul 20 17:47:19 2019

@author: shashitth
"""

class Node():
    def __init__(self, key):
        self._key = key
        self.parent = None
        self.left = None
        self.right = None
        self._height = 0
        
    @property
    def key(self):
        return self._key
    
    @property
    def height(self):
        return self._height

    def __lt__(self, other):
        return self.key < other.key
    
class AVLTree():
    
    def __init__(self):
        self._root = None
    
    @property
    def root(self):
        return self._root
       
    def insert_non_root_node(self, key):
        next_node = self.root
        parent_node = self.root
        while(next_node != None):
            if parent_node.key > key:
                parent_node = next_node
                next_node = next_node.left
            else:
                parent_node = next_node
                next_node = next_node.right
        if parent_node.key < key:
            print("right node", key, "@ parent", parent_node.key)
            next_node = Node(key)
            parent_node.right = next_node
            parent_node.height += 1
        else:
            print("left node", key, "@ parent", parent_node.key)
            next_node = Node(key)
            parent_node.left = next_node
            parent_node.height += 1

    def insert(self, key):
        if self.root == None:
            self.root = Node(key)
        else:
            self.insert_non_root_node(key)
        
            
class BinaryTree():
    def __init__(self):
        self._root = None
    
    @property
    def root(self):
        return self._root
    
    def update_current_height(self, node):

        parent_node = node.parent
        if parent_node == None:
            return
        left_node_height = right_node_height = 0        
        left_node = parent_node.left
        right_node = parent_node.right
        if left_node != None:
            left_node_height = left_node.height
        if right_node != None:
            right_node_height = right_node.height
        parent_node.height= max (left_node_height, right_node_height) + 1
        self.update_current_height(parent_node)        
        
    def get_x_node(self, y_node, child_left_heavy):
        x_node = None        
        if (y_node.left != None and y_node.right != None):
            if(y_node.left.height > y_node.right.height):
                x_node = y_node.left
                child_left_heavy = True
            else:
                x_node = y_node.right
        elif (y_node.left != None):
            x_node = y_node.left
            child_left_heavy = True
            print(child_left_heavy )
        else:
            x_node = y_node.right
        return x_node

    def inorder_traversal_structure(self,x_node, y_node, z_node):
        node_list = []
        node_list.append(x_node)
        node_list.append(y_node)
        node_list.append(z_node)
        node_list.sort()
        a_node = node_list[0]
        b_node = node_list[1]
        c_node = node_list[2]
        return node_list

    def rotate_avl_tree(self, a_node, b_node, c_node, z_node, left_heavy):
        if(child_left_heavy):
            z_node.parent.left = b_node
        else:
            z_node.parent.right = b_node
        a_node.parent = b_node # 50 ->62
        c_node.parent = b_node # 78 ->62
        b_node.parent = z_node.parent #62->44
        a_node.right = b_node.left # 54
        c_node.left = b_node.right # None
        b_node.right = c_node # 78
        b_node.left = a_node # 50
    
    
    def balance_tree(self, inserted_node):
        parent_node = inserted_node.parent
        a_node = b_node = c_node = None
        while(parent_node != None):
            left_height =right_height = 0
            if parent_node.left:
                left_height = parent_node.left.height                
            if parent_node.right:
                right_height = parent_node.right.height
            if abs(left_height - right_height) > 1:
                z_node = parent_node
                x_node = y_node = None       
                
                left_heavy = False
                child_left_heavy = False

                if(left_height > right_height):
                    y_node = parent_node.left
                    left_heavy = True
                else:
                    y_node = parent_node.right

                if y_node != None:
                    x_node  = self.get_x_node(y_node, child_left_heavy)

                node_list = self.inorder_traversal_structure(x_node, y_node, z_node)
                break    
            parent_node = parent_node.parent
        if a_node != None and b_node != None and c_node != None:
            self.rotate_avl_tree(a_node, b_node, c_node, z_node, child_left_heavy)
                
            
    def insert_non_root_node(self, key):
        next_node = self.root
        parent_node = self.root
        while(next_node != None):
            if parent_node.key > key:
                temp = next_node
                next_node = parent_node.left
                parent_node = temp
            else:
                temp = next_node
                next_node = parent_node.right
                parent_node = temp
        if parent_node.key < key:
            next_node = Node(key)
            next_node.parent = parent_node
            parent_node.right = next_node
        else:
            next_node = Node(key)
            next_node.parent = parent_node            
            parent_node.left = next_node
        return next_node
         
    def insert(self, key):
        if self.root == None:
            self.root = Node(key)
        else:
            inserted_node = self.insert_non_root_node(key)
            self.update_current_height(inserted_node)
            self.balance_tree(inserted_node)
            
    def inorder_traversal(self, node):
        left_node = node.left
        if left_node != None:
            self.inorder_traversal(left_node)
        print(node.key, node.height)
        right_node = node.right
        if right_node != None:
            self.inorder_traversal(right_node)


def main():
    b_tree = BinaryTree()
    my_list = [44, 17, 32, 78, 50, 48, 62, 88]
    for item in my_list:
        b_tree.insert(item)
    b_tree.inorder_traversal(b_tree.root)
    print("****************************")
    b_tree.insert(54)
    b_tree.inorder_traversal(b_tree.root)
if __name__ == '__main__':
    main()
