 #include <iostream>
 #include <math.h>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <cmath>

 using namespace std;
 
struct Coords
{
    int x;
    int y;
};
using coordVec = std::vector<Coords>;
int isIntersect(coordVec& vec1, coordVec& vec2, unsigned int overlap, unsigned int rcenter)
{
    double min1 = sqrt(vec1[0].x * vec1[0].x + vec1[0].y * vec1[0].y);
    double min2 = sqrt(vec2[0].x * vec2[0].x + vec2[0].y * vec2[0].y);
    for(auto& i : vec1)
    {
        if(sqrt(i.x *i.x + i.y * i.y) <= min1 && overlap+rcenter >= sqrt(i.x *i.x + i.y * i.y))
        {
            min1 = i.x *i.x + i.y * i.y; 
        }  
    }
     for(auto& j : vec2)
    {
        if( sqrt(j.x *j.x + j.y * j.y) <= min2 && overlap + rcenter*overlap+rcenter >= sqrt(j.x *j.x + j.y * j.y))
        {
            min2 = j.x *j.x + j.y * j.y;
        }  
    }
    if(min1 < min2)
    {
        return 1;
    }
    if(min2 < min1)
    {
        return 2;
    }
   return 0;
}
int prestige(coordVec& vec1, coordVec& vec2, unsigned int overlap, unsigned int rcenter, int flag)
{     
    std::vector<double> data1;
    std::vector<double> data2; 
    
    for(auto& e : vec1)
    {
        if(overlap+rcenter >= sqrt(e.x *e.x + e.y * e.y))
            data1.push_back(e.x*e.x + e.y*e.y);
    }
      for(auto& q : vec2)
    {
        if(overlap+rcenter >= sqrt(q.x *q.x + q.y *q.y))
            data2.push_back(q.x*q.x+ q.y*q.y);
    }
     int count = 0;
     int counter =0;
     if (flag = 1)
     {
        for (const auto& x : data1) 
        {
            for (const auto& y : data2) 
            {
                if(x<y)
                {
                    count++;
                    if(count == data2.size())
                    {
                        counter++;
                    }
                }
            }
          
        }
    }
     if (flag = 2)
     {
        for (const auto& x : data2) 
        {
            for (const auto& y : data1) 
            {
                if(x<y)
                {
                    count++;
                    if(count == data1.size())
                    {
                        counter++;
                    }
                }
            }
          
        }
     }

     return counter;
}
 int main()
 {  
    unsigned int overlap;
    unsigned int rcenter;
    Coords cordinate;
    coordVec vector_cords;
    std::cin >> overlap >> rcenter;
    if (overlap == 0 && rcenter ==0)
    {
        std::cout<<overlap<<std::endl;
        std::cout<<rcenter;
    }
    for(int i = 0;i < 16; ++i)
    {
        std::cin >> cordinate.x >> cordinate.y;
       
        vector_cords.push_back(cordinate);
    }

    //first team
    std::vector<Coords> t1(vector_cords.begin(), vector_cords.begin() + 8);
    //second team
    std::vector<Coords> t2(vector_cords.begin() + 8, vector_cords.begin() + 16);
    
   std::cout<<isIntersect(t1, t2, overlap, rcenter)<<std::endl;
   std::cout<<prestige(t1, t2, overlap, rcenter, isIntersect(t1, t2, overlap, rcenter));

     return 0;
 }