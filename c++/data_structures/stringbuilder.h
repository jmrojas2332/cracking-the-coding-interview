#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H

#include "arraylist.h"


namespace datastructures
{
    class StringBuilder : public ArrayList<char> {
      public:
        std::string toString();
        void pushBack(const std::string &str);
    };

    void StringBuilder::pushBack(const std::string &str)
    {
        for (const char &c : str) {
            ArrayList<char>::pushBack(c);
        }
    }

    std::string StringBuilder::toString()
    {
        return std::string(this->data());
    }
}

#endif