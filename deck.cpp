//
// Created by Amrith Lotlikar on 11/8/2018.
//

#include "deck.h"
#include "card.h"
#include <cstdlib>
#include <ctime>

Deck::Deck() {
    int card_pointer = 0;
    for(int i = 1; i < 14; i++){
        Card::Suit suit;
        suit = Card::diamonds;
        Card card1(i, suit);
        myCards[card_pointer] = card1;
        card_pointer++;
        suit = Card::hearts;
        Card card2(i, suit);
        myCards[card_pointer] = card2;
        card_pointer++;
        suit = Card::spades;
        Card card3(i, suit);
        myCards[card_pointer] = card3;
        card_pointer++;
        suit = Card::clubs;
        Card card4(i, suit);
        myCards[card_pointer] = card4;
        card_pointer++;
    }
    myIndex = 0;
}

void Deck::shuffle() {
    unsigned int the_time =  (unsigned)time(0);
    srand(the_time);
    for(int i = 0; i < SIZE * 15; i++){
        int card_one = rand()%SIZE;
        int card_two = rand()%SIZE;
        Card holder = myCards[card_one];
        myCards[card_one] = myCards[card_two];
        myCards[card_two] = holder;
    }
}

Card Deck::dealCard() {
    if(myIndex == SIZE){
        Card card;
        return card;
    }
    myIndex++;
    return myCards[myIndex - 1];
}

int Deck::size() const {
    return SIZE - myIndex;
}