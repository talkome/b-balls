/**
 * Created by talko on 6/9/22.
 */
#pragma once
#include <string>
#include <random>
#include <utility>
#include <ostream>

using namespace std;

class Team {

public:
    string name;
    double skills;
    int score;
    int wins_counter;
    int losses_counter;

    // constructors
    Team(string name): name(std::move(name)), score(0), wins_counter(0), losses_counter(0){
        set_skill();
    };

    // destructors
    ~Team()= default;

    //methods
    void set_skill();

    // operators
    friend ostream& operator<<(ostream& out, const Team& team);
};
