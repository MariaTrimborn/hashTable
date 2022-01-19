#include <iostream>
#include <fstream>
using namespace std;

int ASCIISentence(std::string str)
{
    int ascIIVal = 0;
    for (int i =0; i < str.length(); i++){
        char x = str.at(i);
        int letterVal = int(x);
        ascIIVal += letterVal;
    }
    return ascIIVal;
}

void hashFunction1(int size){
    string array[size];
    for(int i = 0; i < size; i++ ){
        array[i] = "STOP";
    }

    string line;
    ifstream words("words.txt");
    if (words.is_open())
    {
        int collisions = 0;
        while(getline (words,line)) {
            int wordTotal = ASCIISentence(line);
            int hashVal = wordTotal % size;
            string stringHashVal = std::to_string(hashVal);
            int isInPlace = 0;
            int collisionCheck = 0;
            while (collisionCheck < 1) {
                string arrayVal = array[hashVal];
                if (arrayVal != "STOP") {
                    collisionCheck++;
                    collisions++;
                } else{
                    break;
                }
            }
            while (isInPlace < 1) {
                string arrayVal = array[hashVal];
                if (arrayVal == "STOP") {
                    array[hashVal] = stringHashVal;
                    isInPlace++;
                } else {
                    array[hashVal++];
                }
            }
        }
        words.close();
        cout << "Num of collisions: " << collisions << endl;
    }

    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}
void hashFunction2(int size){
    string array[size];
    for(int i = 0; i < size; i++ ){
        array[i] = "STOP";
    }

    string line;
    ifstream words("words.txt");
    if (words.is_open())
    {
        int collisions = 0;
        while(getline (words,line)) {
            int wordTotal = ASCIISentence(line);
            int hashVal = wordTotal % 2;
            string stringHashVal = std::to_string(hashVal);
            int isInPlace = 0;
            int collisionCheck = 0;
            while (collisionCheck < 1) {
                string arrayVal = array[hashVal];
                if (arrayVal != "STOP") {
                    collisionCheck++;
                    collisions++;
                } else{
                    break;
                }
            }
            while (isInPlace < 1) {
                string arrayVal = array[hashVal];
                if (arrayVal == "STOP") {
                    array[hashVal] = stringHashVal;
                    isInPlace++;
                } else {
                    array[hashVal++];
                }
            }
        }
        words.close();
        cout << "Num of collisions: " << collisions << endl;
    }

    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}

void hashFunction3(int size){
    string array[size];
    for(int i = 0; i < size; i++ ){
        array[i] = "STOP";
    }

    string line;
    ifstream words("words.txt");
    if (words.is_open())
    {
        int collisions = 0;
        while(getline (words,line)) {
            int wordTotal = ASCIISentence(line);
            int x;
            if ( wordTotal % 11 == 0)
                x = 1;
            else{
                x = 0;
            }
            int hashVal = (wordTotal % size) - x;
                if(hashVal == -1){
                    hashVal = 1;
                }
            string stringHashVal = std::to_string(hashVal);
            int isInPlace = 0;
            int collisionCheck = 0;
            while (collisionCheck < 1) {
                string arrayVal = array[hashVal];
                if (arrayVal != "STOP") {
                    collisionCheck++;
                    collisions++;
                } else{
                    break;
                }
            }
            while (isInPlace < 1) {
                string arrayVal = array[hashVal];
                if (arrayVal == "STOP") {
                    array[hashVal] = stringHashVal;
                    isInPlace++;
                } else {
                    array[hashVal++];
                }
            }
        }
        words.close();
        cout << "Num of collisions: " << collisions << endl;
    }

    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}

int main() {
    cout << "first hash function- word size % table size" << endl;
    int smallArray = 17;
    int medArray = 19;
    int lrgArray = 23;
    cout << "small Array (17): " << endl;
    hashFunction1(smallArray);
    cout << "medium Array (19): " << endl;
    hashFunction1(medArray);
    cout << "Large Array (23): " << endl;
    hashFunction1(lrgArray);
    cout << "second hash function- word size % 2" << endl;
    cout << "small Array (17): " << endl;
    hashFunction2(smallArray);
    cout << "medium Array (19): " << endl;
    hashFunction2(medArray);
    cout << "Large Array (23): " << endl;
    hashFunction2(lrgArray);
    cout << "third hash function- if wordTotal % 11 = 0, x = 1, else x = 0. Then hashval = wordTotal % size - x" << endl;
    cout << "small Array (17): " << endl;
    hashFunction3(smallArray);
    cout << "medium Array (19): " << endl;
    hashFunction3(medArray);
    cout << "Large Array (23): " << endl;
    hashFunction3(lrgArray);



    return 0;
}
