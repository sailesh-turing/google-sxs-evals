#include <iostream>
#include <filesystem> // Include the header
#include <vector>
#include "hyperloglog.hpp" // Your HyperLogLog header

std::vector<hyperloglog_t*> LoadHLLObjectsFromFiles(const std::string& directoryPath) {
    std::vector<hyperloglog_t*> hllObjects;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".hll") { // Assuming your HLL files have a .hll extension
            // Load the HLL object from the file (you'll need to implement this part)
            hyperloglog_t* hll = new hyperloglog_t(); // Or however you create your HLL objects
            // ... code to load data from entry.path() into hll ... 
            hllObjects.push_back(hll);
        }
    }

    return hllObjects;
}

int main() {
    // ...
    return 0;
}