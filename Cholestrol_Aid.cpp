#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inputFile("infile.txt");
string line, line1;
int main()
{
    int num_of_patients;
    string patient_name;
    string HDL,LDL,systolic,diastolic;
    string num_of_sets;

    cin >> num_of_patients;
    if (inputFile)
    {
        for (int i = 0; i < num_of_patients; i++)
        {
            getline(inputFile,patient_name,' ');
            inputFile.ignore(2,' ');
            getline(inputFile,num_of_sets);
            cout << "The patient's name is " << patient_name << endl;
            cout << "The patient has " << num_of_sets << " sets of readings" << endl;
            for (int j = 1; j <= stoi(num_of_sets); j++)
            {
                getline(inputFile,HDL,' ');
                getline(inputFile,LDL,' ');
                getline(inputFile,systolic,' ');
                getline(inputFile,diastolic,'\n');

                cout << "Data Set " << j << endl;
                cout << "This patient's HDL is " << HDL << endl;
                cout << "This patient's LDL is " << LDL << endl;
                cout << "This patient's systolic is " << systolic << endl;
                cout << "This patient's diastolic is " << diastolic << endl;
                cout << "\n";
            }
        }
    }
        
    inputFile.close();
    return 0;
}