#include <iostream>
#include "double_linked_list.h"
#include "word_tree.h"
#include "graph.h"
#include "path_finder.h"
#include "merge_sorter.h"
#include "binary_searcher.h"

void homework1();

void homework2();

void homework3();

int main() {

    // Homework 1
    homework1();

    // Homework 2
    homework2();

    //  Homework 3
    homework3();

    return 0;
}

/**
 * This method has all of the code for homework 1.
 */
void homework1() {
    // Homework 1
    // Creating a new list
    auto *list = new double_linked_list();
    std::cout << "Adding \"5\" to front" << std::endl;
    list->insert_front(5);
    std::cout << "Adding \"10\" to front" << std::endl;
    list->insert_front(10);
    std::cout << "Adding \"50\" to front" << std::endl;
    list->insert_front(50);
    std::cout << "Adding \"20\" to rear" << std::endl;
    list->insert_rear(20);
    std::cout << "List should look like [50, 10, 5, 20]" << std::endl;
    std::cout << "List size " << list->list_size() << std::endl;
    std::cout << "Removing front int" << std::endl;
    std::cout << list->remove_front_int() << std::endl;
    std::cout << "List should look like [10, 5, 20]" << std::endl;
    std::cout << "Removing rear int" << std::endl;
    std::cout << list->remove_rear_int() << std::endl;
    std::cout << "List should look like [10, 5]" << std::endl;
    std::cout << "Removing front int" << std::endl;
    std::cout << list->remove_front_int() << std::endl;
    std::cout << "List should look like [5]" << std::endl;
    std::cout << "Removing front int" << std::endl;
    std::cout << list->remove_front_int() << std::endl;
    std::cout << "List should look like []" << std::endl;
    std::cout << "List size " << list->list_size() << std::endl;
    void *pnt = new node;
    void *pnt1 = new node;
    std::cout << "Adding a pointer to front of the list" << std::endl;
    list->insert_front(pnt);
    std::cout << "List should look like [" << pnt << "]" << std::endl;
    std::cout << "Adding a pointer to rear of the list" << std::endl;
    list->insert_rear(pnt1);
    std::cout << "List should look like [" << pnt << ", " << pnt1 << "]" << std::endl;
    std::cout << "List size " << list->list_size() << std::endl;
    std::cout << "Removing the front pointer from the list" << std::endl;
    std::cout << list->remove_front_pntr() << std::endl;
    std::cout << "List should look like [" << pnt1 << "]" << std::endl;
    std::cout << "Checking if the list is empty (should be 0)" << std::endl;
    std::cout << list->empty() << std::endl;
    std::cout << "Removing the rear pointer from the list" << std::endl;
    std::cout << list->remove_rear_pntr() << std::endl;
    std::cout << "Checking if the list is empty (should be 1)" << std::endl;
    std::cout << list->empty() << std::endl;
}

/**
 * This method has all of the code for homework 2.
 */
void homework2() {
    auto *w = new word_tree();
    w->read_file("../test.txt");
}

/**
 * This method has all of the code for homework 3.
 */
void homework3() {
    // Creating a graph from the file
    auto *g = new graph();
    g->read_file("../mapcampus.txt");

    // Looping to get user input
    while (true) {

        // Prompting the user
        std::cout << '\n'
                  << "Enter the starting intersection and the ending intersection to begin routing and c to exit"
                  << '\n';

        // Getting the input
        std::string input;
        std::getline(std::cin, input);


        if (input == "c") {
            break;
        } else {
            // Creating variables
            std::string start, end;

            // Splitting on white space
            std::stringstream stream(input);
            stream >> start >> end;

            // Shortest path
            path_finder::weighted_shortest(start, end, *g);

            std::cout << "-----------------------------------------------------\n";

            // Fastest path
            path_finder::weighted_fastest(start, end, *g);
        }
    }
}