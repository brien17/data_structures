//
// Created by Cam on 3/8/2020.
//

#ifndef DATA_STRUCTURES_WORD_TREE_H
#define DATA_STRUCTURES_WORD_TREE_H


#include "double_linked_list.h"


struct tree_node {
    double_linked_list *lines;
    std::string word = "";
    tree_node *Lchild;
    tree_node *Rchild;
    int height = 0;
};

class word_tree {
private:

public:
    // Double pointer to the root of the tree
    tree_node **root = nullptr;

    // Get the max of 2 numbers
    int max(int a, int b) {
        return ((a > b) ? a : b);
    }

    // Gets the height of a node passed in
    int node_height(tree_node *T) {
        if (T == nullptr)
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
        if (root == nullptr) { // If this is the first node in the tree
            std::cout <<5;
            tree_node *temp = new tree_node();
            std::cout <<5;
            (temp)->word = word_to_insert;
            std::cout <<5;
            (temp)->lines = new double_linked_list();
            (temp)->lines->insert_rear(line_number);
            std::cout <<5;
            (temp)->Lchild = (temp)->Rchild = nullptr;
            std::cout <<5;
            root = &temp;
        } else if (*T == nullptr) { // If there is nothing where the data belongs
            std::cout << 1 << std::endl;
            (*T) = new tree_node();
            std::cout << 1 << std::endl;
            (*T)->word = word_to_insert;
            std::cout << 1 << std::endl;
            (*T)->lines = new double_linked_list();
            (*T)->lines->insert_rear(line_number);
            std::cout << 1 << std::endl;
            (*T)->Lchild = (*T)->Rchild = nullptr;
            std::cout << 1 << std::endl;
        } else if (word_to_insert.compare((*T)->word) == 0) { // Data goes here
            std::cout << 2 << std::endl;
            (*T)->lines->insert_rear(line_number);
        } else if (word_to_insert.compare((*T)->word) == 1) { // Go right
            std::cout << 3 << std::endl;
            insert((&((*T)->Lchild)), word_to_insert, line_number);
            if (node_height((*T)->Rchild) - node_height((*T)->Lchild) == 2) { // Tree is out of balance
                if (word_to_insert.compare((*T)->Rchild->word) == 1) { //
                    single_rotate_right(T);
                } else {
                    double_rotate_right(T);
                }
            }
        } else {
            std::cout << 4 << std::endl;
            insert(&((*T)->Rchild), word_to_insert, line_number);
            if (node_height((*T)->Lchild) - node_height((*T)->Rchild) == 2) { // Tree is out of balance
                if (word_to_insert.compare((*T)->Lchild->word) == -1) { //
                    single_rotate_left(T);
                } else {
                    double_rotate_left(T);
                }
            }
        }
    }

    void print_tree(tree_node **T) {
        std::cout << "0";
        if (*T != nullptr) {
            std::cout << (*T)->word.c_str() << " : ";
            std::cout << "1";
            while (true) {
                std::cout << "2";
                int line = (*T)->lines->remove_front_int();
                std::cout << "3";
                if (line == -1) {
                    break;
                } else {
                    std::cout << line << ", ";
                }
            }
            std::cout << "4";
            print_tree(&((*T)->Lchild));
            print_tree(&((*T)->Rchild));
        }
    }
};


#endif //DATA_STRUCTURES_WORD_TREE_H
