#include "object.h"
#include "lispString.h"
#include "number.h"
#include "symbolsList.h"
#include "nil.h"
#include "doublet.h"
#include "lispFunctions.h"
#include "read.h"
#include "exceptions.h"

#include <string.h>
#include <gtest/gtest.h>


TEST(lispFunctions, length) {
    Doublet doubletLength0(new Nil, new Nil);
    Doublet doubletLength1(new Number(5), new Nil);

    EXPECT_EQ(length(doubletLength0), 0);
    EXPECT_EQ(length(doubletLength1), 1);
}

TEST(readClass, getWord) {
    std::string word1 = Read::getWord("abc");
    std::string word2 = Read::getWord("abc def");
    std::string word3 = Read::getWord("abc(");
    std::string word4 = Read::getWord("abc)");
    std::string word5 = Read::getWord("");

    EXPECT_EQ(word1, "abc");
    EXPECT_EQ(word2, "abc");
    EXPECT_EQ(word3, "abc");
    EXPECT_EQ(word4, "abc");
    EXPECT_EQ(word5, "");
}

TEST(readClass, isNumber) {
    EXPECT_EQ(Read::isNumber("645"), true);
    EXPECT_EQ(Read::isNumber("abc"), false);
    EXPECT_EQ(Read::isNumber("1abc2"), false);
}

TEST(readClass, isString) {
    EXPECT_EQ(Read::isString("\"645\""), true);
    EXPECT_EQ(Read::isString("abc"), false);
}

TEST(readClass, read) {
    std::string input = "(abc def";
    std::stringstream stream(input);
    Read * toRead = new Read(stream);

    ASSERT_THROW(toRead->read(), UnterminatedList);

    std::string input2 = ")abc def";
    std::stringstream stream2(input2);
    Read * toRead2 = new Read(stream2);

    ASSERT_THROW(toRead2->read(), TooManyParents);

    std::string input3 = "(abc)) def";
    std::stringstream stream3(input3);
    Read * toRead3 = new Read(stream3);

    ASSERT_THROW(toRead3->read(), TooManyParents);

    std::string input4 = "abc) def";
    std::stringstream stream4(input4);
    Read * toRead4 = new Read(stream4);

    ASSERT_THROW(toRead4->read(), TooManyParents);




    std::string input5 = "(abc def)";
    std::stringstream stream5(input5);
     Read * toRead5 = new Read(stream5);

    ASSERT_THROW(toRead5->read(), UnterminatedCons);
}

