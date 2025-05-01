//% c++ -std=c++11 danmaku2.cpp libraylib.a -framework Cocoa -framework IOKit
#include "raylib.h"
#include <vector>

struct 主人公{
    int x;
    int y;
    void 動け(){
        if(IsKeyDown(KEY_LEFT)){
            x = x - 3;
            if (x < 0) {
                x = 15;
            }
        }
        if(IsKeyDown(KEY_RIGHT)){
            x = x + 3;
            if (x > 800) {
                x = 800 - 15;
            }
        }
        if(IsKeyDown(KEY_UP)){
            y = y - 3;
            if (y < 0) {
                y = 15;
            }
        }
        if(IsKeyDown(KEY_DOWN)){
            y = y + 3;
            if (450 < y) {
                y = 450 - 15;
            }
        }
    }
    void draw(){
        DrawCircle(x, y, 12, WHITE);
        //DrawRectangle(x-6, y-6, 12, 12, YELLOW);
    }
};

struct 弾;
std::vector<弾*> 弾たち;

struct 弾{
    float x;
    float y;
    float sx;     // x方向のスピード
    float sy;     // y方向のスピード
    int 動け(){
        x = x + sx;
        y = y + sy;
        if(x<0 || 800<x || y<0 || 450<y){
            // 画面の外に出た
            return 0;
        }
        return 1;
    }
    int check被弾(主人公* shujin){
        return CheckCollisionCircles( 
            (Vector2){(float)x, (float)y}, 5, 
            (Vector2){(float)(*shujin).x, (float)(*shujin).y}, 12 
        );
    }
    void draw(){
        DrawCircle(x, y, 5, YELLOW);
    }
};

struct てき{
    int x;
    int y;
    int xs;
    int ys;
    int 銃口x;
    int 銃口y;
    int 銃口xs;
    int 銃口ys;
    void 動け(){
        x = x + xs;
        y = y + ys;
        if(800<x){
            xs = -xs;
        }
        if(x<0){
            xs = -xs;
        }
        if(450<y){
            ys = -ys;
        }
        if(y<0){
            ys = -ys;
        }
    }
    void 弾出す(){
        弾たち.push_back( new 弾{(float)x, (float)y, (float)銃口x/10+xs, (float)銃口y/10+ys} );
        銃口x = 銃口x + 銃口xs;
        銃口y = 銃口y + 銃口ys;
        if(銃口x < -20){
            銃口x = -20;
            銃口xs =  0;
            銃口ys = -8;
        }
        if(+20 < 銃口x){
            銃口x = +20;
            銃口xs =  0;
            銃口ys = +8;
        }
        if(銃口y < -20){
            銃口y = -20;
            銃口xs = +8;
            銃口ys =  0;
        }
        if(+20 < 銃口y){
            銃口y = +20;
            銃口xs = -8;
            銃口ys =  0;
        }
    }
    void draw(){    //描く
        DrawCircle(x, y, 20, BROWN);
    }
};

int main(){
    InitAudioDevice();
    InitWindow(800, 450, "Danmaku++");
    SetTargetFPS(60);

    Texture2D bg = LoadTexture("background.png");
    Music bgm = LoadMusicStream("BGM.mp3");
    Sound gameover = LoadSound("gameover.mp3");

START:
    PlayMusicStream(bgm);
    float time0 = GetTime();
    弾たち.clear();    
    主人公 shujin0{ 400, 400 };
    てき teki0{ 400, 225, 1, 1, 21, 21, 0, 0 };

    int kaisu = 0;
    while( !WindowShouldClose() ){
        UpdateMusicStream(bgm);
        shujin0.動け();
        teki0.動け();
        if(kaisu%2 == 0){
            teki0.弾出す();
        }
        kaisu = kaisu + 1;

        int gameover = 0;

        {auto i = 弾たち.begin();
        while(i != 弾たち.end()){
            if( (**i).check被弾(&shujin0) == 1){
                gameover = 1;
            }
            i = i + 1;
        }}

        if(gameover == 1){
            break;
        }

        {auto i = 弾たち.begin();
        while(i != 弾たち.end()){
            int まだいる = (**i).動け();
            if(まだいる == 0){
                delete *i;
                i = 弾たち.erase(i);
            }else{
                i = i + 1;
            }
        }}

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(bg, 0, 0, WHITE);

            DrawText(TextFormat("%0.2f", GetTime() - time0), 10, 10, 20, WHITE);

            teki0.draw();

            {auto i = 弾たち.begin();
            while(i != 弾たち.end()){
                (**i).draw();
                i = i + 1;
            }}

            shujin0.draw();
        EndDrawing();
    }

    // gameover
    StopMusicStream(bgm);
    PlaySound(gameover);
    float time = GetTime() - time0;
    while(! WindowShouldClose() ){
        if (IsKeyPressed(KEY_SPACE)) {
            goto START;
        }
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(bg, 0, 0, WHITE);

            DrawText(TextFormat("%0.2f", time), 10, 10, 20, WHITE);

            teki0.draw();

            {auto i = 弾たち.begin();
            while(i != 弾たち.end()){
                (**i).draw();
                i = i + 1;
            }}

            shujin0.draw();
            DrawText("PRESS SPACE KEY", 100, 225, 60, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}