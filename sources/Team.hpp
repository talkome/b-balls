/**
 * Created by talko on 6/9/22.
 */
#pragma once
#include <string>
#include <random>
#include <utility>
#include <ostream>

using namespace std;

const int SD = 123;

class Team {

public:
    string name;
    double skills;
    int score;
    int wins_counter;
    int losses_counter;

    // constructors
    Team(string name): name(std::move(name)), score(0), skills(set_skill()), wins_counter(0), losses_counter(0){};

    // destructors
    ~Team()= default;

    //methods
    static double set_skill();

    // operators
    friend ostream& operator<<(ostream& out, const Team& team);
};
