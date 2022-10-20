#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _card {
    int palo;
    int num;
} card;

typedef struct _deck {
    int num_cards;
    card **cards;
} deck;

card *make_card(int palo, int num)
{
    card *newCard = malloc(sizeof(card));
    newCard->palo = palo;
    newCard->num = num;

    return newCard;
}

deck *make_standard_deck( void )
{
    deck *newDeck = malloc( sizeof(deck) );

    newDeck->num_cards = 52;
    newDeck->cards = malloc( 52 * sizeof(card *) );

    int index = 0;
    for ( int palo = 0; palo < 4; palo++ )
        for ( int num = 1; num <= 13; num++ )
            newDeck->cards[index++] = make_card( palo, num );

    return newDeck;
}
int checkPoker(int i[5],deck *stdDeck){
    if((stdDeck->cards[i[0]]->num)==(stdDeck->cards[i[1]]->num)&&(stdDeck->cards[i[1]]->num)==(stdDeck->cards[i[2]]->num)&&(stdDeck->cards[i[2]]->num)==(stdDeck->cards[i[3]]->num))
        return 1;
    
    return 0;
}
int checkPierna(int i[5],deck *stdDeck){
    if((stdDeck->cards[i[0]]->num==stdDeck->cards[i[1]]->num&&stdDeck->cards[i[0]]->num==stdDeck->cards[i[3]]->num)||(stdDeck->cards[i[0]]->num==stdDeck->cards[i[1]]->num&&stdDeck->cards[i[0]]->num==stdDeck->cards[i[2]]->num)||(stdDeck->cards[i[0]]->num==stdDeck->cards[i[2]]->num&&stdDeck->cards[i[0]]->num==stdDeck->cards[i[3]]->num)||(stdDeck->cards[i[1]]->num==stdDeck->cards[i[2]]->num&&stdDeck->cards[i[1]]->num==stdDeck->cards[i[3]]->num))
        return 1;
    
    return 0;
}

int checkPar(int i[5],deck *stdDeck){
    if((stdDeck->cards[i[0]]->num==stdDeck->cards[i[1]]->num||stdDeck->cards[i[0]]->num==stdDeck->cards[i[2]]->num)||(stdDeck->cards[i[0]]->num==stdDeck->cards[i[3]]->num||stdDeck->cards[i[1]]->num==stdDeck->cards[i[2]]->num)||(stdDeck->cards[i[1]]->num==stdDeck->cards[i[3]]->num||stdDeck->cards[i[2]]->num==stdDeck->cards[i[3]]->num))
        return 1;
    
    return 0;
}

int main( void )
{
    srand(time(NULL));
    int i[5];
    i[0]=(rand()%52);
    i[1]=(rand()%52);
    i[2]=(rand()%52);
    i[3]=(rand()%52);
    i[4]=(rand()%52);
    for(int j=0;j<5;j++){
        for(int m=0;m<5;m++){
            if(m!=j){
                if(i[j]==i[m]){
                    if(i[j]<51){
                        i[j]++;
                    }
                    else{
                        i[j]=0;
                    }
                }
            }
        }
    }
    
    deck *stdDeck = make_standard_deck();

    for(int x=0;x<5;x++){
    printf( "palo=%d num=%2d\n", stdDeck->cards[i[x]]->palo, stdDeck->cards[i[x]]->num );
    }
    if(checkPoker(i,stdDeck)){
        printf("%s\n","Poker");
    }
    else if(checkPierna(i,stdDeck)){
        printf("%s\n","Pierna");
    }
    else if(checkPar(i,stdDeck)){
        printf("%s\n","Par");
    }
    else{
        printf("%s\n","Nada");
    }
    
/* free the deck when we're done with it */
    for (int i = 0; i < stdDeck->num_cards; i++ )
        free( stdDeck->cards[i] );
    free( stdDeck->cards );
    free( stdDeck );
}