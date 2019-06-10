#include "../Example.h"

#include <gtest/gtest.h>

bool foo()
{
    return false;
}

int num()
{
    return 14;
}

// MACRO DEMONSTRATIONS
// TEST(ExampleTests, DemonstrateGTestMacros)
// {
//     // Check out https://github.com/google/googletest/blob/master/googletest/docs/primer.md for more info
//     //EXPECT_TRUE(false);
    
//     // const bool result = foo();
//     // // (expected, actual) passes if actual matches expected
//     // EXPECT_EQ(true, result) << "foo has failed the expected bool test"; 
//     // EXPECT_EQ(15, num()) << "num = " << num() << std::endl;

//     //for (int i = 0; i < 5; i++)
//     //    EXPECT_EQ(true, result) << "i= " << i; // can test if something fails in a loop

//     //ASSERT_TRUE(false); // if we don't pass this line, don't continue
// }

// fixture
struct ExampleTests
: public ::testing::Test
{
    int* x; // bad practice but just for demonstration

    int GetX() { return *x; } // convenience func, remove all x's in bottom funcs

    virtual void SetUp() override
    {
        std::cout << "SETTING UP!\n";
        x = new int(42);
    }

    virtual void TearDown() override
    {
        std::cerr << "TEARING DOWN!\n";
        delete x;
    }
};

TEST_F(ExampleTests, MAC)
{
    //int x = 42;
    int y = 16;
    int sum = 100;
    int oldSUm = sum;
    int expectedNewSum = sum + GetX() * y;
    EXPECT_EQ(
        expectedNewSum,
        MAC(GetX(), y, sum)
    );
    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}

// outside of fixture
// ExampleTests.exe --gtest_filter=ExampleTests2* will only run second test case
// --gtest_filter=*MAC would only run first one or *Square for second
TEST(ExampleTests2, Square)
{
    int x = 5;
    int expectedSquare = x * x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}