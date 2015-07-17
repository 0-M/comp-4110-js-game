
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Deque.h"


double generateRandomFloat(int upperLimit);
char* generateRandomName();
Data generateStock();
double generateRandomChange(int max);
void updateLedger(DequePtr deq);


int main(int argc, char *argv[])
{
    srand ( time(NULL) );
    DequePtr deque = initDeque();
    Data data,temp,toAdd;
    int iterations,i,iterationsCounter,input,input2,update;
    double capital;
    iterations = 10;
    update = 0;
    iterationsCounter = 0;
    capital = 1000;
    for(i = 0; i < iterations; i++)
    {
        data = generateStock();
        addFront(deque,data);
    }

    while(iterationsCounter < iterations)
    {
        input2 = 0;
        printf("1. Show capital.\n");
        printf("2. Check first.\n");
        printf("3. Check last.\n");
        printf("4. Buy first.\n");
        printf("5. Buy last.\n");
        printf("6. Sell first\n");
        printf("7. Sell last\n");
        scanf("%d",&input);
        switch(input)
        {
        case 1  :
            printf("You have %.2f dollars remaining.\n",capital);
            printf("\n");
            break;
        case 2 :
            printf("Here is information about the stock at the top of the ledger.\n");
            printf("\n");
            temp = getFront(deque);
            printf("Name of stock: %s\n",temp.nameOfStock);
            printf("Number of shares: %d\n",temp.numberOfShares);
            printf("Purchase cost per share: %.2f\n",temp.PurchaseCostPerShare);
            printf("Current price per share: %.2f\n",temp.CurrentPricePerShare);
            printf("The number of shares you can purchase of %s is: %d\n",temp.nameOfStock,(int)(capital/temp.PurchaseCostPerShare));
            printf("You can sell your %d shares of %s for %.2f dollars,a %.2f percent change.\n",temp.numberOfShares,temp.nameOfStock,temp.numberOfShares * temp.CurrentPricePerShare,(((temp.numberOfShares * temp.CurrentPricePerShare)/(temp.numberOfShares * temp.PurchaseCostPerShare))- 1) * 100);
            printf("\n");
            break;
        case 3 :
            printf("Here is information about the stock at the bottom of the ledger.\n");
            printf("\n");
            temp = getBack(deque);
            printf("Name of stock: %s\n",temp.nameOfStock);
            printf("Number of shares: %d\n",temp.numberOfShares);
            printf("Purchase cost per share: %.2f\n",temp.PurchaseCostPerShare);
            printf("Current price per share: %.2f\n",temp.CurrentPricePerShare);
            printf("The number of shares you can purchase of %s is: %d\n",temp.nameOfStock,(int)(capital/temp.PurchaseCostPerShare));
            printf("You can sell your %d shares of %s for %.2f dollars,a %.2f percent change.\n",temp.numberOfShares,temp.nameOfStock,temp.numberOfShares * temp.CurrentPricePerShare,(((temp.numberOfShares * temp.CurrentPricePerShare)/(temp.numberOfShares * temp.PurchaseCostPerShare))- 1) * 100);
            printf("\n");
            break;
        case 4 :
            temp = getFront(deque);
            do
            {
                printf("How many shares of %s would you like to buy, you can afford a maximum of %d shares:",temp.nameOfStock,(int)(capital/temp.PurchaseCostPerShare));
                scanf("%d",&input2);
            }
            while(input2 > (capital/temp.PurchaseCostPerShare) || input2 < 0);

            capital = capital - (input2)*(temp.PurchaseCostPerShare);
            printf("%d shares of %s purchased, %.2f dollars remaining",input2,temp.nameOfStock,capital);
            toAdd = temp;
            toAdd.numberOfShares = input2;
            addFront(deque,toAdd);
            printf("\n");
            update = 1;
            iterationsCounter++;
            break;
        case 5 :
            temp = getBack(deque);
            do
            {
                printf("How many shares of %s would you like to buy, you can afford a maximum of %d shares:",temp.nameOfStock,(int)(capital/temp.PurchaseCostPerShare));
                scanf("%d",&input2);
            }
            while(input2 > (capital/temp.PurchaseCostPerShare) || input2 < 0);

            capital = capital - (input2)*(temp.PurchaseCostPerShare);
            printf("%d shares of %s purchased, %.2f dollars remaining",input2,temp.nameOfStock,capital);
            toAdd = temp;
            toAdd.numberOfShares = input2;
            addFront(deque,toAdd);
            printf("\n");
            iterationsCounter++;
            update = 1;
            break;
        case 6 :
            temp = getFront(deque);
            if(deque -> head == NULL)
            {
                printf("No stocks to sell.\n");
            }
            else
            {
                printf("Selling %d shares of %s, for %.2f dollars each.  For a total of %.2f dollars\n",temp.numberOfShares,temp.nameOfStock,temp.CurrentPricePerShare,(temp.numberOfShares * temp.CurrentPricePerShare));
                capital = capital + (temp.numberOfShares * temp.CurrentPricePerShare);
                printf("You now have %.2f dollars.\n",capital);
                removeFront(deque);
                iterationsCounter++;
                update = 1;

            }
            break;
        case 7 :
            temp = getBack(deque);
            if(deque -> head == NULL)
            {
                printf("No stocks to sell.\n");
            }
            else
            {
                printf("Selling %d shares of %s, for %.2f dollars each.  For a total of %.2f dollars\n",temp.numberOfShares,temp.nameOfStock,temp.CurrentPricePerShare,(temp.numberOfShares * temp.CurrentPricePerShare));
                capital = capital + (temp.numberOfShares * temp.CurrentPricePerShare);
                printf("You have %.2f dollars remaining.\n",capital);
                removeBack(deque);
                iterationsCounter++;
                update = 1;
            }
            break;

        default :
            printf("Invalid choice, please try again.\n");
        }
        if(update == 1)
        {
            update = 0;
            updateLedger(deque);
        }
    }
    if(capital > 1000)
    {
        printf("After 10 turns you ended with %.2f dollars.  Good job!\n",capital);

    }
    else
    {
        printf("After 10 turns you ended with %.2f dollars.  Better luck next time.\n",capital);
    }


    printf("\n\n\n");
    destroyDeque(deque);
    return 0;
}


double generateRandomFloat(int upperLimit)
{
    double part1,part2;
    part1 = rand() % 100;
    part1 = (double)(part1 / 100);
    part2 = rand() % 100;
    return (part1 + part2);
}

double generateRandomChange(int max)
{
    int sign;
    double result;
    sign = 0;
    result = (double)(rand() % 25)/100;
    if(rand() % 1000 > 499)
    {
        sign = 1;
    }
    else
    {
        sign = -1;
    }
    return (result * sign);
}

char * generateRandomName()
{
    char letter,*name;
    name = malloc(4);
    int i,randLetter;
    randLetter = 0;
    for(i = 0; i < 3; i++)
    {
        while(randLetter < 65 || randLetter > 90)
        {
            randLetter = rand() % 90;
        }
        letter = randLetter;
        name[i] = letter;
        randLetter = 0;
    }
    return name;
}

Data generateStock()
{
    char *s;
    Data stock;
    s = generateRandomName();
    stock.nameOfStock = s;
//    printf("StockName: %s\n",stock.nameOfStock);
    stock.numberOfShares = rand() % 100;
    //printf("Number of Shares: %d\n",stock.numberOfShares);
    stock.PurchaseCostPerShare = generateRandomFloat(1000);
    //printf("Purchase cost per share: %.2f\n",stock.PurchaseCostPerShare);
    stock.CurrentPricePerShare = stock.PurchaseCostPerShare;
    //printf("Current cost per share: %.2f\n",stock.CurrentPricePerShare);

    //free(s);
    return stock;
}

void updateLedger(DequePtr deq)
{
    double change;
    change = 0;
    NodePtr temp;
    temp = deq -> head;

    printf("\n");
    while(temp != NULL)
    {

            change = generateRandomChange(25);
            temp -> data.CurrentPricePerShare = temp -> data.CurrentPricePerShare + (temp-> data.CurrentPricePerShare) * change;
            if(change > 0)
            {
                printf("The price of %s has gone up %.2f percent.\n",temp -> data.nameOfStock,change * 100);
            }
            else
            {
                printf("The price of %s has gone down %.2f percent.\n",temp -> data.nameOfStock,change * 100);
            }
        temp = temp -> next;

    }


}
