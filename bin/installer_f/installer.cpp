#include <iostream>
#include <string>
#include <fstream>
#include <fmt/format.h>

int main() 
{
    std::string curr_path = std::filesystem::current_path().u8string();
    auto res_path = [curr_path]() {
        std::string path(curr_path.begin(), curr_path.begin() + curr_path.find("/bin"));
        return path;
}();
    std::ofstream file(fmt::format("{}/ProGen", res_path));
    if (!file.is_open())
        std::cerr << "Failed to create launcher" << std::endl;
    file << fmt::format(R"(cd {}
make
./ProGen
make fclean
    )", curr_path);
    file.close();
    system(fmt::format("chmod 777 {}/ProGen", res_path).c_str());
    return 0;
}