#include <iostream>
#include <string>
#include <cstring>
#include "display.cpp"

using namespace std;

int pomptIsNumber(string prompt);
void dispImacWars();
void display(unit *matrix[9][9]);
void preDisplay(unit *matrix[9][9]);
void testXY(unit *matrix[10][10], unit *unit_to_move);
void setUpPos(unit *matrix[10][10], unit *units_table, int nbFighters, player *p1, player *p2);
