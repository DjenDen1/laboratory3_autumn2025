#include "functions.h"
void printDLLE(std::list<DLLE*> DLLElist)

{   
    int n = 0; 

    while(n != -1)
    {
        std::cout << "НАЧАЛО РАБОТЫ DLLE list"<< std::endl;
        std::cout << "Выберите опцию: " << std::endl;
        std::cout << princhain()<<std::endl;
        std::cout << "1. введите от 0 до " << DLLElist.size()-1 << " чтобы выбрать элемент" << std::endl;
        std::cout << "2. введите -1 для выхода из функции" << std::endl;
         std::cout << princhain()<<std::endl;
        std::cout << "Ваш ввод - ";
        std::cin >> n;
        
        if(n == -1) break;
        
        if(n >= 0 && n < DLLElist.size())
        {
            std::list<DLLE*>::iterator it = DLLElist.begin();
            std::advance(it, n);
            
            int choice = 0;
            while(choice != -1)
            {   
               
                std::cout << "Работа с " << n << " элементом(DLLE) " << std::endl;
                std::cout << "Выберите опцию: " << std::endl;

                std::cout << prinequal() << std::endl;
                
                std::cout << "1. введите 1 для промотра double_number ("<<n<<")"  << std::endl;
                std::cout << "2. введите 2 для просмотра integer_number ("<<n<<")"  <<std::endl;
                std::cout << "3. введите 3 для просмотра integer_number_fractional_part ("<<n<<")" << std::endl;
                std::cout << "4. введите 4 для просмотра integerHEX ("<<n<<")" << std::endl;
                std::cout << "5. введите 5 для просмотра doubleHEX ("<<n<<")" << std::endl;
                std::cout << "6. введите 6 для просмотра integerBIN ("<<n<<")" << std::endl;
                std::cout << "7. введите 7 для просмотра doubleBIN ("<<n<<")" << std::endl;
                std::cout << "8. введите 8 для просмотра right_forward_ptr (а точнее на какое double_number указывает) ("<<n<<")" << std::endl;
                std::cout << "9. введите 9 для просмора  left_back_ptr (а точнее на какое double_number указывает) ("<<n<<")" << std::endl;
                std::cout << "введите -1 для выхода" << std::endl;
                
                std::cout << prinequal() << std::endl;
                
                std::cout << std::endl;
                std::cout << "Ваш ввод - ";
                
                std::cin >> choice;
                std::cout << std::endl;
                if(choice == -1) break;
                
                // Используем choice для выбора поля, а не n
                switch(choice) {
                    case 1:
                        std::cout << prinl() <<"        double_number -- "<< (*it)->double_number <<"       "<< prinl() << std::endl;
                        break;
                    case 2:
                        std::cout <<prinl()<<"      integer_number -- "<< (*it)->integer_number <<"     "<<prinl()<< std::endl;
                        break;
                    case 3:
                        std::cout <<prinl()<<"      integer_number_fractional_part -- "<<(*it)->intger_number_fractional_part <<"       "<<prinl()<< std::endl;
                        break;
                    case 4:
                        std::cout <<prinl()<<"      integerHEX -- "<< (*it)->integerHEX <<"     "<< prinl()<<std::endl;
                        break;
                    case 5:
                        std::cout <<prinl()<<"      doubleHEX -- "<< (*it)->doubleHEX <<"      "<<prinl()<< std::endl;
                        break;
                    case 6:
                        std::cout <<prinl()<<"      integerBIN -- "<<(*it)->integerBIN <<"      "<<prinl()<< std::endl;
                        break;
                    case 7:
                        std::cout <<prinl()<<"      doubleBIN -- "<<(*it)->doubleBIN <<"      "<<prinl()<< std::endl;
                        break;
                    case 8:
                        if((*it)->right_forward_ptr == nullptr)
                        {
                            std::cout << prinl() <<"        right_forward_ptr -- "<< "nullptr" <<"      "<< prinl() << std::endl;
                        }
                        else std::cout <<prinl()<<"     right_forward_ptr -- "<< (*it)->right_forward_ptr->double_number <<"        "<<prinl()<<std::endl;
                        break;
                    case 9:
                        if((*it)->left_back_ptr == nullptr)
                        {
                            std::cout << prinl() <<"        left_back_ptr -- "<< "nullptr" <<"      "<< prinl() << std::endl;
                        }
                        else std::cout << prinl() <<"       left_back_ptr -- "<< (*it)->left_back_ptr->double_number <<"        "<< prinl() << std::endl;
                    default:
                        std::cout << "Неверный выбор!" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Неверный индекс элемента!" << std::endl;
        }
    }
}


void printMLLE(std::list<MLLE*> MLLElist)
{
    int n = 0; 

    while(n != -1)
    {
        std::cout << "НАЧАЛО РАБОТЫ  MLLE list" << std::endl;
        std::cout << "Выберите опцию: " << std::endl;
        std::cout << princhain()<<std::endl;
        std::cout << "1. введите от 0 до " << MLLElist.size()-1 << " чтобы выбрать элемент" << std::endl;
        std::cout << "2. введите -1 для выхода из функции" << std::endl;
        std::cout << princhain()<<std::endl;
        std::cout << "Ваш ввод - ";
        std::cin >> n;
        
        if(n == -1) break;
        
        if(n >= 0 && n < MLLElist.size())
        {
            std::list<MLLE*>::iterator it = MLLElist.begin();
            std::advance(it, n);
            
            int choice = 0;
            while(choice != -1)
            {
                std::cout << "Работа с " << n << " элементом(MLLE) " << std::endl;
                std::cout << "Выберите опцию: " << std::endl;

                std::cout << prinequal() << std::endl;
                
                std::cout << "1. введите 1 для промотра double_number ("<<n<<")"  << std::endl;
                std::cout << "2. введите 2 для просмотра integer_number ("<<n<<")"  <<std::endl;
                std::cout << "3. введите 3 для просмотра integer_number_fractional_part ("<<n<<")" << std::endl;
                std::cout << "4. введите 4 для просмотра integerHEX ("<<n<<")" << std::endl;
                std::cout << "5. введите 5 для просмотра doubleHEX ("<<n<<")" << std::endl;
                std::cout << "6. введите 6 для просмотра integerBIN ("<<n<<")" << std::endl;
                std::cout << "7. введите 7 для просмотра doubleBIN ("<<n<<")" << std::endl;
                std::cout << "8. введите 8 для просмотра right_forward_ptr (а точнее на какое double_number указывает) ("<<n<<")" << std::endl;
              
                std::cout << "введите -1 для выхода" << std::endl;
                
                std::cout << prinequal() << std::endl;
                
                std::cout << std::endl;
                std::cout << "Ваш ввод - ";
                
                std::cin >> choice;
                std::cout << std::endl;
                if(choice == -1) break;
                
                // Используем choice для выбора поля, а не n
                switch(choice) {
                    case 1:
                        std::cout << prinl() <<"     double_number -- " <<(*it)->double_number <<"       "<< prinl() << std::endl;
                        break;
                    case 2:
                        std::cout <<prinl()<< "     integer_number -- "<<(*it)->integer_number<<"       " <<prinl()<< std::endl;
                        break;
                    case 3:
                        std::cout <<prinl()<<"      integer_number_fractional_part -- "<< (*it)->integer_number_fractional_part <<"     "<<prinl()<< std::endl;
                        break;
                    case 4:
                        std::cout <<prinl()<<"      integerHEX -- "<<(*it)->integerHEX <<"     "<<prinl()<<std::endl;
                        break;
                    case 5:
                        std::cout <<prinl()<<"      doubleHEX -- "<<(*it)->doubleHEX <<"     " <<prinl()<< std::endl;
                        break;
                    case 6:
                        std::cout <<prinl()<<"      integerBIN -- "<<(*it)->integerBIN <<"      "<<prinl()<< std::endl;
                        break;
                    case 7:
                        std::cout <<prinl()<<"      doubelBIN -- "<< (*it)->doubleBIN <<"       "<<prinl()<< std::endl;
                        break;
                    case 8:
                        if((*it)->right_forward_prt == nullptr)
                        {
                            std::cout << prinl() <<"        right_forward_ptr -- "<< "nullptr"<<"       " << prinl() << std::endl;
                        }
                        else std::cout <<prinl()<<"     right_forward_ptr -- "<< (*it)->right_forward_prt->double_number <<"        "<<prinl()<<std::endl;
                        break;
                    default:
                        std::cout << "Неверный выбор!" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Неверный индекс элемента!" << std::endl;
        }
    }
}

void intelectual_print(std::list<DLLE*> DLLE0, std::list<MLLE*> MLLE0)
{
    int n = 0; 
    
    while(n != -1)
    {
        std::cout << "Выберите с каким контейнером вы хотите работать: " << std::endl;
        std::cout << "1. для работы с DLLE листом нажмите - '1' " << std::endl;
        std::cout << "2. для работы с MLLE листом нажмите - '2' " << std::endl;
        std::cout << "3. для выхода нажмите - '-1' " << std::endl; // Добавляем явный вариант выхода
        std::cout << "Ваш ввод - ";
        std::cin >> n;
        std::cout << std::endl;
        
        prinequal();
        
        switch (n)
        {
            case 1: 
                printDLLE(DLLE0);
                break;
            case 2: 
                printMLLE(MLLE0);
                break;
            case -1:
                std::cout << "Выход из функции..." << std::endl;
                break;
            default:
                std::cout << "Неверная опция!" << std::endl;
                break;
        }
        
        std::cout << std::endl;
    }
}