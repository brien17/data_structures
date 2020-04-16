//
// Created by Cam on 3/23/2020.
//

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H
#include "double_linked_list.h"
#include "merge_sorter.h"
#include "binary_searcher.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cctype>

struct graph_node {
    std::string intersection;
    std::string direction;
    int distance;
    int speed_limit;
    double_linked_list connections;

};


class graph {
private:
    int size;
    std::vector<graph_node> my_graph;
public:
    int get_size() {
        return size;
    }

    std::vector<graph_node> get_graph() {
        return my_graph;
    }

    void add_vertex(std::string name) {
        auto temp = new graph_node();
        temp->intersection = name;
        my_graph.push_back(*temp);
        size++;
    }

    void add_connection(int start_vertex, int end_vertex) {
        my_graph[start_vertex].connections.insert_rear(end_vertex);
    }

    void print() {
        for (int i = 1; i < my_graph.size(); i++) {
            std::cout << i;
            while (true) {
                int connection = my_graph[i].connections.remove_front_int();
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
        // Set to hold all unique intersections
        std::set<std::string> intersections;
        // Vector to hold intersections so they can be sorted
        std::vector<std::string> intersections_vect(intersections.begin(), intersections.end());

        if (my_file.is_open()) {

            while (getline(my_file, line)) {
                // Creating variable to hold intersection
                std::string intersection;

                // Getting stream
                std::stringstream stream(line);

                // Splitting on whitespace for string
                getline(stream, intersection, ' ');

                // Adding intersection to the list
                intersections.insert(intersection);

            }
            // Closing resources
            my_file.close();

            // Copy set to vector
            intersections_vect.assign(intersections.begin(), intersections.end());

            // Sorting the intersections
            merge_sorter::sort(intersections_vect);

            // Adding nodes to the graph for each intersection
            for (std::string intersection : intersections_vect) {
                add_vertex(intersection);
            }

            std:: cout << binary_searcher::binary_search_string(intersections_vect, "Centaurus&Gemini");


        } else {

            std::cout << "Unable to open file";

        }
    }
};


#endif //DATA_STRUCTURES_GRAPH_H
