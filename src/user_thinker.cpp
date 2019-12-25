#include "user_thinker.h"
#include "utils.h"
#include <iostream>

void UserThinker::reset()
{
    std::cout << "Starting new game!" << std::endl;
}

Response UserThinker::getResponse(int guess)
{
    Response response;
    std::cout << "Opponent guesses " << guess << "." << std::endl;
    int cnt = 0;
    do
    {
        std::cout << "What is your response (bulls cows)? ";
        std::cin >> response.bulls >> response.cows;
    }
    while (!isResponseValid(response) && cnt++ < 5);
    return response;
}
