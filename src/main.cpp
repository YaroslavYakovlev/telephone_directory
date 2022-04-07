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

std::string parsData(std::string data, int part) {
  for (int i = 0; i < part; i++) {
    data = data.erase(0, data.find(" ") + 1);
  }
  data = data.substr(0, data.find(" "));
  std::cout << "Phone - " << data << std::endl;
  return data;
}

std::string parsePartOne(std::string data) {
  std::string strPatrOne;
  return strPatrOne = data.substr(0, data.find(" "));
}

std::string parsePartTwo(std::string data) {
  std::string strPartTwo;
  strPartTwo = data.erase(0, data.find(" "));

  return strPartTwo = data.substr((data.find(" ") + 1), data.length());
}

int main() {
  std::cout << "Telephone directory" << std::endl;
  std::string data;
  std::string phone;
  std::string person;
  bool access = true;
  telephone_directory();
  std::cout << "Enter data" << std::endl;
  std::getline(std::cin, data);
  phone = parsePartOne(data);
  person = parsePartTwo(data);

  if (!phone.empty() && !person.empty()) {
    fill_telephone_directory(phone, person);
  } else {
    for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); it++) {
      if (it->first == data) {
        std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
        std::cout << std::endl;
      } else if (it->second == data) {
        std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
        std::cout << std::endl;
      }
    }
  }

  for (std::map<std::string, std::string>::iterator it = directory.begin(); it != directory.end(); it++) {
    std::cout << "Telephone - " << it->first << " Person " << it->second << std::endl;
  }
  return 0;
}
