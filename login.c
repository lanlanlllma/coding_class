/*
logging in interface
sim_gui style login interface

function:
draw_loggin() -> show the login interface
    return: 

get_username() -> get the username from user
    return: char*

get_password() -> get the password from user
    hidden input
    return: char*

login(char usrname, char pwd) -> login verification
    return: int


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int login(char* username, char* password){
    FILE* fp;
    fp = fopen("user.dat", "r");
    if (fp == NULL)
    {
        return 0;
    }
    char* usrname = (char*)malloc(50);
    char* pwd = (char*)malloc(50);
    while (fscanf(fp, "%s %s", usrname, pwd) != EOF)
    {
        if (strcmp(usrname, username) == 0 && strcmp(pwd, password) == 0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}


char* get_username(){
    char* username = (char*)malloc(50);
    scanf("%s", username);
    return username;
}

char* get_password(){
    char* password = (char*)malloc(50);
    scanf("%s", password);
    return password;
}

void draw_loggin(){
    int flag=0;
    system("cls");
    printf("                                                  Welcome to contact manager\n");
    printf("                                                   Please login to continue\n");
    printf("                                                        Username: ");
    char* username = get_username();
    printf("                                                        Password: ");
    char* password = get_password();
    flag = login(username, password);
    while(flag==0){
        system("cls");
        printf("                                                  Welcome to contact manager\n");
        printf("                                                   Please login to continue\n");
        printf("                                                  Wrong username or password\n");
        printf("                                                        Username: ");
        username = get_username();
        printf("                                                        Password: ");
        password = get_password();
        flag = login(username, password);
    }

}
