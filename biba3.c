int putchar(int);
int printf(const char*, ...);

void putNumber(int n){
    if(n >= 100) putchar(48 + (n / 100));
    if(n >= 10) putchar(48 + ((n / 10) % 10) );
    if(n >= 0) putchar(48 + (n % 10));
}

void teki_draw(int x,int y,int hp){
    putNumber(x);
    putchar(',');
    putNumber(y);
    putchar(',');
    putNumber(hp);
    putchar('\n');
}

struct Teki{
    int x;
    int y;
    int hp;
};

void Teki_draw(struct Teki tk){
    putNumber(tk.x);
    putchar(',');
    putNumber(tk.y);
    putchar(',');
    putNumber(tk.hp);
    putchar('\n');
}

void Teki_yarareta(struct Teki* ptk){
printf("%p\n", ptk);
    (*ptk).x = 999;
    (*ptk).y = 999;
    (*ptk).hp = 999;
}

int main(){
    int tekix[3];
    int tekiy[3];
    int tekihp[3];

    // teki 0 出現
    tekix[0] = 100;
    tekiy[0] = 0;
    tekihp[0] = 5;
    teki_draw(tekix[0],tekiy[0],tekihp[0]);

    // teki 1 出現
    tekix[1] = 200;
    tekiy[1] = 0;
    tekihp[1] = 4;
    teki_draw(tekix[1],tekiy[1],tekihp[1]);

    struct Teki teki0;
    teki0.x = 100;
    teki0.y = 0;
    teki0.hp = 8;
    Teki_draw(teki0);

    struct Teki teki1;
    teki1.x = 200;
    teki1.y = 0;
    teki1.hp = 2;
    Teki_draw(teki1);

    Teki_yarareta(&teki1);
    Teki_draw(teki1);

    return 0;
}
