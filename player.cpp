#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#include "string.h"
#include "header.h"

using namespace std;



string tempName;

void achievementGet();

void createPlayers(int id, player *player1, int id2, player *player2){
    //CREATE PLAYER1

    player1->id = 1;
    cout << "Okay Player 1, how should I call you ? (max 8 chars)" << '\n';
    cout << ">> ";
    getline(cin, tempName);
    tempName.erase( remove( tempName.begin(), tempName.end(), ' ' ), tempName.end() );
    while (tempName.length() == 0 || tempName.length() > 8 ) {
      cout << "Ahem... I told you max 8 chars (- . - )\"" << '\n';
      cout << ">> ";
      getline(cin, tempName);
      tempName.erase(remove(tempName.begin(), tempName.end(), ' '), tempName.end());
    }
    player1->playerName = tempName;
    if (tempName == "sylvain" || tempName == "steeve")  achievementGet();
    tempName = "";
    cout << "Okay Player 1, now you are " << player1->playerName << "." << '\n' << '\n';

    //CREATE PLAYER 2

    player2->id = 2;
    cout << "Okay Player 2, how should I call you ? (max 8 chars)" << '\n';
    cout << ">> ";
    getline(cin, tempName);
    tempName.erase( remove( tempName.begin(), tempName.end(), ' ' ), tempName.end() );
    while (tempName.length() == 0 || tempName.length() > 8 ) {
      cout << "Ahem... I told you max 8 chars \"(- . - )" << '\n';
      cout << ">> ";
      getline(cin, tempName);
      tempName.erase(remove(tempName.begin(), tempName.end(), ' '), tempName.end());
    }
    player2->playerName = tempName;
    if (tempName == "sylvain" || tempName == "steeve")  achievementGet();
    tempName = "";
    cout << "Okay Player 2, now you are " << player2->playerName << "." << '\n' << '\n';
}

void achievementGet() {
  system("CLS");
  cout << "Congratulations, you unlocked the special end !" << "\n\n\n";
  cout << tempName << "... Ahem... You should not enter your real name on this game..." << "\n\n\n";
  cout << "                                       .....'',;;::cccllllllllllllcccc:::;;,,,''...'',,'.." << "\n";
  cout << "                            ..';cldkO00KXNNNNXXXKK000OOkkkkkxxxxxddoooddddddxxxxkkkkOO0XXKx:." << "\n";
  cout << "                      .':ok0KXXXNXK0kxolc:;;,,,,,,,,,,,;;,,,''''''',,''..              .'lOXKd'" << "\n";
  cout << "                 .,lx00Oxl:,'............''''''...................    ...,;;'.             .oKXd." << "\n";
  cout << "              .ckKKkc'...'',:::;,'.........'',;;::::;,'..........'',;;;,'.. .';;'.           'kNKc." << "\n";
  cout << "           .:kXXk:.    ..       ..................          .............,:c:'...;:'.         .dNNx." << "\n";
  cout << "          :0NKd,          .....''',,,,''..               ',...........',,,'',,::,...,,.        .dNNx." << "\n";
  cout << "         .xXd.         .:;'..         ..,'             .;,.               ...,,'';;'. ...       .oNNo" << "\n";
  cout << "         .0K.         .;.              ;'              ';                      .'...'.           .oXX:" << "\n";
  cout << "        .oNO.         .                 ,.              .     ..',::ccc:;,..     ..                lXX:" << "\n";
  cout << "       .dNX:               ......       ;.                'cxOKK0OXWWWWWWWNX0kc.                    :KXd." << "\n";
  cout << "     .l0N0;             ;d0KKKKKXK0ko:...              .l0X0xc,...lXWWWWWWWWKO0Kx'                   ,ONKo." << "\n";
  cout << "   .lKNKl...'......'. .dXWN0kkk0NWWWWWN0o.            :KN0;.  .,cokXWWNNNNWNKkxONK: .,:c:.      .';;;;:lk0XXx;" << "\n";
  cout << "  :KN0l';ll:'.         .,:lodxxkO00KXNWWWX000k.       oXNx;:okKX0kdl:::;'',;coxkkd, ...'. ...'''.......',:lxKO:." << "\n";
  cout << " oNNk,;c,'',.                      ...;xNNOc,.         ,d0X0xc,.     .dOd,           ..;dOKXK00000Ox:.   ..''dKO," << "\n";
  cout << "'KW0,:,.,:..,oxkkkdl;'.                'KK'              ..           .dXX0o:'....,:oOXNN0d;.'. ..,lOKd.   .. ;KXl." << "\n";
  cout << ";XNd,;  ;. l00kxoooxKXKx:..ld:         ;KK'                             .:dkO000000Okxl;.   c0;      :KK;   .  ;XXc" << "\n";
  cout << "'XXdc.  :. ..    '' 'kNNNKKKk,      .,dKNO.                                   ....       .'c0NO'      :X0.  ,.  xN0." << "\n";
  cout << ".kNOc'  ,.      .00. ..''...      .l0X0d;.             'dOkxo;...                    .;okKXK0KNXx;.   .0X:  ,.  lNX'" << "\n";
  cout << " ,KKdl  .c,    .dNK,            .;xXWKc.                .;:coOXO,,'.......       .,lx0XXOo;...oNWNXKk:.'KX;  '   dNX." << "\n";
  cout << "  :XXkc'....  .dNWXl        .';l0NXNKl.          ,lxkkkxo' .cK0.          ..;lx0XNX0xc.     ,0Nx'.','.kXo  .,  ,KNx." << "\n";
  cout << "   cXXd,,;:, .oXWNNKo'    .'..  .'.'dKk;        .cooollox;.xXXl     ..,cdOKXXX00NXc.      'oKWK'     ;k:  .l. ,0Nk." << "\n";
  cout << "    cXNx.  . ,KWX0NNNXOl'.           .o0Ooldk;            .:c;.':lxOKKK0xo:,.. ;XX:   .,lOXWWXd.      . .':,.lKXd." << "\n";
  cout << "     lXNo    cXWWWXooNWNXKko;'..       .lk0x;       ...,:ldk0KXNNOo:,..       ,OWNOxO0KXXNWNO,        ....'l0Xk," << "\n";
  cout << "     .dNK.   oNWWNo.cXK;;oOXNNXK0kxdolllllooooddxk00KKKK0kdoc:c0No        .'ckXWWWNXkc,;kNKl.          .,kXXk," << "\n";
  cout << "      'KXc  .dNWWX;.xNk.  .kNO::lodxkOXWN0OkxdlcxNKl,..        oN0'..,:ox0XNWWNNWXo.  ,ONO'           .o0Xk;" << "\n";
  cout << "      .ONo    oNWWN0xXWK, .oNKc       .ONx.      ;X0.          .:XNKKNNWWWWNKkl;kNk. .cKXo.           .ON0;" << "\n";
  cout << "      .xNd   cNWWWWWWWWKOkKNXxl:,'...;0Xo'.....'lXK;...',:lxk0KNWWWWNNKOd:..   lXKclON0:            .xNk." << "\n";
  cout << "      .dXd   ;XWWWWWWWWWWWWWWWWWWNNNNNWWNNNNNNNNNWWNNNNNNWWWWWNXKNNk;..        .dNWWXd.             cXO." << "\n";
  cout << "      .xXo   .ONWNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNK0ko:'..OXo          'l0NXx,              :KK," << "\n";
  cout << "      .OXc    :XNk0NWXKNWWWWWWWWWWWWWWWWWWWWWNNNX00NNx:'..       lXKc.     'lONN0l.              .oXK:" << "\n";
  cout << "      .KX;    .dNKoON0;lXNkcld0NXo::cd0NNO:;,,'.. .0Xc            lXXo..'l0NNKd,.              .c0Nk," << "\n";
  cout << "      :XK.     .xNX0NKc.cXXl  ;KXl    .dN0.       .0No            .xNXOKNXOo,.               .l0Xk;." << "\n";
  cout << "     .dXk.      .lKWN0d::OWK;  lXXc    .OX:       .ONx.     . .,cdk0XNXOd;.   .'''....;c:'..;xKXx," << "\n";
  cout << "     .0No         .:dOKNNNWNKOxkXWXo:,,;ONk;,,,,,;c0NXOxxkO0XXNXKOdc,.  ..;::,...;lol;..:xKXOl." << "\n";
  cout << "     ,XX:             ..';cldxkOO0KKKXXXXXXXXXXKKKKK00Okxdol:;'..   .';::,..':llc,..'lkKXkc." << "\n";
  cout << "     :NX'    .     ''            ..................             .,;:;,',;ccc;'..'lkKX0d;." << "\n";
  cout << "     lNK.   .;      ,lc,.         ................        ..,,;;;;;;:::,....,lkKX0d:." << "\n";
  cout << "    .oN0.    .'.      .;ccc;,'....              ....'',;;;;;;;;;;'..   .;oOXX0d:." << "\n";
  cout << "    .dN0.      .;;,..       ....                ..''''''''....     .:dOKKko;." << "\n";
  cout << "     lNK'         ..,;::;;,'.........................           .;d0X0kc'." << "\n";
  cout << "     .xXO'                                                 .;oOK0x:." << "\n";
  cout << "      .cKKo.                                    .,:oxkkkxk0K0xc'." << "\n";
  cout << "        .oKKkc,.                         .';cok0XNNNX0Oxoc,." << "\n";
  cout << "          .;d0XX0kdlc:;,,,',,,;;:clodkO0KK0Okdl:,'.." << "\n";
  cout << "              .,coxO0KXXXXXXXKK0OOxdoc:,.." << "\n";
  cout << "                        ..." << "\n";
  do
  {
   cout << '\n' << "Press a key to continue..." << '\n';
  } while (cin.get() != '\n');
  exit(0);
}
