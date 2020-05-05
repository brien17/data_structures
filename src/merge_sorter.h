//
// Created by Cam on 4/15/2020.
//

#ifndef DATA_STRUCTURES_MERGE_SORTER_H
#define DATA_STRUCTURES_MERGE_SORTER_H

#include <string>
#include <vector>
#include <iostream>


/**
 * This class is an implementation of a merge sort that has methods to sort vectors containing strings or ints.
 */
class merge_sorter {
public:
    /**
     * This method performs the search on a vector of strings.
     * @param list The list of strings to be searched
     */
    static void sort(std::vector<std::string> &list) {
        std::vector<std::string> temp_list(list.size());
        msort(list, temp_list, 0, list.size() - 1);
    }

    /**
    * This method performs the search on a vector of ints.
    * @param list The list of strings to be searched
    */
    static void sort(std::vector<int> &list) {
        std::vector<int> temp_list(list.size());
        msort(list, temp_list, 0, list.size() - 1);
    }

    /**
     * This method performs the sort by finding the center of the list then calling itself on the left half and the
     * right half and then calling the merge method.
     * @param list The list to be sorted
     * @param temp_list The temporary list that is used in the sorting algorithm
     * @param left The left ending index of the list
     * @param right The right ending index of the list
     */
    static void msort(std::vector<std::string> &list, std::vector<std::string> &temp_list, int left, int right) {
        int center;
        if (left < right) {
            center = (left + right) / 2;
            msort(list, temp_list, left, center);
            msort(list, temp_list, center + 1, right);
            merge(list, temp_list, left, center + 1, right);
        }
    }

    /**
    * This method performs the sort by finding the center of the list then calling itself on the left half and the
    * right half and then calling the merge method.
    * @param list The list to be sorted
    * @param temp_list The temporary list that is used in the sorting algorithm
    * @param left The left ending index of the list
    * @param right The right ending index of the list
    */
    static void msort(std::vector<int> &A, std::vector<int> &TA, int left, int right) {
        int center;

        if (left < right) {
            center = (left + right) / 2;
            msort(A, TA, left, center);
            msort(A, TA, center + 1, right);
            merge(A, TA, left, center + 1, right);
        }
    }

    /**
     * This method performs the merge operation of the algorithm by adding the elements of a two sublists to the
     * temp list in a sorted order and using that to sort a section of the full list.
     * @param list The list to be sorted
     * @param temp_list The temporary list that is used in the sorting algorithm
     * @param left The left ending index
     * @param right The right ending index of the left list
     * @param right_end The right ending index of the right list
     */
    static void merge(std::vector<std::string> &list, std::vector<std::string> &temp_list, int left, int right, int right_end) {

        int left_end = right - 1;
        int temp = left;
        int n = right_end - left + 1;

        while (left <= left_end && right <= right_end) {
            if (list[left].compare(list[right]) <= 0) {
                temp_list[temp++] = list[left++];
            } else {
                temp_list[temp++] = list[right++];
            }
        }

        while (left <= left_end) {
            temp_list[temp++] = list[left++];
        }

        while (right <= right_end) {
            temp_list[temp++] = list[right++];
        }

        for (int i = 0; i < n; i++) {
            list[right_end] = temp_list[right_end];
            --right_end;
        }
    }

    /**
    * This method performs the merge operation of the algorithm by adding the elements of a two sublists to the
    * temp list in a sorted order and using that to sort a section of the full list.
    * @param list The list to be sorted
    * @param temp_list The temporary list that is used in the sorting algorithm
    * @param left The left ending index
    * @param right The right ending index of the left list
    * @param right_end The right ending index of the right list
    */
    static void merge(std::vector<int> &A, std::vector<int> &TA, int left, int right, int right_end) {

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

        for (unsigned int i = 0; i < TA.size(); i++) {
            A[i] = TA[i];
        }
    }
};


#endif //DATA_STRUCTURES_MERGE_SORTER_H
