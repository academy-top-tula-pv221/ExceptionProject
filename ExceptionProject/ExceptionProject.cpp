#include <iostream>
#include <string>

using namespace std;

class Exception
{
    string message;
public:
    Exception(string message = "error") : message{ message } {}
    virtual string Message()
    {
        return message;
    }

};

class RangeException : public Exception
{
public:
    RangeException() : Exception("Out of range") {};
};


class FileException : public Exception
{
    int code;
public:
    FileException(string message = "File error", int code = 0)
        : Exception(message), code{ code } {}
    string Message() override
    {
        return to_string(code) + " " + Exception::Message();
    }
};

double Div(double a, double b)
{
    if (b == 0)
        throw new Exception("Divide by zero");
    return a / b;
}

void Func(double a)
{
    if (a == 10)
        throw new FileException();
}

int main()
{
    double x, y;
    cout << "input numbers: ";
    cin >> x >> y;
    double z;
    try
    {
        Func(x);
        z = Div(x, y);
    }
    catch (Exception*& ex)
    {
        cout << ex->Message() << "\n";
        
        z = 0;
    }
    
    cout << z;
}
