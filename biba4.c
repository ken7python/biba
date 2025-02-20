//% cc biba4.c libraylib.a -framework Cocoa -framework IOKit
#include "raylib.h"

int main(void){
    InitWindow(800, 450, "biba4");
    SetTargetFPS(60);

    while(! WindowShouldClose()){
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}