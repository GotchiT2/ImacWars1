#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <limits>
#include <cstdlib>


#include "header.h"

using namespace std;


//////////////////////////
///////// VARS ///////////
//////////////////////////

player player1;
player player2;
int nbFighters;
unit *units_table[10][10];
int turn_token = 0;
int unit_to_move;
int newX,newY, oldX, oldY;
int unit_to_atk;
int unit_to_heal;
char choice;
string name;
string prompt;


//////////////////////////
////// PROTOTYPES ////////
//////////////////////////


void turn(unit *nb_of_units);
int unitToMove(int unit_to_move, unit *nb_of_units);
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

void setup() {
  dispRules();
  do
  {
   cout << '\n' << "Press a key to continue..." << '\n';
  } while (cin.get() != '\n');
  dispRules();
  createPlayers(1, &player1, 2, &player2);
  nbFighters = defineNbOfUnits();
  unit nb_of_units[nbFighters*2];
  player1.numberOfUnities = nbFighters;
  player2.numberOfUnities = nbFighters;
  dispImacWars();
  preDisplay(units_table);
  createUnits(nbFighters, nb_of_units, &player1, &player2);
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      units_table[i][j] = NULL;
    }
  }
  dispImacWars();
  preDisplay(units_table);
  setUpPos(units_table, nb_of_units, nbFighters, &player1, &player2);
  turn(nb_of_units);
}

void turn(unit *nb_of_units){  //PLAYER TURN LAUNCH
    while (player1.numberOfUnities > 0 && player2.numberOfUnities > 0) {
      dispImacWars();
      preDisplay(units_table);
      cout << "player1 units : " << player1.numberOfUnities <<"\n";
      cout << "player2 units : " << player2.numberOfUnities <<"\n";
      displayUnitsList(nb_of_units);
      unit_to_move = unitToMove(unit_to_move, nb_of_units);     //CHOOSE UNIT TO MOVE

      system("CLS");
      dispImacWars();
      preDisplay(units_table);
      displayUnitsList(nb_of_units);

      testXY(units_table, &nb_of_units[unit_to_move]);          //CHOOSE DESTINATION

      system("CLS");
      dispImacWars();
      preDisplay(units_table);
      displayUnitsList(nb_of_units);

      if (nb_of_units[unit_to_move].type_of_unit == "Healer") {
        healerFun(unit_to_move, nb_of_units);
      } else {
        unit_to_atk = unitToAtk(unit_to_move, nb_of_units);      //CHOOSE UNIT TO ATK
        if (unit_to_atk != -1) {
          atkProcess(nb_of_units, unit_to_move, unit_to_atk);
        }
      }

      system("CLS");
      dispImacWars();
      preDisplay(units_table);
      changeToken();
    }
}

int unitToMove(int unit_to_move, unit *nb_of_units){
  if (turn_token == 0)
    cout << "Okay " << player1.playerName << ", choose a character you want to play with (between 1 and " << nbFighters << ")" << '\n';
  else
    cout << "Okay " << player2.playerName << ", choose a character you want to play with (between 1 and " << nbFighters << ")" << '\n';
  cout << ">> ";
  cin >> prompt;
  unit_to_move = pomptIsNumber(prompt);
  unit_to_move += turn_token*nbFighters;
  unit_to_move--;

  while (unit_to_move < 0 || unit_to_move >= nbFighters*2 || nb_of_units[unit_to_move].health <= 0 || nb_of_units[unit_to_move].idPlayer != turn_token+1) {
    cout << '\n';
    cout << '\n';
    cout << "This is not a unit number. Please try again..." << '\n';
    cout << ">> ";
    cin >> prompt;
    unit_to_move = pomptIsNumber(prompt);
    cout << '\n';
    unit_to_move += turn_token*nbFighters;
    unit_to_move--;
  }
  return unit_to_move;
}

int unitToAtk(int unit_to_move, unit *nb_of_units) {
  changeToken();
  cout << "Okay " << name << ", Do you want to attack someone ? (y or n)" << '\n';
  cout << "(y or n) >> ";
  cin >> choice;
  if (choice == 'N' || choice == 'n') {
    changeToken();
    return -1;
  }

  cout << "(unit # to attack) >> ";
  cin >> prompt;
  unit_to_atk = pomptIsNumber(prompt);
  unit_to_atk += (turn_token)*nbFighters;
  unit_to_atk--;

  int distanceAtk = abs(nb_of_units[unit_to_atk].x - nb_of_units[unit_to_move].x) + abs(nb_of_units[unit_to_atk].y - nb_of_units[unit_to_move].y);
  while(distanceAtk > nb_of_units[unit_to_move].speed || nb_of_units[unit_to_atk].health <= 0 || nb_of_units[unit_to_atk].idPlayer != turn_token + 1) {
    if (nb_of_units[unit_to_atk].health <= 0)
      cout << "This unit is already dead or doesn't exist ! Do you want to skip your turn ? (y or n)" << '\n';
    else
      cout << "This unit is too far from you or doesn't exist... Do you want to skip your turn ? (y or n)" << '\n';
    cout << ">> ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
      changeToken();
      return -1;
    }

    cout << "Enter a correct unit" << '\n';
    cout << ">> ";
    cin >> prompt;
    unit_to_atk = pomptIsNumber(prompt);
    unit_to_atk += (turn_token)*nbFighters;
    unit_to_atk--;
    distanceAtk = abs(nb_of_units[unit_to_atk].x - nb_of_units[unit_to_move].x) + abs(nb_of_units[unit_to_atk].y - nb_of_units[unit_to_move].y);
  }
  changeToken();
  return unit_to_atk;
}

void atkProcess(unit *nb_of_units, int unit_to_move, int unit_to_atk) {
  int critRand = rand() * 100;
  int atk = nb_of_units[unit_to_move].atk;
  int def = nb_of_units[unit_to_atk].atk;
  int atkX = nb_of_units[unit_to_atk].x;
  int atkY = nb_of_units[unit_to_atk].y;
  int moveX = nb_of_units[unit_to_move].x;
  int moveY = nb_of_units[unit_to_move].y;

  if (critRand <= nb_of_units[unit_to_move].critical) {
    atk += 15;
  }
  if (nb_of_units[unit_to_atk].health <= atk) {
    nb_of_units[unit_to_atk].health = 0;
    nb_of_units[unit_to_atk].isAlive = false;
    units_table[atkY][atkX] = NULL;
    if (turn_token == 1) {
      player1.numberOfUnities--;
    }
    else {
      player2.numberOfUnities--;
    }
    return;
  }
  else {
    nb_of_units[unit_to_atk].health -= atk;
    int dis = abs(atkX-moveX) + abs(atkY - moveY);
    if (dis <= nb_of_units[unit_to_atk].speed && nb_of_units[unit_to_move].health < def)
      nb_of_units[unit_to_move].health = 1;
    else {
      if (abs(atkX-moveX) + abs(atkY - moveY) <= nb_of_units[unit_to_atk].speed)
        nb_of_units[unit_to_move].health -= def;
    }
  }
}

void healerFun(int unit_to_move, unit *nb_of_units) {
  string promptH;
  int f;
  cout << "Do you want to attack [1], heal [2] or skip your turn [enter another char] ?" << '\n';
  cout << ">> ";
  cin >> promptH;
  f = healerPrompt(promptH);
  while (f == 0 && f == 1 && f == 2) {
    cout << "Enter a correct number please..." << '\n';
    cout << ">> ";
    cin >> promptH;
    f = healerPrompt(promptH);
  }

  switch (f) {
    case 1:
      unit_to_atk = unitToAtk(unit_to_move, nb_of_units);      //CHOOSE UNIT TO ATK
      if (unit_to_atk != -1) {
        atkProcess(nb_of_units, unit_to_move, unit_to_atk);
      }
      return;
    case 2:
      unit_to_heal = unitToHeal(unit_to_move, nb_of_units);   //CHOOSE UNIT TO HEAL
      if (unit_to_heal != -1) {
        healProcess(nb_of_units, unit_to_move, unit_to_heal);
      }
      return;
  }


}

int healerPrompt(string str) {
  if (str == "0") return 0;
  else if (str == "1") return 1;
  else if (str == "2") return 2;
  return 5;
}

int unitToHeal(int unit_to_move, unit *nb_of_units) {
  cout << "Okay " << name << ", Do you want to heal someone (+20 hp) ? (y or n)" << '\n';
  cout << "(y or n) >> ";
  cin >> choice;
  if (choice == 'N' || choice == 'n') return -1;

  cout << "(unit # to heal) >> ";
  cin >> prompt;
  unit_to_heal = pomptIsNumber(prompt);
  unit_to_heal += (turn_token)*nbFighters;
  unit_to_heal--;

  while(nb_of_units[unit_to_heal].health <= 0 || nb_of_units[unit_to_heal].idPlayer != turn_token+1) {
    cout << "This unit is already dead, doesn't exist or is not one of yours ! Do you want to skip your turn ? (y or n)" << '\n';
    cout << ">> ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
      changeToken();
      return -1;
    }

    cout << "Enter a correct unit" << '\n';
    cout << ">> ";
    cin >> prompt;
    unit_to_heal = pomptIsNumber(prompt);
    unit_to_heal += (turn_token)*nbFighters;
    unit_to_heal--;
  }

  return unit_to_heal;
}

void healProcess(unit *nb_of_units, int unit_to_move, int unit_to_heal) {
  int critRand = rand() * 100;
  int heal = nb_of_units[unit_to_move].heal;
  if (critRand <= nb_of_units[unit_to_move].critical) {
    heal += 15;
  }
  if (nb_of_units[unit_to_heal].totalHealth <= nb_of_units[unit_to_heal].health + heal)
    nb_of_units[unit_to_heal]. health = nb_of_units[unit_to_heal].totalHealth;
  else
    nb_of_units[unit_to_heal].health += heal;
}

void displayUnitsList(unit *nb_of_units){
  cout << player1.playerName << " units left :" << '\n';
  for (int i = 0; i < nbFighters; i++) {
    if (nb_of_units[i].type_of_unit == "Healer" && nb_of_units[i].health > 0)
      cout << "    Unit #" << i+1 << " : " << nb_of_units[i].unit_name << " ( " << nb_of_units[i].x << " , " << nb_of_units[i].y << " ) || Health : " << nb_of_units[i].health << " || Speed : " << nb_of_units[i].speed << " || Atk_range : 6 ; Heal_range : Infinite || Atk : " << nb_of_units[i].atk << " || Heal : +20hp || Critical : " << nb_of_units[i].critical << '\n';
    else if (nb_of_units[i].health > 0 && nb_of_units[i].type_of_unit != "Healer")
      cout << "    Unit #" << i+1 << " : " << nb_of_units[i].unit_name << " ( " << nb_of_units[i].x << " , " << nb_of_units[i].y << " ) || Health : " << nb_of_units[i].health << " || Speed : " << nb_of_units[i].speed << " || Range : " << nb_of_units[i].speed << " || Atk : " << nb_of_units[i].atk << " || Critical : " << nb_of_units[i].critical << '\n';
  }
  cout << '\n' << '\n';
  cout << player2.playerName << " units left :" << '\n';
  for (int i = 0; i < nbFighters; i++) {
    if (nb_of_units[i+nbFighters].type_of_unit == "Healer" && nb_of_units[i+nbFighters].health > 0)
      cout << "    Unit #" << i+1 << " : " << nb_of_units[i+nbFighters].unit_name << " ( " << nb_of_units[i+nbFighters].x << " , " << nb_of_units[i+nbFighters].y << " ) || Health : " << nb_of_units[i+nbFighters].health << " || Speed : " << nb_of_units[i+nbFighters].speed << " || Range : Infinite || Atk : " << nb_of_units[i+nbFighters].atk << " || Heal : +20hp || Critical : " << nb_of_units[i+nbFighters].critical << '\n';
    else if (nb_of_units[i+nbFighters].health > 0 && nb_of_units[i+nbFighters].type_of_unit != "Healer")
      cout << "    Unit #" << i+1 << " : " << nb_of_units[i+nbFighters].unit_name << " ( " << nb_of_units[i+nbFighters].x << " , " << nb_of_units[i+nbFighters].y << " ) || Health : " << nb_of_units[i+nbFighters].health << " || Speed : " << nb_of_units[i+nbFighters].speed << " || Range : " << nb_of_units[i+nbFighters].speed << " || Atk : " << nb_of_units[i+nbFighters].atk << " || Critical : " << nb_of_units[i+nbFighters].critical << '\n';
  }
  cout << '\n' << '\n' << '\n';
}

void changeToken() {
  if (turn_token == 0)
  turn_token = 1;
  else
  turn_token = 0;
}

void gameOver() {
  if (player1.numberOfUnities==0 && player2.numberOfUnities==0){
    system("CLS");
    cout << "||===================================================================||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||        _____ _   _              ____________  ___  _    _         ||"<< '\n';
    cout << "||       |_   _| | ( )             |  _  \\ ___ \\/ _ \\| |  | |        ||"<< '\n';
    cout << "||         | | | |_|/ ___    __ _  | | | | |_/ / /_\\ \\ |  | |        ||"<< '\n';
    cout << "||         | | | __| / __|  / _` | | | | |    /|  _  | |/\\| |        ||"<< '\n';
    cout << "||        _| |_| |_  \\__ \\ | (_| | | |/ /| |\\ \\| | | \\  /\\           ||"<< '\n';
    cout << "||        \\___/ \\__| |___/  \\__,_| |___/ \\_| \\_\\_| |_/\\/  \\/         ||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||===================================================================||"<< '\n';
    do
    {
     cout << "\n\n\n" << "Press a key to continue..." << '\n';
    } while (cin.get() != '\n');
  }

  if (player1.numberOfUnities>0 && player2.numberOfUnities==0){
    system("CLS");
    cout << "||===================================================================||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||           ______ _       _____   _____________     __             ||"<< '\n';
    cout << "||           | ___ \\ |     / _ \\ \\ / /  ___| ___ \\   /  |            ||"<< '\n';
    cout << "||           | |_/ / |    / /_\\ \\ V /| |__ | |_/ /   `| |            ||"<< '\n';
    cout << "||           |  __/| |    |  _  |\\ / |  __||    /     | |            ||"<< '\n';
    cout << "||           | |   | |____| | | || | | |___| |\\ \\    _| |_           ||"<< '\n';
    cout << "||           \\_|   \\_____/\\_| |_/\\_/ \\____/\\_| \\_|   \\___/           ||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||                        _    _ _____ _   _                         ||"<< '\n';
    cout << "||                       | |  | |_   _| \\ | |                        ||"<< '\n';
    cout << "||                       | |  | | | | |  \\| |                        ||"<< '\n';
    cout << "||                       | |/\\| | | | | . ` |                        ||"<< '\n';
    cout << "||                       \\  /\\  /_| |_| |\\  |                        ||"<< '\n';
    cout << "||                        \\/  \\/ \\___/\\_| \\_/                        ||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||===================================================================||"<< '\n';

    cout << "\n" << "Score : " << nbFighters*1000 - (nbFighters-player1.numberOfUnities)*200 << '\n';
    system("PAUSE");
  }

  if (player1.numberOfUnities==0 && player2.numberOfUnities>0){
    system("CLS");
    cout << "||===================================================================||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||           ______ _       _____   _____________     _____          ||"<< '\n';
    cout << "||           | ___ \\ |     / _ \\ \\ / /  ___| ___ \\   / __  \\         ||"<< '\n';
    cout << "||           | |_/ / |    / /_\\ \\ V /| |__ | |_/ /   `' / /'         ||"<< '\n';
    cout << "||           |  __/| |    |  _  |\\ / |  __||    /      / /           ||"<< '\n';
    cout << "||           | |   | |____| | | || | | |___| |\\ \\    ./ /___         ||"<< '\n';
    cout << "||           \\_|   \\_____/\\_| |_/\\_/ \\____/\\_| \\_|   \\_____/         ||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||                        _    _ _____ _   _                         ||"<< '\n';
    cout << "||                       | |  | |_   _| \\ | |                        ||"<< '\n';
    cout << "||                       | |  | | | | |  \\| |                        ||"<< '\n';
    cout << "||                       | |/\\| | | | | . ` |                        ||"<< '\n';
    cout << "||                       \\  /\\  /_| |_| |\\  |                        ||"<< '\n';
    cout << "||                        \\/  \\/ \\___/\\_| \\_/                        ||"<< '\n';
    cout << "||                                                                   ||"<< '\n';
    cout << "||===================================================================||"<< '\n';
    cout << "\n" << "Score : " << nbFighters*1000 - (nbFighters-player2.numberOfUnities)*200 << '\n';
    system("PAUSE");
  }
}
