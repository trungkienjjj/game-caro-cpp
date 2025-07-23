#include <string>
#include "ConsoleFoundation.h"
#include "PLAYERVSBOT.h"
#include "PlayervsPlayer.h"
#include <fstream>
#include "MenuGame.h"

using namespace std; 


void SaveGame_ESC();
void LoadGame(string taptin);
void XuLyLoadGame();
void SaveGame_ESC_BOT();
void Name_file(const char* s, string& taptin);
void Name_file_bot(const char* s, string& taptin);