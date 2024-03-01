// Daryl Chit 015707807
// CECS 325-02
// Prog 2 - Single File Fibo Solitaire
// 09/26/2023
//
// I certify that this program is my own original work. I did not copy any part
//of this program from
// any other source. I further certify that I typed each and every line of code
//in this program.


#include <iostream>
#include <cstdlib>
using namespace std;
#include <vector>

class Card
{
    private:
        char rank;
        char suit;

    public: // functions/behaviors
  Card()
  {
    suit = 'X';
    rank = 'X';
  }
  
  Card(char r, char s)
  {
    suit = s;
    rank = r;
  }
  
  int getValue()
  {
    if (rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K')
    {
      return 10;
    }
    else if(rank == 'A')
    {
      return 1;
    }
    else if(rank == 'X')
    {
      return 0;
    } else {
      return (rank - '0');
    }
  }
  
  void show()
  {
    if(rank == 'T')
      {
        cout << 10;
      } else {
        cout << rank;
      }
    cout << suit << ", ";
  }
      
};

class Deck
{
    private:
    	vector<Card> myDeck;

    public:
  Deck()
  {
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suits[] = {'S', 'H', 'D', 'C'};
  
    for(char s : suits)
      {
        for(char r : ranks)
          {
            myDeck.push_back(Card(r,s));
          }
      }
  }
  
  void newDeck()
  {
  
    for (Card x : myDeck)
      {
        myDeck.pop_back();
      }
      
      char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suits[] = {'S', 'H', 'D', 'C'};
  
    for(char s : suits)
      {
        for(char r : ranks)
          {
            myDeck.push_back(Card(r,s));
          }
      }
  }
  
  Card deal()
  {
    Card dealtCard = myDeck.back();
    myDeck.pop_back();
      return dealtCard;
  }
  
  void shuffle()
  {
    //srand(time(0));
    vector<Card> shuffledDeck;
    while(myDeck.size() != 0)
      {
        int randNum = rand()%myDeck.size();
        shuffledDeck.push_back(myDeck[randNum]);
        myDeck.erase(myDeck.begin()+randNum);
      }
    
    shuffledDeck.swap(myDeck);
  }
  
  bool isEmpty()
  {
    if (myDeck.size() == 0)
    {
      return true;
    } else {
      return false;
    }
  }
  
  void show()
  {
    int gridCounter = 0;
    for (Card c : myDeck)
      {
        gridCounter++;
        c.show();
        if(gridCounter == 13)
        {
          cout << endl;
          gridCounter = 0;
        }
      }
  }

};

bool isFibo(int sum)
{
  if (sum == 1 || sum == 2 || sum == 3 || sum == 5 || sum == 8 || sum == 13 || sum == 21 || sum == 34 || sum == 55 || sum == 89 || sum == 144 || sum == 233 || sum == 377 || sum == 610 || sum == 987)
  {
    return true;
  } else {
    return false;
  }
}

int main()
{
  srand(time(0));
  Deck deck = Deck();
  cout << endl << "Welcome to Fibonacci Solitaire! \n1) Create New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Fibo Solitaire\n5) Win Fibo Solitaire\n6) Exit" << endl;

  bool play = true;
  
  int userInput = 0;
  cin >> userInput;
  if(userInput == 6)
  {
    play = false;
  }
  while(play == true)
    {
      switch(userInput)
      {
        case 1:
          deck.newDeck();
          break;
        
        case 2:
          deck.show();
          break;
        
        case 3:
          deck.shuffle();
          break;
        
        case 4:
            {
              int sum = 0;
              int pile = 0;
              while (!deck.isEmpty())
                {
                  
                  Card drawnCard = deck.deal();
                  drawnCard.show();
                  
                  sum += drawnCard.getValue();
                  if (deck.isEmpty())
                  {
                    if (isFibo(sum) != true)
                    {
                      cout << endl << "NOT FIBO: " << sum << endl;
                    pile++;
                    } else {
                      cout << "YOU WIN" << sum << endl;
                      pile++;
                      sum = 0;
                    }
                    
                  }
                  if (isFibo(sum) == true)
                  {
                    cout << "FIBO: " << sum << endl;
                    pile++;
                    sum = 0;
                  }
                
                }
              if (pile == 0)
              {
                cout << "Deck is empty. Press 1 to Create New Deck" << endl;
              } else {
                cout << endl << "Piles: " << pile << endl << endl;
              }
              
            }
          break;
        
        case 5:
          {
            int gamesPlayed = 0;
            bool winner = false;
            while(winner == false)
              {
                gamesPlayed++;
                int sum = 0;
                int pile = 0;
                while (!deck.isEmpty())
                  {
                    Card drawnCard = deck.deal();
                    drawnCard.show();
                    
                    sum += drawnCard.getValue();
                    if (deck.isEmpty())
                    {
                      if (isFibo(sum) != true)
                      {
                        cout << endl << "NOT FIBO: " << sum << endl;
                        pile++;
                        
                      } else {
                        cout << "YOU WIN " << "sum: " << sum << endl << "Games Played: " << gamesPlayed << endl;
                        
                        pile++;
                        sum = 0;
                        winner = true;
                      }
                    }
                    if (isFibo(sum) == true)
                    {
                      cout << "FIBO: " << sum << endl;
                      pile++;
                      sum = 0;
                    }
                  }
              if (pile == 0)
              {
                deck.newDeck();
                deck.shuffle();
              } else {
                cout << endl << "Piles: " << pile << endl;
              }
            }
          }
        case 6:
          play = false;
          break;
    }
      cout << endl << "1) Create New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Fibo Solitaire\n5) Win Fibo Solitaire \n6) Exit" << endl;
      cin >> userInput;
    }
    
  return 0;
}
