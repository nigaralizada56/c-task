
#include <array>
#include <vector>
#include <iostream>

// The contents of Searching.cpp

template<typename T, std::size_t N>
int linearSearch(std::array<T, N> arr, T target) {
    for (std::size_t i = 0; i < N; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int linearSearch(std::vector<T> vec, T target) {
    for (std::size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int binarySearch(std::vector<T> vec, T target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            return mid;
        }
        else if (vec[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template<typename T>
int binarySearchFirst(std::vector<T> vec, T target) {
    int index = binarySearch(vec, target);
    if (index == -1) {
        return -1;
    }
    while (index > 0 && vec[index - 1] == target) {
        --index;
    }
    return index;
}

template<typename T, std::size_t N>
int binarySearch(std::array<T, N> arr, T target) {
    int left = 0;
    int right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template<typename T, std::size_t N>
int binarySearchFirst(std::array<T, N> arr, T target) {
    int index = binarySearch(arr, target);
    if (index == -1) {
        return -1;
    }
    while (index > 0 && arr[index - 1] == target) {
        --index;
    }
    return index;
}

// Main function to test

int main() {
    std::array<int, 6> arr = {1, 2, 2, 2, 3, 4};
    std::vector<int> vec = {1, 2, 2, 2, 3, 4};
    
    int target = 2;

    // Test binarySearchFirst for std::array
    int firstIndexArray = binarySearchFirst(arr, target);
    std::cout << "First occurrence in array: " << firstIndexArray << std::endl;

    // Test binarySearchFirst for std::vector
    int firstIndexVector = binarySearchFirst(vec, target);
    std::cout << "First occurrence in vector: " << firstIndexVector << std::endl;

    return 0;
}
