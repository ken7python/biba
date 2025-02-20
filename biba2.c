int putchar(int);

void putNchars(char c[]){
    int i = 0;
    while (c[i]){
        putchar(c[i]);
        i = i + 1;
    }
}
void putNumber(int n){
    if(n >= 100) putchar(48 + (n / 100));
    if(n >= 10) putchar(48 + ((n / 10) % 10) );
    if(n >= 0) putchar(48 + (n % 10));
}

int main(){
    int i = 65; // 65:'A'
    while (i < 65 + 26){ // 65 + 26 = 91:'Z'
        putchar(i);
        i = i + 1;
    }

    char age = 23;

    //put6chars('T','o','m','a','t','o');
    //put6chars('T','o',0,0,0,0);
    //put6chars('T','o','m',0,0,0);
    //putchar(age);

    //char tomato[] = {'T','o','m',' ','i','s',' ',0};
    char tomato[] = "Tom is ";
    putNchars(tomato);
    putNumber(age);

    return 0;
}