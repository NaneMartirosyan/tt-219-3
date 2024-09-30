#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

void findMaxProduct(const std::vector<int>& arr) {
    int n = arr.size();
    if (n < 2) {
        std::cout << "Array must have at least two elements!" << std::endl;
        return;
    }

    std::vector<int> sorted_arr = arr; 
    std::sort(sorted_arr.begin(), sorted_arr.end());
    int product1 = sorted_arr[n-1] * sorted_arr[n-2];
    int element1a = sorted_arr[n-1];
    int element1b = sorted_arr[n-2];

    int product2 = sorted_arr[0] * sorted_arr[1];
    int element2a = sorted_arr[0];
    int element2b = sorted_arr[1];

    if (product1 > product2) {
        std::cout << "The two elements with the maximum product are: " 
                  << element1a << " and " << element1b << std::endl;
        std::cout << "Their product is: " << product1 << std::endl;
    } else {
        std::cout << "The two elements with the maximum product are: " 
                  << element2a << " and " << element2b << std::endl;
        std::cout << "Their product is: " << product2 << std::endl;
    }
}

int main() {
    std::vector<int> arr = {-10, -20, 5, 9, 2, 6}; 

    findMaxProduct(arr);

    return 0;
}
