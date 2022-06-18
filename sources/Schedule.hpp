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
    explicit Schedule(const League& league) : league(league) {}

    // Destructor
    ~Schedule()=default;

    // methods
    void play();
    void set_up_games() const;
    void sequence_of_victories();
    void sequence_of_losses();
    void leagues_top_teams();
    void results_table();
    void high_score();
};
