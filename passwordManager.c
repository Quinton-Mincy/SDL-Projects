#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//
int main(int argc, char** argv){
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* cloudSurface;
    SDL_Texture* cloudTexture;

    SDL_Rect popUp;
    popUp.x = 150;
    popUp.y = 200;
    popUp.w = 400;
    popUp.h = 300;

    SDL_Rect cloud0;
    cloud0.x = 0;
    cloud0.y = 0;
    cloud0.h = 50;
    cloud0.w = 50;
    SDL_Rect cloud1;
    cloud1.x = 120;
    cloud1.y = 78;
    cloud1.h = 50;
    cloud1.w = 50;
    SDL_Rect cloud2;
    cloud2.x = 400;
    cloud2.y = 45;
    cloud2.h = 50;
    cloud2.w = 50;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL RENDER FAILED... ERROR: %s\n",SDL_GetError());
    }else{
        printf("SDL RENDER INITIALIZED\n");
    }

    window = SDL_CreateWindow("SDL Password Manager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    cloudSurface =  SDL_LoadBMP("./images/cloud.bmp");

    SDL_SetColorKey(cloudSurface, SDL_TRUE, SDL_MapRGB(cloudSurface->format, 0xFF, 0, 0xFF));

    cloudTexture = SDL_CreateTextureFromSurface(renderer, cloudSurface);
    SDL_FreeSurface(cloudSurface);

    bool eventLoopActive = true;
    while(eventLoopActive){
        int x, y;
        SDL_Event event;
        //move clouds across the screen
        if(cloud0.x == (699)){
            cloud0.x = 0;
        }else if(cloud1.x == (699)){
            cloud1.x = 0;
        }else if(cloud2.x == (699)){
            cloud2.x = 0;
        }
        else{
            cloud0.x++;
            cloud1.x++;
            cloud2.x++;
        }
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                eventLoopActive = false;
            }
            //reads keyboard input
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    eventLoopActive = false;
                }else{
                    printf("%s Was Pressed...\n",SDL_GetScancodeName(event.key.keysym.scancode));
                }
            }
            //reads mouse input
            if(event.type == SDL_MOUSEBUTTONDOWN){
                SDL_GetMouseState(&x,&y);
                printf("(x: %d, y: %d)\n",x , y);
            }
            
        }
        //set backbround color and clear previous render
        SDL_SetRenderDrawColor(renderer, 0, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);//clears window

        SDL_Delay(40);//slows cloud animation

        SDL_RenderCopy(renderer, cloudTexture, NULL, &cloud0);//render clouds
        SDL_RenderCopy(renderer, cloudTexture, NULL, &cloud1);
        SDL_RenderCopy(renderer, cloudTexture, NULL, &cloud2);
        
        //render in password authentication pop up
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(renderer,&popUp);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer,&popUp);

        SDL_RenderPresent(renderer);//display new render. Similar to update window, but instead of using a double buffer and flipping between them, we render entire screen through each loop
    }
    //free memory
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(cloudTexture);

    SDL_Quit();

    return 0;
}
