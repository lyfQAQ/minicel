#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

namespace fs = std::filesystem;
std::vector<std::string> slurp_file(const fs::path &file_path)
{
    if (!fs::exists(file_path))
    {
        std::cerr << "ERROR: file not found\n";
    }
    std::ifstream in_file(file_path);

    std::vector<std::string> cells;

    if (in_file.is_open())
    {
        std::string line;
        while (std::getline(in_file, line))
        {
            // std::cout << line << "\n";
            std::istringstream tokens(line);

            for (std::string token; std::getline(tokens, token, '|');)
            {
                cells.push_back(token);
            }
        }
        in_file.close();
    }
    else
    {
        std::cerr << "Failed to open file: " << file_path << std::endl;
    }
    return cells;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./minicel <input.csv>\n";
        std::cerr << "ERROR: input file isnot provided\n";
        return 1;
    }

    const fs::path input_file_path(argv[1]);
    auto cells = slurp_file(input_file_path);
    for (auto &cell : cells)
    {
        std::cout << cell << '\n';
    }
}