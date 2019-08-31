#ifndef FEATCLASS_H
#define FEATCLASS_H

#include <string>
#include "attributeClass.h"

class Feat
{
public:
    Feat();
    ~Feat();
    
    std::string GetName() { return name; }
private:
    std::string name;
    std::string classification;
    int modifier;
    Attribute atribute; 
};

#endif // !FEATCLASS_H
