#include <Game.h>
#include <fstream>
#include "gtest/gtest.h"

basic_string<char> runGame(unsigned int seed, Game aGame) {
    srand(seed);
    bool notAWinner;

    testing::internal::CaptureStdout();
    do {
        aGame.roll(rand() % 5 + 1);

        if (rand() % 9 == 7) {
            notAWinner = aGame.wrongAnswer();
        } else {
            notAWinner = aGame.wasCorrectlyAnswered();
        }
    } while (notAWinner);
    return testing::internal::GetCapturedStdout();
}

TEST(players_3, seed_0) {
    Game aGame;
    int seed = 0;
    const char *playerName = "Chet";
    const char *playerName1 = "Pat";
    const char *playerName2 = "Sue";
    aGame.add(playerName);
    aGame.add(playerName1);
    aGame.add(playerName2);

    string actual = runGame(seed, aGame);
    string expected = "Chet is the current player\nThey have rolled a 4\nChet's new location is 4\nThe category is Pop\nPop Question 0\nQuestion was incorrectly answered\nChet was sent to the penalty box\nPat is the current player\nThey have rolled a 3\nPat's new location is 3\nThe category is Rock\nRock Question 0\nQuestion was incorrectly answered\nPat was sent to the penalty box\nSue is the current player\nThey have rolled a 4\nSue's new location is 4\nThe category is Pop\nPop Question 1\nQuestion was incorrectly answered\nSue was sent to the penalty box\nChet is the current player\nThey have rolled a 2\nChet is not getting out of the penalty box\nPat is the current player\nThey have rolled a 5\nPat is getting out of the penalty box\nPat's new location is 8\nThe category is Pop\nPop Question 2\nAnswer was correct!!!!\nPat now has 1 Gold Coins.\nSue is the current player\nThey have rolled a 3\nSue is getting out of the penalty box\nSue's new location is 7\nThe category is Rock\nRock Question 1\nAnswer was correct!!!!\nSue now has 1 Gold Coins.\nChet is the current player\nThey have rolled a 1\nChet is getting out of the penalty box\nChet's new location is 5\nThe category is Science\nScience Question 0\nQuestion was incorrectly answered\nChet was sent to the penalty box\nPat is the current player\nThey have rolled a 4\nPat is not getting out of the penalty box\nSue is the current player\nThey have rolled a 1\nSue is getting out of the penalty box\nSue's new location is 8\nThe category is Pop\nPop Question 3\nAnswer was correct!!!!\nSue now has 2 Gold Coins.\nChet is the current player\nThey have rolled a 3\nChet is getting out of the penalty box\nChet's new location is 8\nThe category is Pop\nPop Question 4\nAnswer was correct!!!!\nChet now has 1 Gold Coins.\nPat is the current player\nThey have rolled a 2\nPat is not getting out of the penalty box\nSue is the current player\nThey have rolled a 3\nSue is getting out of the penalty box\nSue's new location is 11\nThe category is Rock\nRock Question 2\nAnswer was correct!!!!\nSue now has 3 Gold Coins.\nChet is the current player\nThey have rolled a 3\nChet is getting out of the penalty box\nChet's new location is 11\nThe category is Rock\nRock Question 3\nAnswer was correct!!!!\nChet now has 2 Gold Coins.\nPat is the current player\nThey have rolled a 3\nPat is getting out of the penalty box\nPat's new location is 11\nThe category is Rock\nRock Question 4\nAnswer was correct!!!!\nPat now has 2 Gold Coins.\nSue is the current player\nThey have rolled a 3\nSue is getting out of the penalty box\nSue's new location is 2\nThe category is Sports\nSports Question 0\nAnswer was correct!!!!\nSue now has 4 Gold Coins.\nChet is the current player\nThey have rolled a 5\nChet is getting out of the penalty box\nChet's new location is 4\nThe category is Pop\nPop Question 5\nAnswer was correct!!!!\nChet now has 3 Gold Coins.\nPat is the current player\nThey have rolled a 3\nPat is getting out of the penalty box\nPat's new location is 2\nThe category is Sports\nSports Question 1\nAnswer was correct!!!!\nPat now has 3 Gold Coins.\nSue is the current player\nThey have rolled a 5\nSue is getting out of the penalty box\nSue's new location is 7\nThe category is Rock\nRock Question 5\nAnswer was correct!!!!\nSue now has 5 Gold Coins.\nChet is the current player\nThey have rolled a 4\nChet is not getting out of the penalty box\nQuestion was incorrectly answered\nChet was sent to the penalty box\nPat is the current player\nThey have rolled a 2\nPat is not getting out of the penalty box\nQuestion was incorrectly answered\nPat was sent to the penalty box\nSue is the current player\nThey have rolled a 5\nSue is getting out of the penalty box\nSue's new location is 0\nThe category is Pop\nPop Question 6\nAnswer was correct!!!!\nSue now has 6 Gold Coins.\n";

    ASSERT_TRUE(actual == expected);
    // with CLION the string difference display takes a lot of time, so it's better to comment this line
    ASSERT_EQ(actual, expected);
}

TEST(players_5, seed_55) {
    Game aGame;
    int seed = 55;
    const char *playerName = "Chet";
    const char *playerName1 = "Pat";
    const char *playerName2 = "Sue";
    const char *playerName3 = "Bob";
    const char *playerName4 = "Mike";
    aGame.add(playerName);
    aGame.add(playerName1);
    aGame.add(playerName2);
    aGame.add(playerName3);
    aGame.add(playerName4);

    string actual = runGame(seed, aGame);
    string expected = "Chet is the current player\nThey have rolled a 4\nChet's new location is 4\nThe category is Pop\nPop Question 0\nAnswer was corrent!!!!\nChet now has 1 Gold Coins.\nPat is the current player\nThey have rolled a 1\nPat's new location is 1\nThe category is Science\nScience Question 0\nAnswer was corrent!!!!\nPat now has 1 Gold Coins.\nSue is the current player\nThey have rolled a 3\nSue's new location is 3\nThe category is Rock\nRock Question 0\nAnswer was corrent!!!!\nSue now has 1 Gold Coins.\nBob is the current player\nThey have rolled a 1\nBob's new location is 1\nThe category is Science\nScience Question 1\nAnswer was corrent!!!!\nBob now has 1 Gold Coins.\nMike is the current player\nThey have rolled a 4\nMike's new location is 4\nThe category is Pop\nPop Question 1\nAnswer was corrent!!!!\nMike now has 1 Gold Coins.\nChet is the current player\nThey have rolled a 5\nChet's new location is 9\nThe category is Science\nScience Question 2\nAnswer was corrent!!!!\nChet now has 2 Gold Coins.\nPat is the current player\nThey have rolled a 5\nPat's new location is 6\nThe category is Sports\nSports Question 0\nAnswer was corrent!!!!\nPat now has 2 Gold Coins.\nSue is the current player\nThey have rolled a 5\nSue's new location is 8\nThe category is Pop\nPop Question 2\nAnswer was corrent!!!!\nSue now has 2 Gold Coins.\nBob is the current player\nThey have rolled a 3\nBob's new location is 4\nThe category is Pop\nPop Question 3\nQuestion was incorrectly answered\nBob was sent to the penalty box\nMike is the current player\nThey have rolled a 3\nMike's new location is 7\nThe category is Rock\nRock Question 1\nAnswer was corrent!!!!\nMike now has 2 Gold Coins.\nChet is the current player\nThey have rolled a 4\nChet's new location is 1\nThe category is Science\nScience Question 3\nAnswer was corrent!!!!\nChet now has 3 Gold Coins.\nPat is the current player\nThey have rolled a 4\nPat's new location is 10\nThe category is Sports\nSports Question 1\nAnswer was corrent!!!!\nPat now has 3 Gold Coins.\nSue is the current player\nThey have rolled a 5\nSue's new location is 1\nThe category is Science\nScience Question 4\nQuestion was incorrectly answered\nSue was sent to the penalty box\nBob is the current player\nThey have rolled a 5\nBob is getting out of the penalty box\nBob's new location is 9\nThe category is Science\nScience Question 5\nAnswer was correct!!!!\nBob now has 2 Gold Coins.\nMike is the current player\nThey have rolled a 5\nMike's new location is 0\nThe category is Pop\nPop Question 4\nAnswer was corrent!!!!\nMike now has 3 Gold Coins.\nChet is the current player\nThey have rolled a 2\nChet's new location is 3\nThe category is Rock\nRock Question 2\nAnswer was corrent!!!!\nChet now has 4 Gold Coins.\nPat is the current player\nThey have rolled a 3\nPat's new location is 1\nThe category is Science\nScience Question 6\nAnswer was corrent!!!!\nPat now has 4 Gold Coins.\nSue is the current player\nThey have rolled a 2\nSue is not getting out of the penalty box\nBob is the current player\nThey have rolled a 4\nBob is not getting out of the penalty box\nMike is the current player\nThey have rolled a 3\nMike's new location is 3\nThe category is Rock\nRock Question 3\nAnswer was corrent!!!!\nMike now has 4 Gold Coins.\nChet is the current player\nThey have rolled a 2\nChet's new location is 5\nThe category is Science\nScience Question 7\nAnswer was corrent!!!!\nChet now has 5 Gold Coins.\nPat is the current player\nThey have rolled a 1\nPat's new location is 2\nThe category is Sports\nSports Question 2\nAnswer was corrent!!!!\nPat now has 5 Gold Coins.\nSue is the current player\nThey have rolled a 3\nSue is getting out of the penalty box\nSue's new location is 4\nThe category is Pop\nPop Question 5\nAnswer was correct!!!!\nSue now has 3 Gold Coins.\nBob is the current player\nThey have rolled a 2\nBob is not getting out of the penalty box\nQuestion was incorrectly answered\nBob was sent to the penalty box\nMike is the current player\nThey have rolled a 1\nMike's new location is 4\nThe category is Pop\nPop Question 6\nAnswer was corrent!!!!\nMike now has 5 Gold Coins.\nChet is the current player\nThey have rolled a 2\nChet's new location is 7\nThe category is Rock\nRock Question 4\nQuestion was incorrectly answered\nChet was sent to the penalty box\nPat is the current player\nThey have rolled a 3\nPat's new location is 5\nThe category is Science\nScience Question 8\nAnswer was corrent!!!!\nPat now has 6 Gold Coins.\n";

    ASSERT_TRUE(actual == expected);
    // with CLION the string difference display takes a lot of time, so it's better to comment this line
    ASSERT_EQ(actual, expected);
}
