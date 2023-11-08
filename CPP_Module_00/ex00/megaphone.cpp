#include <iostream>
#include <cstring>

int	main(int argc, char* argv[]){
	std::string	ans;
	std::size_t	n;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		ans.clear();
		n = std::strlen(argv[i]);
		for (size_t j = 0; j < n; j++) {
			ans += std::toupper(static_cast<unsigned char>(argv[i][j]));
		}
		std::cout << ans;
	}
	std::cout << std::endl;
	return (0);
}
