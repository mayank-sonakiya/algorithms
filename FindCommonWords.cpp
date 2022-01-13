// Brute Force Method in first thought. 

#include<iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]) {
    map<string,int> global_map;
    string word;
    fstream file;
    for (int i=1; i<argc; i++){
        file.open(argv[i]);
	
        map<string,int> local_map;
        
        while (file >> word){
            if (local_map.find(word) == local_map.end()){
                if (!global_map[word])
                    global_map[word]=1;
                else
                    global_map[word]= global_map[word]+1;
                local_map[word]=1;
            }       
        }
	  file.close();
    }
	  map<string,int>::iterator it;
    cout << "Common words are: \n";
    for (it=global_map.begin(); it!=global_map.end(); it++){
	      if (it->second == (argc-1))
            cout << it->first << endl;
    }
    return 0;
}
