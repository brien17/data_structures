//
// Created by Cam on 3/8/2020.
//

#ifndef DATA_STRUCTURES_WORD_TREE_H
#define DATA_STRUCTURES_WORD_TREE_H


#include "double_linked_list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cctype>




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
    tree_node *root = nullptr;

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
        single_rotate_right(&((*T)->Lchild));
        single_rotate_left(T);
    }

    // Insert into the tree a word and the line number that the word is on
    void insert(tree_node **T, std::string word_to_insert, int line_number) {
        // Making all of the words lower case
        std::transform(word_to_insert.begin(), word_to_insert.end(), word_to_insert.begin(), ::tolower);
        if (root == nullptr) { // If this is the first node in the tree
            auto *temp = new tree_node;
            (temp)->word = word_to_insert;
            (temp)->lines = new double_linked_list();
            (temp)->lines->insert_rear(line_number);
            (temp)->Lchild = (temp)->Rchild = nullptr;
            root = temp;
        } else if ((*T) == nullptr) { // If there is nothing where the data belongs
            (*T) = new tree_node;
            (*T)->word = word_to_insert;
            (*T)->lines = new double_linked_list();
            (*T)->lines->insert_rear(line_number);
            (*T)->Lchild = (*T)->Rchild = nullptr;
        } else if (word_to_insert == (*T)->word) { // Data goes here
            (*T)->lines->insert_rear(line_number);
        } else if (word_to_insert.compare((*T)->word) == 1) { // Go right
            insert((&((*T)->Lchild)), word_to_insert, line_number);
            if (node_height((*T)->Rchild) - node_height((*T)->Lchild) == 2) { // Tree is out of balance
                if (word_to_insert.compare((*T)->Rchild->word) == 1) { //
                    single_rotate_right(T);
                } else {
                    double_rotate_right(T);
                }
            }
        } else {
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

    void print_tree(tree_node *T) {
        if (T != nullptr) {
            print_tree((T)->Rchild);

            std::cout << (T)->word.c_str() << " : " << (T)->lines->remove_front_int();


            while (true) {
                int line = (T)->lines->remove_front_int();
                if (line == -1) {
                    break;
                } else {
                    std::cout << ", " << line;
                }
            }
            std::cout << '\n';

            print_tree((T)->Lchild);
        }
    }

    void read_file(std::string const &file_path) {
        std::string line;
        std::ifstream my_file(file_path);
        int line_number = 0;
        if (my_file.is_open()) {

            while (getline(my_file, line)) {
                // incrementing line number
                line_number++;

                // Creating variable to hold word
                std::string word;
                // Getting stream
                std::stringstream stream(line);
                // Splitting on whitespace for string
                while (getline(stream, word, ' ')) {
                    insert(&root, word, line_number);
                }

            }

            print_tree(root);
            my_file.close();

        } else {

            std::cout << "Unable to open file";

        }
    }
};


#endif //DATA_STRUCTURES_WORD_TREE_H
