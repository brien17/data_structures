//
// Created by cam on 3/9/2020.
//

#ifndef DATA_STRUCTURES_HASH_H
#define DATA_STRUCTURES_HASH_H


class hash {
public:
    // General hashing function
    // A is a char array used to create the hash number, n is the size of the hash table
    int add(char A[], int n) {
        char *p = A;
        unsigned int return_val = 0;
        // While there are char in the char array
        while (p != nullptr) {
            // Shifts return val 5 to the left (multiply by 32) then add next char
            return_val = (return_val << 5u) + *(p++);
        }
        return return_val % n;
    }


};


#endif //DATA_STRUCTURES_HASH_H
