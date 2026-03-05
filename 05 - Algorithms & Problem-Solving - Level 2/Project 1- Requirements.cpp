#include <iostream>
#include <windows.h>


using namespace std;

enum enGameChoice { Stone = 1, Peper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


int ReadNumber()
{
    short Number;

    std::cout << "How Many Rounds 1 to 10 ?\n";
    cin >> Number;

    return Number;
}


enWinner GetRoundWin(int PlayerChoice, int computerChoice)
{

    if (PlayerChoice == computerChoice)
    {
        return enWinner::Draw;
    }
    else if (PlayerChoice == enGameChoice::Peper && computerChoice == Stone)
    {
        return enWinner::Player1;
    }
    else if (PlayerChoice == enGameChoice::Stone && computerChoice == Scissors)
    {
        return enWinner::Player1;
    }
    else if (PlayerChoice == enGameChoice::Scissors && computerChoice == Peper)
    {
        return enWinner::Player1;
    }
    else if (PlayerChoice == enGameChoice::Peper && computerChoice == Scissors)
    {
        return enWinner::Computer;
    }
    else if (PlayerChoice == enGameChoice::Scissors && computerChoice == Stone)
    {
        return enWinner::Computer;
    }
    else if (PlayerChoice == enGameChoice::Stone && computerChoice == Peper)
    {
        return enWinner::Computer;
    }
}


void PrintRoundGame(int GameLength)
{
 
	int PlayerChoice = 0;
    int roundWinner = 0;
    int computerChoice = 0;

    string FinalWin = " ";

    int Player1Counter = 0;
    int ComputerCounter = 0;
    int DrawCounter = 0;

        for (int i = 0; i < GameLength; i++)
        {
            cout << "Round [" << i + 1 << "] begins:\n";

            cout << "Your Choice: [1]:Stone, [2]:Peper, [3]:Scissors ? ";
			cin >> PlayerChoice;

            cout << "\n_____________________Round [" << i+1 << "]_____________________\n\n";

            cout << "Player1 Choice: ";

            switch (PlayerChoice)
            {
            case Stone:  std::cout << "Stone\n"; break;
            case Peper:  std::cout << "Peper\n"; break;
            case Scissors:  std::cout << "Scissors\n"; break;
            }

            std::cout << "Computer chose: ";
            switch (computerChoice= RandomNumber(1, 3))
            {
            case Stone:  std::cout << "Stone\n"; break;
            case Peper:  std::cout << "Peper\n"; break;
            case Scissors:  std::cout << "Scissors\n"; break;
            }
     

            std::cout << "Round Winner  : ";
            roundWinner = GetRoundWin(PlayerChoice, computerChoice);
            switch (roundWinner)
            {

            case Player1:  std::cout << "[Player1]\n"; break;
            case Computer:  std::cout << "[Computer]\n"; break;
            case Draw:  std::cout << "[No Winner]\n"; break;
            }


            if (roundWinner == Computer)
            {
                system("color 4F");
            }
            else if (roundWinner == Player1)
            {
                system("color 2F");
            }
            else if (roundWinner == Draw)
            {
                system("color 6F");
            }

            if (roundWinner == Player1)
            {
                Player1Counter++;
            }
            else if (roundWinner == Computer)
            {
                ComputerCounter++;
            }
            else
            {
                DrawCounter++;
            }


            

            cout << "\n___________________________________________________\n\n";
        }


        cout << "\n\t\t___________________________________________________\n\n";
        cout << "\t\t                    +++Game Over+++                  \n";
        cout << "\n\t\t___________________________________________________\n\n";
        cout << "\n\t\t_________________[ Game Results ]__________________\n\n";
        cout << "\t\tGame Rounds        : " << GameLength << "\n";
        cout << "\t\tPlayer1 won times  : " << Player1Counter << "\n";
        cout << "\t\tComputer won times : " << ComputerCounter << "\n";
        cout << "\t\tDraw times         : " << DrawCounter << "\n";
        switch (roundWinner)
        {
        case Player1: cout << "\t\tFinal Winner       : Player1\n"; break;
        case Computer: cout << "\t\tFinal Winner       : Computer\n"; break;
        case Draw: cout << "\t\tFinal Winner       : No Winner\n"; break;
        }


        cout << "\n\t\t___________________________________________________\n\n";
}


void PrintFinalWinner()
{
    string Again;

    do
    {
        PrintRoundGame(ReadNumber());
		cout << "\nDo you want to play again ? [y/n] ? ";
        cin >> Again;

        if (Again == "y" || Again == "Y")
        {
            system("cls");
            system("color 0F");
        }
    } while (Again == "y" || Again == "Y");
}
int main()
{

    srand((unsigned)time(NULL));
    PrintFinalWinner();
 
    return 0;
}