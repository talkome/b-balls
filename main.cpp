#include "Schedule.hpp"

int main() {
    // version 1
    League league1;
    Schedule schedule1(league1);
    schedule1.play();

    // version 2
    vector<Team*> teams{new Team{"A",0.2},new Team{"B",0.3},new Team{"C",0.5},
                        new Team{"D",0.6},new Team{"E",0}};
    League league2(teams);
    Schedule schedule2(league2);
    schedule2.play();
}
