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
   
    @key.setter
    def key(self, value):
        self._key = key

    @property
    def height(self):
        return self._height
    
    @height.setter
    def height(self, value):
        self._height = value


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
    
    @root.setter
    def root(self, value):
        self._root = value

    def update_node_height(self, node):
        left_node = node.left
        right_node = node.right
        left_height = right_height = 0
        if left_node != None and right_node != None:
            left_height = left_node.height
            right_height = right_node.height
        elif left_node != None:
            left_height = left_node.height
        elif right_node != None:
            right_height = right_node.height
        node.height = max(left_height, right_height) + 1
        
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
        
    def get_x_node(self, y_node):
        x_node = None
        child_left_heavy = False
        if (y_node.left != None and y_node.right != None):
            if(y_node.left.height > y_node.right.height):
                x_node = y_node.left
                child_left_heavy = True
            else:
                x_node = y_node.right
        elif (y_node.left != None):
            x_node = y_node.left
            child_left_heavy = True
        else:
            x_node = y_node.right
        return x_node,  child_left_heavy

    def inorder_traversal_structure(self,x_node, y_node, z_node):
        node_list = []
        node_list.append(x_node)
        node_list.append(y_node)
        node_list.append(z_node)
        node_list.sort()
        return node_list

    def rotate_avl_tree(self, a_node, b_node, c_node, z_node, child_left_heavy, left_heavy):
        if(z_node.parent != None):
            if(z_node.parent.left == z_node):
                z_node.parent.left = b_node
            else:
                z_node.parent.right = b_node
        z_node_parent = z_node.parent
        if(a_node.key == self.root.key or c_node.key == self.root.key):
            self.root = b_node
        #print(left_heavy, child_left_heavy)
        if(left_heavy and child_left_heavy):
            c_node.parent = b_node
            c_node.left = b_node.right
            if(b_node.right != None):
                b_node.right.parent = c_node
            b_node.left = a_node
            b_node.right = c_node
            b_node.parent = z_node_parent
        elif(not left_heavy and not child_left_heavy):
            a_node.right = b_node.left
            if(b_node.left != None):
                b_node.left.parent = a_node
            b_node.left = a_node
            b_node.right = c_node
            a_node.parent = b_node
            b_node.parent = z_node_parent
        else:
            #print(z_node_parent.key, a_node.key, z_node_parent.key, c_node.key)
            a_node.parent = b_node 
            c_node.parent = b_node 
            b_node.parent = z_node_parent 
            a_node.right = b_node.left 
            c_node.left = b_node.right 
            b_node.right = c_node 
            b_node.left = a_node 
        self.update_node_height(a_node)
        self.update_node_height(c_node)
        self.update_node_height(b_node)
        self.update_current_height(b_node)
            
    def balance_tree(self, inserted_node):
        parent_node = inserted_node.parent
        a_node = b_node = c_node = None
        left_heavy = False
        child_left_heavy = False
        while(parent_node != None):
            left_height =right_height = 0
            if parent_node.left:
                left_height = parent_node.left.height                
            if parent_node.right:
                right_height = parent_node.right.height
            if abs(left_height - right_height) >= 2:
                z_node = parent_node
                x_node = y_node = None       
                        
                if(left_height > right_height):
                    y_node = parent_node.left
                    left_heavy = True
                else:
                    y_node = parent_node.right

                if y_node != None:
                    x_node, child_left_heavy   = self.get_x_node(y_node)
                node_list = self.inorder_traversal_structure(x_node, y_node, z_node)
                a_node = node_list[0]
                b_node = node_list[1]
                c_node = node_list[2]
                break    
            parent_node = parent_node.parent
        if a_node != None and b_node != None and c_node != None:
            self.rotate_avl_tree(a_node, b_node, c_node, z_node, child_left_heavy, left_heavy)
                
            
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
        next_node.height = 1
        return next_node
         
    def insert(self, key):
        if self.root == None:
            self.root = Node(key)
            self.root.height = 1
        else:
            inserted_node = self.insert_non_root_node(key)
            self.update_current_height(inserted_node)
            self.balance_tree(inserted_node)
            #self.inorder_traversal(self.root)
            
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
    print("****************************")
    b_tree.inorder_traversal(b_tree.root)
    print("****************************")
    b_tree.insert(54)
    b_tree.inorder_traversal(b_tree.root)
    print("****************************")
    new_my_list = [14, 17, 11, 7, 5] 
    b_avl_tree = BinaryTree()
    for item in new_my_list:
        b_avl_tree.insert(item)
    b_avl_tree.inorder_traversal(b_avl_tree.root)
    print("*****************************")
    test_set = [50, 25, 10, 5, 7, 3, 30, 20, 8, 15]
    test_b_tree = BinaryTree()
    for item in test_set:
        test_b_tree.insert(item)
    test_b_tree.inorder_traversal(test_b_tree.root)
    print("Root:", test_b_tree.root.key)
    print("****************************")
    big_list = [100,55,50,45,47,70,80,78,77,79,82,81,83,150,140,135,142,143,180,170,165,160,175,173,200,190,195,500,1000,1500,2000,3000,4000,5000,6000,7000,8000,9000]
    big_avl_tree = BinaryTree()
    for item in big_list:
        big_avl_tree.insert(item)
    print("****************************")
    big_avl_tree.inorder_traversal(big_avl_tree.root)
    print("Root:", big_avl_tree.root.key)
    print("****************************")
    
if __name__ == '__main__':
    main()
