#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <stdio.h> 
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <fstream> 
using namespace std;
using namespace std::chrono;
    
    // =============================================================
    // using struct defing components
   
    
    struct maxArray{
        
        float totalSum;
        int sIndex;
        int eIndex;
      
    };
    
    // =============================================================
    
    void RandomArray(int array[], int size)
{
	for (int i = 0; i < size; ++i) array[i] = std::rand() % 50 + 1;
}
    
    void printArray(const int[],const int);
    void printData(const maxArray&);
    
    //declaration of max-sub-array 
    //maxArray findMaxSubArray(const int[],const int, const int,const int);
    
     //declaration of  Brute-force
    maxArray bruteForce(const int[],const int);
    
    int main()
{
    maxArray res;
        
    // A dynamically created arrays
    const int size = 30000;//array SIZE
	int start = 1, end = size-1;
	int array[size] = { 0 };

        
        
    //generting random numbers
	std::srand(std::time(nullptr)); // **** important ****
	RandomArray(array, size);
	
	
	 cout <<"--------------------------------------------\n";
            cout << "Brute-force:\n";
            
            
           	//TIME CALCULATION
         	clock_t  clock1=0,clock2=0,clock3=0;//declaration of timer
         	clock1=clock();
            res = bruteForce(array,size);
           	clock2 = clock();
           	clock3=clock2-clock1;
	        float totalTime = (float)(clock3 ) /CLOCKS_PER_SEC;//soting time in SECONDS
         	cout << "Total Time taken by brute force is is: " << totalTime <<"seconds"<< endl;
        	//	printArray(array,size);
		    printData(res);
            return 0;
       
        
}   


//***********************************************************
//==================Funtion Definitons===========================
//***********************************************************
    void printArray(const int ARR[], const int SIZE)
    {
	int i;
	for (i = 0; i < SIZE; i++)
		cout << ARR[i] << " ";
	cout << endl;
    }

//***************************************************    
// This function to print data of array
    void printData(const maxArray &R){
        cout << "The maximum sub-array: \n";
         cout << "Total Sum: " << R.totalSum << endl;
        cout << "Start index: " << R.sIndex << endl;
        cout << "End index: " << R.eIndex << endl;
       
    }
    
//***************************************************************
maxArray bruteForce(const int ARR[], const int SIZE){
      
        int low = 0;
        int high = 0;
        int m = ARR[0];
        int maxSum;
   
      maxArray res;
       maxSum = 0x80000000;
	for (int i = 0; i < SIZE; ++i)
	{
		int sum = 0;
		for (int j = i; j < SIZE; ++j)
		{
			int sum = sum+ARR[j];
			if (sum > maxSum)
			{
				maxSum = sum;
				low = i;
				high = j;
			}
		}
	}
       
       // saving the in struct variable 
        res.sIndex = low;
        res.eIndex   = high;
        res.totalSum   = maxSum;
        
        // return the record.
        return res;
    }
    //*************************************************************************


