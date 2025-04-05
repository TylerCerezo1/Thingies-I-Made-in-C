#include <stdio.h>
#include <stdlib.h>

#define FILENAME "saveData.dat"

typedef struct {
    char name[50];
    int age;
} User;

void saveData(User user){
    FILE *file =fopen(FILENAME, "wb");//writing in bytes. saves space
    if (file == NULL){
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

User loadData(){
    FILE*file = fopen(FILENAME, "rb");//reading in byts. saves space
    User user;

    if(file == NULL){
        printf("Error opening file for reading. \n");
        //Setting default parameters
        user.age = 0;
        user.name[0] = '\0';
    }

    fread(&user, sizeof(User), 1, file);
    fclose(file);
    return user;
}

int main(){
    User user;

    printf("Enter your name: ");
    fgets(user.name, sizeof(user.name), stdin);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    //save data
    saveData(user);
    //loads data
    User loadedUser = loadData();
    printf("Loaded data:\nName: %sAge: %d\n",loadedUser.name, loadedUser.age);

    return 0;
}