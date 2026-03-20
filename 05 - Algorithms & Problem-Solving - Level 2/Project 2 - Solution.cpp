#include <iostream>

using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3 , Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

string GetOpTypeSmbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mult:
		return "*";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}

string GetQuestionsLevelText(enQuestionsLevel QuestionsLevel)
{
	string arrQuestionsLevelText[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionsLevelText[QuestionsLevel - 1];
}
int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

short ReadHowManyQustions()
{
	short NumberOfQustions = 0;
	do
	{
		cout << "How Many Qustions do you want to answer ? ";
		cin >> NumberOfQustions;
	} while (NumberOfQustions < 1 || NumberOfQustions > 10);

	return NumberOfQustions;
}

enQuestionsLevel ReadQusetionsLevel()
{
	short QustionsLevel = 1;

	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med , [3] Hard ,[4] Mix ? ";
		cin >> QustionsLevel;

	} while (QustionsLevel < 1 || QustionsLevel > 4);

	return enQuestionsLevel (QustionsLevel);
}

enOperationType ReadOpType()
{
	short OpType;

	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OpType;

	} while (OpType < 1 || OpType > 5);

	return enOperationType(OpType);
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F"); // Green for correct answers.
	else
	{
		system("color 4F"); // Red for incorrect answers.
		cout << "\a"; // Plays an alert sound.
	}
}

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionsLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResults = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions;
	enQuestionsLevel QuestionsLevel;
	enOperationType OpType;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool isPass = false;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mult:
		return Number1 * Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

enOperationType GetRandomOperationType()
{
	int Op = RandomNumber(1, 4);
	return (enOperationType)Op;
}

stQuestion GenerateQuetsion(enQuestionsLevel QuestionsLevel, enOperationType OpType)
{
	stQuestion Question;

	if (QuestionsLevel == enQuestionsLevel::Mix)
	{
		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}

	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationType();
	}

	Question.OperationType = OpType;

	switch (QuestionsLevel)
	{
	case enQuestionsLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;
		return Question;

	case enQuestionsLevel::MedLevel:
		Question.Number1 = RandomNumber(1, 50);
		Question.Number2 = RandomNumber(1, 50);
	
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;
		return Question;

	case enQuestionsLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;
		return Question;

	case enQuestionsLevel::Mix:
		Question.Number1 = RandomNumber(1, 100);
		Question.Number2 = RandomNumber(1, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;
		return Question;
	}

	return Question;
}

void GenerateQuizzQuestoion(stQuizz& Quizz)
{
	
	for (short Questoion = 0; Questoion < Quizz.NumberOfQuestions; Questoion++)
	{
		Quizz.QuestionList[Questoion] = GenerateQuetsion(Quizz.QuestionsLevel, Quizz.OpType);
	}
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}
void PrintTheQusetino(stQuizz& Quizz, short QuiestionsNumber)
{
	cout << "\n";
	cout << "Qusrtion [" << QuiestionsNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
	cout << Quizz.QuestionList[QuiestionsNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuiestionsNumber].Number2 << " ";
	cout << GetOpTypeSmbol(Quizz.QuestionList[QuiestionsNumber].OperationType);
	cout << "\n________" << endl;
}

void CorrectTheQustionAnswers(stQuizz& Quizz, short QuiestionsNumber)
{
	if (Quizz.QuestionList[QuiestionsNumber].PlayerAnswer != Quizz.QuestionList[QuiestionsNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuiestionsNumber].AnswerResults = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answers :-( \n";
		cout << "The right answer is: ";
		cout << Quizz.QuestionList[QuiestionsNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[QuiestionsNumber].AnswerResults = true;
		Quizz.NumberOfRightAnswers++;

		cout << "Right Answer :-) \n";
	}
	cout << endl;

	SetScreenColor(Quizz.QuestionList[QuiestionsNumber].AnswerResults);
	
}

void AskAndCorrectQustionListAnswers(stQuizz& Quizz)
{
	for (short QustoionNumber = 0; QustoionNumber < Quizz.NumberOfQuestions; QustoionNumber++)
	{
		PrintTheQusetino(Quizz, QustoionNumber);

		Quizz.QuestionList[QustoionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQustionAnswers(Quizz, QustoionNumber);
	}

	Quizz.isPass = (Quizz.NumberOfQuestions >= Quizz.NumberOfWrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
	if (Pass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";
	cout << "______________________________\n\n";
	cout << " Final Results is " << GetFinalResultsText(Quizz.isPass);
	cout << "\n______________________________\n\n";

	cout << "Number of Qustoion: " << Quizz.NumberOfQuestions << endl;
	cout << "Qustoion Level	   : " << GetQuestionsLevelText(Quizz.QuestionsLevel) << endl;
	cout << "OpType			   : " << GetOpTypeSmbol(Quizz.OpType) << endl;
	cout << "Number Of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "______________________________\n";
}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQustions();
	Quizz.QuestionsLevel = ReadQusetionsLevel();
	Quizz.OpType = ReadOpType();

	GenerateQuizzQuestoion(Quizz);
	AskAndCorrectQustionListAnswers(Quizz);
	PrintQuizzResults(Quizz);
}

void ResetSreecn()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{

	char PlayAgin = 'Y';
	do
	{
		ResetSreecn();
		PlayMathGame();

		cout << "Do you want to play agin? Y/N? ";
		cin >> PlayAgin;

	} while (PlayAgin == 'Y' || PlayAgin=='y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}