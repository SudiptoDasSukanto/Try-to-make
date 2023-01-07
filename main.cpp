
#include "AllHeader.h"
int prevTime = 0;
int currentTime = 0;
float deltaTime = 0;
const int level_changed = 121;
const int game_over = 111;
const int help = 40;
const int scores = 80;
const int RETURN = 90;
const int EXIT = 100;

int main(int agr, char *args[])
{
    init();
    TexLoad();
    rect();
    music = Mix_LoadWAV("res/FesliyanStudios.com.mp3");
    mouse_click = Mix_LoadWAV("res/mouseclick.mp3");
    while (Running)
    {  
        prevTime = currentTime;
        // currentTime = SDL_GetTicks();
        deltaTime = (currentTime - prevTime) / 1000.0f;
        GetEvent();
        if (main_game) Game();   
        else if (start)  Start();
        else if (Next_Back)   NextBackGround();

        else if (gameover == 1)  Gameover();
        
    }
   
   close();
    
    return 0;
}