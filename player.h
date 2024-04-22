#pragma once
#ifndef player_H
#define player_h


#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <limits>
#include <vector>
#include <random>
#include <cstdlib>


using namespace std;

class Player {
private:
    int hp;
public:
    Player(int z);
    void setHealth(int x);
    int getHealth() const;

};
#endif;

