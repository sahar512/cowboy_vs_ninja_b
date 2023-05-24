#include "Point.hpp"
#include <string>
#pragma once
using namespace std;
namespace ariel
{
    class Character
    {
    protected:
        Point location;
        std::string name;
        int characterHit;
        bool InTeam;

    public:
        // Character(string name, int characterHit , const Point &location);
        // Character(const Character& other);
        // Character(Character&& other)noexcept;
        // Character& operator=(const Character& other);
        // Character& operator=(Character&& other)noexcept;
        virtual ~Character() = default;
        Character(string name, const Point &location, int characterHit) : name(name), location(location), characterHit(characterHit), InTeam(false) {}
        bool isAlive() const;
        double distance(Character *other) const;
        void hit(int HitPoints);
        // bool InTeamm();
        // gitters
        bool getInTeam() const;
        const Point &getLocation() const;
        string getName() const;
        int getCharacterHit() const;
        // setters
        void setInTeam(bool InTeam);
        void setLocation(const Point &location);
        void setName(string name);
        void setCharacterHit(int chracterHit);

        virtual std::string print() const = 0;
    };

};
