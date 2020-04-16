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
        r = list.size() - 1;
        while (r-f > 1) {
            int mid = (r+f) / 2;
            if (list[mid].compare(value) < 0) {
                f = mid + 1;
            } else {
                r = mid;
            }
        }
        if (list[f].compare(value) == 0) {
            index = f;
        } else if (list[r].compare(value) == 0) {
            index = r;
        } else {
            index = -1;
        }

        return index;
    }

};


#endif //DATA_STRUCTURES_BINARY_SEARCHER_H
