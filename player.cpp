//
// Created by Amrith Lotlikar on 11/8/2018.
//

#include "player.h"
#include <ctime>
#include <cstdlib>

Player::Player() {
    myName = "";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    int card_one = -1;
    int card_two = -1;
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c1){
            card_one = i;
            break;
        }
    }
    for(int j = 0; j < myHand.size(); j++){
        if(myHand[j] == c2){
            card_two = j;
            break;
        }
    }
    if(card_one > -1 && card_two > -1){
        if(card_two < card_one){
            myHand.erase(myHand.begin() + card_one);
            myHand.erase(myHand.begin() + card_two);
        }
        else{
            myHand.erase(myHand.begin() + card_two);
            myHand.erase(myHand.begin() + card_one);
        }
        myBook.push_back(c1);
        myBook.push_back(c2);
    }
}

bool Player::cardInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    int position = -1;
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c){
            position = i;
            break;
        }
    }
    if(position > -1){
        Card c = myHand[position];
        myHand.erase(myHand.begin() + position);
        return c;
    }
    return Card();
}

string Player::showHand() const {
    string hand = "";
    for(int i = 0; i < myHand.size(); i++){
        if(i == 0){
            hand += myHand[i].toString();
        }
        else{
            hand += ", ";
            hand += myHand[i].toString();
        }
    }
    return hand;
}

string Player::showBooks() const {
    string books = "";
    for(int i = 0; i < myBook.size(); i++){
        if(i == 0){
            books += myBook[i].toString();
        }
        else{
            books += ", ";
            books += myBook[i].toString();
        }
    }
    return books;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

bool Player::rankInHand(Card c) const {
    int rank = c.getRank();
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == rank){
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    if(myHand.size() == 0) return Card();
    unsigned int the_time =  (unsigned)time(0);
    srand(the_time);
    return myHand[rand()%myHand.size()];
}

void Player::initBooks() {
    for(int i = 0; i < myHand.size() - 1; i++){
        int rank = myHand[i].getRank();
        for(int j = i + 1; j < myHand.size(); j++){
            if(rank == myHand[j].getRank()){
                Card c1 = myHand[i];
                Card c2 = myHand[j];
                myHand.erase(myHand.begin() + j);
                myHand.erase(myHand.begin() + i);
                myBook.push_back(c1);
                myBook.push_back(c2);
                i--;
                break;
            }
        }
    }
}

Card Player::getCardOfRank(Card c) {
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()){
            Card desired = myHand[i];
            myHand.erase(myHand.begin() + i);
            return desired;
        }
    }
    return Card();
}



