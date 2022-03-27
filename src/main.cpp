#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> directory;

void telephone_directory() {
  directory.insert(std::make_pair("12-23-34", "Ivanov"));
  directory.insert(std::make_pair("54-05-02", "Petrov"));
  directory.insert(std::make_pair("28-82-01", "Sidorov"));
  directory.insert(std::make_pair("23-90-03", "Ivanov"));
}

void fill_telephone_directory(std::string telephone, std::string person) {
  directory.insert(std::make_pair(telephone, person));
}

int main() {
  std::cout << "Telephone directory" << std::endl;
  std::string data;
  std::string phone;
  std::string person;
  bool access = true;
  telephone_directory();
  std::cout << "Enter data" << std::endl;
  std::cin >> data;
  for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); it++) {
    if (it->first == data) {
      std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
      std::cout << std::endl;
      access = false;
    } else if (it->second == data) {
      std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
      std::cout << std::endl;
      access = false;
    }
  }
  if (access == true)
    for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); it++) {
      if (it->first != data) {
        std::cout << "Enter person:" << std::endl;
        std::cin >> person;
        fill_telephone_directory(data, person);
        break;
      }
    }

  for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); it++) {
    std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
  }
  return 0;
}
