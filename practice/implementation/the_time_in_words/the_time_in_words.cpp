#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

if m == 0:
    print to_word(h) + ' o\' clock'
elif m == 30:
        print 'half past ' + to_word(h)
elif m < 30:
    if m == 1:
        print 'one minute past ' + to_word(h)
    elif m == 15:
        print 'quarter past '  + to_word(h)
    elif m < 21:
        print to_word(m) + ' minutes past ' + to_word(h)
    elif m < 30:
        print 'twenty ' + to_word(m % 10) + ' minutes past ' + to_word(h)
else:
    m = 60 - m
    if m == 1:
        print 'one to ' + to_word(h + 1)
    elif m == 15:
        print 'quarter to '  + to_word(h + 1)
    elif m < 21:
        print to_word(m) + ' minutes to ' + to_word(h + 1)
    elif m < 30:
        print 'twenty ' + to_word(m % 10) + ' minutes to ' + to_word(h + 1)

*/

string toWord(int value)
{
    const vector<string> words{
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
         "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
         "eighteen", "nineteen", "twenty"};
    return words.at(value - 1);
}

int main(){
    int h, m ;
    cin >> h >> m;
    
    if (m == 0)
    {
        cout << toWord(h) << " o' clock" << endl;    
    }
    else if (m == 30)
    {
        cout << "half past " <<  toWord(h) << endl;    
    }
    else if (m < 30)
    {
        if (m == 1)
        {
            cout << "one minute past "<< toWord(h) << endl;    
        }
        else if (m == 15)
        {
            cout << "quarter past " << toWord(h) << endl;   
        }
        else if (m < 21)
        {
            cout << toWord(m) << " minutes past " << toWord(h) << endl;      
        }
        else
        {
            cout << "twenty " << toWord(m % 10) << " minutes past " << toWord(h) << endl;    
        }    
    }
    else
    {
        m = 60 - m;
        if (m == 1)
        {
            cout << "one to " << toWord(h + 1) << endl;    
        }
        else if (m == 15)
        {
            cout << "quarter to " << toWord(h + 1) << endl;    
        }
        else if (m < 21)
        {
            cout << toWord(m) << " minutes to " << toWord(h + 1) << endl;    
        }
        else
        {
            cout << "twenty " << toWord(m % 10) << " minutes to " << toWord(h + 1) << endl;    
        }
    }
    return 0;
}

