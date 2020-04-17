#include <iostream>
#include "double_linked_list.h"
#include "word_tree.h"
#include "graph.h"
#include "path_finder.h"
#include "merge_sorter.h"
#include "binary_searcher.h"

int main() {
//    // Homework 1
//    // Creating a new list
//    auto *list = new double_linked_list();
//    std::cout << "Adding \"5\" to front" << std::endl;
//    list->insert_front(5);
//    std::cout << "Adding \"10\" to front" << std::endl;
//    list->insert_front(10);
//    std::cout << "Adding \"50\" to front" << std::endl;
//    list->insert_front(50);
//    std::cout << "Adding \"20\" to rear" << std::endl;
//    list->insert_rear(20);
//    std::cout << "List should look like [50, 10, 5, 20]" << std::endl;
//    std::cout << "List size " << list->list_size() << std::endl;
//    std::cout << "Removing front int" << std::endl;
//    std::cout << list->remove_front_int() << std::endl;
//    std::cout << "List should look like [10, 5, 20]" << std::endl;
//    std::cout << "Removing rear int" << std::endl;
//    std::cout << list->remove_rear_int() << std::endl;
//    std::cout << "List should look like [10, 5]" << std::endl;
//    std::cout << "Removing front int" << std::endl;
//    std::cout << list->remove_front_int() << std::endl;
//    std::cout << "List should look like [5]" << std::endl;
//    std::cout << "Removing front int" << std::endl;
//    std::cout << list->remove_front_int() << std::endl;
//    std::cout << "List should look like []" << std::endl;
//    std::cout << "List size " << list->list_size() << std::endl;
//    void *pnt = new node;
//    void *pnt1 = new node;
//    std::cout << "Adding a pointer to front of the list" << std::endl;
//    list->insert_front(pnt);
//    std::cout << "List should look like [" << pnt << "]" << std::endl;
//    std::cout << "Adding a pointer to rear of the list" << std::endl;
//    list->insert_rear(pnt1);
//    std::cout << "List should look like [" << pnt << ", " << pnt1 << "]" << std::endl;
//    std::cout << "List size " << list->list_size() << std::endl;
//    std::cout << "Removing the front pointer from the list" << std::endl;
//    std::cout << list->remove_front_pntr() << std::endl;
//    std::cout << "List should look like [" << pnt1 << "]" << std::endl;
//    std::cout << "Checking if the list is empty (should be 0)" <<std::endl;
//    std::cout << list->empty() << std::endl;
//    std::cout << "Removing the rear pointer from the list" << std::endl;
//    std::cout << list->remove_rear_pntr()<< std::endl;
//    std::cout << "Checking if the list is empty (should be 1)" <<std::endl;
//    std::cout << list->empty() << std::endl;
//
//    // Homework 2
//    word_tree *w = new word_tree();
//    w->read_file("../test.txt");
//    auto my_graph = new graph();
//    my_graph->add_vertex();
//    my_graph->add_vertex();
//    my_graph->add_vertex();
//    my_graph->add_connection(1,2);
//    my_graph->add_connection(1,3);
//    my_graph->add_connection(2,3);
//    my_graph->print();
//    auto p = new path_finder();
//    p->unweighted(1, *my_graph);
//
//  Homework 3

    // Creating a graph from the file
    graph *g = new graph();
    g->read_file("../mapcampus.txt");

    while (true) {

        std::cout << '\n'
                  << "Enter the starting intersection and the ending intersection to begin routing and c to exit"
                  << '\n';

        std::string input;

        std::getline(std::cin, input);

        if (input.compare("c") == 0) {
            break;
        } else {
            // Creating variables
            std::string start, end;

            // Splitting on white space
            std::stringstream stream(input);
            stream >> start >> end;

            std::cout << path_finder::get_vertex_from_string(start, g->get_graph()) << path_finder::get_vertex_from_string(end, g->get_graph());

            // Shortest path
            path_finder::weighted_shortest(start, end, *g);

            // Fastest path
            path_finder::weighted_fastest(start, end, *g);
        }
    }


    return 0;
}