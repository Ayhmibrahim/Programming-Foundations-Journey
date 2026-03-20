#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoice{ Stone = 1, Peper =2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	int RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;

};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}		  

string WinnerName(enWinner Winner)
{

	string arrWinnerName[3] = { "Player1" , "Computer","No Winner" };
	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Peper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Peper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::Player1;
}

string ChoiceName(enGameChoice Winner)
{
	string arrGameChoices[3] = { "Stone" , "Peper","Scissors" };

	return arrGameChoices[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	if (Winner == Player1)
	{
		system("color 2F");
	}
	else if (Winner == Computer)
	{
		system("color 4F");
		cout << "\a";
	}
	else if (Winner == Draw)
	{
		system("color 6F");
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{

	cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n";
	cout << "__________________________________\n" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);

}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{

	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;

}

stGameResults FillGameResults(int GameRound, short Player1WinTimes,short ComputerWinTimes, short DrawTimes)
{

	stGameResults GameResults;

	GameResults.GameRounds = GameRound;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

enGameChoice ReadPlayerChoice()
{

	short Choice = 1;

	do
	{
		cout << "Your Choice: [1]:Stone, [2]:Peper, [3]:Scissors ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;

}

enGameChoice GetComPuterChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound  = 1; GameRound  <= HowManyRounds; GameRound ++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComPuterChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);


		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}

	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "	    	+++ G a m e O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";

}

void ShowFinalGameResults(stGameResults GameResults)
{

	cout << Tabs(2) << "_____________________ [Game Results] _____________________\n\n";
	cout << Tabs(2) << "Game Rounds	   : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw times	   : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner	   : [" << GameResults.WinnerName << "]" << endl;
	cout << Tabs(2) << "_________________________________________________________\n\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRounds()
{
	short Number;
	std::cout << "How Many Rounds 1 to 10 ?\n";
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, Enter a valid one: " << endl;

		cin >> Number;
	}

	return Number;
}

void ResetSreecn()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{

	char PlayAgain = 'Y';

	do
	{
		ResetSreecn();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << Tabs(2) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;


	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	StartGame();

    return 0;
}