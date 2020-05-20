#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>

void play_game()
{
    int random = rand() % 251;
    //std::cout<< random <<std::endl;
    std::cout << "guess a number" << std::endl;
    while(true)
    {
        int guess;
        std::cin >> guess;
        if(guess == random)
        {
            std::cout << "YOU WIN\n" << std::endl;
            break;
        }
        else if (guess < random)
        {
            std::cout << "too low\n"<<std::endl;
        }
        else
        {
            std::cout << "too high" << std::endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        std::cout << "0. QUIT" << std::endl << "1. Play Game\n";
        std::cin >>choice;

        switch(choice)
        {
            case 0:
                std::cout << "Thanks for nothing\n";
                return 0;
            case 1:
                play_game();
                break;
        }
    }
    while (choice != 0);
}


