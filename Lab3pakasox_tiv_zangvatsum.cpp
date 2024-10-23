#include <iostream>
#include <vector>

int findMissingElement(const std::vector<int>& arr) {
    int n = arr.size(); 
    int total_sum = (n + 1) * (n + 2) / 2;

    int array_sum = 0;
    for (int num : arr) {
        array_sum += num;
    }
    return total_sum - array_sum;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 5, 6}; 

    int missing_element = findMissingElement(arr);
    std::cout << "The missing element is: " << missing_element << std::endl;

    return 0;
}
