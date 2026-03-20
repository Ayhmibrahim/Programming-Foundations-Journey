#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enum enQuizzLevel {   Easy = 1, Med = 2, Hard = 3, Mix = 4   };

enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

enum enPassOrFail { Pass = 1 , Fail = 2};

struct stQuizz
{
    short NumberOfQuizz = 0;
    string LevelQuizz = "";
    string OpType = "";
    short NumberOfReightAnswer = 0;
    short NumberOfWorngAnswer = 0;
    enPassOrFail Results = Fail;
};

short ReadHowManyQuestions()
{
    short NumberOfQuizz = 0;

    cout << "How Many Questions do you want to answer ? ";
    cin >> NumberOfQuizz;

    return NumberOfQuizz;
}

enQuizzLevel ReadQuizzLevel()
{
    short Level = 1;

    do
    {
        cout << "Enter Questions Level [1] Easy, [2] Med , [3] Hard ,[4] Mix ? ";
        cin >> Level;

    } while (Level < 1 || Level > 4);

    return enQuizzLevel (Level);
}

enOpType ReadOperationType()
{
    short OpType = 1;

    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> OpType;

    } while (OpType < 1 || OpType > 5);

    return enOpType(OpType);
}

void GenerateReandomNumber(short& Num, short& Num2, enQuizzLevel SetLevel)
{

    switch (SetLevel)
    {
        case enQuizzLevel::Easy:
        {
            Num = RandomNumber(0, 10);
            Num2 = RandomNumber(0, 10);

            break;
        }
        case enQuizzLevel::Med:
        {
            Num = RandomNumber(10, 50);
            Num2 = RandomNumber(10, 50);

            break;
        }
        case enQuizzLevel::Hard:
        {

            Num = RandomNumber(50, 100);
            Num2 = RandomNumber(50, 100);

            break;
        }
        case enQuizzLevel::Mix:
        {

            Num = RandomNumber(0, 100);
            Num2 = RandomNumber(0, 100);

            break;
        }
    }
}

int ReadCalculator(short Num, short Num2, enOpType OpType)
{

    switch (OpType)
    {
        case enOpType::Add:
        {
            return Num + Num2;
        }

        case enOpType::Sub:
        {
            return Num - Num2;
        }
        case enOpType::Mul:
        {
            return Num * Num2;
        }
        case enOpType::Div:
        {
            if (Num2 == 0)
            {
                return 0;
            }
            else
            {
                return Num / Num2;
            }
        }  
     
    }
    return 0;
}

string OpTypeChar(enOpType OpType)
{
    string arrOpType[5] = { "+", "-", "*", "/", "Mix" };
    return arrOpType [OpType-1];
}

string LevelTypeChar(enQuizzLevel Level)
{
    string arrLevel[4] = { "Easy" , "Med" , "Hard","Mix" };
    return arrLevel[Level -1];
}

int AnswerPlyer(short Num, short Num2, enOpType OpType)
{
    int Answer = 0;
    cout << "\n" << Num << endl;
    cout << Num2 << " " << OpTypeChar(OpType) << endl;
    cout << "________________\n";
    cin >> Answer;

    return Answer;
}

void SetWinnerScreenColor(enPassOrFail Winner)
{
    if (Winner == Pass)
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
 
}

stQuizz PlayGame()
{
    stQuizz QuizzInfo;

    enOpType OperationType;
    enQuizzLevel Level;

    short Num = 0, Num2 = 0, NumberOfReightAnswer = 0, NumberOfWorngAnswer = 0;
    
    
    short HowManyQuestions = ReadHowManyQuestions();

    Level = ReadQuizzLevel();

    OperationType = ReadOperationType();

    for (short Question = 1; Question <= HowManyQuestions; Question++)
    {
        cout << "\n\nQuestion [" << Question << "/" << HowManyQuestions << "]\n";

        GenerateReandomNumber(Num, Num2, Level);

        enOpType QuestionOpType = OperationType;
        if (OperationType == MixOp)
            QuestionOpType = static_cast<enOpType>(RandomNumber(1, 4)); 

        int CorrectAnswer = ReadCalculator(Num, Num2, QuestionOpType);
        int PlayerAnswer = AnswerPlyer(Num, Num2, QuestionOpType);

        enPassOrFail Result = (PlayerAnswer == CorrectAnswer) ? Pass : Fail;

        if (Result == Pass)
        {
            cout << "Right Answer :-)";
            NumberOfReightAnswer++;
        }
        else
        {
            cout << "Worng Answer :-(\n" << "The righ answer is: " << CorrectAnswer;
            NumberOfWorngAnswer++;
        }

        SetWinnerScreenColor(Result);
    }


    QuizzInfo.NumberOfQuizz = HowManyQuestions;
    QuizzInfo.NumberOfReightAnswer = NumberOfReightAnswer;
    QuizzInfo.NumberOfWorngAnswer = NumberOfWorngAnswer;
    QuizzInfo.OpType = OpTypeChar(OperationType);
    QuizzInfo.LevelQuizz = LevelTypeChar(Level);


    if (NumberOfReightAnswer > NumberOfWorngAnswer)
        QuizzInfo.Results = Pass;
    else
        QuizzInfo.Results = Fail;

    return QuizzInfo;
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

void ShowGameOverScreen(stQuizz QuizzInfo)
{
    cout <<"\n__________________________________________________________\n\n";
    cout << "	    	Fianl Results is ";
    if (QuizzInfo.Results == Fail)
        cout << "Fail :-(\n";
    else
        cout << "Pass :-)\n";
    cout <<"__________________________________________________________\n\n";

}

void ShowFinalGameResults(stQuizz QuizzInfo)
{

    cout << "_____________________ [Game Results] _____________________\n\n";
    cout << "Number Of Questions : " << QuizzInfo.NumberOfQuizz << endl;
    cout << "Questions Level     : " << QuizzInfo.LevelQuizz << endl;
    cout << "OpType              : " << QuizzInfo.OpType << endl;
    cout << "Number Of Reight Answers: " << QuizzInfo.NumberOfReightAnswer << endl;
    cout << "Number Of Worng Answers: " << QuizzInfo.NumberOfWorngAnswer << endl;
    cout << "_________________________________________________________\n\n";

    SetWinnerScreenColor(QuizzInfo.Results);
}

void ResetSreecn()
{
    system("cls");
    system("shutdown /r /t 0");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetSreecn();
        stQuizz GameResults = PlayGame();
        ShowGameOverScreen(GameResults);
        ShowFinalGameResults(GameResults);

        cout << Tabs(2) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;


    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}