#include<iostream>
#include <cstdlib>
#include<stdlib.h>
#include<fstream>

using namespace std;

#define n 1000
#define m n*3

//Read comments for better understanding.

int main()
 {
    //Variable assignment
        double cr, cc, ccm;
	int A[n][4];
        int B[m], C[m], D[n];
	int current, a, b, k=0, l=0;
        double diff=0.0;
	int count, cd = 0, cdr=0, cdm=0;
        
        srand ( time(NULL) ); //calling random number function.
    
        for(int i=0; i<n;i++) // using loop to generate 1000 random numbers.
        {
        D[i]=rand()%255;       
         }
    
         ofstream myfile ("numbers.txt"); // writing generated random numbers into a text file.
         if (myfile.is_open())
         {    
            for(int cnt = 0; cnt < n; cnt ++){
            myfile << D[cnt] <<" ";
         }
            myfile.close();
         }
         else cout << "Unable to open file";
  
        
        
        ifstream file("numbers.txt"); // opening the text file to to read previously generated random numbers.
        if(file.is_open())
        {
        for(int num = 0; num < n; num++)
        {
            file >> A[num][0];        //reading random number from file
            A[num][1] = A[num][0]%5;  //calculating %5 of each number
            A[num][2] = A[num][0]%6;  //calculating %6 of each number
            A[num][3] = A[num][0]%7;  //calculating %7 of each number
        }
        }
        
        for(int i=0;i<n;i++)          //recording data row wise.
	{
		for(int j=1;j<4;j++)
		{
			B[k]=A[i][j];
			k++;                   
		}                		
	}
         
        for (int i = 1; i < 4; i++)  //recording data column wise.
	{
                for( int j=0; j<n; j++)
                {
                    C[l]=A[j][i];
                    l++;
                }
        }
        
        //displaying the output.
        
        cout<<"   Random Number     % 5:     % 6:     % 7:   "<<endl;

        for(int p=0; p<10; p++)
        {
            cout<<endl;
                cout<<"     "<<A[p][0]<<"              "<<A[p][1]<<"       "<<A[p][2]<<"        "<<A[p][3]<<"       ";

        }
       
        cout<<endl<<endl<<endl<<"   Row by Row: ";
        for(int i=0;i<30;i++)
        {
		cout<<B[i]<<" ";
        }
        
        cout<<endl<<endl<<"   Col by Col: ";
        
        for(int i=0;i<30;i++)
        {
		cout<<C[i]<<" ";
        }
        cout<<endl<<endl;
        
        
        cout<<endl<<endl<<"Row by Row RLE: "<<endl<<endl;;
	for (int i = 0; i < m;)   //implementing row by row RLE.
	{
		current = B[i];
		count = 0;
		while (i < m && current == B[i])
		{
			count++;
			i++;
		}
                 cd += 2;
           
                }
        
        cr = (double)(cd) /(double) (m);
 
        cout << endl<<endl<<"Compression Ratio:  "<<cr<<endl<<endl;

	

        cout <<endl<<endl<<"Column by Column RLE: "<<endl<<endl; 

	for (int i = 0; i < m;)    //implementing column by column RLE.
	{
		current = C[i];
		count = 0;
		while (i < m && current == C[i])
		{
			count++;
			i++;
		}
                 cdr += 2;
           
                }
        
        cc = (double)(cdr) /(double) (m);

	cout << endl<<endl<<"Compression Ratio:  "<<cc<<endl<<endl;


    return 0;

}

