#include "object.h"
#include "lispString.h"
#include "number.h"
#include "symbolsList.h"
#include "nil.h"
#include "doublet.h"
#include "lispFunctions.h"

#include <string.h>
#include <gtest/gtest.h>


TEST(lispFunctions, length) {
    Doublet doubletLength0(new Nil, new Nil);
    Doublet doubletLength1(new Number(5), new Nil);


    EXPECT_EQ(length(doubletLength0), 0);
    EXPECT_EQ(length(doubletLength1), 1);
}
