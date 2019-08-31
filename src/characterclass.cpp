#include "../hdr/characterClass.h"

Character::Character()
{
    for ( ulong i = 0; i < m_attributes.size(); i++ )
    {
        m_attributes[i] = 10;
    }
}

//std::vector<int> Character::getAllAttributes()
//{
//    std::vector<int> returnArray;
//    for (int i = 0; i < m_attributes.size(); i++)
//    {
//        //returnArray.push_back(m_attributes[i]);
//    }
//    return returnArray;
//}
