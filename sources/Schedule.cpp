/**
 * Created by talko on 6/9/22.
 */
#include "Schedule.hpp"

using namespace std;

// methods
void Schedule::play() {
    cout << "set up the games" << endl;
    set_up_games();
    cout << "results table: " << endl;
    results_table();
}

void Schedule::set_up_games() const {
    unsigned long size = this->league.teams.size();
    for (unsigned long i = 1; i < size; i++) {
        for (unsigned long j = 0; j < size; j++) {
            (Game(this->league.teams[i], this->league.teams[(i + j) % size]));
        }
    }
}

void Schedule::results_table() {
    cout << "sequence of victories: " << endl;
    sequence_of_victories();
    cout << "sequence of losses: " << endl;
    sequence_of_losses();
    cout << "leagues top teams: " << endl;
    leagues_top_teams();
    cout << "high score: " << endl;
    high_score();
}

void Schedule::sequence_of_victories() {
    vector<pair<string,int>> name_score;
    for (auto &team: this->league.teams){
        name_score.emplace_back(team->name, team->losses_counter);
    }

    auto max = max_element(name_score.begin(),name_score.end(),
                           [] (const auto & p1, const auto & p2) { return p1.second < p2.second; });

    cout<< "longest sequence of losses is: " << max->first << " with score: "<< max->second << endl;
}

void Schedule::sequence_of_losses() {
    vector<pair<string,int>> name_score;
    for (auto &team: this->league.teams){
        name_score.emplace_back(team->name, team->wins_counter);
    }

    auto min = max_element(name_score.begin(),name_score.end(),
                           [] (const auto & p1, const auto & p2) { return p1.second < p2.second; });

    cout<< "longest sequence of losses is: " << min->first << " with score: "<< min->second << endl;
}

void Schedule::leagues_top_teams() {
    sort(this->league.teams.begin(), this->league.teams.end(),
              [](Team* a, Team* b){ return a->wins_counter > b->wins_counter; });
    for_each(this->league.teams.begin(), this->league.teams.end(),
             [](const Team* a){ cout << *a << endl; });
}

void Schedule::high_score() {
    sort(this->league.teams.begin(), this->league.teams.end(),
         [](Team* a, Team* b){ return (a->wins_counter - a->losses_counter) > (b->wins_counter - b->losses_counter); });
    for_each(this->league.teams.begin(), this->league.teams.end(),
             [](const Team* a){ cout << *a << endl; });
}