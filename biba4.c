//% cc biba4.c libraylib.a -framework Cocoa -framework IOKit
#include "raylib.h"

struct Hero{
    int x;
    int y;
    int r;
};

void Hero_(struct Hero* hero){
    (*hero).x = 400;
    (*hero).y = 225;
    (*hero).r = 30;
}

void Hero_draw(struct Hero* hero){
    DrawCircle((*hero).x, (*hero).y, (*hero).r, WHITE);
}

int main(void){
    InitWindow(800, 450, "biba4");
    SetTargetFPS(60);

    struct Hero hero0;
    Hero_(&hero0);

    while(! WindowShouldClose()){
        BeginDrawing();
            Hero_draw(&hero0);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}