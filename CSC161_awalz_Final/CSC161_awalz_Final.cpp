// CSC161_awalz_Final.cpp 
// Author: Austin Walz
// Date: 4/22/22
// Description: Final Project of CSC161. It will be a version of BlackJack
//

#include <iostream>
#include <string>
#include <unordered_set>

#include"CardPack.h"

using namespace std;
void Menu();
void Play();
void Rules();
void GenerateCard(BaseCard& hand, unordered_set<int>& set);
void HousePlay(BaseCard& houseHand, BaseCard& playerHand, unordered_set<int>& set, int bet);
void DisplayBoard(BaseCard houseHand, BaseCard playerHand);

bool Playing = false;

int money = 10'000;


int main()
{
    Playing = true;
    while (Playing) Menu();
}

void Menu() {
    srand(time(NULL));
    string input;

    system("CLS");

    cout << "Welcome to BlackJack!\n" <<
        "\n\n" <<
        "Please Select an Option: \n" <<
        "1. Play\n" <<
        "2. Rules\n" <<
        "3. Quit\n\n";

    //Input and makes all characters lowercase
    while (money > 0) {
        getline(cin, input);
        for (int i = 0; i < input.length(); i++) {
            input[i] = tolower(input[i]);
        }

        //Brings User to correct area they picked
        if (input == "1" || input == "play") {
            Play();
            break;
        }
        if (input == "2" || input == "rules") {
            Rules();
            break;
        }
        if (input == "3" || input == "quit") {
            cout << "\nEnding Program\n";
            Playing = false;
            break;
        }
        else {
            cout << "Invalid Response choose 1, 2, or 3: ";
        }
    }

    if (money == 0) {
        Playing = false;
        system("CLS");
        cout << "You have no more money to gamble. Get Lost.\n";
    }


}

void Play() {
    system("CLS");

    unordered_set<int> set;
    string choice;

    bool HouseTurn = false;

    int turn = 1, bet;

    BaseCard HouseHand;
    HouseHand.setHouse(true);

    BaseCard PlayerHand;

    //Asks for Player's Bet
    cout << "Enter bet Amount 1-" << money << ": ";
    cin >> bet;
    while (bet < 1 || bet > money) {

        //Clears console if someone inputs a char into int input
        if (cin.fail()) {
            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
        }

        cout << "Invalid Must be Between 1-" << money <<endl;
        cin >> bet;
    }
    cin.get();

    //Sets inital cards
    for (int i = 0; i < 2; i++) {
        //Gets a random number and makes sure it's not already in set (In play in the game)
        GenerateCard(PlayerHand,set);
        GenerateCard(HouseHand,set);

    }

    //Allows Player to do actions until bust or stand
    while (!HouseTurn && PlayerHand.getValue() <= 21) {
        
        //Users Input
        while (PlayerHand.getValue() <= 21) {
            DisplayBoard(HouseHand, PlayerHand);
            
            //Displays possible options
            if (turn == 1 && bet <= money / 2)
                cout << "\n1. Hit, 2. Stand, 3. Double Down";
            else
                cout << "\n1. Hit, 2. Stand";
            cout << endl;

            //Converts input to lower case
            getline(cin, choice);
            for (int i = 0; i < choice.length(); i++) {
                choice[i] = tolower(choice[i]);
            }

            //Does Correct Action
            if (choice == "1" || choice == "hit") {
                GenerateCard(PlayerHand, set);
                turn++;
            }
            if (choice == "2" || choice == "stand") {
                HouseTurn = true;
                break;
            }
            if (choice == "3" || choice == "double down" || choice == "dd" || choice == "double" && turn == 1 && bet <= money / 2) {
                turn++;
                bet = 2 * bet;
                GenerateCard(PlayerHand, set);
            }

        }

    }

   
    //Player Bust
    if (PlayerHand.getValue() > 21) {
        DisplayBoard(HouseHand, PlayerHand);
        cout << "\nLose Due to a Bust with a value of " << PlayerHand.getValue() << "\n";
        money -= bet;
    
    }
    else
        HousePlay(HouseHand, PlayerHand, set, bet);

    system("pause");
}

void Rules() {
    system("CLS");
    cout << "Rules of Black Jack: \n\n\n\n" <<

        "Overview of BlackJack: \n" <<
        "-----------------------\n\n" <<
        "Goal of BlackJack is to get to a hand at a value higher than the House/Dealer (House will be being used) but not above 21.\n\n\n" <<

        "Player Interactions: \n" <<
        "-----------------------\n\n" <<
        "Hand: Current cards\n" <<
        "Hit: Recieve a card\n" <<
        "Stand: No longer recieve cards and goes to House's turn" <<
        "Bet: Place an amount of money to gamble for a chance to double it or lose it all\n" <<
        "Double Down: Only available as a first action. Doubles the current bet if possible\n" <<
        "\n\n\n" <<

        "Outcomes: \n" <<
        "-----------------------\n\n" <<
        "Losing:\n" <<
        "\t-Busting: When the hand goes over 21\n" <<
        "\t-Losing to House: When the House has a higher card value\n\n" <<
        "Tie\n" <<
        "\t-Push: When House has Same value as hand\n\n" <<
        "Winning:\n" <<
        "\t-House Busts: When the Hosue busts\n" <<
        "\t-Card Value 21: When Hand's value is at 21\n" <<
        "\t-Higher Value than House: When Hand is higher than House at end of game\n\n\n" <<

        "The House:\n" <<
        "-----------------------\n\n" <<
        "The House will have one card shown and the other not shown to give an idea of what card value the House has.\n" <<
        "The House will show both cards when it's the House's turn\n" <<
        "If House's value is below 17 it will keep hitting until ir reaches above 17 or busts\n" <<
        "If cards are shown to be at 17 the House will stand\n\n\n" <<

        "Cards:\n" <<
        "-----------------------\n\n" <<
        "Each card has a value\n" <<
        "Cards with a number on them have that number as it's value\n" <<
        "If a card has J, Q, or K, the value is 10\n" <<
        "If a card has an A, the value is 11 or 1. Meaning it's 11 unless total card value goes over 21 then it becomes 1\n\n\n";
    

    system("pause");
    Menu();
}


//Gives the Hand Holder an extra card
void GenerateCard(BaseCard& hand, unordered_set<int>& set){
    int cardNum = rand() % 52 + 1;
    while (set.count(cardNum)) cardNum = rand() % 52 + 1;
    set.insert(cardNum);

    //Determines which suit the card will be in
    //Spades
    if (cardNum <= 13) {
        SpadeCard card(cardNum);
        if (hand.getHouse() && hand.getSize() == 0) card.setFlip(true);
        hand += card;
    }

    //Diamonds
    else if (cardNum > 13 && cardNum <= 26)
    {
        DiamondCard card(cardNum);
        if (hand.getHouse() && hand.getSize() == 0) card.setFlip(true);
        hand += card;
    }

    //Clubs
    else if (cardNum > 26 && cardNum <= 39)
    {
        ClubCard card(cardNum);
        if (hand.getHouse() && hand.getSize() == 0) card.setFlip(true);
        hand += card;
    }

    //Hearts
    else {
        HeartCard card(cardNum);
        if (hand.getHouse() && hand.getSize() == 0) card.setFlip(true);
        hand += card;
    }


    //Will Drop Ace's Value to 1 if can & needed to stay below 21
    if (hand.hasAce());

}


//House Plays to get to 17 or Busts then compares House to Player
void HousePlay(BaseCard& houseHand, BaseCard& playerHand, unordered_set<int>& set, int bet) {
    houseHand.unFlip();
    DisplayBoard(houseHand, playerHand);

    //House Keeps Hitting util at or Above 17
    while (houseHand.getValue() < 17) {
        GenerateCard(houseHand, set);
        DisplayBoard(houseHand, playerHand);
        system("pause");
        cout << endl;
    }
    if (houseHand.getValue() == 21) {

        //House won by Black Jack (Lose)
        if (playerHand.getValue() < 21) {
            cout << "House BlackJack, Lost with " << playerHand.getValue() << endl;
            money -= bet;
        }

        //Both Player and House had BlackJack (Tie)
        if (playerHand == 21)cout << "Its a Push!\n";
    }
    //House Busts (Win)
    else if (houseHand.getValue() > 21) {
        cout << "House Bust with " << houseHand.getValue() << endl;
        money += bet;
    }

    //House had Higher Value than Player (Lose)
    else if (houseHand.getValue() > playerHand.getValue()) {
        cout << "House Wins with: " << houseHand.getValue() << " Versus: " << playerHand.getValue() << endl;
        money -= bet;
    }

    //House and Player Push (Tie)
    else if (houseHand == playerHand) cout << "It's a Push!\n";

    //Player had Higher than House (Win)
    else {
        cout << "House lost with " << houseHand.getValue() << " Versus: " << playerHand.getValue() << endl;
        money += bet;
    }



}

//Allows mroe friendly UI
void DisplayBoard(BaseCard houseHand, BaseCard playerHand) {
    system("CLS");

    cout << "House's Hand:\n" <<
        houseHand;

    cout << "\n\nPlayer's Hand:\n" <<
        playerHand << endl;

}