/**
 * Created by talko on 6/9/22.
 */
#include "League.hpp"

// methods
void League::generate_team() {
    vector<string> teams_name_list = {"A","B","C","D","E",
                                      "F","G","H","I","J",
                                      "K","L","M","N","O",
                                      "P","Q","R","S","T"};

    for (unsigned long i = 0; i < NUM_OF_TEAMS; ++i) {
        std::mt19937 gen (SD);
        std::uniform_real_distribution<double> dis(0.0, 1.0);
        double team_skill = dis(gen);
        this->teams.push_back(new Team(teams_name_list[i],team_skill));
    }

}
