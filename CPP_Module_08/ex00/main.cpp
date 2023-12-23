#include "easyfind.hpp"

int main() {
  std::vector<int> nums;

  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  try {
    std::vector<int>::iterator it = easyfind(nums, 2);
    std::cout << "Found the number " << *it << " at index "
              << std::distance(nums.begin(), it) << std::endl;
  } catch (const NotFoundException &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
