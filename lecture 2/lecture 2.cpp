// lecture 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Source.cpp"
#include <fstream>
#include <iostream>
#include <cstring>

struct PlayerState
{
    char name[20];
    int level;
    double health;
    int experience;

};

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
		file.read((char*)& student, sizeof(student));
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

void readTextFile(const char name[]) {
	std::ifstream file;
	char o;
	file.open(name, std::ios::binary);
	file.get(o);
		while (!file.eof()) {		
            std::cout.put(o);
			file.get(o);
		}
        std::cout << std::endl;
		file.close();
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

	readTextFile("professionalism.txt");

    PlayerState playerlist[3];

    char name1[] = "Klaas";

    playerlist[0].level = 172;
    strcpy_s(playerlist[0].name, "Klaas Vaak");
    playerlist[0].health = 100;
    playerlist[0].experience = 1567;

    playerlist[1].level = 76;
    strcpy_s(playerlist[1].name, "Albert Einstein");
    playerlist[1].health = 0;
    playerlist[1].experience = 9999;

    playerlist[2].level = 35;
    strcpy_s(playerlist[2].name, "Lady Gaga");
    playerlist[2].health = 55.7;
    playerlist[2].experience = 1337;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "name:" << playerlist[i].name << " level: " << playerlist[i].level << " health: " << playerlist[i].health << " experience: " << playerlist[i].experience << std::endl;
    }

    std::ofstream gamedata;
    
    gamedata.open("game.dat", std::ios::binary);
    for (int i = 0; i < 3; i++)
    {
        gamedata.write((char*)&playerlist[i], sizeof(playerlist[i]));
    }
    gamedata.close();

    std::ifstream inputgamedata;
    PlayerState currentplayer;

    inputgamedata.open("game.dat", std::ios::binary);
    for (int i = 0; i < 3; i++)
    {
        inputgamedata.read((char*)&currentplayer, sizeof(currentplayer));
        std::cout << currentplayer.name << std::endl;
    }




    
    

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
