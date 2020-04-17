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
#include <ios>


struct edge {
    std::string street_name;
    std::string direction;
    double distance;
    int speed_limit;
    int end_vertex;
};

struct vertex {
    std::string intersection;
    std::vector<edge> connections;

};


class graph {
private:
    int size;
    std::vector<vertex> my_graph;
public:
    int get_size() {
        return size;
    }

    std::vector<vertex> get_graph() {
        return my_graph;
    }

    void add_vertex(std::string name) {
        auto temp = new vertex();
        temp->intersection = name;
        my_graph.push_back(*temp);
        size++;
    }

    void add_connection(int start_vertex, int end_vertex, std::string street, std::string dir, double dist, int speed) {
        auto temp = new edge();
        temp->street_name = street;
        temp->direction = dir;
        temp->distance = dist;
        temp->speed_limit = speed;
        temp->end_vertex = end_vertex;
        my_graph[start_vertex].connections.push_back(*temp);
    }

//    void print() {
//        for (int i = 1; i < my_graph.size(); i++) {
//            std::cout << i;
//            while (true) {
//                int connection = my_graph[i].connections.remove_front_int();
//                if (connection == -1) {
//                    break;
//                } else {
//                    std::cout << " " << connection;
//
//                }
//            }
//            std::cout << '\n';
//        }
//    }

    void read_file(std::string const &file_path) {
        std::string line;
        std::ifstream my_file(file_path);
        // Set to hold all unique intersections
        std::set<std::string> intersections;
        // Vector to hold intersections so they can be sorted
        std::vector<std::string> intersections_vect(intersections.begin(), intersections.end());

        if (my_file.is_open()) {

            // Looping to create vertices
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

            // Copy set to vector
            intersections_vect.assign(intersections.begin(), intersections.end());

            // Sorting the intersections
            merge_sorter::sort(intersections_vect);

            // Adding nodes to the graph for each intersection
            for (std::string intersection : intersections_vect) {
                add_vertex(intersection);
            }

            // Closing file
            my_file.close();

            std::ifstream my_file2(file_path);

            // Looping to create edges
            while (getline(my_file2, line)) {
                // Creating variables to hold data
                std::string start_intersection, end_intersection, street_name, direction, dist_temp, speed_temp;
                double distance;
                int speed_limit;

                // Getting stream
                std::stringstream stream(line);

                // Splitting on whitespace for string
                my_file2 >> start_intersection >> street_name >> end_intersection >> direction >> dist_temp >> speed_temp;
                distance = std::stod(dist_temp);
                speed_limit = std::stoi(speed_temp);

                // Adding the connection
                add_connection(binary_searcher::binary_search_string(intersections_vect, start_intersection),
                               binary_searcher::binary_search_string(intersections_vect, end_intersection),
                               street_name, direction, distance, speed_limit);
            }

            // Closing file
            my_file2.close();

        } else {
            std::cout << "Unable to open file";
        }
    }
};


#endif //DATA_STRUCTURES_GRAPH_H
