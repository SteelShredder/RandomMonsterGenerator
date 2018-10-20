//
//  main.cpp
//  RandomMonsterGenerator
//
//  Created by Gavin Gavington on 10/19/18.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Monster
{
public:
    enum MonsterType
    {
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES
    };
private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;
public:
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints)
        : m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints)
    {
        
    }
    std::string getTypeString() const
    {
        switch(m_type)
        {
            case DRAGON: return "dragon";
            case GOBLIN: return "goblin";
            case OGRE: return "ogre";
            case ORC: return "orc";
            case SKELETON: return "skeleton";
            case TROLL: return "troll";
            case VAMPIRE: return "vampire";
            case ZOMBIE: return "zombie";
            default: return "???";
        }
        return 0;
    }
    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
    }
};
class MonsterGenerator
{
public:
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
    static Monster generateMonster()
    {
        static std::string s_names[6]{"Bob","Nick","Gavin","Jones","Nose","Taco"};
        static std::string s_roars[6]{"roar","bleh","meow","moo","quack","cheep cheep"};
        return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1)), s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], getRandomNumber(1, 100));
    }
};
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    
    Monster m = MonsterGenerator::generateMonster();
    m.print();
    
    return 0;
}
