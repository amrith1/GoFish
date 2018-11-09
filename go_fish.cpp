//
// Created by Amrith Lotlikar on 11/9/2018.
//
#include "player.h"
#include "deck.h"
#include "card.h"
#include <iostream>
#include <fstream>
using namespace std;

void turn(Player &p1, Player &p2, Deck &deck, ofstream &log){
    bool p1_done = false;
    while(!p1_done){
        if(p1.getHandSize() > 0){
            Card bait = p1.chooseCardFromHand();
            log << p1.getName() << " asks - Do you have a " << bait.rankString(bait.getRank()) << "?\n";
            if(p2.rankInHand(bait)){
                log << p2.getName() << " says - Yes, I have a " << bait.rankString(bait.getRank()) << ".\n";
                log << p1.getName() << " books the " << bait.rankString(bait.getRank()) << "." << endl << endl;
                Card pair = p2.getCardOfRank(bait);
                p1.addCard(pair);
                p1.bookCards(bait, pair);
            }
            else{
                log << p2.getName() << " says - Go Fish.\n";
                if(deck.size() > 0){
                    Card drawn = deck.dealCard();
                    log << p1.getName() << " draws " << drawn.toString() << "." <<endl;
                    if(p1.rankInHand(drawn)){
                        Card pair = p1.getCardOfRank(drawn);
                        p1.addCard(pair);
                        p1.addCard(drawn);
                        p1.bookCards(drawn, pair);
                        log << p1.getName() << " books the " << pair.rankString(pair.getRank())<< ".\n";
                    }
                    else{
                        p1.addCard(drawn);
                    }
                    log << endl;

                }
                else{
                    log << p1.getName() << " can't draw because the deck is empty.\n\n";
                }
                p1_done = true;
            }
        }
        else{
            if(deck.size() > 0){
                Card drawn = deck.dealCard();
                p1.addCard(drawn);
                log << p1.getName() << " has no cards so he draws " << drawn.toString() << "." <<endl << endl;
                p1_done = true;
            }
            else{
                log << p1.getName()<< " has no cards and the deck is empty." << endl << endl;
                p1_done = true;
            }

        }
    }
}


int main(){
    ofstream log;
    log.open("gofish_results.txt");
    log<< "Game has begun. Cards are dealt.\n";

    Player p1("Player 1");
    Player p2("Player 2");
    Deck deck;
    deck.shuffle();
    for(int i = 0; i < 7; i++){
        p1.addCard(deck.dealCard());
        p2.addCard(deck.dealCard());
    }
    p1.initBooks();
    p2.initBooks();
    log<<p1.getName()<<" starts with hand: "<< p1.showHand()<< " and books " << p1.showBooks() << endl;
    log<<p2.getName()<<" starts with hand: "<< p2.showHand()<< " and books " << p2.showBooks() << endl<<endl;

    bool terminate = (p1.getHandSize() == 0) && (p2.getHandSize() == 0) && (deck.size() == 0);
    while(!terminate){
        turn(p1, p2, deck, log);
        turn(p2, p1, deck, log);
        log<<p1.getName()<<" has hand: "<< p1.showHand()<< ".\n";
        log<<p2.getName()<<" has hand: "<< p2.showHand()<< "." << endl<<endl;
        terminate = (p1.getHandSize() == 0) && (p2.getHandSize() == 0) && (deck.size() == 0);
    }

    log << p1.getName() << " has books " << p1.showBooks() << ".\n";
    log << p2.getName() << " has books " << p2.showBooks() << ".\n\n";

    if(p1.getBookSize() == p2.getBookSize()){
        log << "The game is a tie!\n";
    }
    else if(p1.getBookSize() > p2.getBookSize()){
        log << p1.getName() << " wins!\n";
    }
    else{
        log << p2.getName() << " wins!\n";
    }

    log.close();
    return 0;
}


