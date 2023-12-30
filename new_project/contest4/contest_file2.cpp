
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
   
    std::ifstream file("data.json");
    json jsonData;
    file >> jsonData;

  
    int userId;
    std::cin >> userId;

    
    int completedTasks = 0;

    for (const auto& project : jsonData) {
     
        for (const auto& task : project["tasks"]) {
            
            if (task["user_id"] == userId && task["completed"]) {
                completedTasks++;
            }
        }
    }

    
    std::cout << completedTasks << std::endl;

    return 0;
}
