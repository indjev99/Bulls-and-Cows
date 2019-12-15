#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include "response.h"

bool isNumberValid(int number);
bool isResponseValid(const Response& response);
bool isResponseFinal(const Response& response);
Response findResponse(int number, int guess);

#endif // UTIL_H_INCLUDED
