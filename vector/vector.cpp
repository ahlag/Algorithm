#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main( void ) {

    vector<string> words;
    for(string temp; cin >> temp;) {
        words.push_back(temp);
        if(temp == "stop" ) { break; }
    }
    cout << "Number of words : " << words.size() << endl;
    
        int i = 0;
    
    for( i = 0; i < words.size(); i++ ) {

            cout << words[i] << endl;
    }
    
    sort(words.begin(),words.end());

    cout << endl << endl;
    
    for( i = 0; i < words.size(); i++ ) {
        
        cout << words[i] << endl;
    }
    

    for( i = 0; i < words.size(); i++ ) {
        if( i == 0 || words[i-1] != words[i] ) {
            cout << "words[" << i << "] = " << words[i] << "   words[" << i-1 << "] = " << words[i-1];
            cout << " i = " << i << endl;
            //cout << words[i] << endl;
        }
    }
    
    return 0;
}
