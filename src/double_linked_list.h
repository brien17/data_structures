//
// Created by cam on 1/13/2020.
//

#ifndef DATA_STRUCTURES_DOUBLE_LINKED_LIST_H
#define DATA_STRUCTURES_DOUBLE_LINKED_LIST_H

#include <iostream>

/**
 * This node represents one element in the linked list. It contains an int data, a void pointer for data, a pointer to
 * the next node and a pointer to the previous node.
 */
struct node {
    int int_data;
    void *pnt_data;
    node *next = nullptr;
    node *prev = nullptr;
};

/**
 * This class is the double linked list and has methods for inserting and removing ints and pointers from the front
 * and rear of the list.
 */
class double_linked_list {

private:
    node *front = nullptr;
    node *rear = nullptr;
    int size = 0;


public:

    /**
     * This method allows you to insert an int into the front of the double linked list.
     * @param new_data The int to insert
     */
    void insert_front(int new_data) {
        node *n = new node;

        // Adding the data
        n->int_data = new_data;
        if (front == nullptr) { // Case empty list;
            // Setting the front and rear
            front = rear = n;
            // Incrementing size
            size++;
        } else { // Case one or more elements
            // Setting next and prev in new node
            n->next = front;
            n->prev = nullptr;
            // Setting previous in second node in list
            front->prev = n;
            // Setting front
            front = n;
            // Incrementing size
            size++;
        }
    }

    /**
     * This method allows you to insert a void pointer into the front of the double linked list.
     * @param new_data The void pointer to insert
     */
    void insert_front(void *new_data) {
        node *n = new node;
        // Adding the data
        n->pnt_data = new_data;
        if (front == nullptr) { // Case empty list;
            // Setting the front and rear
            front = rear = n;
            // Incrementing size
            size++;
        } else { // Case one or more elements
            // Setting next and prev in new node
            n->next = front;
            n->prev = nullptr;
            // Setting previous in second node in list
            front->prev = n;
            // Setting front
            front = n;
            // Incrementing size
            size++;
        }
    }

    /**
     * This method allows you to insert an int into the rear of the double linked list.
     * @param new_data The int to insert
     */
    void insert_rear(int new_data) {
        node *n = new node;
        // Adding the data
        n->int_data = new_data;
        if (rear == nullptr) { // Case empty list
            // Setting the front and rear
            front = rear = n;
            // Incrementing size
            size++;
        } else { // Case one or more elements
            // Setting previous nad next in new node
            n->next = nullptr;
            n->prev = rear;
            // Setting the next of the second to last node
            rear->next = n;
            // Setting rear to the new node
            rear = n;
            // Incrementing size
            size++;
        }
    }

    /**
     * This method allows you to insert a void pointer into the rear of the double linked list.
     * @param new_data The void pointer to insert
     */
    void insert_rear(void *new_data) {
        node *n = new node;
        // Adding the data
        n->pnt_data = new_data;
        if (rear == nullptr) { // Case empty list
            // Setting the front and rear
            front = rear = n;
            // Incrementing size
            size++;
        } else { // Case one or more elements
            // Setting previous nad next in new node
            n->next = nullptr;
            n->prev = rear;
            // Setting the next of the second to last node
            rear->next = n;
            // Setting rear to the new node
            rear = n;
            // Incrementing size
            size++;
        }
    }

    /**
     * This method removes the front int from the double linked list.
     * @return The front int of the list
     */
    int remove_front_int() {
        int hold = 0;
        if (front == nullptr) { // Case empty list
            return -1;
        } else if (front == rear) { // Case one item
            // Getting data
            hold = front->int_data;
            // Deleting front
            delete front;
            // Setting front and rear to null
            front = rear = nullptr;
            // Decrementing size
            size--;
        } else { // Case two or more
            // Getting data
            hold = front->int_data;
            // Setting front to next node
            front = front->next;
            // Deleting front node
            delete front->prev;
            // Setting previous of next node to null
            front->prev = nullptr;
            // Decrementing size
            size--;
        }
        return hold;
    }

    /**
     * This method removes the front void pointer from the double linked list
     * @return The front void pointer of the list
     */
    void *remove_front_pntr() {
        void *hold = nullptr;
        if (front == nullptr) { // Case empty list
            return front;
        } else if (front == rear) { // Case one item
            // Getting data
            hold = front->pnt_data;
            // Deleting front
            delete front;
            // Setting front and rear to null
            front = rear = nullptr;
            // Decrementing size
            size--;
        } else { // Case two or more
            // Getting data
            hold = front->pnt_data;
            // Setting front to next node
            front = front->next;
            // Deleting front node
            delete front->prev;
            // Setting previous of next node to null
            front->prev = nullptr;
            // Decrementing size
            size--;
        }
        return hold;
    }

    /**
     * This method removes the rear int from the double linked list
     * @return The rear int of the list
     */
    int remove_rear_int() {
        int hold = 0;
        if (rear == nullptr) { // Case empty list
            return 0;
        } else if (front == rear) { // Case one item
            // Getting data
            hold = rear->int_data;
            // Deleting node
            delete rear;
            // Making front and rear null
            front = rear = nullptr;
            // Decrementing size
            size--;
        } else { // Case two or more
            // Getting data
            hold = rear->int_data;
            // Setting rear to second to last item
            rear = rear->prev;
            // Deleting last item
            delete rear->next;
            // Setting next in rear to null
            rear->next = nullptr;
            // Decrementing size
            size--;
        }
        return hold;
    }

    /**
     * This method removes the rear void pointer from the double linked list
     * @return The rear void pointer of the list
     */
    void *remove_rear_pntr() {
        void *hold = nullptr;
        if (rear == nullptr) { // Case empty list
            return rear;
        } else if (front == rear) { // Case one item
            // Getting data
            hold = rear->pnt_data;
            // Deleting node
            delete rear;
            // Making front and rear null
            front = rear = nullptr;
            // Decrementing size
            size--;
        } else { // Case two or more
            // Getting data
            hold = rear->pnt_data;
            // Setting rear to second to last item
            rear = rear->prev;
            // Deleting last item
            delete rear->next;
            // Setting next in rear to null
            rear->next = nullptr;
            // Decrementing size
            size--;
        }
        return hold;
    }

    /**
     * This method returns the size of the list.
     * @return The int of the size of the list
     */
    int list_size() {
        return size;
    }

    /**
     * This method returns 1 if the list is empty and 0 if the list is not empty.
     * @return 1 if the list is empty or 0 if the list is not empty
     */
    int empty() {
        if (rear == nullptr) { // If the list is empty
            return 1;
        } else { // If the list is not empty
            return 0;
        }
    }

};


#endif //DATA_STRUCTURES_DOUBLE_LINKED_LIST_H
