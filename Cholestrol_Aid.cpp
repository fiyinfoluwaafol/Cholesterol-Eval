#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Initialization of Variables
ifstream inputFile("infile.txt");
int num_of_patients;
string patient_name;
string HDL,LDL,systolic,diastolic;
string num_of_sets;

//Prototypes for Functions
float HDL_LDL_ratio(int HLevels, int Llevels);
void evaluate_cholesterol(int HLevels, int Llevels, string& placeholder1, string& placeholder2);
void evaluate_blood_pressure(int syst, int dias, string& placeholder1, string& placeholder2);

int main()
{
    cout << "Enter the number of patient records: ";
    cin >> num_of_patients; // Asks user for the number of patient records to be evaluated

    if (inputFile)
    {
        //Outer loop iterates through each patient's records, so that it can read their names and their set(s) of readings accordingly from the file
        for (int i = 0; i < num_of_patients; i++)
        {
            getline(inputFile,patient_name,' '); //For each iteration of the outer loop, it reads patient's name from the file
            inputFile.ignore(2,' '); //Ignores everything between Patient's name and the number of sets of readings for that patient
            cout << "\n------------------------------\n\n";
            getline(inputFile,num_of_sets); //For each iteration of the outer loop, it reads the number of sets of readings for that patient
            cout << "Current Patient's Name- " << patient_name << endl;
            
            //Inner loop below, iterates through each line of sets of readings for a patient; so that it reads the HDL, LDL, systolic and diastolic values for each set.
            for (int j = 1; j <= stoi(num_of_sets); j++) //Used stoi() because num_of_sets is stored as a string but its integer value is needed at this point
            {
                getline(inputFile,HDL,' '); //Reads the HDL value for a given set of readings
                getline(inputFile,LDL,' '); //Reads the LDL value for a given set of readings
                getline(inputFile,systolic,' '); //Reads the systolic value for a given set of readings
                getline(inputFile,diastolic,'\n'); //Reads the diastolic value for a given set of readings

                cout << "DATA SET " << j << endl; //Prints to screen the current data set being evaluated

                //TODO: Replace the below with the function calls for evaluation and interpretation of values
                //      because the below was only used to test that the values were being read properly
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

/**
 * This function does
 * 
 * @author FirstName LastName
 * @param HLevels parameter description
 * @param Llevels parameter description
 * @version 1.0
 */
float HDL_LDL_ratio(int HLevels, int Llevels)
{
    return 0;
}

/**
 * This function does
 * 
 * @author FirstName LastName
 * @param HLevels parameter description
 * @param Llevels parameter description
 * @param placeholder1 parameter description
 * @param placeholder2 parameter description
 * @version 1.0
 */
void evaluate_cholesterol(int HLevels, int Llevels, string& placeholder1, string& placeholder2)
{

}

/**
 * This function does
 * 
 * @author FirstName LastName
 * @param syst parameter description
 * @param dias parameter description
 * @param placeholder1 parameter description
 * @param placeholder2 parameter description
 * @version 1.0
 */
void evaluate_blood_pressure(int syst, int dias, string& placeholder1, string& placeholder2)
{

}