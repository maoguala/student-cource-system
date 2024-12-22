#include <iostream>
#include <fstream> //datastream processing (to used save and read information of student & teacher )
#include <filesystem> // Create file Path if doesn't exist,but it can't write the files  
#include <windows.h>
#include <stdlib.h> // add option: Exit the system

std::ifstream in_a; // Read the file
std::ofstream out_a; // Write the file 
std::ifstream in_b; // Another data stream
std::ofstream out_b; // Another data stream

std::string student_number; //record student number temporarily 
std::string student_name; // record student name temporarily
std::string student_course; // record student cource temporarily
std::string student_teacher; // record student's teacher temporarily


char opt_sel = '0'; //To save system option selected
//std::string sel_page_req = "請輸入選擇：";


void home_page()
{
    std::cout << "   學生選課系統選單\n";
    std::cout << "--------------------\n";
    std::cout << "(1).學生資訊查詢or新增\n";
    std::cout << "(2).老師資訊查詢or新增\n";
    std::cout << "(3).學生選課\n";
    std::cout << "(4).離開系統\n";
    std::cout << "--------------------\n";
    std::cout << "請輸入選擇：";
}

void student_page()
{
    std::cout << "(1).查詢學生資訊\n";
    std::cout << "(2).新增學生資訊\n";
    std::cout << "(3).回到主頁面\n";
    std::cout << "--------------------\n";
    std::cout << "請輸入選擇："; //"請輸入選擇："
}

void add_student_info()
{
    system("cls");
    std::cout << "請輸入學生姓名：";
    std::cin >> student_name;
    system("cls");
    std::cout << "請輸入學生學號：";
    std::cin >> student_number;
    system("cls");
    std::cout << "請輸入學生課程：";
    std::cin >> student_course;
    system("cls");
    std::cout << "請輸入學生的導師：";
    std::cin >> student_teacher;
    system("cls");
}

void student_comfirm()
{ // To comfirm student info

    std::cout << "----------------------------------------\n";
    std::cout << "學生姓名：" << student_name << std::endl;
    std::cout << "學生學號：" << student_number << std::endl;
    std::cout << "學生課程：" << student_course << std::endl;
    std::cout << "學生導師：" << student_teacher << std::endl;
    std::cout << "----------------------------------------\n";
    std::cout << "請問以上是否正確？ (Y/N)：";
    std::cin >> opt_sel; //Yes or no
    system("cls");
}

//save to the file name called student_number.csv
std::string student_info_dir = "./student_info/";
std::string student_info_file = ""; // save the student's info into ./student_info/student_number.csv

void save_student_info()
{ //word for save student info from write in
    student_info_file = student_info_dir + student_number + ".csv"; // Update after confirm 
    out_a.open(student_info_file, std::ios::out); // Mode write
    out_a << student_name << "," << student_number << "," << student_course << "," << student_teacher;
    out_a.close(); //close data stream for write in 
}
