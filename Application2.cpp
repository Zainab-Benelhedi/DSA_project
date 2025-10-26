// Application2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int pos(string ch,  int c);
int main()
{
    int m[5][6];
    int t[30];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; i < 6; j++) {
            cout << "enter m[" << i << "][" << j << "] :";
            cin >> m[i][j];
        } 
    }
    int l = 0;
    string ch = "";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; i < 6; j++) {
            if (pos(ch,  m[i][j]) == 0) {
                t[l] = m[i][j];
                ch=ch+stoi (m[i][j])+",";
            }
        }
    }
    return 0;
}
int 
int pos(string ch, int c) {
    int test = 0;
    int i = 0;
    while (i <= ch.size() && test == 0) {
        if (ch[i] == to_string(c)) {
            test = 1;
        }
        else
            i++;
    }
    return test;
}
//this is a test