#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream ifs;
  std::ofstream ofs;
  std::string line, filename, s1, s2;
  std::string::size_type pos;

  if (argc != 4) {
    std::cerr << "Error: Incorrect number of arguments." << std::endl
              << "Usage: ./Sed <input_filename> <string_to_replace> "
                 "<replacement_string>"
              << std::endl;
    return (1);
  }
  ifs.open(argv[1]);
  if (!ifs.is_open()) {
    std::cerr << "Error: Failed to open input file '" << argv[1]
              << "'. File may not exist or cannot be read." << std::endl;
    return (1);
  }
  filename = argv[1];
  s1 = argv[2];
  s2 = argv[3];
  filename += ".replace";
  ofs.open(filename.c_str());
  if (!ofs.is_open()) {
    std::cerr << "Error: Failed to create output file '" << filename
              << "'. Check if you have write permissions." << std::endl;
    return (1);
  }
  while (std::getline(ifs, line)) {
    if (!s1.empty()) {
      pos = 0;
      while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.size());
        line.insert(pos, s2);
        pos += s2.size();
      }
    }
    ofs << line << std::endl;
  }
  ifs.close();
  ofs.close();
  return (0);
}
