#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inputFile("infile.txt"); //Initialization of input file stream object that would be read from for this program

//Initialization of Variables
int num_of_patients; // Stores the number of patients to be evaluated
string patient_name; // Stores a given patient's name
string value1,value2,value3,value4; //Stores the values read from the data sets for a given patient
int HDL,LDL,systolic,diastolic; //Stores the numerical value of the read values from the data sets for a given patient
string num_of_sets; //Stores the number of data sets for a given patient

//Prototypes for Functions

float HDL_LDL_ratio(int HLevels, int Llevels);
void evaluate_cholesterol(int HLevels, int Llevels, string &placeholder1, string &placeholder2);
void evaluate_blood_pressure(int syst, int dias, string &placeholder1, string &placeholder2);

int main()
{
    cout << "Enter the number of patient records: ";
    cin >> num_of_patients; // Asks user for the number of patient records to be evaluated

    if (inputFile) //Checks to see whether the input file object is open and ready to be read from
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
                getline(inputFile,value1,' '); //Reads the HDL value for a given set of readings
                getline(inputFile,value2,' '); //Reads the LDL value for a given set of readings
                getline(inputFile,value3,' '); //Reads the systolic value for a given set of readings
                getline(inputFile,value4,'\n'); //Reads the diastolic value for a given set of readings

                //The variables that were read to from the value are reassigned to new variables with more appropriate data types, rather than string.
                HDL = stoi(value1); //The first value read represents the HDL value
                LDL = stoi(value2); //The second value read represents the LDL value
                systolic = stoi(value3); //The third value read represents the systolic value
                diastolic = stoi(value4); //The fourth value read represents the diastolic value

                cout << "DATA SET " << j << endl; //Prints to screen the current data set being evaluated

                //TODO: Replace the below with the function calls for evaluation and interpretation of values
                //      because the below was only used to test that the values were being read properly
                cout << "This patient's HDL is " << HDL << endl;
                cout << "This patient's LDL is " << LDL << endl;
                cout << HDL_LDL_ratio(HDL,LDL) << " - This is the HDL to LDL ratio" << endl; //TODO: Remove function call, as this was only called to act as a functin stub for the HDL_LDL_ratio() function
                cout << "This patient's systolic is " << systolic << endl;
                cout << "This patient's diastolic is " << diastolic << endl;
                cout << "\n";
            }
        }
        inputFile.close();
    }
    else //If input file object is in a fail state, it runs to an error, and prints to the screen that an erro was encountered
    {
        cout << "Ran into an error in attempting to read from the input file. Check that the input file exists." << endl;
    }
        //Testing out SSH keys with GitHub
    return 0;
}

/**
 * This function calculates the HDl to LDL ratio,
 * as well as print to the screen the interpretations of their values
 * 
 * @author Chase Adams
 * @param HLevels HDL reading for a given patient
 * @param Llevels LDL reading for a given patient
 * @version 1.0
 */
float HDL_LDL_ratio(int HLevels, int Llevels)
{
    float ratio = float(HLevels)/float(Llevels); //intialzing ratio variable and setting it equal to the ratio HDL/LDL
    if (ratio <= 0.3){
        cout << "This ratio is not good." << endl; //ratio is considered "not good" if it is less than or equal to 0.3
    } 
    else if (ratio > 0.3){
        cout << "This ratio is good." << endl; //ratio is considered "good" if it is greater than 0.3
    }
    return ratio; //return ratio (function requires a return data type of float)
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
void evaluate_cholesterol(int HLevels, int Llevels, string &placeholder1, string &placeholder2)
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
void evaluate_blood_pressure(int syst, int dias, string &placeholder1, string &placeholder2)
{

}
