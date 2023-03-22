#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <fstream>

using namespace std;
 
vector<int> split(const string &str, char sep)
{
    vector<int> tokens;
    int i;
    stringstream ss(str);
    while (ss >> i) {
        tokens.push_back(i);
        if (ss.peek() == sep) {
            ss.ignore();
        }
    }
    return tokens;
}
int ceil1(float num) 
{
    int inum = (int)num;
    if (num == (float)inum) 
    {
        return inum;
    }
    return inum + 1;
}
int main()
{
    char sep = 'x';
    float n,k,omega;
    std::cin>>omega>>n>>k;
    vector<int> tokens;
    vector<vector<int>> temp;
    vector<float> avg;
    vector<float> height_new;
    std::string str; 
    
   //corner case 
    if(n == 0 || omega == 0 || k == 0)
    {
        return 0 ;
    }

    //regular
	for(int i =0; i < n; ++i)
	{   
	    std::cin>>str;
		vector<int> tokens = split(str, sep); 
		temp.push_back(tokens);
		avg.push_back((float)tokens[1]/(float)tokens[0]);
		
		height_new.push_back(ceil1(avg[i]*omega));
		//std::cout<<height_new[i]<<std::endl;
	}
	for (int i = 0; i < height_new.size(); i++) {
    for (int j = 0; j < height_new.size()-1; j++) {
      if (height_new[j] > height_new[j + 1]) {
        float b = height_new[j]; // создали дополнительную переменную
        height_new[j] = height_new[j + 1]; // меняем местами
        height_new[j + 1] = b; // значения элементов
      }
    }
  }
    float min, max; 
    int counter= 0;
    for(int z = 0; z<height_new.size();++z)
    {   
        if(counter<k)
        {
            min = min + height_new[z];
            counter++;
        }
    }
   int counter_1 = 0; 
   for(int z_1 = height_new.size()-1 ;z_1>=0;z_1--) 
   {
       if(counter_1<k)
        {
            max = max + height_new[z_1];
            counter_1++;
        }
   }
    ofstream fout("cpp_ans.txt",ios::binary); 
    fout <<to_string((int)min)<<to_string((int)max);
    fout.close();
    return 0;
}