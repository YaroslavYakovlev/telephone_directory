#include <iostream>
#include <map>
#include <string>

struct command {
  std::string add = "add";
  std::string find = "find";
};

std::map<std::string, std::string> directory;

void telephone_directory() {
  directory.insert(std::pair<std::string, std::string>("12-23-34", "Ivanov"));
  directory.insert(std::pair<std::string, std::string>("54-05-02", "Petrov"));
  directory.insert(std::pair<std::string, std::string>("28-82-01", "Sidorov"));
  directory.insert(std::pair<std::string, std::string>("23-90-03", "Ivanov"));
}

void fill_telephone_directory(std::string telephone, std::string person) {
  directory.insert(std::pair<std::string, std::string>(telephone, person));
}

int main() {
  std::cout << "Telephone directory" << std::endl;
  command cmd;
  std::string data;
  std::string phone;
  std::string person;
  std::string action;
  telephone_directory();
  std::cout << "Enter command (add/find)" << std::endl;
  std::cin >> action;
  if (action == cmd.find) {
    std::cout << "Enter data" << std::endl;
    std::cin >> data;
    for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); it++) {
      if (it->first == data) {
        std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
        std::cout << std::endl;
      } else if (it->second == data) {
        std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
        std::cout << std::endl;
      }
    }
  } else if (action == cmd.add) {
    std::cout << "Enter telephone:" << std::endl;
    std::cin >> phone;
    std::cout << "Enter person:" << std::endl;
    std::cin >> person;
    fill_telephone_directory(phone, person);
  } else {
    std::cout << "Error command" << std::endl;
  }

  for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); it++) {
    std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
  }
  return 0;
}
