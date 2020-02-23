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
    maxArray maxSubArray(const int[],const int, const int,const int);
    
    //declaration of  cross-sum 
    maxArray maxCross(const int[],const int, const int,const int, const int);
    
    
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
	
	 cout << "Max sub array:\n";
           	//TIME CALCULATION
         	clock_t  clock1=0,clock2=0,clock3=0;//declaration of timer
         	clock1=clock();
            res = maxSubArray(array,size,0,size-1);
           	clock2 = clock();
           	clock3=clock2-clock1;
            // Get the ending time
             float totalTime = (float)(clock3 ) /CLOCKS_PER_SEC;//time in SECONDS
         	cout << "Total Time taken by CRoss SUM is is: " << totalTime <<"seconds"<< endl;
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

    
// This function to print data of array
    void printData(const maxArray &R){
        cout << "The maximum sub-array: \n";
         cout << "Total Sum: " << R.totalSum << endl;
        cout << "Start index: " << R.sIndex << endl;
        cout << "End index: " << R.eIndex << endl;
       
    }

 // *************************************************************
   maxArray maxSubArray(const int ARR[],const int SIZE
                                      , const int start,
                                      const int end){
        //if one element
        if(end == start){
           
           maxArray result;
           
            result.totalSum   = ARR[start];
            result.sIndex = start;
            result.eIndex   = end;
           
            
           
            return result;
        }else{
            
            // fot  midpoint index:
            int mid = (start + end) / 2;
          
            

            maxArray left;
            maxArray right;
            maxArray cross;
       
            // Recursively to find max subarray in first half of array
            left  = maxSubArray(ARR,SIZE,start,mid);
             // Recursively to find max subarray in second half of array
            right = maxSubArray(ARR,SIZE,mid+1,end);
             // Recursively to find max subarray in cross section of mid
            cross = maxCross(ARR,SIZE,start,mid,end);
            
           
            if(left.totalSum >= right.totalSum && 
               left.totalSum >= cross.totalSum){
                return left;// left sub array 
                
            } else if(right.totalSum >= left.totalSum && 
                      right.totalSum >= cross.totalSum){
                      return right;//right sub array
            } else {
               
                return cross;
            }
        }
    }
    
    
 //***********************************************************************  
    maxArray maxCross(const int ARR[],const int SIZE, const int start, 
    const int mid, const int end){
        
        int left  = 0;
        int right = 0;
        int sum = 0;
        maxArray result;
       
        left = ARR[mid];
        sum = ARR[mid];
        result.sIndex = mid;
    
        // Start from the next item
        for(int i=mid-1; i>=start; i--){
            
             sum = sum+ARR[i];
            // If  bigger sum
            if(sum > left){
                left = sum;
                result.sIndex = i;
            }
        }
       
        sum = 0;
        right = ARR[mid+1];
        sum = ARR[mid+1];
        result.eIndex = mid+1;
        
        // Start from the next item
        for(int i=mid+2; i<=end; i++){
            
             sum =sum+ARR[i];
            // If get a bigger sum
            if(sum > right){
                right = sum;
                result.eIndex = i;
            }
        }
        
     
        result.totalSum = left + right;
        return result;
    }
    

          
