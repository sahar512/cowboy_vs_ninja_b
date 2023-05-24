#include"Team.hpp"
#pragma once
namespace ariel{
    class Team2 : public Team {
        public:
        Team2(Character *Team2Leader); 
       
        
        void attack(Team *enemy) override;


        Character* findTheClosest(Team * other) const override;
        
            
        
        void print()override; 


    };

};