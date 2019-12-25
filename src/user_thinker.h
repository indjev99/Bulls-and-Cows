#ifndef USER_THINKER_H_INCLUDED
#define USER_THINKER_H_INCLUDED

#include "thinker.h"

struct UserThinker final : Thinker
{
    void reset();
    Response getResponse(int guess);
};

#endif // USER_THINKER_H_INCLUDED
