// c++ -std=c++11 danmaku.cpp -lraylib && ./a.out
// c++ -std=c++11 danmaku.cpp -lraylib -framework Cocoa -framework IOKit && ./a.out
// c++ -std=c++11 danmaku.cpp librailib.a -framework Cocoa -framework IOKit && ./a.out
#include "raylib.h"
#include <vector>

struct 弾;
std::vector<弾*> 弾たち;

struct 弾{
    int x;
    int y;
    int sx; //x方向のスピード
    int sy; //y方向のスピード
    int 動け(){
        x = x + sx;
        y = y + sy;
        if (x < 0 || 800 < x || y < 0 || 450 < y){
            //画面の外に出た
            return 0;
        }
        return 1;
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
    void 動け(){
        x = x + xs;
        y = y + ys;
        if (800 < x) {
            xs = -xs;
        }
        if (x < 0) {
            xs = -xs;
        }
        if(450 < y) {
            ys = -ys;
        }
        if (y < 0) {
            ys = -ys;
        }
    }
    
    void 弾出す(){
        弾たち.push_back( new 弾{x , y,銃口x * 3 + xs,銃口y*8 + ys} );
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

struct 主人公{
    int x;
    int y;
    void 動け() {
        if (IsKeyDown(KEY_LEFT)) {
            x = x - 3;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            x = x + 3;
        }
        if (IsKeyDown(KEY_UP)) {
            y = y - 3;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y = y + 3;
        }
    }
    void draw() {
        DrawCircle(x, y, 12, YELLOW);
    }
};

int main(){
    InitWindow(800, 450, "Danmaku++");
    SetTargetFPS(60);

    主人公 shujin0 { 400, 400 };
    てき teki0{ 400, 50, 3, 3, 1, 1, -1 };
    
    while( !WindowShouldClose() ){
        shujin0.動け();
        teki0.動け();
        teki0.弾出す();

        {
            auto i = 弾たち.begin();
            while(i != 弾たち.end()){
                int まだいる = (**i).動け();
                if (まだいる == 0){
                    delete *i;
                    i = 弾たち.erase(i);
                }else{
                    i = i + 1;
                }
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

            shujin0.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}