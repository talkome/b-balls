/**
 * Created by talko on 6/9/22.
 */
#pragma once
#include <vector>
#include "Team.hpp"
#include "Game.hpp"

using namespace std;

const unsigned long NUM_OF_TEAMS = 20;

class League {

public:
    vector<Team*> teams;

    // constructor
    explicit League(const vector<Team*>& teams): teams(teams){};

    League(){
        generate_team();
    };

    // Destructor
    ~League()=default;

    // methods
    void generate_team();
};
