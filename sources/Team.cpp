/**
 * Created by talko on 6/9/22.
 */
#include "Team.hpp"

using namespace std;

// operators
ostream &operator<<(ostream& out, const Team &team) {
    out << "{name:"<< team.name
    << ", score:"<< team.score
    << ", level:" << team.skills
    << ", wins:" << team.wins_counter
    << ", loses:" << team.losses_counter
    << "}";
    return out;
}

void Team::set_skill() {
    std::mt19937 gen (123);
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double x = dis(gen);
    this->skills = x;
}
