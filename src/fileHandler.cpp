#include "../include/FileHandler.h"
  FileHandler::FileHandler() {}

  std::string FileHandler::getTextfileData(std::string path) {
    constexpr auto read_size = std::size_t(4096); // define a chunk to read in.

    std::ifstream file(path);
    if (!file.is_open()) {
      printError("File Loading Failed");
      std::cout << "Couldn't load file: " << path << std::endl;
      return "";
    }
    auto out = std::string();
    auto buf =
        std::string(read_size, '\0'); // Define a buffer of read_size that ends
                                      // in '\0' for proper string termination
    while (file.read(&buf[0], read_size)) {
      out.append(buf, 0, file.gcount());
    }

    out.append(buf, 0, file.gcount());
    return out;
  }
