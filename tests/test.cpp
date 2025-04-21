#include <gtest.h>
#include "TString.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"

TEST(TStringTest, DefaultConstructor)
{
    TString s;
    EXPECT_STREQ(s.GetStr(), "");
    EXPECT_EQ(s.GetLen(), 0);
}

TEST(TStringTest, ConstructorFromConstChar)
{
    TString s("abc");
    EXPECT_STREQ(s.GetStr(), "abc");
    EXPECT_EQ(s.GetLen(), strlen("abc"));
}

TEST(TStringTest, CopyConstructor)
{
    TString original("abc");
    TString copy(original);
    EXPECT_STREQ(copy.GetStr(), original.GetStr());
    EXPECT_EQ(copy.GetLen(), original.GetLen());
}

TEST(TStringTest, MoveConstructor)
{
    TString original("abc");
    TString moved(std::move(original));
    EXPECT_STREQ(moved.GetStr(), "abc");
    EXPECT_EQ(moved.GetLen(), 4);
}

TEST(TStringTest, SetStrUpdatesContent)
{
    TString s;
    s.SetStr("abcd");
    EXPECT_STREQ(s.GetStr(), "abcd");
    EXPECT_EQ(s.GetLen(), 4);
}

TEST(TStringTest, SetLenUpdatesLength)
{
    TString s("abc");
    s.SetLen(2);
    EXPECT_STREQ(s.GetStr(), "ab");
    EXPECT_EQ(s.GetLen(), 2);
}

TEST(TStringTest, PlusOperatorConcatenation)
{
    TString a("ab");
    TString b("cd");
    TString result = a + b;
    EXPECT_STREQ(result.GetStr(), "abcd");
    EXPECT_EQ(result.GetLen(), 4);
}

TEST(TStringTest, MultiplyOperatorRepeatsString)
{
    TString s("ab");
    TString result = s * 3;
    EXPECT_STREQ(result.GetStr(), "ababab");
    EXPECT_EQ(result.GetLen(), 6);
}

TEST(TStringTest, AssignmentOperatorDeepCopy)
{
    TString original("abc");
    TString copy;
    copy = original;
    original.SetStr("new");
    EXPECT_STREQ(copy.GetStr(), "abc");
}

TEST(TStringTest, IndexOperatorAccess)
{
    TString s("abc");
    EXPECT_EQ(s[0], 't');
    s[0] = 'T';
    EXPECT_EQ(s[0], 'T');
}

TEST(TStringTest, OutputOperator)
{
    TString s("abc");
    std::ostringstream os;
    os << s;
    EXPECT_EQ(os.str(), "abc");
}

TEST(TStringTest, InputOperator)
{
    TString s;
    std::istringstream input("abc");
    input >> s;
    EXPECT_STREQ(s.GetStr(), "abc");
    EXPECT_EQ(s.GetLen(), 3);
}

#pragma clang diagnostic pop