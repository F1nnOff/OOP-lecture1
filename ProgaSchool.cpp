#include <iostream>
#include <string>
#include <vector>
// Создам структуру, хочу посмосмотреть на жизнь переменных
// Это не просто набор полей под одним именем
// Появляются функции внутри
// Нетривиальная логика оброботки полей
struct Student {

};

//по умолчанию private
class Child {
public:
    std::string Name, Surname;
    double AvarageMark = 0.0; //  Примитивный тип -> инициализируем

    // Хитрая функция, которая работает при создании объекта
    Child() {
        std::cout << "A new object was born!\n";
    }
    // Ничего не возвращают
    ~Child() {
        std::cout << "Object is died\n";
    }
};

void Test (const Child& a, int test) {
    std::cout << "Child " << a.Name << " participates in test " << test << "\n";
}

int main() {
    Child a;
    a.Name = "Petya";
    a.Surname = "Gerasimov";
    a.AvarageMark = 5.0;
    Test(a, 2);
    //a.Test(2);
    // объект живет до конца блока(компилятор зовет деструктор)
    // если не прописать, то вызовется тривиальный
    // все это для освобождения памяти
}

// хотим вызывать функцию от метода
void Test (int test) const {
    std::cout << "Child" << Name << " participates in test " << test << "\n";
}
// хотим создавать объект сразу с инициилизацией
Child a("Petya", "Gerasimov", 5.0);
// исправим конструктор

Child(
        const string& name,
        const string& surname,
        double avaregemark = 0.0
) {
    Name = name;
    Surname = surname;
    AvarageMark = avaragemark;
    std::cout << "A new object was born!\n";
}
//это сработает, но создасться всеравно путым и перезапишиться
//более правильно :
Child(
        const string& name,
        const string& surname,
        double avaregemark = 0.0
)
        : Name(name)
        , Surname(surname)
        , AvarageMark(avaragemark)
{
    std::cout << "A new object was born!\n";
}