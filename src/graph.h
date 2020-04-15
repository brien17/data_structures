//
// Created by Cam on 3/23/2020.
//

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H
#include "double_linked_list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cctype>

class graph {
private:
    int size;
    std::vector<double_linked_list> my_graph;
public:
    int get_size() {
        return size;
    }

    std::vector<double_linked_list> get_graph() {
        return my_graph;
    }

    void add_vertex() {
        auto temp = new double_linked_list();
        my_graph.push_back(*temp);
        size++;
    }

    void add_connection(int start_vertex, int end_vertex) {
        my_graph[start_vertex].insert_rear(end_vertex);
    }

    void print() {
        for (int i = 1; i < my_graph.size(); i++) {
            std::cout << i;
            while (true) {
                int connection = my_graph[i].remove_front_int();
                if (connection == -1) {
                    break;
                } else {
                    std::cout << " " << connection;

                }
            }
            std::cout << '\n';
        }
    }

    void read_file(std::string const &file_path) {
        std::string line;
        std::ifstream my_file(file_path);
        int line_number = 0;
        std::vector<std::string> intersections;
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


#endif //DATA_STRUCTURES_GRAPH_H
