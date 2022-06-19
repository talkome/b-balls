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
    League(const vector<Team*>& teams): teams(teams){
        if (teams.empty()){
            throw invalid_argument("team invalid");
        }
    };

    League(const League& other){
        this->teams = other.teams;
    }

    League(League&& other) noexcept;

    League(){
        generate_team();
    };

    // Destructor
    ~League()=default;

    // methods
    void generate_team();

    // operators
    League& operator=(const League& other);
    League& operator=(League&& other) noexcept;
};
