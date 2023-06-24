#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// Создайте класс Circle(окружность).
// Реализуйте через перегруженные операторы:
// 1. Проверка на равенство радиусов двух окружностей(операция ==);
// 2. Сравнения длин двух окружностей(операция <);
// 3. Пропорциональное изменение размеров окружности, путем изменения ее радиуса(операция += и -=);
// 4. Увеличение и уменьшение радиуса окружности на 1 (операции ++ и--, в префиксной и постфиксной формах);

class Circle
{
private:
    double r;
public:
    Circle() :r() {}
    Circle(double R) :r(R) {}

    void SetR(double R)
    {
        if (R > 0) { this->r = R; }
        else { cout << "Ошибка: Радиус равен 0. Не возможно создать круг!!!\n"; }
    }

    double GetR() const { return r; }
    double GetS() const { return M_PI * (r * r); }
    double GetLen() const { return 2 * M_PI * r; }

    // 1. Проверка на равенство радиусов двух окружностей(операция ==);
    bool operator == (const Circle& obj) const
    {
        return this->GetR() == obj.GetR();
    }

    // 2. Сравнения длин двух окружностей(операция <);
    bool operator < (const Circle& obj) const
    {
        return this->GetLen() < obj.GetLen();
    }

    // 3. Пропорциональное изменение размеров окружности, путем изменения ее радиуса(операция += и -=);
    Circle& operator += (double addR)
    {
        this->r += addR;
        return *this;
    }

    Circle& operator -= (double divR)
    {
        this->r -= divR;
        return *this;
    }

    // 4. Увеличение и уменьшение радиуса окружности на 1 (операции ++ и--, в префиксной и постфиксной формах);
    Circle& operator ++ ()
    {
        ++(this->r);
        return *this;
    }
    Circle operator ++ (int)
    {
        Circle temp;
        temp.r = this->r;
        this->r++;
        return temp;
    }

    Circle& operator -- ()
    {
        --(this->r);
        return *this;
    }
    Circle operator -- (int)
    {
        Circle temp;
        temp.r = this->r;
        this->r--;
        return temp;
    }


    // cout, cin
    friend istream& operator>>(istream& is, Circle& obj)
    {
        double t;
        cout << "R = ";
        (is >> t).ignore();
        obj.SetR(t);
        return is;
    }

    friend ostream& operator<<(ostream& os, const Circle& obj)
    {
        os << "R: " << obj.GetR() << endl;
        os << "S: " << obj.GetS() << endl;
        os << "L: " << obj.GetLen() << endl;
        return os;
    }
};

int main()
{
    Circle A;
    Circle B(40);
    cout << "Введите данные для окружности А: \n";
    cin >> A;
    cout << "\nОкружность А:\n" << A << endl;
    cout << "Окружность B:\n" << B << endl;

    cout << "--------------------------------------------------" << endl;
    (A == B) ? cout << "А == B\n" : cout << "A != B\n";
    (A.GetLen() > B.GetLen()) ? cout << "Длина А больше В\n" : ((A.GetLen() < B.GetLen()) ? cout << "Длина В больше А\n" : cout << "Длина В равна длине А\n");

    cout << "--------------------------------------------------" << endl;
    cout << "Операторы += и -=" << endl;
    A += 20;
    cout << "Окружность А (+= 20):\n" << A << endl;
    B -= 20;
    cout << "Окружность B (-= 20):\n" << B << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "Операторы ++" << endl;
    A++;
    cout << "Окружность А (A++):\n" << A << endl;
    ++B;
    cout << "Окружность B (++B):\n" << B << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "Операторы --" << endl;
    A--;
    cout << "Окружность A (A--):\n" << A << endl;
    --B;
    cout << "Окружность B (--B):\n" << B << endl;
}