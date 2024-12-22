//Terminal indicated the tranditional chinese with chcp 65001
//The EOF problem must be fix(e.g. ^z ^c)
#include "student-info-sys-variable.h"



int main()
{
    while(true)
    {   
        //Path check
        if(!std::filesystem::exists(student_info_dir))
    {   
        //std::filesystem::create_directories(Log_Directory);  // create the directory
        if(std::filesystem::create_directories(student_info_dir))
        {
            //std::cout  << "Created!";
        }
        else
        {
            std::cerr << "無法建立資料夾，請檢查有無權限執行檔案或者磁碟空間是否足夠！\n";
            return 1; //Error and turnoff the program  
        }
    }
    //-------------------------------------------------
         
        home_page(); //display the Homepage.
        //std::cout << sel_page_req; //"請輸入選擇："
        std::cin >> opt_sel;

        if(opt_sel == '1')
        {
            while(true) // if the program has the problem it will initialize the loop
            {
                system("cls");
                student_page(); //display the option: student page
                std::cin >> opt_sel;
                if(opt_sel == '1')
                {   
                   



                    system("cls"); // The program has already terminated.
                    break; // The program has already terminated.
                }
                else if(opt_sel == '2')
                {
                    while(true)
                    {
                        //write down the student info
                        add_student_info();
                        //comfirm
                        student_comfirm(); // ask user the info is right or not.
                        if(opt_sel == 'y' || opt_sel == 'Y')
                        {
                        
                            //Used .cvs format to save data
                            save_student_info();

                            std::cout << "資料已保存至" << student_number + ".csv" << std::endl;
                            Sleep(2500);
                            system("cls");
                            break; //Exit the saving phrase 
                        }
                        else if(opt_sel == 'n' || opt_sel == 'N')
                        {
                            std::cout << "資料將不會保存!" << std::endl;
                            Sleep(2500);
                            system("cls");
                            break; //Exit the saving phrase
                        }
                        else
                        {
                            do{
                                std::cout << "無效的輸入~請再輸入一次";
                                Sleep(2500);
                                system("cls");   
                                student_comfirm(); // ask user the info is right or not.
                                
                                if(opt_sel == 'n' || opt_sel == 'N')
                                {
                                    std::cout << "資料將不會保存!" << std::endl;
                                    Sleep(2500);
                                    system("cls");

                                }
                                else if(opt_sel == 'y' || opt_sel == 'Y')
                                {
                                    //Used .cvs format to save data
                                    save_student_info();

                                    std::cout << "資料已保存至" << student_number + ".csv" << std::endl;
                                    Sleep(2500);
                                    system("cls");
                                    break; //Exit the saving phrase 
                                }
                                
                            }
                            while(opt_sel != 'y' && opt_sel != 'Y' && opt_sel != 'n' && opt_sel != 'N'); //when opt_sel equal to y or n will stop the loop
                            break; //Exit the saving phrase 
                        }
                        ///---------------------------terminated
                        //system("cls"); // The program has already terminated.
                        //break; // The program has already terminated.
                    }
                }
                else if(opt_sel == '3')
                {
                    system("cls");
                    break; //Exit the selecting phrase
                }
                else if(opt_sel != '1' || opt_sel != '2' || opt_sel != '3')
                {
                    system("cls");
                    std::cout << "無效的輸入，請再次輸入!";
                    Sleep(2500);
                    system("cls");
                }
            }
               
        }
        else if(opt_sel == '2')
        {
            system("cls");
        }
        else if(opt_sel == '3')
        {
            system("cls");
        }
        else if(opt_sel == '4')
        {
            exit(1); //Terminate the system
        }
        else if(opt_sel != '1' || opt_sel != '2' || opt_sel != '3' || opt_sel != '4')
        {
            system("cls");
            std::cout << "無效的輸入，請再次輸入!";
            Sleep(2500);
            system("cls");
        }
    }
    
    return 0;
}