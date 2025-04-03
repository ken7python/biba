// c++ -std=c++11 danmaku.cpp -lraylib && ./a.out
// c++ -std=c++11 danmaku.cpp -lraylib -framework Cocoa -framework IOKit && ./a.out
#include "raylib.h"
#include <vector>

struct 弾{
    int x;
    int y;
    int sx; //x方向のスピード
    int sy; //y方向のスピード
    void 動け(){
        x = x + sx;
        y = y + sy;
    }
    void draw(){
        DrawCircle(x, y, 5, YELLOW);
    }
};

//弾* tama = nullptr;
std::vector<弾*> 弾たち;

struct てき{
    int x;
    int y;
    int 銃口x;
    int 銃口y;
    int 銃口xs;
    
    void 弾出す(){
        弾たち.push_back( new 弾{x , y,銃口x * 3,銃口y*8} );
        銃口x = 銃口x + 銃口xs;
        if (銃口x < -20){
            銃口xs = -銃口xs;
        }
        if (+20 < 銃口x){
            銃口xs = -銃口xs;
        }
    }
    void draw(){    //描く
        DrawCircle(x, y, 20, BROWN);
    }
};

int main(){
    InitWindow(800, 450, "Danmaku++");
    SetTargetFPS(60);

    てき teki0{ 400, 50, 1, 1, -1 };
    
    while( !WindowShouldClose() ){
        teki0.弾出す();

        {
            auto i = 弾たち.begin();
            while(i != 弾たち.end()){
                (**i).動け();
                i = i + 1;
            }
        }

        BeginDrawing();
            ClearBackground(BLACK);

            teki0.draw();
            
            {
                auto i = 弾たち.begin();
                while(i != 弾たち.end()){
                    (**i).draw();
                    i = i + 1;
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}