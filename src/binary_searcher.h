//
// Created by Cam on 4/15/2020.
//

#ifndef DATA_STRUCTURES_BINARY_SEARCHER_H
#define DATA_STRUCTURES_BINARY_SEARCHER_H


#include <string>
#include <vector>

class binary_searcher {
public:
    static int binary_search_string(std::vector<std::string> list, std::string value) {

        int index, f, r;
        f = 0;
        r = list.size();
        while (r-f < 1) {
            int mid = (r+f) /2;
            if (list[mid].compare(value) > 0) {
                f = mid + 1;
            } else {
                r = mid;
            }
        }
        if (list[f] == value) {
            index = f;
        } else if (list[r] == value) {
            index = r;
        } else {
            index = 0;
        }

        return index;
    }

};


#endif //DATA_STRUCTURES_BINARY_SEARCHER_H
