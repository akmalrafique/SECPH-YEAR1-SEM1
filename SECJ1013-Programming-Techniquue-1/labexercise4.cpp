//NAME:AKMAL RAFIQUE BIN AHMAD RAPHAIE.
//matrics number:A25CS0181.
//date:9/1/26
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int readFile(float Tempf[],int size);
void computeC(float TEMPC[],float TEMPF[],int DATA);
float average(float tempC[],int Data);
char grade(float Temperature); 
void writeFile(float tempC[],float tempF[],int DATA);
int main(){
    int size=20,data,high = 0, med = 0, low = 0;
    float avrg,tempf[size],tempc[size];
    data=readFile(tempf,size);
    computeC(tempc,tempf,data);
    avrg=average(tempc,data);
    writeFile(tempc,tempf,data);
    cout<<"The average temperature in celcius is: "<<fixed<<setprecision(1)<<avrg<<endl;
        for (int i = 0;i<data;i++) {
            char g =grade(tempc[i]);
            if (g=='H') high++;
            else if (g =='M') med++;
            else if (g =='L') low++;
        }
    cout<<"Number of High temperatures: "<<high<< endl;
    cout<<"Number of Medium temperatures: "<<med<< endl;
    cout<<"Number of Low temperatures: "<<low<< endl;

    return 0;
}
int readFile(float Tempf[],int size){
    int i=0,count=0;
    ifstream infile("input.txt");
    while(infile>>Tempf[i]){
        i++;
        count++;
    }
    return count;
}

void computeC(float TEMPC[],float TEMPF[],int DATA){
    for(int i=0;i<DATA;i++){
        TEMPC[i]=(5.0/9.0)*(TEMPF[i]-32);
    }
}
float average (float tempC[],int Data){
    float sum=0,avg;
    for(int i=0;i<Data;i++){
        sum+=tempC[i];
    }
    avg=sum/Data;
    return avg;
}
char grade(float Temperature){
 
        if (Temperature >= 35.0) {
        return 'H';
    } else if (Temperature >= 20.0) {
        return 'M';
    } else {
        return 'L';
    }
        }

void writeFile(float tempC[],float tempF[],int DATA){
    ofstream outfile("output.txt");
    outfile<<setw(15)<<"C(Celcius)"<<setw(15)<<"F(Fahrenheit)"<<setw(15)<<"Description"<<endl;
    outfile<<setw(15)<<"=========="<<setw(15)<<"=========="<<setw(15)<<"=========="<<endl;
    for(int i=0;i<DATA;i++){
        outfile<<setw(15)<<fixed<<setprecision(2)<<tempC[i]<<setw(15)<<tempF[i]<<setw(15)<<grade(tempC[i])<<endl;
    }

}


