/**
 * Created by talko on 6/9/22.
 */
#include <utility>
#include <iostream>
#include "League.hpp"

using namespace std;

class Schedule {

public:
    League league;

    // Constructor
    Schedule(League& league) : league(league) {}

    Schedule(Schedule& other){
        this->league = other.league;
    }

    Schedule(Schedule&& other) noexcept;

    // Destructor
    ~Schedule()=default;

    // methods
    void play();
    void set_up_games() const;
    void sequence_of_victories();
    void sequence_of_losses();
    void leagues_top_teams();
    void results_table();
    void loses_vs_wins();
    void high_score();

    // operators
    Schedule& operator=(const Schedule& other);
    Schedule& operator=(Schedule&& other) noexcept;

};
