#include "Team.hpp"
#include "iostream"
#include <limits>
using namespace std;
namespace ariel
{
    Team::Team(Character *leader) : TeamLeader(leader), sizeOfTeammembers(1)
    {
        if (leader == nullptr)
        {
            throw invalid_argument("null");
        }
        if (TeamLeader->getInTeam())
        {
            throw runtime_error("Leader is already in team");
        }

        TeamLeader->setInTeam(true);
        teammembers.push_back(TeamLeader);
    }
    void Team::add(Character *newFighter)
    {
        if (newFighter == nullptr)
        {
            throw invalid_argument("null");
        }

        if (teammembers.size() >= 10)
        {
            throw runtime_error("Team is full");
        }

        if (newFighter->getInTeam())
        {
            throw runtime_error("Player has a team");
        }

        teammembers.push_back(newFighter);
        newFighter->setInTeam(true);
        // sizeOfTeammembers++;
    }
    int Team::stillAlive() const
    {
        int AliveFighters = 0;
        for (Character *fighter : teammembers)
        {
            if (fighter->isAlive())
                AliveFighters++;
        }
        return AliveFighters;
    }
    const Character *Team::getLeader() const
    {
        return TeamLeader;
    }

    void Team::setTeammembers(Character *leader)
    {
        TeamLeader = leader;
    }

    const vector<Character *>& Team::getTeammembers() const
    {
        return teammembers;
    }
    void Team::print()
    {
        for (Character *fighter : teammembers)
        {
            if (dynamic_cast<Cowboy *>(fighter) != nullptr)
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                cout << cowboy->print() << endl;
            }
            else if (dynamic_cast<Cowboy *>(fighter) != nullptr)
            {
                Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                cout << ninja->print() << endl;
            }
        }
    }
    int Team::getsizeOfTeammembers() const
    {
        return sizeOfTeammembers;
    }
    Character *Team::findTheClosest(Team *other) const
    {
        double Theclosest = std::numeric_limits<double>::max();
        Character *closestCharacter = nullptr;

        for (Character *member : other->teammembers)
        {
            if (member->isAlive())
            {
                double MDist = getLeader()->distance(member);
                if (member->isAlive() && Theclosest > MDist)
                {
                    Theclosest = MDist;
                    closestCharacter = member;
                }
            }
        }
        return closestCharacter;
    }
    Character *Team::pickNewLeader()
    {
        if (TeamLeader->isAlive())
            return TeamLeader;

        double Theclosest = std::numeric_limits<double>::max();
        Character *getLeader = nullptr;

        for (Character *member : teammembers)
        {
            if (member->isAlive())
            {
                double MDist = member->distance(TeamLeader);
                if (Theclosest > MDist)
                {
                    Theclosest = MDist;
                    getLeader = member;
                }
            }
        }
        return getLeader;
    }
    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            throw invalid_argument(" null");
        }

        else if (enemy == this)
        {
            throw invalid_argument("Cant attack youself!");
        }

        else if (enemy->stillAlive() == 0)
        {
            throw std::runtime_error("cant attack dead team ");
        }
        else if (this->stillAlive() == 0)
        {
            throw std::runtime_error("Team is dead");
        }

        else if (!TeamLeader->isAlive())
        {
            TeamLeader = pickNewLeader();
        }

        Character *victim = findTheClosest(enemy);

        for (Character *fighter : teammembers)
        {
            if (!victim->isAlive())
            {
                if (!enemy->stillAlive())
                    return;
                victim = findTheClosest(enemy);
            }
            if (fighter->isAlive())
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                if (cowboy != nullptr && cowboy->isAlive())
                {
                    if (cowboy->hasboolets())
                        cowboy->shoot(victim);

                    else
                        cowboy->reload();
                }
            }
        }

        for (Character *fighter : teammembers)
        {
            if (!victim->isAlive())
            {
                if (enemy->stillAlive() == 0)
                    return;
                victim = findTheClosest(enemy);
            }

            if (fighter->isAlive())
            {
                Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                if (ninja != nullptr && ninja->isAlive())
                {
                    if (ninja->distance(victim) <= 1)
                        ninja->slash(victim);
                    else
                        ninja->move(victim);
                }
            }
        }
    }

}