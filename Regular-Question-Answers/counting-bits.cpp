#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i < n; i++){
            vector<int> bin = decToBinary(n);
            int numberOfOnes = 0;
            for(int i = 0; i < bin.size(); i++){
                if(bin[i] == 1)
                    numberOfOnes++;
            }
            result.push_back(numberOfOnes);
        }
        return result;
    }
vector<int> decToBinary(int n){
    int temp = n;
    vector<int> bin;
    while(temp != 0){
        bin.push_back(temp % 2);
        temp = temp / 10;
    }
    return bin;
}

int main(){
    int n = 5;
    // vector<int> res = countBits(n);
    // for(int i = 0; i < res.size(); i++){

    // }
    cout<<countBits(n)<<endl;
}