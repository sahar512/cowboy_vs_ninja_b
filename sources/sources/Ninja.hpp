#include "Character.hpp"
#pragma once
namespace ariel{
    class Ninja : public Character{
        private:
            int speed;// the ninjas speed 
        public:
        Ninja(string name, int hitpoints, const Point &location , int speed); 
        void move(Character *enemy);
        void slash(Character *enemy);
        //~Ninja(); 
        std::string print()const override; 

    };
    
} ;   