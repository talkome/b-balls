/**
 * Created by talko on 6/9/22.
 */
#pragma once
#include <ostream>
#include <random>
#include "Team.hpp"

using namespace std;

const int TEN = 10;

class Game {
public:
    Team* home_team;
    Team* outside_team;
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<double> home_prob{77.5,8};
    normal_distribution<double> outside_prob{75, 8};

    // constructor
    Game(Team* t1,Team* t2): home_team(t1), outside_team(t2){
        play(t1,t2);
    };

    // Destructor
    ~Game()=default;

    // methods
    void play(Team*,Team*);

    // operators
    friend ostream& operator<<(ostream&, const Game&);
};
