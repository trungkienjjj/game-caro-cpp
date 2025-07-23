#pragma once
#include "ConsoleFoundation.h"
#include <stdio.h>
#include "Decorate.h"
#include "PLAYERVSBOT.h"
#include "PlayervsPlayer.h"
#include "MenuGame.h"
#include "PLAYERVSBOT.h"


int AskContinue();
int AskContinueFound(void (*func1)(), void (*func2)(), void(*func3)());
void AskcontinuePlayer();
void AskcontinueBot();
