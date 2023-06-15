#include <iostream>
#include "includes/account.h"
#include "includes/RegisterUser.h"
#include "includes/AccountVerifier.h"

int ChoiceSelection1;

int main() {
    std::cout << "Hello, welcome to ATM! Please select from the list below!" << std::endl;
    std::cout << "Press 1 to login to your account." << std::endl;
    std::cout << "Press 2 to register an account with us." << std::endl;
    std::cin >> ChoiceSelection1;
    
    if(ChoiceSelection1 == 1) {
        std::cout << "Please enter your Username, and Password below.";
        std::cout << "Username: \n";
        std::cin >> Username;
        std::cout << "Password: \n";
        std::cin >> Password;
        VerifyUserIsRegistered();
    }
    if(ChoiceSelection1 == 2) {
        RegisterUser();
    }
    if(ChoiceSelection1 != 1 || 2) {
        std::cout << "Invalid entry! ";
        main();
    }
    return 0;
}
