//
// Created by Cam on 3/23/2020.
//

#ifndef DATA_STRUCTURES_PATH_FINDER_H
#define DATA_STRUCTURES_PATH_FINDER_H

#include <queue>
#include "graph.h"
#include <vector>

using namespace std;

struct table {
    bool known = false;
    double dist = 100000;
    int path = -1;
};

class path_finder {
public:
    /**
     * Finds shortest path based on distance and prints the path to the console.
     * @param starting_vertex The intersection to start at
     * @param ending_vertex The ending destination
     * @param G The graph
     */
    static void weighted_shortest(std::string start, std::string end, graph G) {
        // Get the graph vector
        auto my_graph = G.get_graph();


        // Getting the indexes from the strings
        int starting_vertex = get_vertex_from_string(start, my_graph);
        int ending_vertex = get_vertex_from_string(end, my_graph);

        // If they are valid indexes
        if ((starting_vertex != -1) && (ending_vertex != -1)) {

            // Initialize the table
            std::vector<table> tables(my_graph.size());
            std::vector<int> positions(my_graph.size());

            // Adding all of the indexes to the positions vector
            for (int i = 0; i < tables.size(); i++) {
                positions[i] = i;
            }

            // Setting the distance of the starting point to zero
            tables[0].dist = 0;

            while (!positions.empty()) {

                int shortest = min_dist(positions, tables);

                tables[shortest].known = true;

                std::vector<edge> edges = my_graph[shortest].connections;

                for (int i = 0; i < edges.size(); i++) {
                    edge e = edges[i];
                    if (tables[shortest].dist + e.distance < tables[e.end_vertex].dist) {
                        tables[e.end_vertex].dist = tables[shortest].dist + e.distance;
                        tables[e.end_vertex].path = shortest;
                    }

                }
            }


            // Holds the directions to give
            std::vector<std::string> directions;

            while (!ending_vertex == starting_vertex) {
                // Getting the correct edge
                edge street;
                for (edge e : my_graph[tables[ending_vertex].path].connections) {
                    if (e.end_vertex == ending_vertex) {
                        street = e;
                    }
                }

                std::string direction = "Take " + street.street_name + " " + street.direction + " to "
                                        + my_graph[ending_vertex].intersection + " "
                                        + std::to_string(street.distance) + " miles";
                directions.push_back(direction);
                ending_vertex = tables[ending_vertex].path;
            }

            directions.push_back("From " + my_graph[starting_vertex].intersection);

            for (int i = directions.size() - 1; i >= 0; i--) {
                std::cout << directions[i] << '\n';
            }
        } else {
            std::cout << "couldn't understand input" << '\n';
        }

    }

    /**
     * Finds shortest path based on distance and prints the path to the console.
     * @param starting_vertex The intersection to start at
     * @param ending_vertex The ending destination
     * @param G The graph
     */
    static void weighted_fastest(std::string start, std::string end, graph G) {
        // Get the graph vector
        auto my_graph = G.get_graph();

        // Getting the indexes from the strings
        int starting_vertex = get_vertex_from_string(start, my_graph);
        int ending_vertex = get_vertex_from_string(end, my_graph);

        // If they are valid indexes
        if ((starting_vertex != -1) && (ending_vertex != -1)) {

            // Initialize the table
            std::vector<table> tables(my_graph.size());
            std::vector<int> positions(my_graph.size());

            // Adding all of the indexes to the positions vector
            for (int i = 0; i < tables.size(); i++) {
                positions[i] = i;
            }

            // Setting the distance of the starting point to zero
            tables[0].dist = 0;

            while (!positions.empty()) {

                int shortest = min_dist(positions, tables);

                tables[shortest].known = true;

                std::vector<edge> edges = my_graph[shortest].connections;

                for (int i = 0; i < edges.size(); i++) {
                    edge e = edges[i];
                    if (tables[shortest].dist + (e.distance / e.speed_limit) < tables[e.end_vertex].dist) {
                        tables[e.end_vertex].dist = tables[shortest].dist + (e.distance / e.speed_limit);
                        tables[e.end_vertex].path = shortest;
                    }

                }

            }


            // Holds the directions to give
            std::vector<std::string> directions;

            while (!ending_vertex == starting_vertex) {
                // Getting the correct edge
                edge street;
                for (edge e : my_graph[tables[ending_vertex].path].connections) {
                    if (e.end_vertex == ending_vertex) {
                        street = e;
                    }
                }

                std::string direction = "Take " + street.street_name + " " + street.direction + " to "
                                        + my_graph[ending_vertex].intersection + " "
                                        + std::to_string((street.distance / street.speed_limit) * 60) + " min";
                directions.push_back(direction);
                ending_vertex = tables[ending_vertex].path;
            }

            directions.push_back("From " + my_graph[starting_vertex].intersection);

            for (int i = directions.size() - 1; i >= 0; i--) {
                std::cout << directions[i] << '\n';
            }
        } else {
            std::cout << "couldn't understand input" << '\n';
        }
    }

    static int min_dist(std::vector<int> &positions, std::vector<table> t) {

        double min = t[positions[0]].dist;
        int position = positions[0];
        int counter = -1;
        int delete_index = 0;

        // Finding minimum distance
        for (int i : positions) {
            counter++;
            if ((t[i].dist < min) && !t[i].known) {
                min = t[i].dist;
                position = i;
                delete_index = counter;
            }

        }

        positions.erase(positions.begin() + delete_index);

        return position;
    }

    static int get_vertex_from_string(std::string str, vector<vertex> g) {
        int return_val = -1;
        for (int i = 0; i < g.size(); i++) {
            if (g[i].intersection.compare(str) == 0) {
                return_val = i;
            }
        }
        return return_val;
    }


};


#endif //DATA_STRUCTURES_PATH_FINDER_H
