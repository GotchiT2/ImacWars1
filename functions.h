#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "functions.cpp"

using namespace std;


void turn(unit *nb_of_units);
void setup();

//ATK
int unitToAtk(int unit_to_move, unit *nb_of_units);
void atkProcess(unit *nb_of_units, int unit_to_move, int unit_to_atk);

//HEAL
int unitToHeal(int unit_to_move, unit *nb_of_units);
void healProcess(unit *nb_of_units, int unit_to_move, int unit_to_heal);


void displayUnitsList(unit *nb_of_units);
void changeToken();
void healerFun(int unit_to_move, unit *nb_of_units);
int healerPrompt(string str);
void gameOver();
