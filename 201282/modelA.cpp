#include <iostream>
#include <string>
#include <map>
#include <vector>

// Assuming you have an EncodableList class like this:
class EncodableList {
public:
  // ... your EncodableList methods ...
  std::vector<std::string> data; 
};

// Assuming you have an EncodableMap class like this:
class EncodableMap {
public:
  // ... your EncodableMap methods ...
  std::map<std::string, EncodableList> data;

  void add(const std::string& key, const EncodableList& list) {
    data[key] = list;
  }
};

int main() {
  EncodableMap myMap;
  
  // Create some EncodableLists
  EncodableList list1;
  list1.data = {"item1", "item2"}; 

  EncodableList list2;
  list2.data = {"item3", "item4", "item5"};

  // Add the lists to the map
  myMap.add("key1", list1);
  myMap.add("key2", list2);

  // Access and print the data
  for (const auto& pair : myMap.data) {
    std::cout << "Key: " << pair.first << std::endl;
    std::cout << "Values: ";
    for (const auto& item : pair.second.data) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}