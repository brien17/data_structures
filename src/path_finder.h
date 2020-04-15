//
// Created by Cam on 3/23/2020.
//

#ifndef DATA_STRUCTURES_PATH_FINDER_H
#define DATA_STRUCTURES_PATH_FINDER_H

#include <queue>
#include "graph.h"

using namespace std;

struct Table {
    int dist = -1;
    int path;
};

class path_finder {
public:
    void unweighted(int starting_vertex, graph G) {
        std::vector<double_linked_list> graph = G.get_graph();
        queue <int> Q;
        int W,V;
        double_linked_list p;
        int size = G.get_size() + 1;
        std::vector<Table> T; // Make this a vector c++ arrays are cancer
        for (int i = 1; i < size; i++) {
            T.push_back(*(new Table()));
        }
        T[starting_vertex].dist = 0;

        Q.push(starting_vertex);
        while (!Q.empty()) {
            V = Q.front();
            p = graph[V];
            while (true) {
                int temp = p.remove_front_int();
                if (temp == -1) {
                    break;
                } else {
                    W = temp;
                    if (T[W].dist == -1) {
                        T[W].dist = T[V].dist + 1;
                        T[W].path = V;
                        Q.push(W);
                    }
                }
            }

        }
        cout << "vertex | dist | path" << endl;
        for (int j = 1; j < T.size(); j++) {
            cout << j << " | " << T[j].dist << " | " << T[j].path << endl;
        }
    }

    void weighted(int starting_vertex, graph G) {

    }
};


#endif //DATA_STRUCTURES_PATH_FINDER_H
