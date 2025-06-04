#include <iostream>
using namespace std;


bool isEven(int number){
    // 10100010 
    bool binaryNumber = true;
    string myNumberString = to_string(number);
    for (auto it = myNumberString.begin(); it != myNumberString.end(); it++)
    {
        if ((*it != '0') && (*it != '1'))
            binaryNumber = false;
    }

    if(binaryNumber){
        return !(number & 1);
    }else{
        return !(number % 2);
    }
}

