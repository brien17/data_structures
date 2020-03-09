#include <iostream>
#include "double_linked_list.h"
#include "word_tree.h"


int main() {
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
    std::cout << "Checking if the list is empty (should be 0)" <<std::endl;
    std::cout << list->empty() << std::endl;
    std::cout << "Removing the rear pointer from the list" << std::endl;
    std::cout << list->remove_rear_pntr()<< std::endl;
    std::cout << "Checking if the list is empty (should be 1)" <<std::endl;
    std::cout << list->empty() << std::endl;

    word_tree *w = new word_tree();
    tree_node *n = new tree_node();
    tree_node **x = &n;
    w->insert((w->getRoot()),"sadf",10);

    return 0;
}