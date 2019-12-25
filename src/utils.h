#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include "response.h"
#include <vector>

bool isNumberValid(int number);
extern const std::vector<int> validNumbers;
int numberToIndex(int number, const Response& response);

bool isResponseValid(const Response& response);
extern const std::vector<Response> validResponses;
int responseToIndex(const Response& response);
bool isResponseFinal(const Response& response);
Response findResponse(int number, int guess);

int randomNumber();
int randomNumber(const std::vector<int>& validNumbers);
void initRandomizer();

#endif // UTIL_H_INCLUDED
