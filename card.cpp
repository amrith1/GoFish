//
// Created by Amrith Lotlikar on 11/8/2018.
//

#include "card.h"

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {
    if(s == spades){
        return "s";
    }
    if(s==hearts){
        return "h";
    }
    if(s == clubs){
        return "c";
    }
    else return "d";
}

string Card::rankString(int r) const {
    switch(r){
        case 1: return "A";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "10";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return "A";
    }
}

bool Card::sameSuitAs(const Card &c) const{
    return suitString(mySuit) == suitString(c.mySuit);
}

bool Card::operator==(const Card &rhs) const {
    return(sameSuitAs(rhs) && (getRank() == rhs.getRank()));
}

bool Card::operator!=(const Card &rhs) const {
    return !(*this == rhs);
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}