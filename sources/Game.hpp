/**
 * Created by talko on 6/9/22.
 */
#pragma once
#include <ostream>
#include <random>
#include "Team.hpp"

using namespace std;

const int TEN = 10;
const double AA = 77.5;
const double A = 75;
const double B = 8;

class Game {
public:
    Team* home_team;
    Team* outside_team;
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<double> home_prob{AA,B};
    normal_distribution<double> outside_prob{A, B};

    // constructor
    Game(Team* t1,Team* t2): home_team(t1), outside_team(t2){
        play(t1,t2);
    };

    Game(Game& other){
        this->home_team = other.home_team;
        this->outside_team = other.outside_team;
    }

    Game(Game&& other) noexcept;

    // Destructor
    ~Game()=default;

    // methods
    void play(Team*,Team*);

    // operators
    friend ostream& operator<<(ostream&, const Game&);
    Game& operator=(const Game& other);
    Game& operator=(Game&& other) noexcept;
};
