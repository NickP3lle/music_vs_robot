#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <fstream>
#include <iostream>

class DataManagerInterface {
  public:
    virtual ~DataManagerInterface() = default;
    static void saveAll();
    static bool loadAll();

    virtual std::string saveData() const = 0;

    virtual DataManagerInterface *loadData(std::string) = 0;
};

#endif