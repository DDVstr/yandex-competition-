// yandex.code.dist.cpp .
//

#include <iostream>
#include <iomanip>
#include "math.h"
#include <stdio.h>

using namespace std; 


int main()
{
    
    int k; //k is for fixed element 
    int a; 
    int* mass; 

    int* c; 

    /*std::cin >> k; */

    std::cout << "enter the number" << std::endl; 

    std::cin >> a; 
   
    std::cout << "a=" << a<<std::endl; 

    std::cout << "enter fixed index" << std::endl; 

    std::cin >> k; 
    std::cout << "k=" << k << std::endl;

    mass = new int[a];

    //mass_k = new  int[k]; 
    c = new int[a];

    for(int i=0; i<a; i++)
    {
        std::cin >> mass[i]; 

        std::cout << "m[" << i << "]="<< mass[i]<< std::endl;    
    } 
    printf("\n");

    for (int y = 0; y < a; y++)
    {
      c[y] = abs(mass[k] - mass[y]);
      printf("\n");

      std::cout << "number of sums= "<<c[y]<<std::endl ;        
    }
    int min1; 
    int min2;
    int buffer; 
    if (c[0] < c[1])
    {
        min1 = 0;
        min2 = 1;
    }
    else
    {
        min1 = 1;
        min2 = 0;
    }
    for (int m = 2; m < a; m++)
    {
        if (c[m] < c[min1])
        {
            buffer = min1;
            min1 = m;
            if (c[buffer] < c[min2])
            {
                min2 = buffer;
            }
            else
            {
                if (c[m] < c[min2])
                {
                    min2 = m;
                }
            }

        }

    }
    std::cout << "#:"<<min1 <<'\t'<<"min[1]="<< c[min1]<<std::endl;
    std::cout << "#:" <<min2 <<'\t'<<"min[2]="<<c[min2] << std::endl; 

    int min_sum; 

    min_sum = c[min1] + c[min2]; 
    std::cout << "dist=" << min_sum;

    delete[]c; 
    delete[]mass; 
}

