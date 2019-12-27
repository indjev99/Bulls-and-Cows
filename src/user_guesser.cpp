#include "user_guesser.h"
#include "utils.h"
#include <iostream>

void UserGuesser::reset()
{
    std::cout << "Starting new game!" << std::endl;
}

int UserGuesser::makeGuess(int guess, Response response)
{
    if (isNumberValid(guess))
    {
        std::cout << "Opponent answers: " << response.bulls << " bulls and " << response.cows << " cows." << std::endl;
    }
    if (isResponseFinal(response))
    {
        std::cout << "Congrats!" << std::endl;
    }
    else
    {
        int cnt = 0;
        do
        {
            std::cout << "What is your guess? ";
            std::cin >> guess;
        }
        while (!isNumberValid(guess) && ++cnt < 5);
    }
    return guess;
}
