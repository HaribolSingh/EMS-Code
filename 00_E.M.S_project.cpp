#include <iostream>
#include <windows.h> // for using sleep function
using namespace std;
string username;
string password;
class employee
{
public:
    string id, address, name;
    string contact_no, salary;
};
employee em[1000];
int total_employee = 0;

void indata();
void show();
void search();
void update();
void delete_d();
void login();
void menu()
{
    cout << "1. press 1 to enter data " << endl;
    cout << "2. press 2 to enter show data " << endl;
    cout << "3. press 3 to enter search data " << endl;
    cout << "4. press 4 to enter update data " << endl;
    cout << "5. press 5 to enter delete data " << endl;
    cout << "6. press 6 to enter exit " << endl;
    int key;
    cout << "press any key..." << endl;
    cin >> key;
    switch (key)
    {
    case 1:
        indata();
        break;
    case 2:
        show();
        break;
    case 3:
        search();
        break;
    case 4:
        update();
        break;
    case 5:
        delete_d();
        break;
    case 6:
        cout << "please login again " << endl;
        login();
    }
}
void indata()
{
    int choice;
    cout << "enter no. of employees that you want to store data" << endl;
    cin >> choice;
    for (int i = total_employee; i < total_employee + choice; i++)
    {
        cout << "enter data of employee " << i + 1 << endl;
        cout << "enter employee id :";
        cin >> em[i].id;
        cout << "enter employee name :";
        cin >> em[i].name;
        cout << "enter employee contact no. :";
        cin >> em[i].contact_no;
        cout << "enter employee salary :";
        cin >> em[i].salary;
        cout << "enter employee address :";
        cin >> em[i].address;
    }
    total_employee += choice;
    menu();
}
void show()
{
    if (total_employee != 0)
    {
        for (int i = 0; i < total_employee; i++)
        {
            cout << "data of employee :" << i + 1 << endl;
            cout << "employee id :" << em[i].id << endl;
            cout << "ermployee name :" << em[i].name << endl;
            cout << "employee salary :" << em[i].salary << endl;
            cout << "employee address :" << em[i].address << endl;
            cout << "employee contact no :" << em[i].contact_no << endl;
        }
    }
    else
    {
        cout << "no record found. your record is empty.!!" << endl;
    }
    menu();
}
void search()
{
    if (total_employee != 0)
    {
        string id;
        cout << "enter id of the employee you want to search:";
        cin >> id;
        for (int i = 0; i < total_employee; i++)
        {
            if (em[i].id == id)
            {
                cout << "data of employee :" << i + 1 << endl;
                cout << "employee id :" << em[i].id << endl;
                cout << "ermployee name :" << em[i].name << endl;
                cout << "employee salary :" << em[i].salary << endl;
                cout << "employee address :" << em[i].address << endl;
                cout << "employee contact no :" << em[i].contact_no << endl;
            }
            break;
            if (i == total_employee - 1)
            {
                cout << "no such record found " << endl;
            }
        }
    }
    else
    {
        cout << "no record found. your record is empty.!!" << endl;
    }
    menu();
}
void update()
{
    if (total_employee != 0)
    {
        string id;
        cout << "enter id you want to update :";
        cin >> id;
        for (int i = 0; i < total_employee; i++)
        {
            if (id == em[i].id)
            {
                cout << "previous data of employee :" << i + 1 << endl;
                cout << "employee id :" << em[i].id << endl;
                cout << "ermployee name :" << em[i].name << endl;
                cout << "employee salary :" << em[i].salary << endl;
                cout << "employee address :" << em[i].address << endl;
                cout << "employee contact no :" << em[i].contact_no << endl;
                cout << "**enter new data :**" << endl;
                cout << "enter employee id :";
                cin >> em[i].id;
                cout << "enter employee name :";
                cin >> em[i].name;
                cout << "enter employee contact no. :";
                cin >> em[i].contact_no;
                cout << "enter employee salary :";
                cin >> em[i].salary;
                cout << "enter employee address :";
                cin >> em[i].address;
            }
            break;
            if (i == total_employee - 1)
            {
                cout << "no such record found " << endl;
            }
        }
    }
    else
    {
        cout << "your record id empty." << endl;
    }
    menu();
}
void delete_d()
{
    if (total_employee != 0)
    {
        int option;
        cout << "1. delete full record :" << endl;
        cout << "2. delete specific employee record :" << endl;
        cout << "choose option :";
        cin >> option;
        if (option == 1)
        {
            total_employee = 0;
            cout << "all record is deleted !!" << endl;
        }
        else if (option == 2)
        {
            string id;
            cout << "enter id you want to delete :";
            cin >> id;
            for (int i = 0; i < total_employee; i++)
            {
                if (em[i].id == id)
                {
                    for (int j = i; j < total_employee; j++)
                    {
                        em[j].address = em[j + 1].address;
                        em[j].contact_no = em[j + 1].contact_no;
                        em[j].id = em[j + 1].id;
                        em[j].name = em[j + 1].name;
                        em[j].salary = em[j + 1].salary;
                    }
                    total_employee--;
                    cout << "data deleted." << endl;
                    break;
                }
                else
                {
                    cout << "no such record found " << endl;
                }
            }
        }
    }
    else
    {
        cout << "your record is empty." << endl;
    }
    menu();
}
void login()
{
    cout << "****EMPLOYEE MANAGEMENT SYSTEM****" << endl;
    cout << "****login*******" << endl;
    string username1, password1;
    cout << "username: ";
    cin >> username1;
    cout << "password: ";
    cin >> password1;
    if (username1 == username && password1 == password)
    {
        cout << "login successfull !!" << endl;
    }
    else
    {
        cout << "check your credentials" << endl;
        // system("CLS");
        login();
    }
}

int main()
{
    cout << "****EMPLOYEE MANAGEMENT SYSTEM****" << endl;
    cout << "****sign up****" << endl;
    cout << "enter user name: ";
    cin >> username;
    cout << "enter your password: ";
    cin >> password;
    cout << "your data is being processed.";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(1000);
    }
    cout << endl;
    cout << "your id is created !!!!!!!!" << endl;
    // system("cls");
    login();
    menu();

    return 0;
}