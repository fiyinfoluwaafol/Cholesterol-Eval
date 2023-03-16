#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
    cout << "\n" << endl;
    if (inputFile) //Checks to see whether the input file object is open and ready to be read from
    {
        //Outer loop iterates through each patient's records, so that it can read their names and their set(s) of readings accordingly from the file
        for (int i = 0; i < num_of_patients; i++)
        {
            getline(inputFile,patient_name,' '); //For each iteration of the outer loop, it reads patient's name from the file
            inputFile.ignore(2,' '); //Ignores everything between Patient's name and the number of sets of readings for that patient
            getline(inputFile,num_of_sets); //For each iteration of the outer loop, it reads the number of sets of readings for that patient

            cout << "Current Patient's Name- " << patient_name << "\n" << endl;
            
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

                //Calls the functions that carry out the actual evaluation of the data read from the input file
                evaluate_cholesterol(HDL,LDL,value1,value2);
                evaluate_blood_pressure(systolic,diastolic,value3,value4);
                cout << "\n\n";
            }
        }
        inputFile.close();
    }
    else //If input file object is in a fail state, it runs to an error, and prints to the screen that an error was encountered
    {
        cout << "Ran into an error in attempting to read from the input file. Check that the input file exists." << endl;
    }
        
    return 0;
}

/**
 * This function calculates the HDl to LDL ratio,
 * as well as print to the screen the interpretations of their values
 * 
 * @author Anverly Jones
 * @param HLevels HDL reading for a given patient
 * @param Llevels LDL reading for a given patient
 * @version 1.0
 */
float HDL_LDL_ratio(int HLevels, int Llevels)
{
    float ratio = float(HLevels)/float(Llevels); //intialzing ratio variable and setting it equal to the ratio HDL/LDL
    return ratio; //return ratio (function requires a return data type of float)
}

/**
 * This function evaluates the information relating to the cholesterol of a patient, such as
 * their HDL and LDL values to give the interpretation of those values.
 * 
 * @author Chase Adams
 * @param HLevels HDL reading for a given patient -> Refers to the integer casted value of value1
 * @param Llevels LDL reading for a given patient -> Refers to the integer casted value of value2
 * @param string_HDL HDL value read directly from the file -> Refers to the variable value1
 * @param string_LDL LDL value read directly from the file -> Refers to the variable value2
 * @version 1.0
 */
void evaluate_cholesterol(int HLevels, int Llevels, string& string_HDL, string& string_LDL)
{
    cout << "Cholesterol Profile" << endl;
    cout << "  HDL: " + string_HDL + " LDL: " + string_LDL << endl; //printing to the screen the patient's HDL and LDL levels using the string pointers
    float H_L_ratio = HDL_LDL_ratio(HLevels,Llevels);
    cout << "  Ratio: " << fixed << setprecision(4) << HDL_LDL_ratio(HLevels,Llevels) << endl;
    
  if (HLevels < 1)
  {
    cout << "  LDL is very low - Do you want to double-check the data?" << endl; //checking if patient data was wrong (unexpected number)
  }  
  else if (HLevels < 40) 
  {  
    cout << "  HDL is too low" << endl; //HDL is too low if it is below 40
  }
  else if (HLevels < 60)
  {
    cout << "  HDL is Okay" << endl; //HDL is okay if it is below 60
  }
  else 
  {
    cout << "  HDL is Excellent" << endl; //HDL is excellent if it is at or above 60
  }
    
   
   
  
  if (Llevels < 1)
  {
    cout << "  LDL is very low - Do you want to double-check the data?" << endl;  //checking if patient data was wrong (unexpected number)
  }  
  else if (Llevels < 100 ) 
  {  
    cout << "  LDL is Optimal" << endl; //LDL is opitmal if it is below 100
  }
  else if (Llevels < 130) 
  {
    cout << "  LDL is Near Optimal" << endl; //LDL is near optimal if it is below 130
  }
  else if (Llevels < 160) 
  {
    cout << "  LDL is Boderline High" << endl; //LDL is borderline high if it is below 160
  }
  else if (Llevels < 190) 
  {
    cout << "  LDL is High" << endl; //LDL is high if it is below 190
  }
  else 
  {
    cout << "  LDL is Very High" << endl; //LDL is very high if it is at or above 190
  }
  
  
  if (H_L_ratio <= 0.3) {
        cout << "  Ratio of HDL to LDL is not good" << endl; //ratio is considered "not good" if it is less than or equal to 0.3
    } 
    else if (H_L_ratio > 0.3){
        cout << "  Ratio of HDL to LDL is good" << endl; //ratio is considered "good" if it is greater than 0.3
    }
    
    
    
}

/**
 * This function evaluates the information relating to the blood pressure of a patient, such as
 * their systolic and diastolic values to give the interpretation of those values.
 * 
 * @author Tatianna Davis
 * @param syst systolic reading for a given patient -> Refers to the integer casted value of value3
 * @param dias diastolic reading for a given patient -> Refers to the integer casted value of value4
 * @param string_syst Systolic value read directly from the file -> Refers to the variable value3
 * @param string_dias Diastolic value read directly from the file -> Refers to the variable value4
 * @version 1.0
 */
void evaluate_blood_pressure(int syst, int dias, string& string_syst, string& string_dias)
{
    cout << "Blood Pressure Profile" << endl;
    cout << "  Systolic: " + string_syst + " Diastolic: " + string_dias << endl;//This was what I proposed earlier
  if (syst < 120){
    cout << "  Systolic reading is Optimal" << endl; //blood pressure is "optimal" if systolic value is below 120
  }
  else if (syst < 130){
    cout << "  Systolic reading is Normal" << endl; //"normal" if systolic is below 130
  }
  else if (syst < 140){
    cout << "  Systolic reading is Normal high" << endl; //"normal high" if systolic is below 140
  }
  else if (syst < 160){
    cout << "  Systolic reading is Stage 1 hypertension" << endl; //"stage 1 hypertension" if systolic is below 160
  }
  else if (syst < 180){
    cout << "  Systolic reading is Stage 2 hypertension" << endl; //"stage 2 hypertension" if systolic is below 180
  }
  else {
    cout << "  Systolic reading is Stage 3 hypertenstion" << endl; //if systolic is greater than or equal to 180, "stage 3 hypertenstion"
  }

   
   

  if (dias < 80){
    cout << "  Diastolic reading is Optimal" << endl; //Diastolic is "optimal" if it is below 80
  }
  else if (dias < 85){
    cout << "  Diastolic reading is Normal" << endl; //Diastolic is "normal" if it is below 85
  }
  else if (dias < 90){
    cout << "  Diastolic reading is High normal" << endl; //Diastolic is "High normal" if it is below 90
  }
  else if (dias < 100){
    cout << "  Diastolic reading is Stage 1 hypertension" << endl; //Diastolic is "stage 1 hypertension" if it is below 100
  }
  else if (dias < 110){
    cout << "  Diastolic reading is Stage 2 hypertension" << endl; //Diastolic is "stage 2 hypertension" if it is below 110
  }
  else {
    cout << "  Diastolic reading is Stage 3 hypertenstion" << endl; //Diastolic is "stage 3 hypertension" if it is above or equal to 110
  }
}