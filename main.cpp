#include <iostream>
#include <utility> //pair, make_pair
#include <vector> //vector
#include <string> //string
#include <algorithm> //sort()

bool sortbysec(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b){
 return (a.second < b.second); 
}

int main(){
  
  std::string people[] = {"Person 1", "Person 2", "Person 3", "Person 4", "Person 5"}; 
  
  //key value pair for person and amount they ate 
  std::vector<std::pair<std::string, int> > list;

  //size of array
  int size = sizeof(people)/sizeof(people[0]);

  //amount of pancake each person ate, plus allocating memeory
  int * ate = new int[size];
   
  std::cout << "Pancake Glutton" << std::endl;
  int count = 1;
  //taking each input for person
  std::cout << "=============" << std::endl;
  std::cout << "Enter the number of Pancakes ate by each Person" << std::endl;
  for(int i = 0; i < size; i++){
    int input{};
    std::cout << "Person " << count++ << " ";
    std::cin >> input;
    ate[i] = input;
  }
  std::cout << "=============" << std::endl;

  for(int i = 0; i < size; i++){
    //make_pair creates a value pair
    list.push_back(make_pair(people[i], ate[i]));
  }

  std::cout << std::endl;

  //sorting the vector list
  std::sort(list.begin(), list.end(), sortbysec);
  std::cout << "=============" << std::endl;
  std::cout << "Sorted" << std::endl;
  for(auto v: list){
    std::cout << v.first << "->" ;
    std::cout << v.second << std::endl;
  }
  std::cout << "=============" << std::endl;

  std::cout << std::endl;

  std::cout << "=============" << std::endl;
  std::cout << "Person who ate the most Pies: " << list.back().second << std::endl;
  std::cout << "=============" << std::endl;

  std::cout << std::endl;
  
  std::cout << "=============" << std::endl;
  std::cout << "Person who ate the less Pies: " << list.at(0).second << std::endl;
  std::cout << "=============" << std::endl;


  
  delete [] ate; 
  return 0;
}
