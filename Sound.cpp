#include "Sound.h"

static int SOUND_ON = 1;
bool isnn = false;
void playSound(int i) {
    static vector<const wchar_t*> soundFile{ L"beep.wav", L"move1.wav",
       L"AnotherPlay.wav", L"error.wav", L"win.wav", L"draw.wav", L"nhaccho1.wav",L"subload.wav",L"StarPlay.wav" ,L"START.wav",L"confirm.wav",L"load.wav",L"showload.wav",L"show_win.wav",L"versus.wav",L"tick.wav"};
    if (isSoundOn == true && SOUND_ON == 1) {
        PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
    }
}

void On_Of_sound() {
    SOUND_ON++;
    if (SOUND_ON > 1) SOUND_ON = 0;

    if (SOUND_ON != 1)
    {
        isSoundOn = false;
        PlaySound(0, 0, 0);
    }
    else if (SOUND_ON == 1) {
        isSoundOn = true;
        playSound(2);
    }
}
void nn() {
    if (isnn == true){
        isnn = false;
        PlaySound(0, 0, 0);
    }
    else  {
        isnn = true;
        Playnn();
    }
}
void Playnn() {
    if (isnn) {
        // Phát âm thanh nền
        PlaySound(L"nhacnen2.wav", NULL, SND_FILENAME | SND_LOOP  | SND_ASYNC | SND_NOSTOP);
    }
}

