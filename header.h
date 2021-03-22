#ifndef HEADER
#define HEADER

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef struct player {
  int id;
  int numberOfUnities;
  string playerName;
} player;

typedef struct unit {
  int id;
  int idPlayer;
  int x;
  int y;
  int health;
  int totalHealth;
  int atk;
  int speed;
  int critical;
  int heal;         // ONLY FOR HEALERS
  string type_of_unit;
  string unit_name;

  bool isAlive;

  int color;

} unit;



// rules.cpp
void dispRules();

// player.cpp
void achievementGet();
void createPlayers(int id, player *player1, int id2, player *player2);

//units.cpp
int nbFightersNotCorrect(string SFighters);
int defineNbOfUnits();
void createUnits(int nbFighters, unit *nb_of_units, player *p1, player *p2);




// functions.cpp
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



// display.cpp
int pomptIsNumber(string prompt);
void dispImacWars();
void display(unit *matrix[10][10]);
void preDisplay(unit *matrix[10][10]);
void testXY(unit *matrix[10][10], unit *unit_to_move);
void setUpPos(unit *matrix[10][10], unit *units_table, int nbFighters, player *p1, player *p2);



#endif
