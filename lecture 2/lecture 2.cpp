// lecture 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Source.cpp"
#include <fstream>
#include <iostream>
#include <cstring>

struct Fraction
{
    int numerator;
    int denumerator;
};

struct Date
{
    int day;
    char month[30];
    int year;
};

struct Student
{
    int number;
    char name[40];
    Date birth; 
};



void showStudents(const char filename[]) {
    std::ifstream file;
    Student student;
    file.open(filename, std::ios::binary);
    while (!file.eof())
    {
        file.read((char*)&student, sizeof(student));
        if (!file.eof()) {
            std::cout << student.number << " " << student.name << std::endl;
            std::cout << student.birth.day << " " << student.birth.month << " " << student.birth.year << std::endl;
        }

    }

    file.close();
}

void simplifyFracture(int &numerator, int &denumerator) {

    int gcd = GCD(numerator, denumerator);
    while(gcd > 1)
    {
        numerator = numerator / gcd;
        denumerator = denumerator / gcd;
        gcd = GCD(numerator, denumerator);
    }

}

//bool palindrome(char string[]) {
//    int size = strlen(string) + 1;
//    char reverse[size];
//    
//    //strcpy_s(reverse, string);
//
//    for (int i = 0; i < sizeof(string); i++)
//        reverse[i] = string[strlen(string) - i - 1];
//    std::cout << reverse << std::endl;
//
//    if (strcmp(string, reverse) =w= 0)
//        return true;
//
//    return false;
//}



bool palindrome(char string[]) {
    for (int i = 0; i < strlen(string); i++)
        if (string[i] != string[strlen(string) - 1 - i])
            return false;
              
    return true;
}





int main()
{
    showStudents("students.dat");
    
    int numerator = 8;
    int denumerator = 12;
    std::cout << numerator << "\n" << "--" << "\n" << denumerator << std::endl;
    simplifyFracture(numerator, denumerator);
    std::cout << numerator << "\n" << "--" << "\n" << denumerator << std::endl;
     
    char names[][20] = { "hanne", "bas", "tim", "timothy fly", "el truco" };

    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    {
        for (int j = 0; j < sizeof(names[0]); j++) {
            if (names[i][j] == 0)
                break;
            std::cout << names[i][j];
        }
        std::cout << std::endl;
    }

    char string[] = "a";
    char arr[] = "baaa";
    
    std::cout << strlen(arr) << std::endl;
    std::cout << palindrome(arr) << std::endl;
    

    //int integer = 10;
    //std::cout << integer << std::endl;
    //while (integer > 5) {
    //    integer--;
    //}
    //std::cout << integer << std::endl;
    //char buffer[6];
    //std::cin.getline(buffer, 6);
    //std::cout << buffer << std::endl;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
