#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


enum suit {CLUBS=1, DIAMONDS, HEARTHS, SPADES};
struct card { suit color; int number; };
// displaying suit
string whichSuit(suit s) {
    switch(s) {
        case CLUBS: return "♣";
        case DIAMONDS: return "♦";
        case HEARTHS: return "♥";
        case SPADES: return "♠";
    }
}
// displaying hand
void showCards(vector<card> player) {
    for(card x : player) {
        string s;
        if(x.number >= 2 && x.number <=10) s=to_string(x.number);
        else
            switch(x.number) {
                case 1: s = "A"; break;
                case 11: s = "J"; break;
                case 12: s = "Q"; break;
                case 13: s = "K"; break;
            }
        cout << s << whichSuit(x.color) << " ";
    }
    cout << endl;
}
// check, what combination player have
bool cmp_by_id(const card& c1, const card& c2) {
    return c1.number < c2.number;
}
void pattern(vector<card> player) {
    sort(player.begin(), player.end(), cmp_by_id);
    for(card x : player) cout << x.number << whichSuit(x.color) << " ";
}

// return random cart
card getCard(vector<card> &deck) {
    int random = rand()%deck.size();
    card karta = deck[random];
    deck.erase(deck.begin()+random);
    return karta;
}

// needs rebuilding
/*
void showHand(vector<card> hand) {
    for(int i : hand)
        cout << ".------.  ";
    cout << endl;
    for(int i : hand) {
        if(i==10)
            cout << "|10--. |  ";
        else if(i==1)
            cout << "|A.--. |  ";
        else if(i==11)
            cout << "|J.--. |  ";
        else if(i==12)
            cout << "|Q.--. |  ";
        else if(i==13)
            cout << "|K.--. |  ";
        else if(i==14)
            cout << "|X.--. |  ";
        else
            cout << "|" << i << ".--. |  ";
    }

    cout << endl;
    for(int i : hand)
        cout << "| (\\/) |  ";
    cout << endl;
    for(int i : hand)
        cout << "| :\\/: |  ";
    cout << endl;
    for(int i : hand) {
        if(i==10)
            cout << "| '--10|  ";
        else if(i==1)
            cout << "| '--'A|  ";
        else if(i==11)
            cout << "| '--'J|  ";
        else if(i==12)
            cout << "| '--'Q|  ";
        else if(i==13)
            cout << "| '--'K|  ";
        else if(i==14)
            cout << "| '--'X|  ";
        else
            cout << "| '--'" << i << "|  ";
    }
    cout << endl;
    for(int i : hand)
        cout << "`------'  ";
    cout << endl;
}
 */

void game() {
    srand(time(NULL));
    // initialize varaibles
    vector<card> deck;
    vector<vector<card>> player;

    // fill the deck with cards
    for(int i=1; i<=4; i++)
        for(int j=1; j<=13; j++) {
            card carda;
            carda.color = (enum suit)i;
            carda.number = j;
            deck.push_back(carda);
        }

    // start game - for every player deal 2 cards;
    for(int i=0; i<2; i++) player.push_back({getCard(deck), getCard(deck)});
    showCards(player[0]);
    vector<card> table;
    //three card on table
    for(int i=0; i<3; i++) table.push_back((getCard(deck)));
    showCards(table);
    table.push_back((getCard(deck)));
    cout << endl;
    showCards(player[0]);
    showCards(table);
    table.push_back((getCard(deck)));
    cout << endl;
    showCards(player[0]);
    showCards(table);
    vector<card> p = table;
    p.push_back(player[0][0]); p.push_back(player[0][1]);
    pattern(p);
}

int main() {
    cout << "Poker game" << endl;
    game();
}