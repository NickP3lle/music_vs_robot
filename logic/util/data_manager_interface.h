#ifndef DATA_MANAGER_INTERFACE_H
#define DATA_MANAGER_INTERFACE_H

#include <fstream>
#include <iostream>

class DataManagerInterface {
  public:
    virtual ~DataManagerInterface() = default;
    static void saveAll();
    static bool loadAll();

    // private:
    virtual std::string toString() const = 0;
    virtual DataManagerInterface *fromString(std::string){};
};

#endif