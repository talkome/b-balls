#include "doctest.h"
#include "sources/Game.hpp"
#include "sources/League.hpp"
#include "sources/Team.hpp"
#include "sources/Schedule.hpp"

using namespace std;

TEST_CASE("1. Check Inputs") {
    vector<Team*> teams(0);
    CHECK_THROWS(League league2(teams));
    CHECK_NOTHROW(new Team("my_team",0.2));
    //CHECK_THROW(new Team("my_team",2.5));
    //CHECK_THROW(new Team("my_team",22.7));
    CHECK_NOTHROW(new Team("the best team in the world!!",0.2));

}

TEST_CASE("2. Check Teams") {
    vector < Team * > teams{new Team{"A", 0.2}, new Team{"B", 0.3}, new Team{"C", 0.4},
                            new Team{"D", 0.5}, new Team{"E", 0.5}};

    for (unsigned long i = 0; i < teams.size(); ++i) {
        for (unsigned long j = 1; j < teams.size(); ++j) {
            CHECK_NE(teams[i], teams[j]);
        }
    }
}

TEST_CASE("3. Check Game") {
    vector<int> results;
    vector<Team*> teams{new Team{"A",0.2},new Team{"B",0.3},new Team{"C",0.4},
                        new Team{"D",0.5},new Team{"E",0.5}};

    Game g1(teams[0], teams[1]);
    results.push_back(g1.outside_team->score - g1.home_team->score);
    Game g2(teams[1], teams[0]);
    results.push_back(g2.outside_team->score - g2.home_team->score);
    Game g3(teams[1], teams[2]);
    results.push_back(g3.outside_team->score - g3.home_team->score);
    Game g4(teams[2], teams[1]);
    results.push_back(g4.outside_team->score - g4.home_team->score);
    Game g5(teams[2], teams[3]);
    results.push_back(g5.outside_team->score - g5.home_team->score);
    Game g6(teams[3], teams[2]);
    results.push_back(g6.outside_team->score - g6.home_team->score);
    Game g7(teams[3], teams[4]);
    results.push_back(g7.outside_team->score - g7.home_team->score);
    Game g8(teams[4], teams[3]);
    results.push_back(g8.outside_team->score - g8.home_team->score);
    Game g9(teams[4], teams[5]);
    results.push_back(g9.outside_team->score - g9.home_team->score);
    Game g10(teams[5], teams[4]);
    results.push_back(g10.outside_team->score - g10.home_team->score);

    for (unsigned long i = 0; i < results.size(); ++i) {
        for (unsigned long j = 1; j < results.size(); ++j) {
            CHECK_NE(results[i], results[j]);
        }
    }
}
