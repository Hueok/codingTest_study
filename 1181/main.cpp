#include <iostream>
#include <string>

bool sortDictly(std::string& word1 , std::string& word2){
    return word1 < word2;
    //return 0 if word1 is bigger. else return 1
}
void swap(std::string& word1, std::string& word2){
    std::string tmp = word1;
    word1 = word2;
    word2 = tmp;
}

void clearDuplication(){}

int main(){
    int N;
    std::cin >> N;
    std::string* box = new std::string[N];
    for(int i=0; i<N; i++){
        std::cin >> box[i];
    }

    for(int i=0; i<N; i++){
        int tmp = N-1; 
        for(int j=i+1; j<N; j++){
            if(box[j].length() < box[tmp].length()){
                tmp = j;
            }
            else if(box[j].length() == box[tmp].length()){
                tmp = sortDictly(box[j], box[tmp]) ? j : tmp; 
            }
        }
        swap(box[i], box[tmp]);
    }

    std::cout << "TEST___________----------------" << std::endl;
    for(int i=0; i<N; i++){
        std::cout << box[i] << std::endl;
    }

    return 0;

}