#pragma once

#include "config.hpp"

namespace Lang
{
	using json = nlohmann::json;

  class LangSystem {
  public:
    bool load(const std::string& baseLang, const std::string& lang) {
      baseTranslations = loadFile("lang/" + baseLang + ".json");
      translations = loadFile("lang/" + lang + ".json");
      return !baseTranslations.empty();
    }

    std::string get(const std::string& key) const {
      auto it = translations.find(key);
      if (it != translations.end()) return it->second;

      auto baseIt = baseTranslations.find(key);
      if (baseIt != baseTranslations.end()) return baseIt->second;

      return key; // fallback
    }

     //supports %s placeholders
    template<typename... Args>
    std::string format(const std::string& key, Args... args) const {
      std::string s = get(key);
      std::string result;
      result.reserve(s.size());

      const char* c = s.c_str();
      size_t i = 0;

      formatImpl(result, c, args...);
      return result;
    }

  private:
    std::unordered_map<std::string, std::string> translations;
    std::unordered_map<std::string, std::string> baseTranslations;

    static std::unordered_map<std::string, std::string>
      loadFile(const std::string& path) {
      std::unordered_map<std::string, std::string> map;

      std::ifstream myfile;
      myfile.open(path);
      if (!myfile.is_open()) return map;

      json j;
      myfile >> j;

      for (auto& [k, v] : j.items()) {
        map[k] = v.get<std::string>();
      }

      return map;
    }

    static void formatImpl(std::string& out, const char* s) {
      out += s;
    }

    template<typename T, typename... Rest>
    static void formatImpl(std::string& out, const char* s, T value, Rest... rest) {
      while (*s) {
        if (s[0] == '%' && s[1] == 's') {
          out += toString(value);
          formatImpl(out, s + 2, rest...);
          return;
        }
        out.push_back(*s++);
      }
    }

    template<typename T>
    static std::string toString(const T& v) {
      return std::to_string(v);
    }

    static std::string toString(const std::string& v) {
      return v;
    }

    static std::string toString(const char* v) {
      return std::string(v);
    }
  };
};