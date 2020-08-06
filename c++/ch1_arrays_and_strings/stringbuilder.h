#include "arraylist.h"

class StringBuilder : public ArrayList<std::string>
{
public:
    friend std::ostream& operator<< (std::ostream &out, const StringBuilder &array);
};


std::ostream& operator<<(std::ostream &out, const StringBuilder &sb)
{
    out << "StringBuilder(";

    for (const auto& val : sb)
    {
        out << val;
    }

    if (!sb.empty())
    {
        out << '\b';  // remove trailing space of last element
    }

    out << ")";

    return out;
}