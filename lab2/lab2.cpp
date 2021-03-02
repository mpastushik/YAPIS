#include <iostream>
#include <regex>
#include <iomanip>
#include <fstream>

std::vector<std::string> split(const std::string & s, std::regex rgx) {
      std::vector<std::string> elems;

      std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
      std::sregex_token_iterator end;

      while (iter != end)  {
          if(*iter != "") elems.push_back(*iter);
          ++iter;
      }
      return elems;
}

int main() {
    std::string text;
    std::ifstream file("file.txt");
    if(file.is_open()) { 
        file >> text;
    }
    std::regex alph = std::regex("[a-z]|[A-Z]|[0-9]");
    std::regex delims = std::regex("[\"]|[+]|[;]|[']");

    std::vector<std::string> str = split(text, delims);
    std::vector<std::string> dlms = split(text, alph);

    bool isString = false;
    bool isSymbol = false;
    for (size_t i = 0, j = 0; i < str.size() || j < dlms.size(); i++, j++) {
		if (j < dlms.size())
			for (const auto& delimeter : dlms[j]) {
				if (delimeter == '\"') {
                    if(isString) isString = false;
                    else isString = true;
                    std::cout << std::setw(10) << delimeter << std::string(10, ' ') << "Double quotes" << '\n';
                }
				else if (delimeter == '\'') {
                    if(isSymbol) isSymbol = false;
                    else isSymbol = true;
                    std::cout << std::setw(10) << delimeter << std::string(10, ' ') << "Single quotes" << '\n';
                }
				else if (delimeter == '+') std::cout << std::setw(10) << delimeter << std::string(10, ' ') << "Concatenation" << '\n';
				else if (delimeter == ';') std::cout << std::setw(10) << delimeter << std::string(10, ' ') << "Semicolon" << '\n';
			}
		if (i < str.size()) {
            if(isString) std::cout << std::setw(10) << str[i] << std::string(10, ' ') << "String" << '\n';
            else if(isSymbol) std::cout << std::setw(10) << str[i] << std::string(10, ' ') << "Symbol" << '\n';
        }
	}
    return 0;
}