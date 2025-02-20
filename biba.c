int oresama_no_sugoi_program(int a){
    // 1〜aまでを足す
    int kekka = 0;
    int i = 1;
    while (i <= a){
        kekka = kekka + i;
        i = i + 1;
    }

    return kekka;
}

int oresugo(){
    return 5;
}

int main(){
    int o1 = oresama_no_sugoi_program(10);
    int o2 = oresugo();
    if ( 255 < o1 + o2){
        return 0;
    }else{
        return o1 + o2;
    }
}