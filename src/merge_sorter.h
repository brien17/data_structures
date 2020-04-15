//
// Created by Cam on 4/15/2020.
//

#ifndef DATA_STRUCTURES_MERGE_SORTER_H
#define DATA_STRUCTURES_MERGE_SORTER_H

#include <string>
#include <vector>
#include <iostream>

class merge_sorter {
public:
    static void sort(std::vector<std::string> &A) {
        std::vector<std::string> TA(A.size());
        msort(A, TA, 0, A.size()-1);
    }

    static void sort(std::vector<int> &A) {
        std::vector<int> TA(A.size());
        msort(A, TA, 0, A.size()-1);
    }

    static void msort(std::vector<std::string> &A, std::vector<std::string> TA, int left, int right) {
        int center;

        if (left < right) {
            center = (left+right) / 2;
            msort(A, TA, left, center);
            msort(A, TA, center+1, right);
            merge(A, TA, left, center+1, right);
        }
    }

    static void msort(std::vector<int> &A, std::vector<int> TA, int left, int right) {
        int center;

        if (left < right) {
            center = (left+right) / 2;
            msort(A, TA, left, center);
            msort(A, TA, center+1, right);
            merge(A, TA, left, center+1, right);
        }
    }

    static void merge(std::vector<std::string> &A, std::vector<std::string> TA, int left, int right, int right_end) {

        int left_end = right - 1;
        int temp = left;
        int n = right_end - left + 1;

        while (left <= left_end && right <= right_end) {
            if (A[left].compare(A[right]) <= 0) {
                TA[temp++] = A[left++];
            } else {
                TA[temp++] = A[right++];
            }
        }

        while (left <= left_end) {
            TA[temp++] = A[left++];
        }

        while (right <= right_end) {
            TA[temp++] = A[right++];
        }

        for (int i = 0; i < TA.size(); i++) {
            A[i] = TA[i];
        }
    }

    static void merge(std::vector<int> &A, std::vector<int> TA, int left, int right, int right_end) {

        int left_end = right - 1;
        int temp = left;
        int n = right_end - left + 1;

        while (left <= left_end && right <= right_end) {
            if (A[left] <= A[right]) {
                TA[temp++] = A[left++];
            } else {
                TA[temp++] = A[right++];
            }
        }

        while (left <= left_end) {
            TA[temp++] = A[left++];
        }

        while (right <= right_end) {
            TA[temp++] = A[right++];
        }

        for (int i = 0; i < TA.size(); i++) {
            A[i] = TA[i];
        }
    }
};


#endif //DATA_STRUCTURES_MERGE_SORTER_H
