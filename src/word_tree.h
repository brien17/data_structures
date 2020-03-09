//
// Created by Cam on 3/8/2020.
//

#ifndef DATA_STRUCTURES_WORD_TREE_H
#define DATA_STRUCTURES_WORD_TREE_H


#include "double_linked_list.h"

struct tree_node {
    double_linked_list *lines = nullptr;
    std::string word = nullptr;
    tree_node *Lchild;
    tree_node *Rchild;
    int height = 0;
};

class word_tree {
private:
    // Double pointer to the root of the tree
    tree_node **root = nullptr;
public:
    // Getter for the root node
    tree_node** getRoot(){
        return root;
    }

    // Get the max of 2 numbers
    int max(int a, int b) {
        return ((a > b) ? a : b);
    }

    // Gets the height of a node passed in
    int node_height(tree_node *T) {
        if (T == NULL)
            return 0;

        // find the height of each subtree
        int lh = node_height(T->Lchild);
        int rh = node_height(T->Rchild);

        return 1 + max(lh, rh);
    }

    // Single rotate to the left
    void single_rotate_left(tree_node **T) {
        tree_node *K1, *K2;
        K2 = *T;
        K1 = (*T)->Lchild;
        K2->Lchild = K1->Rchild;
        K1->Rchild = K2;
        *T = K1;
        K1->height = node_height(K1);
        K2->height = node_height(K2);
    }

    // Single rotate to the right
    void single_rotate_right(tree_node **T) {
        tree_node *K1, *K2;
        K2 = *T;
        K1 = (*T)->Rchild;
        K2->Rchild = K1->Lchild;
        K1->Lchild = K2;
        *T = K1;
        K1->height = node_height(K1);
        K2->height = node_height(K2);
    }

    // Double rotate to the right
    void double_rotate_right(tree_node **T) {
        single_rotate_left(&((*T)->Rchild));
        single_rotate_right(T);
    }

    // Double rotate to the left
    void double_rotate_left(tree_node **T) {
        single_rotate_right(&((*T)->Rchild));
        single_rotate_left(T);
    }

    // Insert into the tree a word and the line number that the word is on
    void insert(tree_node **T, std::string word_to_insert, int line_number) {
        if (*T == nullptr) { // If there is nothing where the data belongs
            (*T) = new tree_node;
            (*T)->word = word_to_insert;
            (*T)->lines->insert_rear(line_number);
            (*T)->Lchild = (*T)->Rchild = nullptr;
            if (root == nullptr) { // If this is the first node in the tree
                root = T;
            }
        }
    }
};


#endif //DATA_STRUCTURES_WORD_TREE_H
