#pragma once
#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Ninja.hpp"
#include <vector>
using namespace std;
namespace ariel
{
    class Team
    {
    private:
        Character *TeamLeader;

        int sizeOfTeammembers;

    public:
        Team(Character *leader);
        virtual ~Team()
        {
            for (Character *member : teammembers)
                delete member;
        }
        void add(Character *newFighter);
        int stillAlive() const;
        int getsizeOfTeammembers() const;
        const Character *getLeader() const;
        const std::vector<Character *> &getTeammembers() const;
        virtual void attack(Team *enemy);
        virtual void print();
        void setTeammembers(Character *leader);
        Character *pickNewLeader();
        virtual Character *findTheClosest(Team *other) const;
        std::vector<Character *> teammembers;
    };

}
