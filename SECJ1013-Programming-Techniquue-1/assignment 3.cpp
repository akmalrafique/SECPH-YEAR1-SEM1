#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void getInput(char[][10], int[], int[], int[]);
int caltotal(int[], int);
int getLowest(int[], int);
int getHighest(int[], int);

int main (){
    const int SIZE = 20;
    char uniName [SIZE][10];
    int numIntake[SIZE], numEnrolemnt[SIZE], numOutput[SIZE];
    int totalIntake, totalEnrolemnt, totalOutput;
    double averageIntake, averageEnrolemnt, averageOutput;
    int lowestIntake, lowestEnrolemnt, lowestOutput;
    int highestIntake, highestEnrolemnt, highestOutput;
    int rangeIntake, rangeEnrolemnt, rangeOutput;
    ifstream infile("input1.txt");
    ofstream outfile("output.txt");
    getInput(uniName, numIntake, numEnrolemnt, numOutput);
    outfile <<"\t NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT" << endl;
    outfile <<"\t \t IN PUBLIC UNIVERSITIES (2015)" << endl;
    outfile << "-------------------------------------------------------------" << endl;
    outfile << left << setw(15) << "UNIVERSITY" << right << setw(10) << "INTAKE" << setw(15) << "ENROLMENT" << setw(12) << "OUTPUT" << endl;
    outfile << "-------------------------------------------------------------" << endl;
    
    for (int i = 0; i < SIZE; i++){
        outfile << left << setw(15) << uniName[i] << right << setw(10) << numIntake[i] << setw(15) << numEnrolemnt[i] << setw(12) << numOutput[i] << endl;
    }
    
    outfile << "-------------------------------------------------------------" << endl;
    totalIntake = caltotal (numIntake, SIZE);
    totalEnrolemnt = caltotal (numEnrolemnt, SIZE);
    totalOutput = caltotal (numOutput, SIZE);
    averageIntake = (double)totalIntake / SIZE;
    averageEnrolemnt = (double)totalEnrolemnt / SIZE;
    averageOutput = (double)totalOutput / SIZE;
    
    outfile << left << setw(15) <<"total" << right << setw(10) << totalIntake << setw(15) << totalEnrolemnt << setw(12) << totalOutput << endl;
    outfile << fixed << setprecision(2);
    outfile << left << setw(15) <<"average" << right << setw(10) << averageIntake << setw(15) << averageEnrolemnt << setw(12) << averageOutput << endl;
    outfile << "-------------------------------------------------------------" << endl;
    outfile << endl; 
    
    lowestIntake = getLowest(numIntake, SIZE);
    outfile << left << setw(45) << "THE LOWEST NUMBER OF STUDENTS' INTAKE" << "= " << numIntake[lowestIntake] << " (" << uniName[lowestIntake] << ")" << endl;
    lowestEnrolemnt = getLowest(numEnrolemnt, SIZE);
    outfile << left << setw(45) << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT" << "= " << numEnrolemnt[lowestEnrolemnt] << " (" << uniName[lowestEnrolemnt] << ")" << endl;  
    lowestOutput = getLowest(numOutput, SIZE);
    outfile << left << setw(45) << "THE LOWEST NUMBER OF STUDENTS' OUTPUT" << "= " << numOutput[lowestOutput] << " (" << uniName[lowestOutput] << ")" << endl;   
    outfile << endl; 
    
    highestIntake = getHighest(numIntake, SIZE);
    outfile << left << setw(45) << "THE HIGHEST NUMBER OF STUDENTS' INTAKE" << "= " << numIntake[highestIntake] << " (" << uniName[highestIntake] << ")" << endl;    
    highestEnrolemnt = getHighest(numEnrolemnt, SIZE);
    outfile << left << setw(45) << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT" << "= " << numEnrolemnt[highestEnrolemnt] << " (" << uniName[highestEnrolemnt] << ")" << endl;   
    highestOutput = getHighest(numOutput, SIZE);
    outfile << left << setw(45) << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT" << "= " << numOutput[highestOutput] << " (" << uniName[highestOutput] << ")" << endl;  
    outfile << endl;
	 
    rangeIntake = numIntake[highestIntake] - numIntake[lowestIntake];
    outfile << left << setw(45) << "THE RANGE OF NUMBER OF STUDENTS' INTAKE" << "= " << rangeIntake << endl;
    rangeEnrolemnt = numEnrolemnt[highestEnrolemnt] - numEnrolemnt[lowestEnrolemnt];
    outfile << left << setw(45) << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT" << "= " << rangeEnrolemnt << endl;
    rangeOutput = numOutput[highestOutput] - numOutput[lowestOutput];
    outfile << left << setw(45) << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT" << "= " << rangeOutput << endl;
    outfile << endl;
    outfile << "-------------------------------------------------------------" <<endl;
    infile.close();
    outfile.close();
    return 0;
}

void getInput(char nameUni[][10] , int intake[] , int enrol[] , int output[]){
    int i= 0;
    ifstream infile("input1.txt");
    if (!infile){
        cout << "Error opening file" << endl;
        return;
    }
    while (i < 20 && infile >> nameUni[i] >> intake[i] >> enrol[i] >> output[i]){
        i++;
    }
}

int caltotal(int arr[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += arr[i];
    }
    return total;
}

int getLowest(int arr[], int size){
    int lowestIndex = 0; 
    for (int i = 1; i < size; i++){
        if (arr[i] < arr[lowestIndex]){
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

int getHighest(int arr[], int size){
    int highestIndex = 0; 
    for (int i = 1; i < size; i++){
        if (arr[i] > arr[highestIndex]){
            highestIndex = i;
        }
    }
    return highestIndex;
}
