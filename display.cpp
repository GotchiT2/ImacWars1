#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "header.h"

using namespace std;

string table[10][10];
string color;

int pomptIsNumber(string prompt) {
  if (prompt == "0") return 0;
  else if (prompt == "1") return 1;
  else if (prompt == "2") return 2;
  else if (prompt == "3") return 3;
  else if (prompt == "4") return 4;
  else if (prompt == "5") return 5;
  else if (prompt == "6") return 6;
  else if (prompt == "7") return 7;
  else if (prompt == "8") return 8;
  else if (prompt == "9") return 9;
  else return -1;
}

void dispImacWars(){
  system("CLS");
  cout <<
  "||===================================================================||"           << "\n" <<
  "||                                                                   ||"           << '\n' <<
  "||     _____ ___  ___  ___   _____   _    _   ___  ______  _____     ||"           << "\n" <<
  "||    |_   _||  \\/  | / _ \\ /  __ \\ | |  | | / _ \\ | ___ \\/  ___|    ||"      << "\n" <<
  "||      | |  | .  . |/ /_\\ \\| /  \\/ | |  | |/ /_\\ \\| |_/ /\\ `--.     ||"     << "\n" <<
  "||      | |  | |\\/| ||  _  || |     | |/\\| ||  _  ||    /  `--. \\    ||"        << "\n" <<
  "||     _| |_ | |  | || | | || \\__/\\ \\  /\\  /| | | || |\\ \\ /\\__/ /    ||"    << "\n" <<
  "||     \\___/ \\_|  |_/\\_| |_/ \\____/  \\/  \\/ \\_| |_/\\_| \\_|\\____/     ||" << "\n" <<
  "||                                                                   ||"           << '\n' <<
  "||===================================================================||"           << "\n" ;
  cout << '\n' << '\n' << '\n'<< '\n'<< '\n';
}

void display(unit *matrix[10][10]) {
  cout << "_________________________________________________________________________" << '\n';
  cout <<"      0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |" << '\n';
  cout << "_________________________________________________________________________" << '\n';
  for (int i = 0; i <= 9; i++) {
    cout << " " << i << "   ";
    for (int j  = 0; j <= 9; j++) {
      cout << table[i][j] << "  |  ";
    }
    cout << '\n';
    cout << "_________________________________________________________________________" << '\n';
  }
}

void preDisplay(unit *matrix[10][10]) {
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      if (matrix[i][j] != NULL) {
        if (matrix[i][j]->idPlayer == 1) {
          if (matrix[i][j]->type_of_unit == "Bowman") {
            table[i][j] = "1B";
          }
          else if(matrix[i][j]->type_of_unit == "Healer") {
            table[i][j] = "1H";
          }
          else
            table[i][j] = "1T";
        }
        else
          if (matrix[i][j]->type_of_unit == "Bowman") {
            table[i][j] = "2B";
          }
          else if(matrix[i][j]->type_of_unit == "Healer") {
            table[i][j] = "2H";
          }
          else
          table[i][j] = "2T";
      }
      else
        table[i][j] = "  ";
    }
  }
  display(matrix);
}

void testXY(unit *matrix[10][10], unit *unit_to_move) {
  string prompt;
  int x,y;
  int oldX = unit_to_move->x;
  int oldY = unit_to_move->y;
  int test = 0;
  cout << "Set your new position." << '\n';
  while(test == 0){
    cout << "x >> ";
    cin >> prompt;
    x = pomptIsNumber(prompt);
    if (x < 0 || x > 9) {
      cout << "X not in range." << '\n';
    }
    else{
      test = 1;
      while (test == 1) {
        cout << "y >> ";
        cin >> prompt;
        y = pomptIsNumber(prompt);
        if (y < 0 || y > 9) {
          cout << "Y not in range." << '\n';
        }
        else {
          int distance = abs(x-oldX) + abs(y-oldY);
          if (distance > unit_to_move->speed) {
            cout << "Too far, you speed is only " << unit_to_move->speed << " !" << '\n';
            cout << "Please enter new positions." << '\n';
            test = 0;
          }
          else {
            if (matrix[y][x] != NULL) {
              cout << "the (x,y) position is already taken, please, enter new positions." << '\n';
              test = 0;
            }
            else{
              test = 2;
              matrix[oldY][oldX] = NULL;
              unit_to_move->x = x;
              unit_to_move->y = y;
              matrix[y][x] = unit_to_move;
            }
          }
        }
      }
    }
  }
}

void setUpPos(unit *matrix[10][10], unit *units_table, int nbFighters, player *p1, player *p2) {
  cout << "Now it's time to choose the starting position of each character." << '\n';
  cout << "To do this, choose x (between 0 and 9), press Enter, and repeat it for y." << '\n';
  cout << "Warning ! Do not try to place your characters out of the map, and on other character's position. (spoiler : it won't work)." << '\n' << '\n';


  string prompt;
  int x,y;
  int test = 0;
  for (int i = 0; i < nbFighters*2; i++) {
    if (units_table[i].idPlayer == 1)
      cout << "Okay " << p1->playerName << ", enter the position of your unit #" << i+1 << " (between 0 and 9 for X and Y)" << '\n';
    else
      cout << "Okay " << p2->playerName << ", enter the position of your unit #" << i-nbFighters +1 << " (between 0 and 9 for X and Y)" << '\n';

    while(test == 0){
      cout << "x >> ";
      cin >> prompt;
      x = pomptIsNumber(prompt);
      if (x < 0 || x > 9) {
        cout << "X not in range." << '\n';
      }
      else{
        test = 1;
        while (test == 1) {
          cout << "y >> ";
          cin >> prompt;
          y = pomptIsNumber(prompt);
          if (y < 0 || y > 9) {
            cout << "Y not in range." << '\n';
          }
          else {
            if (matrix[y][x] != NULL) {
              cout << "the (x,y) position is already taken, please, enter new positions." << '\n';
              test = 0;
            }
            else
              test = 2;
          }
        }
      }
    }

    test = 0;

    units_table[i].x = x;
    units_table[i].y = y;
    matrix[y][x] = &units_table[i];


    system("CLS");
    dispImacWars();
    preDisplay(matrix);
  }
}
