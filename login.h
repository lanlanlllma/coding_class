// contact_manager.h
#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to log in using the provided username and password
int login(char* username, char* password);

// Function to get the username input from the user
char* get_username();

// Function to get the password input from the user
char* get_password();

// Function to display the login screen and handle the login process
void draw_loggin();

#endif // CONTACT_MANAGER_H
