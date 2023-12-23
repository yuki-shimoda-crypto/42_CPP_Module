#include "easyfind.hpp"

int main() {
  std::vector<int> nums;

  nums.pusu_back(0);
  nums.pusu_back(1);
  nums.pusu_back(2);
  nums.pusu_back(3);
  try {
    std::vector<int>::iterator it = easyfind(nums, 2);
    std::cout << "Found the number " << *it << " at index "
              << std::distance(nums.begin(), it) << std::endl;
  } catch (const NotFoundException &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
