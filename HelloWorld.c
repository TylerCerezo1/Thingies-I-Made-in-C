#include <stdio.h>
#include <string.h>

void helloWorld(char* textToSayReference){
    char helloText[] = "Hello";
    int interval = 0;
    while(interval < 5){
        textToSayReference[interval] = helloText[interval];
        interval++;
    }
    char worldText[] = " World";
    interval = 5;
    int worldInterval = 0;
    while (interval < 11)
    {
        textToSayReference[interval] = worldText[worldInterval];
        interval++;
        ++worldInterval;
    }
    interval = 0;
    while(interval < 3){
        textToSayReference[strlen(textToSayReference)-interval] = '\0';
        interval++;
    }
    
}

int main(){
    char textToSay[] = "Good bye world";
    helloWorld(textToSay);
    //printf("start");
    printf(textToSay);
    //printf("done");
}