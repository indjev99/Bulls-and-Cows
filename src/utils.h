#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include "response.h"
#include <vector>

bool isNumberValid(int number);
int numberToIndex(int number);

bool isResponseValid(Response response);
bool isResponseFinal(Response response);
Response findResponse(int number, int guess);

std::vector<int> findDigits(int number);
int findNumber(const std::vector<int>& digits);

extern std::vector<int> validNumbers;
extern std::vector<Response> validResponses;
extern std::vector<int> validDigits;
extern std::vector<int> validPos;

int responseToIndex(Response response);

int randomNumber();
void initRandomizer();

void setParams(int numDigits);

#endif // UTIL_H_INCLUDED
