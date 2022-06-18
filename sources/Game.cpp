/**
 * Created by talko on 6/9/22.
 */
#include "Game.hpp"

using namespace std;

// methods
void Game::play(Team *home, Team *outside) {
    int home_score = (int)(home_prob(gen) + TEN*home->skills);
    int outside_score = (int)(outside_prob(gen) + TEN*outside->skills);
    home->score += home_score;
    home->score -= outside_score;
    outside->score += outside_score;
    outside->score -= home_score;
    if (home->score > outside->score){
        home->wins_counter++;
        outside->losses_counter++;
    } else {
        outside->wins_counter++;
        home->losses_counter++;
    }
}

// operators
ostream &operator<<(ostream& out, const Game& game) {
    out << "{{home_team team name:" << game.home_team->name
    << ", score:" << game.home_team->score
    << ", level:" << game.home_team->skills
    << "},{outside_team team name:" << game.outside_team->name
    << ", score:" << game.outside_team->score
    << ", level:" << game.outside_team->skills
    << "}}";
    return out;
}


