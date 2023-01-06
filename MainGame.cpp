#include "AllHeader.h"

float frameTime = 0;
   
    int cnt[100] = {}, flag[100] = {}, one[100] = {};
    int i = 0;
   
    int main_game = 0, jump = 0, direction = 0, ct = 0;
    int Next_Back = 0;
    int gameover = 0;
    int score=0;
    

    int Time;

void Game(){
     Time = SDL_GetTicks();
            frameTime++;
            if (frameTime == 30 && playerPosition.y + playerPosition.h <= ZoombiePosition.y)
            {
                frameTime = 0;
                playerPosition.y = playerPosition.y + jump_hight;
            }

            frameTime++;
            if (frameTime == 60)
            {
                frameTime = 0;
                ZoombieRect.x += frameW1;
                if (ZoombieRect.x + frameW1 >= textureWidth1)
                {

                    //  ZoombieRect.y+=frameH1;
                    ZoombieRect.x = 0;
                }
            }
            // score++;
            // ZoombiePosition.x-=3 ;

            SDL_RenderClear(rend);

            SDL_RenderCopy(rend, moon_tex, NULL, NULL);
            SDL_RenderCopy(rend, tex2, NULL, &dest2);
            SDL_RenderCopy(rend, tex2, NULL, &dest22);
            SDL_RenderCopy(rend, temp2, &playerRect, &playerPosition);
            SDL_RenderCopy(rend, temp, &ZoombieRect, &ZoombiePosition);
            SDL_RenderCopyEx(rend, fire, 0, &dest_fire, 0, 0, SDL_FLIP_HORIZONTAL);

            dest_fire.x -= 3;

            if ((playerPosition.x + playerPosition.w >= dest_fire.x && playerPosition.x <= dest_fire.x && playerPosition.y <= dest_fire.y && playerPosition.y + playerPosition.h >= dest_fire.y))
            {
                dest_fire.x = -1280;
                score = score + 10;
            }
            if ((playerPosition.x + playerPosition.w >= ZoombiePosition.x && playerPosition.x <= ZoombiePosition.x && playerPosition.y <= ZoombiePosition.y && playerPosition.y + playerPosition.h >= ZoombiePosition.y))
            {
                ZoombiePosition.x = WINDOW_WIDTH;
                gameover = 1;
                main_game = 0;
            }
            // dest.x+=3 ;
            if (playerPosition.x + playerPosition.w > ZoombiePosition.x + ZoombiePosition.w)
            {

                temp = Zoombie_tex;
                // Zoombie_tex = temp ;
                ZoombiePosition.x += 1;
            }

            else if (playerPosition.x + playerPosition.w < ZoombiePosition.x + ZoombiePosition.w)
            {

                temp = ZoombieR_tex;
                ZoombiePosition.x -= 1;
            }
            else
            {
                temp = ZoombieR_tex;
            }

            // s--;
            // if(s<dest2.w)
            //  s=0;
            dest2.x += 3;
            dest22.x += 3;
            if (dest2.x >= WINDOW_WIDTH)
            {
                dest2.x = 0;
                dest22.x = -dest22.w;
            }
            if (dest_fire.x <= -400)
            {
                dest_fire.x = WINDOW_WIDTH;
            }

            // for(int j=0; j<=99; j++)
            // {
            //     if(cnt[j])
            //         cout<<"cnt"<<j<<" "<<cnt[j]<<endl;

            // if(cnt[j])
            // {
            //     if(!one[j])
            //         dest1[j].x=(int)x_pos+270;
            //     one[j]=1;

            //     if(!flag[j])
            //     {
            //         dest1[j].y=dest.y+73;
            //         flag[j]=1;
            //     }

            //     SDL_RenderCopy(rend, tex1, NULL, &dest1[j]);

            //     dest1[j].x+=6;

            //     if(dest1[j].x>=1680)
            //     {
            //         cnt[j]=0;
            //         flag[j]=0;
            //         one[j]=0;
            //     }
            // }
            // }
            // if(x_pos>=WINDOW_WIDTH)
            // {
            //     x_pos=-400;
            // }
            if (dest.y <= 380)
            {
                dest.y = WINDOW_HEIGHT * 0.45;
            }

            if (playerPosition.x >= WINDOW_WIDTH)
            {
                // SDL_Delay(1500);
                gameover = 1;
                main_game = 0;
                // playerPosition.y=100;
            }

            SDL_RenderPresent(rend);
            // SDL_Delay(1000/40);
}