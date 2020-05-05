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

/**
 * This struct functions as an edge in the graph and represents a street in the map. It contains the street name,
 * direction, distance, speed limit, and ending vertex for the street that it is representing.
 */
struct edge {
    std::string street_name;
    std::string direction;
    double distance;
    int speed_limit;
    int end_vertex;
};


/**
 * This struct functions as a vertex in the graph and represents an intersection on the map. It contains the
 * intersection name and vector of the edges that it has.
 */
struct vertex {
    std::string intersection;
    std::vector<edge> connections;

};


/**
 * This class contains a graph and the methods that operate the graph. The graph is used to model streets and \
 * intersections for a map.
 */
class graph {
private:
    // The graph object
    std::vector<vertex> my_graph;
public:

    /**
     * This method is a getter for the my_graph field.
     * @return The my_graph field
     */
    std::vector<vertex> get_graph() {
        return my_graph;
    }

    /**
     * This method allows you to add a vertex to the graph
     * @param name
     */
    void add_vertex(std::string &name) {
        auto temp = new vertex();
        temp->intersection = name;
        my_graph.push_back(*temp);
    }

    /**
     * This method allows you to add an edge to the graph.
     * @param start_vertex The starting vertex of the edge
     * @param end_vertex The ending vertex of the edge
     * @param street The street name of the edge
     * @param dir The cardinal direction the edge goes in
     * @param dist The length of the edge
     * @param speed The speed limit for the edge
     */
    void add_edge(int start_vertex,
                        int end_vertex,
                        std::string &street,
                        std::string &dir,
                        double dist,
                        int speed) {
        auto temp = new edge();
        temp->street_name = street;
        temp->direction = dir;
        temp->distance = dist;
        temp->speed_limit = speed;
        temp->end_vertex = end_vertex;
        my_graph[start_vertex].connections.push_back(*temp);
    }


    /**
     * This method reads from a file and creates a graph based on the information in the file.
     * @param file_path The path to the file
     */
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
                my_file2 >> start_intersection >> street_name >> end_intersection >> direction >> dist_temp
                         >> speed_temp;
                distance = std::stod(dist_temp);
                speed_limit = std::stoi(speed_temp);

                // Adding the connection
                add_edge(binary_searcher::binary_search_string(intersections_vect, start_intersection),
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
