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
    int good_points;
    int bad_points;

    // constructors
    Team(string name, double skill): name(std::move(name)),score(0),skills(skill),wins_counter(0),losses_counter(0),good_points(0),bad_points(0){
        if (skill > 1 || skills < 0){
            throw invalid_argument("skills invalid");
        }
    };

    Team(Team& other){
        this->name = other.name;
        this->skills = other.skills;
        this->score = other.score;
        this->good_points = other.good_points;
        this->bad_points = other.bad_points;
        this->wins_counter = other.wins_counter;
        this->losses_counter = other.losses_counter;
    }

    Team(Team&& other) noexcept;

    // destructors
    ~Team()= default;

    // methods
    void hitting(int x);
    void absorb(int x);

    // operators
    friend ostream& operator<<(ostream& out, const Team& team);
    Team& operator=(Team&& other) noexcept;
    Team& operator=(Team const& other) noexcept;
};
