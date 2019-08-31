#ifndef ATTRIBUTECLASS_H
#define ATTRIBUTECLASS_H

#include <vector>
#include <string>

typedef struct
{
    std::string name;
    int value;
} Aspect;

class Attribute
{
public: 
    //Constructor/destructor
    Attribute(std::string _name, int _ID, std::vector<Aspect> _aspects): name(_name), ID(_ID), aspects(_aspects) {}
    Attribute(std::string _name, int _ID): name(_name), ID(_ID) {}
    Attribute(std::string _name): name(_name) {}
    Attribute(int _ID): ID(_ID) {}
    Attribute(){}

    ~Attribute() {}

    // Setters
    void setName( std::string _name ) { name = _name; }
    void setID( int _ID ) { ID = _ID; }
    void setAspects( std::vector<Aspect> _aspects ) { aspects = _aspects; }

    // Getters
    std::string getName() { return name; }
    int getID() { return ID; }
    
    Aspect getAspect( int index );// { return aspects(index); }
    Aspect getAspect( std::string );
    

private: 
    std::string name;
    int ID; // of type 0xab, 0 to f

    std::vector<Aspect> aspects;
};

#endif // !ATTRIBUTECLASS_H
