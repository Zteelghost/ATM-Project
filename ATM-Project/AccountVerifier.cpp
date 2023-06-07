#include <iostream>
#include <string>
#include <fstream>
#include "includes/account.h"
#include "includes/AccountVerifier.h"

void VerifyUserIsRegistered() {
   std::ifstream VerifyUsername("Usernames.txt");
    while (std::getline (VerifyUsername, Username)) {
        if(Username != FindUsername && VerifyUsername.eof() == false) {
            continue;
        } else if(Username == FindUsername) {
            UsernameFound = true;
            break;
        } else if(Username != FindUsername && VerifyUsername.eof() == true) {
            UsernameFound = false && FindUsername != Username;
            UsernameNotFound = true;
        }
    }
    VerifyUsername.close();

    std::ifstream VerifyPassword("Passwords.txt");
    while (std::getline (VerifyPassword, Password)) {
        if(Password != FindPassword && VerifyPassword.eof() == false) {
            continue;
        } else if(Password == FindPassword) {
            PasswordFound = true;
            break;
        } else if(Password != FindPassword && VerifyPassword.eof() == true) {
            PasswordFound = false && FindPassword != Password;
            PasswordNotFound = true;
        }
    }
    VerifyPassword.close();

    if(UsernameFound && PasswordFound == true) {
        LoggedIn = true;
    } else if(UsernameFound == true && PasswordFound != true) {
        std::cout << "Password is incorrect. Please reenter your password." << std::endl;
    } else if(UsernameFound == false && PasswordFound == true) {
        std::cout << "Username is incorrect. Please reenter your username." << std::endl;
    } else if(UsernameFound && PasswordFound == false) {
        std::cout << "Username and password is incorrect. Please reenter your details." << std::endl;
    } else {
        std::cout << "AccountVerifier.cpp is broken. Fix it before continuing." << std::endl; 
    }

    if(LoggedIn == true) {
        AccountMenu();
    }
}