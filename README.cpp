#include <iostream>
#include <array>
#include <string>

class User
{
public:
    std::string name;
    int age;

     User(std::string n, int a)
    {
        name = n;
        age = a;
    }
    User ()
    {
    }
};

std::array<User, 100> users;

enum OPTIONS
{
    ADD = 1,
    FETCH,
    EXIT
};

void printMenu()
{
    std::cout << "1. Add Record" << "\n";
    std::cout << "2. Fetch Record" << "\n";
    std::cout << "3. Exit " << "\n";
}

size_t getOption()
{
    std::cout << "Enter option: ";
    int op;
    std::cin >> op;
    return op;
}

std::string getUsername()
{
    std::cout << "Enter Name: ";
    std::string name;
    std::cin >> name;
    return name;
}

size_t getAge()
{
    std::cout << "Enter age: ";
    int age;
    std::cin >> age;

    if (age < 1 || age > 170)
    {
        std::cout << "Invalid age:";
    }
    return age;
}


size_t getID()
{
    std::cout << "Enter ID: ";
    int id;
    std::cin >> id;
    if(id < 0 || id > users.size())
    {std::cout << "Invalid ID \n";}
    return id;
}

void addRecord(std::string name, int age)
{
    static size_t id = 1;
    if (id < users.size())
    {
        User new_user{name,age};
        users.at(id) = new_user;
        id++;
        std::cout << "name: " << name << ", age = " << age << "\n";
    }
    else
    {
        std::cout << "Full Users\n";
    }
}

void fetchRecord(int ID)
{
    if (ID >= 0 && ID < users.size() && !users.at(ID).name.empty())
    {
        std::cout << "User ID: " << ID << "\nname : " << users.at(ID).name << ", age = " << users.at(ID).age << "\n";
    }
    else
    {
        std::cout << "User not found.\n";
    }
}

int main()
{
    bool isRunning = true;
    while (isRunning)
    {
        printMenu();

        int op = getOption();

        switch (static_cast<OPTIONS>(op))
        {
        case OPTIONS::ADD:
        {
            std::string name = getUsername();
            size_t age = getAge();
            addRecord(name, age);
        }
        break;
        case OPTIONS::FETCH:
        {
            size_t id = getID();
            fetchRecord(id);
        }
        break;
        case OPTIONS::EXIT:
            isRunning = false;
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    }
    return 0;
}
