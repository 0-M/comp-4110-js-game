#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Poker.h"
#include <time.h>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::sort;
using std::cin;


//DeckOfCards function definitions

DeckOfCards::DeckOfCards() //Default initializer that initializes all the cards in the deck
{
    currentCard = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            Card Temp(j,i);
            deck.push_back(Temp);
        }
    }
    for(int i = 0; i < 1000; i++)
    {
        shuffle();
    }
}
void DeckOfCards::shuffle() //shuffle the deck
{
    srand (time(NULL));
    for(int i = 0; i < 52; i++)
    {
        swap(deck[i],deck[rand() % 51]);
    }
}
Card DeckOfCards::dealCard() //Returns the next card object from the deck and removes it from the deck
{
    Card temp = deck.back();
    deck.pop_back();
    //cout << deck.size() << endl;
    return temp;
    //Card temp = deck[currentCard];
    //currentCard = currentCard + 1;
    //return temp;
}
bool DeckOfCards::moreCard() //Returns a value indicating whether there are more Cards to deal
{
    if(deck.size() != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Calculating hand values
void Hand::dealHand(DeckOfCards * arg)
{
    for(int i = 0; i < 5; i++)
    {
        hand.push_back(arg->dealCard());
    }

}

Hand::Hand() //Deal five cards to hand
{
    handValue = 0;
    highCard = -1;
    highCards[0] = -1;
    highCards[1] = -1;
    highCards[2] = -1;
//    Card t1(4,2),t2(4,3),t3(10,1),t4(10,0),t5(2,2);
//    hand.push_back(t2);
//    hand.push_back(t3);
//    hand.push_back(t1);
//    hand.push_back(t5);
//    hand.push_back(t4);
//   for(int i = 0; i < 5; i++)
//   {
//        hand.push_back()
//   }
}
//all of these functions need to set handValue, highest card,proximity and junk cards
void Hand::hasFlush() //check for a flush
{
    suitSort();
    //int towardsFlush[4];
    for(int i = 0; i < 4; i++)
    {
        towardsFlush[i] = 0;
        for(int j = 0; j < 5; j++)
        {
            if(hand[j].getSuit() == i)
            {
                towardsFlush[i] = towardsFlush[i] + 1;
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(towardsFlush[i] == 5)
        {
            handValue = 5;
            highCard = hand[4].getFace();
            break;
        }
    }
}
void Hand::hasStraight() //check for a straight
{
    faceSort();
    towardsStraight[0] = 0;
    towardsStraight[1] = 0;
    for(int i = 0; i < 4; i++)
    {
        if(hand[i].getFace() + 1 == hand[i+1].getFace())
        {
            towardsStraight[1] = i + 1;
        }
        else
        {
            towardsStraight[0] = i + 1;
        }
    }
//    cout << endl;
//    cout << "towardsStraight[0]: " << towardsStraight[0] << endl;
//    cout << "towardsStraight[1]: " << towardsStraight[1] << endl;
    if(towardsStraight[0] == 0 && towardsStraight[1] == 4)
    {
        handValue = hand[4].getFace();
        highCard = hand[4].getFace();
        if(handValue == 5)
        {
            handValue = 8;
        }
        else
        {
            handValue = 4;
        }
    }


}
//void Hand::hasFourOfAKind() // check for four of a kind
//{
//    int rs = 0,ct = 1;
//    for(int i = 0; i < 4; i++)
//    {
//        if(hand[i].getFace() == hand[i+1].getFace())
//        {
//            ct = ct + 1;
//            cout << "..." << ct << endl;
//            if(ct == 4)
//            {
////                 cout << "i:" << i << endl;
////                 cout << "Yay" << endl;
//                handValue = 7;
//                highCard = hand[3].getFace();
//                // cout << "highCard: " << highCard << endl;
//                return;
//            }
//        }
//        else
//        {
//            ct = 0;
//        }
//        if(i == 3 && ct != 4 && rs == 0)
//        {
//            //cout << "blah: " << ct << endl;
//            rs = 1;
//            i = 1;
//            ct = 1;
//        }
//        //cout << "ct: " << ct << endl;
//    }
//}
void Hand::hasFourOfAKind()
{
    int ct = 1;
    for(int i = 0; i < 4; i++)
    {
        if(hand[i].getFace() == hand[i+1].getFace())
        {
            ct = ct + 1;
            if(ct == 4)
            {
                handValue = 7;
                highCard = hand[2].getFace();
                return;
            }
        }
        else
        {
            ct = 1;
        }
    }
}

void Hand::hasThreeOfAKind() //check for three of a kind
{
    int ct = 1;
    for(int i = 0; i < 4; i++)
    {
        if(hand[i].getFace() == hand[i+1].getFace())
        {
            ct = ct + 1;

            if(ct == 3)
            {
                handValue = 3;
                highCards[0] = hand[2].getFace();
                //cout << "here we are: " << hand[3].getFace() << endl;
                // cout << highCard << endl;
            }
        }
        else
        {
            ct = 1;
        }
    }

}

//void Hand::hasTwoPair() //check for two pair
//{
//
//}
void Hand::hasPairs() //check for pairs
{
    int numP = 0;
    //cout << "highCard: " << highCard << endl;

    for(int i = 0; i < 4; i++)
    {
        //cout << "hand[i]: " << hand[i].getFace() << endl;
        if(hand[i].getFace() == hand[i+1].getFace() && highCards[0] != hand[i].getFace())
        {
            numP = numP + 1;
            if(highCards[0] == -1)
            {
                //  cout << "1" << endl;
                highCards[0] = hand[i].getFace();
            }
            else if(highCards[1] == -1)
            {
                //    cout << "2" << endl;
                highCards[1] = hand[i].getFace();
            }
            else
            {
                //     cout << "3" << endl;
                highCards[2] = hand[i].getFace();
            }
        }
    }
    if(numP == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            if(hand[i].getFace() != highCards[0] && hand[i].getFace() != highCards[1])
            {
                //   cout << "test2" << endl;
                highCards[2] = hand[i].getFace();
            }
        }
    }
    if(numP == 1 && handValue == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            if(hand[i].getFace() != highCards[0])
            {
                // cout << "test1" << endl;
                highCards[1] = hand[i].getFace();
            }
        }
    }
//        cout << "numP: " << numP << endl;
//    cout << "high 1:" << highCards[0] << endl;
//    cout << "high 2:" << highCards[1] << endl;
//    cout << "high 3:" << highCards[2] << endl;
    if(handValue == 3 && numP == 1)
    {
        handValue = 6; //Full house
        return;
    }
    if(numP == 2)
    {
        handValue = 2;
        return;
    }
    if(numP == 1)
    {
        handValue = 1;
        return;
    }




}
void Hand::calcHandValue() //calculate the hand value(call all the other functions)
{
    suitSort();
    faceSort();

    hasFlush();
    hasStraight();
    if(handValue != 0)
    {
        //cout << "Hand value: " << handValue << endl;
        return;
    }
    hasFourOfAKind();
    if(handValue != 0)
    {
        // cout << "Hand value1: " << handValue << endl;
        return;
    }
    hasThreeOfAKind();
    hasPairs();
    if(handValue != 0)
    {
        //cout << "Hand value2: " << handValue << endl;
        return;
    }
    for(int i = 0; i < 5; i++)
    {
        if(hand[i].getFace() > highCards[0])
        {
            highCards[0] = hand[i].getFace();
        }
    }
    //cout << "HighCard: " << highCards[0] << endl;

}

bool cmpSuit(Card arg1,Card arg2)
{
    return (arg1.getSuit() < arg2.getSuit());
}

bool cmpFace(Card arg1,Card arg2)
{
    return (arg1.getFace() < arg2.getFace());
}

void Hand::suitSort()
{
    sort(hand.begin(),hand.end(),cmpSuit);
}
void Hand::faceSort()
{
    sort(hand.begin(),hand.end(),cmpFace);
}

void Hand::printHand()
{
    for(unsigned int i = 0; i < hand.size(); i++)
    {
        cout << hand[i].toString() << endl;
    }
}

int Hand::greaterHand(Hand dealer,Hand player) //2 means player wins, 1 means dealer wins
{
    //int toRet = 0;
    if(dealer.handValue > player.handValue)
    {
        // cout << "1" << endl;
        return 1;
    }
    else if(dealer.handValue < player.handValue)
    {
        // cout << "2" << endl;
        return 2;
    }
//    if(dealer.highCards[0] > player.highCards[0])
//    {
//        return 1;
//    }
//    if(dealer.highCards[0] < player.highCards[0])
//    {
//        return 2;
//    }
    else if(dealer.handValue == player.handValue)
    {
        if(dealer.handValue == 0) //both have nothing
        {
            if(dealer.highCards[0] > player.highCards[0])
            {
                cout << "3" << endl;
                return 1;
            }
            else
                cout << "4" << endl;
            return 2;
        }
        if(dealer.handValue == 1) //both have a pair
        {
            if(dealer.highCards[0] > player.highCards[0])
            {
                cout << "5" << endl;
                return 1;
            }
            if(dealer.highCards[0] < player.highCards[0])
            {
                cout << "6" << endl;
                return 2;
            }
            if(dealer.highCards[0] == player.highCards[0])
            {
                if(dealer.highCards[1] > player.highCards[1])
                {
                    cout << "7" << endl;
                    return 1;
                }
                if(dealer.highCards[1] < player.highCards[1])
                {
                    cout << "8" << endl;
                    return 2;
                }
            }
            else
            {
                cout << "9" << endl;
                return 1;
            }
        }
        if(dealer.handValue == 2) //both have two pairs
        {
            if(dealer.highCards[0] > player.highCards[0])
            {
                cout << "10" << endl;
                return 1;
            }
            if(dealer.highCards[0] < player.highCards[0])
            {
                cout << "11" << endl;
                return 2;
            }
            if(dealer.highCards[1] > player.highCards[1])
            {
                cout << "12" << endl;
                return 1;
            }
            if(dealer.highCards[1] < player.highCards[1])
            {
                cout << "13" << endl;
                return 2;
            }
            if(dealer.highCards[2] > player.highCards[2])
            {
                cout << "14" << endl;
                return 1;
            }
            if(dealer.highCards[2] < player.highCards[2])
            {
                cout << "15" << endl;
                return 2;
            }
            else
            {
                cout << "16" << endl;
                return 1;
            }
        }
        if(dealer.handValue == 3)//both have three of a kind
        {
            if(dealer.highCards[0] > player.highCards[0])
            {
                cout << "17" << endl;
                return 1;
            }
            if(dealer.highCards[0] < player.highCards[0])
            {
                cout << "18" << endl;
                return 2;
            }
            if(dealer.highCards[1] > player.highCards[1])
            {
                cout << "19" << endl;
                return 1;
            }
            if(dealer.highCards[1] < player.highCards[1])
            {
                cout << "20" << endl;
                return 2;
            }
            else
            {
                cout << "21" << endl;
                return 1;
            }
        }
        if(dealer.handValue == 4)//both have straight
        {
            if(dealer.highCard > player.highCard)
            {
                cout << "22" << endl;
                return 1;
            }
            if(dealer.highCard < player.highCard)
            {
                cout << "23" << endl;
                return 2;
            }
            else
            {
                cout << "24" << endl;
                return 1;
            }
        }
        if(dealer.handValue == 5) //both have flush
        {
            if(dealer.highCard > player.highCard)
            {
                cout << "25" << endl;
                return 1;
            }
            if(dealer.highCard < player.highCard)
            {
                cout << "26" << endl;
                return 2;
            }
            else
            {
                cout << "27" << endl;
                return 1;
            }
        }
        if(dealer.handValue == 6)//both have a full house
        {
            if(dealer.highCards[0] > player.highCards[0])
            {
                cout << "28" << endl;
                return 1;
            }
            if(dealer.highCards[0] < player.highCards[0])
            {
                cout << "29" << endl;
                return 2;
            }
            if(dealer.highCards[1] > player.highCards[1])
            {
                cout << "30" << endl;
                return 1;
            }
            if(dealer.highCards[1] < player.highCards[1])
            {
                cout << "31" << endl;
                return 2;
            }
            else
            {
                cout << "32" << endl;
                return 1;
            }
        }
        if(dealer.handValue == 7)//both have four of a kind
        {
            if(dealer.highCard > player.highCard)
            {
                cout << "33" << endl;
                return 1;
            }
            if(dealer.highCard < player.highCard)
            {
                cout << "34" << endl;
                return 2;
            }
            else
            {
                cout << "35" << endl;
                return 1;
            }
        }
        if(dealer.handValue == 8)
        {
            if(dealer.highCard > player.highCard)
            {
                cout << "36" << endl;
                return 1;
            }
            if(dealer.highCard < player.highCard)
            {
                cout << "37" << endl;
                return 2;
            }
            else
            {
                cout << "38" << endl;
                return 1;
            }
        }
    }
    return 0;
}

void Hand::replaceCardsPlayer(DeckOfCards * deck) // replace num amount of cards at locations in arr
{
    int numReplace = -1,num = 0,locs[3],ct = 0;
    vector<int> toRep;
    vector<Card> temp;
    locs[0] = -1;
    locs[1] = -1;
    locs[2] = -1;
    cout << "How many cards would you like to replace? ";
    while(numReplace < 1 || numReplace > 3)
    {
        cin >> numReplace;
        if(numReplace < 1 || numReplace > 3)
        {
            cout << "Try Again: ";
        }
    }
    for(int i = 0; i < numReplace; i++)
    {
        cout << "Which card would you like to replace? ";
        cin >> locs[num];
        num = num + 1;
    }
    for(int i = 0; i < 3; i++)
    {
        toRep.push_back(locs[i]);
    }
    sort(toRep.begin(),toRep.end());
//    for(int i = 0; i < 3; i++)
//    {
//        cout << i << ": " << toRep[i] << endl;
//    }
    for(int i = 2; i > -1; i--)
    {
        if(toRep[i] != -1)
        {
            ct = ct + 1;
            hand.erase(hand.begin() + toRep[i] - 1);
        }
    }
    //cout << hand.size() << endl;
//    for(unsigned int i = 0;i < temp.size();i++)
//    {
//        temp[i].toString();
//    }
    //cout << "CT: " << ct << endl;

    for(int i = 0; i < ct; i++)
    {
        hand.push_back(deck->dealCard());
    }
    cout << "You have replaced " << ct << " cards." << endl;
    faceSort();
}
void Hand::replaceCardsDealer(Hand player,DeckOfCards * deck) // replace num amount of cards at locations in arr
{
    if(handValue > player.handValue) //Hand is better, don't change any cards
    {
        //cout << "1" << endl;
        return;
    }
    //  cout << "2" << endl;
    int suits[2],ct = 0;
    countSuits(suits);
    // cout << "suits[1]: " << suits[1] << endl;
    if(handValue == 0 && suits[1] > 1)
    {
        // cout << suits[0] << endl;
        // cout << suits[1] << endl;
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            if(hand[i].getSuit() != suits[0] && ct < 4)
            {
                ct = ct + 1;
                hand.erase(hand.begin() + i);
                // hand.push_back(deck->dealCard());
            }
        }

    }
    for(int i = 0; i < ct; i++)
    {
        if(hand.size() < 5)
        {
            hand.push_back(deck->dealCard());
        }
    }
    if(handValue == 1)
    {
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            if(hand[i].getFace() != highCards[0])
            {
                ct = ct + 1;
                hand.erase(hand.begin() + i);
            }
        }
    }
    for(int i = 0; i < ct; i++)
    {
        if(hand.size() < 5)
        {
            hand.push_back(deck->dealCard());
        }
    }
    if(handValue == 2)
    {
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            if(hand[i].getFace() != highCards[0] && hand[i].getFace() != highCards[1])
            {
                ct = ct + 1;
                hand.erase(hand.begin() + i);
            }

        }
    }
    for(int i = 0; i < ct; i++)
    {
        if(hand.size() < 5)
        {
            hand.push_back(deck->dealCard());
        }
    }
    if(handValue == 3)
    {
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            if(hand[i].getFace() != highCards[0])
            {
                ct = ct + 1;
                hand.erase(hand.begin() + i);
            }
        }

    }
    for(int i = 0; i < ct; i++)
    {
        if(hand.size() < 5)
        {
            hand.push_back(deck->dealCard());
        }
    }

    if(ct > 0)
    {
        cout << "The dealer has elected to replace " << ct << " cards." << endl << endl;
    }
}

void Hand::countSuits(int * arr) //arr should be two elements first should what suit has the most and how many
{
    suitSort();
    int ct[4],ret[2];
    ct[0] = 0;
    ct[1] = 0;
    ct[2] = 0;
    ct[3] = 0;
    ret[0] = 0;
    ret[1] = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(hand[j].getSuit() == i)
            {
                ct[i] = ct[i] + 1;
            }
        }
    }
    for(int i = 3; i > -1; i--)
    {
        if(ct[i] >= ret[1])
        {
            ret[1] = ct[i];
            ret[0] = i;
        }
    }
    arr[0] = ret[0];
    arr[1] = ret[1];
    // cout << ret[0] << endl;
    // cout << ret[1] << endl;
}

//void Hand::countStraights(int * arr)//arr should be three elements first will be the start of ordered cards second will be the end, third will be number in a row
//{
//    faceSort();
//    //printHand();
//    vector<Card> temp2 = hand;
//    for(int i = 0; i < temp2.size(); i++)
//    {
//        if(temp2[i].getFace() == temp2[i + 1].getFace())
//        {
//            temp2.erase(temp2.begin() + i);
//        }
//    }
//    //for(int i = 0;i < temp2.size();i++)
//    //{
//      cout << temp2.size() << endl;
//    //}
//        int ret[3],temp[2],tempCt = 0,ct = 0;;
//        ret[0] = 0;
//        ret[1] = 0;
//        ret[2] = 0;
//        temp[0] = -1;
//        temp[1] = -1;
//        for(int i = 0; i < 5; i++)
//        {
//            int temp[2];
//            int tempCt = 0;
//            if(hand[i].getFace() == hand[i + 1].getFace() - 1)
//            {
//                if(temp[0] == -1)
//                {
//                    temp[0] = i;
//                    tempCt = tempCt + 1;
//                }
//                else
//                {
//                    temp[1] = i;
//                    tempCt = tempCt + 1;
//                }
//            }
//            else
//            {
//                if(tempCt > ct)
//                {
//                    ret[0] = temp[0];
//                    ret[1] = temp[1];
//                    ret[2] = tempCt;
//                    ct = tempCt;
//                    temp[0] = -1;
//                    temp[1] = -1;
//                    tempCt = 0;
//                }
//            }
//        }
//        for(int i = 0; i < 3; i++)
//        {
//            cout << ret[i] << endl;
//        }
//    }
