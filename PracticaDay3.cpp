#include <iostream>
#include <cmath>

using namespace std;

const float g = 9.8;

struct Ball 
{
    float y = 0;
    float time = 0;
    float vy = 0;
    float v = 0;
    float ay = 0;
    float m = 0;

    Ball() {
    }
};

struct TestBall
{
    float y = 25.1;
    float vy = 30;
};

// Моделирование изменения положения шарика за время dt в секундах, шар бросают вертикально в вверх
void move(Ball* ball, float dt) 
{
    ball->y = ball->vy * dt - (g * dt * dt) / 2;
    ball->v = ball->vy - g * dt;
}

// Напечатать на экран параметры полета шарика
void show(Ball ball) 
{
    cout << "Положение шара y = " << ball.y << endl;
    cout << "Скорость шара = " << abs(ball.v) << endl;
}

void TestMove(TestBall* test, float dt)
{
    if (move(test, dt))
        cout << "True";
    else
        cout << "false";
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    Ball b;
    TestBall a;
    float t = 0;
    float deltaT = 1;           // Длительность такта моделирования
    cout << "Задайте начальные условия\n";
    cout << "Скорость v = ";
    cin >> b.vy;
    cout << endl;
    cout << "Масса m = ";
    cin >> b.m;
    cout << endl;
    cout << "Время моделирования t = ";
    cin >> b.time;
    cout << endl;

    while (b.time != t) 
    {
        move(&b, t);         // Сдвинуть шарик за один такт моделирования
        if (b.y < 0)
            exit;
        else
        {
            cout << "Параметры полёта шара за " << t << "-ую секунду: " << endl;
            show(b);
            t = t + deltaT;           // Увеличить счетчик времени
        }
    }
    float time = 1;
    TestMove(&a, time);

    return 0;
}