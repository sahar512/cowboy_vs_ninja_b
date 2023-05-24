#include"Character.hpp"
#include"Point.hpp"
#include<string>
#pragma once
namespace ariel{
    class Cowboy: public Character{
        int bullets; 
    public:  
        Cowboy(string name , const Point &location); 

        //Cowboy(const std::string& name, const Point& location );
        // Cowboy(string name, const Point &location);
        // Cowboy(Cowboy&& other)noexcept; 
        // Cowboy( const Cowboy& other); 
        // Cowboy& operator=(const Cowboy& other); 
        // Cowboy& operator=(Cowboy&& other)noexcept; 


        //~Cowboy()override; //destructer
        //Cowboy(string name, Point &&location); 

        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        std::string print()const override;


    };
};