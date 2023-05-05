#include <bits/stdc++.h>
using namespace std;

int choice;
const int max_specialization = 20;
const int max_patient = 5;

bool status[max_specialization + 1][max_patient];
string names[max_specialization + 1][max_patient];
int currentpatient[max_specialization] = {0};

void AddNewPatient();
void printAllpateints();
void getNextPatient();

void SystemOpen(int choice)
{
    while(true)
    {
        cout << "\n======================" << endl;
        cout << "Enter your Choice: " << endl;
        cout << "1) Add new patient " << endl;
        cout << "2) print all patients " << endl;
        cout << "3) Get next patient" << endl;
        cout << "4) Exit" << endl;
        cout << "======================" << endl;
        cin >> choice;

        if (choice == 1)
        {
            AddNewPatient();
        }
        else if (choice == 2)
        {
            printAllpateints();
        }
        else if (choice == 3)
        {
            getNextPatient();

        }
        else if (choice == 4)
        {
            cout << "Come back again !" << endl;
            break;
        }
        else
        {
            cout << "pls Enter a valid choice" << endl;
            SystemOpen(choice);
        }
    }
}



void AddNewPatient()
{
    cout << "Enter specialization, name, status : " << endl;
    int special;
    bool urgent;
    string name;
    cin >> special >> name >> urgent;

    if (currentpatient[special] == max_patient)
        cout << "Sorry , Queue is Full At this specialization!" << endl;
    else
    {
        if (urgent)
        {
            for(int i = currentpatient[special] - 1; i >= 0; i--)
            {
                names[special][i + 1] = names[special][i];
                status[special][i + 1] = status[special][i];
            }
            names[special][0] = name;
            status[special][0] = urgent;
        }
        else
        {
            names[special][currentpatient[special]] = name;
            status[special][currentpatient[special]] = urgent;
        }
        currentpatient[special]++;
    }
}

void printAllpateints()
{
    int special;
    cout << "Enter the specialization the you want its patients " << endl;
    cin >> special;

    if (currentpatient[special])
    {
        for(int i = 0; i < currentpatient[special]; i++)
            cout << names[special][i] << " " << status[special][i] << endl;
    }
    else
    {
        cout << "No patients in this specialization " << endl;
        cout << "=====================================" << endl;
    }
}

void getNextPatient()
{
    int special;
    cout << "Enter the specialization to get the patient on the waiting list " << endl;
    cin >> special;

    if (currentpatient[special])
    {
        cout << names[special][0] <<" go with the Dr, pls" << endl;
        for(int i = 0; i < currentpatient[special]; i++)
        {
            names[special][i] = names[special][i + 1];
            status[special][i] = status[special][i + 1];
        }

        currentpatient[special]--;
    }
    else
        cout << "No one on the waiting list, take a rest Dr." << endl;
}

int main()
{
    SystemOpen(choice);
    return 0;
}
