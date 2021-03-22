#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "header.h"
using namespace std;



void dispRules() {
  char choice;
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

  cout << "||                                                                   ||"<< '\n';
  cout << "|| Welcome to : ImacWars                                             ||"<< '\n';
  cout << "||                                                                   ||"<< '\n';
  cout << "|| Rules are simple :                                                ||"<< '\n';
  cout << "|| 1 - Choose an amount of fighters in each team                     ||"<< '\n';
  cout << "|| 2 - Name and place your fighters                                  ||"<< '\n';
  cout << "|| 3 - Destroy the opponent                                          ||"<< '\n';
  cout << "||                                                                   ||"<< '\n';
  cout << "|| Each unite has its own class (bowman, tank, healer) which grant   || \n|| it a special effect.                                              ||"<< '\n';
  cout << "||                                                                   ||"<< '\n';
  cout << "|| The tank unit has a lot of health and strength, but it is         || \n|| really slow.                                                      ||"<< '\n';
  cout << "|| The bowman is a normal unit with a balance kit                    ||"<< '\n';
  cout << "|| The healer is weak, but faster than everyone else and can heal    || \n|| his teammates (or attack).                                        ||"<< '\n';
  cout << "||                                                                   ||"<< '\n';
  cout << "|| When it's your turn, select one of your units by using its ID     ||"<< '\n';
  cout << "|| Then, choose the coordinate to move it                            ||"<< '\n';
  cout << "||                                                                   ||"<< '\n';
  cout << "|| Finally, target one of your opponent's unit to attack it          ||\n|| (if in range)                                                     ||" << '\n';
  cout << "|| Or target one of your unit to heal it                             ||\n|| (if you're playing the healer)                                    ||" << '\n';
  cout << "||                                                                   ||"<< '\n';
  cout << "|| Warning !                                                         ||"<< '\n';
  cout << "|| When you attack, the opponent unit will hurt you                  ||\n|| (if you are in its range)                                         ||" << '\n';
  cout << "||                                                                   ||"<< '\n';
  cout << "||===================================================================||"<< "\n\n";
  cout << "\n\n";
}
