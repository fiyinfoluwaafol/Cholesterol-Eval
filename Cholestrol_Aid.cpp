#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inputFile("infile.txt");
string line, line1;
int main()
{
    int num_of_patients; 
    char num_of_sets;
    cin >> num_of_patients;
    //for (int i = 1; i <= num_of_patients; i++)
    //{
        if (inputFile.is_open())
        {
            while (getline(inputFile,line))
            {
                
                if (isalpha(line[0]))
                {
                    num_of_sets = line.at((line.length()-1));
                    //cout << num_of_sets << endl;
                    for (int i = 1; i <= num_of_sets; i++)
                    {
                        getline(inputFile,line1);
                        if (isalpha(line1[0]))
                        {
                            cout << "BREAKING POINT" << endl;
                            continue;
                        }
                        cout << line1 << endl;
                    }
                }
                
            }
        }
        inputFile.close();

    //}
    return 0;
}