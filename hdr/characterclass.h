#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H
/*Make ability and feat class to hold values of said objects. */

#include <vector>
#include <string>

#include "featClass.h"

//Character::Character()
class Character
{
    public:
        Character();
        ~Character() {}

        // Getters
        // attributes
        std::vector<int> GetAllAtributes() { return m_attributes; }
        int GetAttribute(int index) { return m_attributes[index]; }
        std::vector<int> GetAtributes(int, int);
        // feats
        //std::vector<std::vector<std::string>> GetAllFeats() { return m_feats: }
        //std::vector<std::string> GetFeat(int index) { return m_feats(index); }
        std::vector<Feat> GetAllfeats() { return m_feats; }
        Feat GetFeat(int index) {return m_feats[index]; }
        std::vector<std::vector<std::string>> GetFeats(int, int);
        // abilities
        std::vector<std::vector<std::string>> GetAllAbilities() { return m_abilities; }
        std::vector<std::string> GetAbility(int index) { return m_abilities[index]; }
        std::vector<std::vector<std::string>> GetAttributes(int, int);

        // Setters
        // attributes
        void SetAllAttributes(std::vector<int> );
        void setAttribute(int, int);
        void setNewAttribute(int _new) { m_attributes.push_back(_new); }
        void SetAttributeSize(int _size) { m_attributes.resize(_size); }

        
    private:
        std::vector<int> m_attributes; 
        //std::vector<std::vector<std::string>> m_feats;
        std::vector<Feat> m_feats;
        std::vector<std::vector<std::string>> m_abilities;
};

#endif // !CHARACTERCLASS_H
