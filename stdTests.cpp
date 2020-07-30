#include<iostream>
#include<string>
#include<vector>
#include<chrono> 

int main(){

  std::vector<std::string> s1;
  std::vector<std::string> s2;
  std::cout<<"starting s1 vector with no std::move and bad initialization"<<'\n';
  auto start = std::chrono::high_resolution_clock::now();
  for(int i=0; i<10000000; i++){
    std::string s;
    s = "A very long string wow";
    s1.push_back(s);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  std::cout<<"Time in microseconds "<<std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
  std::cout<<"done s1\n";
  //std::cin.get();
  std::cout<<"starting s2 with move and good initializer"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  for(int i=0; i<10000000; i++){
    const std::string s = "A very long string wow";
    s2.push_back(std::move(s));
  }
  stop = std::chrono::high_resolution_clock::now();
  std::cout<<"Tim in microseconds "<<std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
  std::cout<<"done s2\n";
    
  s1.clear();
  s2.clear();

  start = std::chrono::high_resolution_clock::now();
  for(int i=0; i<10000; i++){
    std::cout<<"printing line number: "<<i<<std::endl;
  }
  stop = std::chrono::high_resolution_clock::now();
  std::cout<<"Tim in microseconds "<<std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
  std::cout<<"\nhit enter to time second print\n";
  std::cin.get();
  start = std::chrono::high_resolution_clock::now();
  for(int i=0; i<10000; i++){
    std::cout<<"printing line number: "<<i<<std::endl;
  }
  stop = std::chrono::high_resolution_clock::now();
  std::cout<<"Tim in microseconds "<<std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();


return 0;
}
