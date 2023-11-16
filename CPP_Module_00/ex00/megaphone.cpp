#include <iostream>
#include <cstring>
#include <cctype>

int	main(int argc, char* argv[]){
	std::string	uppercase_str;
	std::size_t	n;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		n = std::strlen(argv[i]);
		for (size_t j = 0; j < n; j++) {
			uppercase_str += std::toupper(static_cast<unsigned char>(argv[i][j]));
		}
	}

	std::cout << uppercase_str << std::endl;
	return (0);
}
