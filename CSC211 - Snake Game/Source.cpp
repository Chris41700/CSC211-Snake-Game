#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 30;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
char answer;
int scoresList[3];
int fruitsCoordinates[30];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void Setup();
void Draw();
void Input();
void Logic();
void sortScores(int[], int);
void displayScores(int[]);
void invisibleFruits(int[]);

int main() 
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    return 0;
}
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    for (int i = 0; i < 30; i++)
    {
        if (i % 2 == 0)
        {
            fruitsCoordinates[i] = rand() % width;
        }
        else
        {
            fruitsCoordinates[i] = rand() % height;
        }
    }
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    for (int i = 0; i < width / 2 + 2; i++)
        cout << "<>";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "<>";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "<>";
        }
        cout << endl;
    }

    for (int i = 0; i < width / 2 + 2; i++)
        cout << "<>";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width || x < 0 || y > height || y < 0)
    {
        sortScores(scoresList, score);
        displayScores(scoresList);

        cout << endl << "Do you want to play again? (Y/N) " << endl;
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            nTail = 0;
            system("cls");
            Setup();
        }
        else if (answer == 'n' || answer == 'N')
        {
            gameOver = true;
        }
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            sortScores(scoresList, score);
            displayScores(scoresList);

            cout << endl << "Do you want to play again? (Y/N) " << endl;
            cin >> answer;

            if (answer == 'y' || answer == 'Y')
            {
                nTail = 0;
                system("cls");
                Setup();
            }
            else if (answer == 'n' || answer == 'N')
            {
                gameOver = true;
            }
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    invisibleFruits(fruitsCoordinates);
    
}

void sortScores(int scoresList[], int score)
{
    int temp;

    if (scoresList[0] != NULL && scoresList[1] != NULL && scoresList[2] != NULL)
    {
        if (scoresList[0] < score)
        {
            temp = scoresList[0];
            scoresList[0] = score;
            score = scoresList[1];
            scoresList[1] = temp;
            scoresList[2] = score;
        }
        else if (scoresList[1] < score)
        {
            temp = scoresList[1];
            scoresList[1] = score;
            scoresList[2] = temp;
        }
        else if (scoresList[2] < score)
        {
            scoresList[2] = score;
        }
    }

    if (scoresList[0] == NULL)
    {
        scoresList[0] = score;
    }
    else if (scoresList[1] == NULL)
    {
        scoresList[1] = score;
    }
    else if (scoresList[2] == NULL)
    {
        scoresList[2] = score;
    }

    if (scoresList[1] < scoresList[2])
    {
        temp = scoresList[1];
        scoresList[1] = scoresList[2];
        scoresList[2] = temp;
    }

    if (scoresList[0] < scoresList[1])
    {
        temp = scoresList[0];
        scoresList[0] = scoresList[1];
        scoresList[1] = temp;
    }
}

void displayScores(int scoresList[])
{
    cout << endl << "----------Top 3 Scores----------" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Score " << i + 1 << ":\t\t" << scoresList[i] << endl;
    }
}

void invisibleFruits(int fruitsCoordinates[])
{
    for (int i = 0; i < 30; i += 2)
    {
        if (i < 10)
        {
            if (x == fruitsCoordinates[i] && y == fruitsCoordinates[i + 1])
            {
                score += 10;
                fruitsCoordinates[i] = rand() % width;
                fruitsCoordinates[i+1] = rand() % height;
                nTail++;
            }
        }
        else if (i < 18)
        {
            if (x == fruitsCoordinates[i] && y == fruitsCoordinates[i + 1])
            {
                score += 20;
                fruitsCoordinates[i] = rand() % width;
                fruitsCoordinates[i+1] = rand() % height;
                nTail += 2;
            }
        }
        else if (i < 26)
        {
            if (x == fruitsCoordinates[i] && y == fruitsCoordinates[i + 1])
            {
                score += 30;
                fruitsCoordinates[i] = rand() % width;
                fruitsCoordinates[i + 1] = rand() % height;
                nTail += 3;
            }
        }
        else if (i < 30)
        {
            if (x == fruitsCoordinates[i] && y == fruitsCoordinates[i + 1])
            {
                score += 50;
                fruitsCoordinates[i] = rand() % width;
                fruitsCoordinates[i + 1] = rand() % height;
                nTail += 5;
            }
        }
    }
}