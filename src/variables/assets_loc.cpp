#include "assets_loc.hpp"

std::vector<std::filesystem::path> Textures_Names;
std::vector<std::filesystem::path> Sounds_Names;


void LoadFromFile(std::vector<std::filesystem::path> *input, std::string file)
{
  namespace fs = std::filesystem;
  for (const auto &entry : fs::directory_iterator(file))
  {
    if (fs::is_regular_file(entry))
    {
      fs::path relative_path = fs::relative(entry.path(), ".");
      //spdlog::info("{}", relative_path.string());
      input->push_back(relative_path);
    }
  }
}