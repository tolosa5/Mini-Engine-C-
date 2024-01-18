
/*
- Macro
- Template (genericos)

const protege el valor para solo pillar

---------------------------

Diferencias entre struct y class:
1. structs son de c y class de c++

2. todas las propiedades, por defecto, de los structs son publicas 
    y las de las clases privadas

----------------------------

*/

#include <iostream>
using namespace std;


#define PRINT(x) cout << x << endl;


//declarar un template
template<class T>
T ConvertFromFloat(float number)
{
    return static_cast<T> number;
}


struct FEmployee
{
    enum class EDepartment
    {
        Gameplay,
        Design,
        Artist,
        NONE
    };

    int age;
    int id;
    float height;
    EDepartment department = EDepartment:: NONE;

    FEmployee()
    {
        age = 25;
    }

    FEmployee(int newAge): id(0), department(EDepartment::Artist) //para asignar cosas desde fuera
    {
        age = newAge;
        id = 1;
    }

    FEmployee(int newAge, EDepartment department): id(0)
    {
        age = newAge;
        this->department = department;
    }

    int SumAgeID()
    {
        return age + id;
    }
    
    //sobrecarga de >, modificar el operador, indispensable el "operator"
    bool operator>(FEmployee inEmp)
    {
        return this->age > inEmp.age;
    }
    
};

struct FClient
{
    int age;
    float spendt;


    FClient(int _age) : age(_age), spendt(0) {};

    bool operator>(FClient& inClient)
    {
        return age > inClient.age;
    }
};

class GeometryForm
{

public:
    
    //constructores siempre publicos, sino no se puede instanciar
    GeometryForm() : id(9), numOfVertex(0), vertexSize(0) {}; //constructor base
    GeometryForm(int _id) : id(_id), numOfVertex(0), vertexSize(0) {};
    
    virtual float GetArea() = 0; //el = 0 hace abstracta la clase
    float GetArea()
    {
        numOfVertex * vertexSize;
    }

    int GetId(){return id;}
    int GetNumOfVertex(){return numOfVertex;}
    float GetVertexSize(){return vertexSize;}

private:

    int id;

protected:

    int numOfVertex;
    float vertexSize = 0;

};

class Triangle : public GeometryForm //lo que podemos ver del padre
{

public:

    Triangle() : GeometryForm() //esto llama al constructor base de su clase base
    {
        numOfVertex = 3;
    }
/*
    float GetArea() override
    {
        return 0;
    }
*/

private:


};

template <class myType>
myType GetOlder(myType e1, myType e2)
{
    /*
    if (e1.age > e2.age)
        return e1;
        
    else return e2;
    */
    return (e1 > e2) ? e1 : e2;
}

void SumAgeToEmployee(FEmployee* e, FClient* c)
{
    e->age += c->age;
}

void main()
{
    //Triangle tri;

    /*
    FEmployee emp1 = new FEmployee(1, FEmployee::EDepartment::Gameplay);
    FEmployee emp2 = new FEmployee(2, FEmployee::EDepartment::Gameplay);

    const FEmployee oldEmp = GetOlder(emp1, emp2);

    FClient c1 = { 5, 654.9f };
    FClient C1 = new FClient(50);
    */
    
    /*
    //pointers
    FEmployee* e1 = new FEmployee();
    FClient* c1 = new FClient(50);
    //reference
    FEmployee& e2 = *e1;
    e1->age = 3;

    SumAgeToEmployee(e1, c1);
    PRINT(SumAgeToEmployee);

    return;
    */
    
    /*
    PrintPrimaryColors();

    //PUNTEROS
    float* f1 = new float (1.0f);
    float* f2 = f1;
    f1 = new float (3.0f);
    f1 = new float (5.0f);
    delete f1; //borrar espacio de memoria que ocupa f1

    //f3 referencia al valor que hay en el espacio de memoria que ocupa f1
    float& f3 = *f1;
    f1 = new float(5.0f);

    //adjudicar a pName el espacio que ocupa la variable
    string name;
    string *pName = &name;

    //llamar a una funcion con template
    float f = 2.0f;
    char c = ConvertFromFloat<char>(f);

    int a = 1, b = 3;
    int sum = Sum(a, b);

    int c = 4, d = 5;
    bool isEqual;

    char num = sum + 97; //de numero a letra minuscula siguiendo la tabla ascii

    Color myColor = Color::Red;

    cout << sum;
    */
    
}

int Sum(int a, int b)
{
    return a + b;
}

int Equal(int a, int b)
{
    return a == b;
}

enum class Color
{
    FIRST = -1,
    Green, //se les puede meter indices, el primero indica los demás
    Blue,
    Red,
    Black,
    Yellow,
    COUNT
};

bool IsPrimaryColor(Color color)
{
    switch (color)
    {
    case Color::Red:
    case Color::Green:
    case Color::Blue:
        return true;
        break;
    }
    return false;
}

void PrintPrimaryColors()
{
    Color myColor;
    for (int i = 0; i < static_cast <int>(Color::COUNT); i++)
    {
        Color curColor = static_cast<Color>(i);
        //bool isPrimary = IsPrimaryColor(curColor);

        if (bool isPrimary = IsPrimaryColor(curColor))
        {
            if (isPrimary)
            {
                cout << "Primary" << endl;
            }
            
            switch (curColor)
            {
            case Color::Red:
            PRINT("RED")
                break;
            case Color::Green:
            PRINT("GREEN")
                break;
            case Color::Blue:
            PRINT("BLUE")
                break;
            }
        }
        
    }
}
