
#include "AllHeader.h"

int prevTime = 0;
int currentTime = 0;
float deltaTime = 0;
// int score = 0;




const int level_changed = 121;
const int game_over = 111;
const int help = 40;
const int scores = 80;
const int RETURN = 90;
const int EXIT = 100;
int getHighScore()
{

    int scores;
    FILE *q = fopen("highscore.txt", "r");
    fscanf(q, "%d", &scores);
    fclose(q);
    return scores;
}

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
        
        
        else if (Next_Back)
        {
            int mousex, mousey;
            int button = SDL_GetMouseState(&mousex, &mousey);
            
            SDL_RenderClear(rend);
           
 
            SDL_RenderCopy(rend, tex_menu, NULL, NULL);
            SDL_RenderPresent(rend);
            


            CallMenu();
  


        }

        else if (gameover == 1)
        {
            Gameover();
        }
    }
   
    SDL_RenderPresent(rend);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(charli1);

    SDL_DestroyTexture(charli2);

    SDL_Quit();
    return 0;
}