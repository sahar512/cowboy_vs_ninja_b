#include"Team.hpp"
#include"Team2.hpp"
#include<iostream>
#include<limits>
//#pragma once
using namespace std; 
namespace ariel{
    Team2::Team2(Character *Team2leader):Team(Team2leader){}

    // void Team2::print()const{
    //     for(Character *fighter :teammembers ){
    //         cout<<fighter->print()<<endl; 
    //     }

    // }
    // void Team2::attack(Team *enemy){
    //     //cheack if there is any fighters in both teams are alive 
    //     if(stillAlive()==0){
    //         throw std::runtime_error("all fighters in the both teams are dead -No game!"); 
    //         return; 
    //     }
    //     //cheack if the enemys team fighters are alive (at least one of them)
    //     if(enemy->stillAlive()==0){
    //         throw std::runtime_error("all fighters in the enemy team are dead!!"); 
    //         return; 
    //     }
    //     //cheak if the enemy team are null 
    //     if(enemy==nullptr){
    //         throw std::invalid_argument("the enemy team is null!!"); 
    //     }
    //     //cheak if the leader is alive 
    //     if(!getLeader()->isAlive()){
    //         Character *newleader2 = nullptr; 
    //         double minDist= numeric_limits<double>::max(); 
    //         for(Character* fighter:getFighters()){
    //             if(fighter->isAlive() && fighter->distance(getLeader())<minDist){
    //                 minDist=TeamLeader->distance(getLeader()); 
    //                 newleader2 = fighter; 
    //             }
    //         }
    //         setLeader(newleader2);  
    //         Character *victim = findVictim(enemy); //new victim 
    //         for(Character *fighter:fighters){
    //             if(!victim->isAlive()){
    //                 if(enemy->stillAlive()==0){
    //                     break; 
    //                 }
    //                 victim=findVictim(enemy); 
    //             }
    //             Cowboy* Cfighter=dynamic_cast<Cowboy*> (fighter);
    //             Ninja* Nfighter=dynamic_cast<Ninja*>(fighter);
    //             if(Cfighter !=nullptr && Cfighter->isAlive()){
    //                 if(Cfighter->hasboolets())
    //                     Cfighter->shoot(victim); 
    //                 else 
    //                     Cfighter->reload(); 
    //             } 
    //             else if(Nfighter!=nullptr && Nfighter->isAlive()){
    //                 if(Nfighter->getLocation().distance(victim->getLocation()) <=1)
    //                     Nfighter->slash(victim); 
    //                 else 
    //                     Nfighter->move(victim); 
    //             }
    //         }
    //     }
    // }
    void Team2::print()
    {
        for(Character* fighter:getTeammembers())
        {
            cout << fighter->print() << endl;
        }
    }

    Character *Team2::findTheClosest(Team * other) const
    {
        double Theclosest = std::numeric_limits<double>::max();
        Character* closestCharacter = nullptr;

        for (Character* member : other->teammembers)
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
    void Team2::attack(Team* enemy)
    {
        

        if(enemy == this) throw invalid_argument("Cant attack youself!");
        if(enemy == nullptr) throw invalid_argument("null");
        
        
        if (stillAlive() == 0  || enemy->stillAlive() == 0 )
            throw runtime_error("Team dead");
        
        if(!getLeader()->isAlive()) 
            setTeammembers(pickNewLeader());

        Character* victim = findTheClosest(enemy);

        for(Character* fighter: getTeammembers())
        {
            if(!victim->isAlive()) 
            {
                if(enemy->stillAlive() == 0) return;
                victim = findTheClosest(enemy);
            }
            else if(fighter->isAlive())
            {
                auto* cowboy = dynamic_cast<Cowboy*>(fighter);
                if(cowboy != nullptr)
                {
                    if(cowboy->hasboolets()) 
                    cowboy->shoot(victim);
                    else cowboy->reload();
                }
                auto* ninja = dynamic_cast<Ninja*>(fighter);
                if(ninja != nullptr)
                {
                    if(ninja->distance(victim) <= 1) 
                    ninja->slash(victim);
                    else ninja->move(victim);
                }
            }
            
        }
    }

}