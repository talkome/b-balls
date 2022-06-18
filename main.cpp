#include "Schedule.hpp"

int main() {
    // version 1
    League league1;
    Schedule schedule1(league1);
    schedule1.play();

    // version 2
    vector<Team*> teams{new Team{"A"},new Team{"B"},new Team{"C"},
                        new Team{"D"},new Team{"E"}};
    League league2(teams);
    Schedule schedule2(league2);
    schedule2.play();
}
