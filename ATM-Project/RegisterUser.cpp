#include <iostream>
#include <string>
#include <fstream>
#include "includes/GlobalUse.h"
#include "includes/RegisterUser.h"


void RegisterUser() {
    std::cout << "Thank you for registering an account with us!" << std::endl;
    std::cout << "Please enter a Username: " << std::endl;
    std::cin >> RegisteredUsername; std::cout << std::endl;
    std::cout << "Please reenter your username for verification: " << std::endl;
    std::cin >> ReverifyRegisteredUsername; std::cout << std::endl;
    std::cout << "Please enter a password: " << std::endl;
    std::cin >> RegisteredPassword; std::cout << std::endl;
    std::cout << "Please reenter your password for verification: " << std::endl;
    std::cin >> ReverifyRegisteredPassword; std::cout << std::endl;
    
    if(RegisteredPassword == ReverifyRegisteredPassword && RegisteredUsername == ReverifyRegisteredUsername) {
        // Write Username and password to respective files
        std::ofstream WriteUsername("Usernames.txt");
        WriteUsername << RegisteredUsername << "\n" << std::endl;
        WriteUsername.close();
        std::ofstream WritePassword("Passwords.txt");
        WritePassword << RegisteredPassword << "\n" << std::endl;
        WritePassword.close();
        std::cout << "Account creation success! Now please login to your account." << std::endl;
        main();
    } else if(RegisteredUsername != ReverifyRegisteredUsername) {
        std::cout << "Username does not matched what you entered. Please try again." << std::endl;
        std::cout << "Please enter a Username: " << std::endl;
        std::cin >> RegisteredUsername; std::cout << std::endl;
        std::cout << "Please reenter your username for verification: " << std::endl;
        std::cin >> ReverifyRegisteredUsername; std::cout << std::endl;
    } else if(RegisteredPassword != ReverifyRegisteredPassword) {
        std::cout << "Password does not match what you entered. Please try again." << std::endl;
        std::cout << "Please enter a password: " << std::endl;
        std::cin >> RegisteredPassword; std::cout << std::endl;
        std::cout << "Please reenter your password for verification: " << std::endl;
        std::cin >> ReverifyRegisteredPassword; std::cout << std::endl;
    } else {
        std::cout << "RegisterUser() is broken. Please fix it." << std::endl;
    }
}