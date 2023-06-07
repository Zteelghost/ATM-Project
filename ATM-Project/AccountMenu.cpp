#include <iostream>
#include <chrono>
#include <thread>
#include "includes/GlobalUse.h"
#include "includes/account.h"

char confirm, anotherTransaction, y, n, ChoiceSelection2;

void Withdrawl() {
    std::cout << "Your balance is: " << accountBalance << std::endl << "How much would you like to withdraw?" << std::endl;
    std::cin >> accountWithdraw; std::cout << std::endl;
    std::cout << "Are you sure you want to withdraw " << accountWithdraw << "?" << std::endl;
    std::cout << "Press y for Yes or n for No" << std::endl;
    std::cin >> confirm;

    if(confirm == y) {
        std::cout << "$" << accountWithdraw << " has been withdrawn" << std::endl;
        accountBalance = accountWithdraw - accountBalance;
        accountWithdraw = 0.00;
        std::cout << "You have $" << accountBalance << " left in your account." << std::endl;
        std::cout << "Would you like to make another transaction?" << std::endl;
        std::cin >> anotherTransaction;

        if(anotherTransaction == y) {
            void Menu();
            } else if(anotherTransaction == n) {
                main();
            } else {
                std::cout << "Invalid entry!" << std::endl;
                Withdrawl();
            }
        }
        if(confirm == n) {
            accountWithdraw = 0.00;
            std::cout << "Transaction cancelled. Redirecting you in 3 seconds..." << std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(3));
            void Menu();
        } else {
            accountWithdraw = 0.00;
            std::cout << "Invalid entry!" << std::endl;
            Withdrawl();
        }
}

void Deposit() {
    std::cout << "Your balance is " << accountBalance << std::endl << "How much would you like to deposit?" << std::endl;
    std::cin >> accountDeposit;
    std::cout << "Are you sure you want to deposit $" << accountDeposit << " ?" << std::endl;
    std::cout << "Press y for yes or n for no" << std::endl;
    std::cin >> confirm;

    if(confirm == y) {
        std::cout << "$ " << accountDeposit << " has been deposited to your account." << std::endl;
        accountBalance = accountDeposit + accountBalance;
        accountDeposit = 0.00;
        std::cout << "You account balance is now $" << accountBalance << std::endl;
        BackToTransactionChoice2:
        std::cout << "Would you like to make another transaction?" << std::endl;
        std::cin >> anotherTransaction;

        if(anotherTransaction == y) {
            void Menu();
        } else if(anotherTransaction == n) {
            main();
        } else {
            std::cout << "Invalid entry!" << std::endl;
            Deposit();
        }
    } else if(confirm == n) {
        accountDeposit = 0.00;
        std::cout << "Transaction cancelled. Redirecting you in 3 seconds..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(3));
        void Menu();
    } else {
        accountDeposit = 0.00;
        std::cout << "Invalid entry!" << std::endl;
        Deposit();
    }
}

void ViewBalance() {
    std::cout << "Your account balance is $" << accountBalance << std::endl;
    std::cout << "Would you like to make another transaction?" << std::endl;
    std::cin >> anotherTransaction;

    if(anotherTransaction == y) {
        void Menu();
    } else if(anotherTransaction == n) {
        main();
    } {
        std::cout << "Invalid entry!" << std::endl;
        ViewBalance();
    }
}

    void Menu() {
    std::cout << "Press 1 to make a withdrawl, press 2 to make a deposit," << std::endl;
    std::cout << "or press 3 to check your account balance. When ready to exit to main menu press 4" << std::endl;

    }

int AccountMenu() {
    std::cout << "Welcome to your Account!" << std::endl;
    void Menu();
    if(ChoiceSelection2 == 1) {
        Withdrawl();
    }
    if(ChoiceSelection2 == 2) {
        Deposit();
    }
    if(ChoiceSelection2 == 3) {
        ViewBalance();
    }
    if(ChoiceSelection2 == 4) {
        main();
    }
    if(ChoiceSelection2 != 1 || 2 || 3 || 4) {
        std::cout << "Invalid entry! Please choose again!" << std::endl;
        Menu();
    }
    return 0;
}





