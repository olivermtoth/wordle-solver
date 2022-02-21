#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> wordList;

void blank(char letter);
void green(char letter, int place);
void orange(char letter, int place);
bool isContain(char letter, std::string container);
void split(std::string guess, std::string result);



int main()
{
    std::ifstream file("words.txt");

    std::string temp;
    while (file>>temp)
    {
        wordList.push_back(temp);
    }
    
    //for(std::string word : wordList){std::cout<<word<<std::endl;}

    std::cout<<"############ WORDLE SOLVER ################"<<std::endl;
    std::cout<<"HOW TO PLAY:"<<std::endl;
    std::cout<<" g = good letter in good place (green)\n o = good letter in wrong place(orange)\n b = the letter not is not in the word(blank)\n"<<std::endl;
    bool solved = false;
    while(solved != true)
    {
        std::string temp1;
        std::cout<<"Enter your guess: ";
        std::cin>>temp;
        if(temp == "-1"){break;}
        std::cout<<"Enter your result: ";
        std::cin>>temp1;
        split(temp, temp1);
        std::cout<<"There are "<<wordList.size()<<" pontential word, do you want ot see them? (y/n)";
        char reply;
        std::cin>>reply;
        if (reply == 'y')
        {
            for(std::string word : wordList){std::cout<<word<<std::endl;}
        }
        else{continue;}
    }
}

void blank(char letter)
{
    for(int i = 0; i<wordList.size();i++)
    {
        for(int j = 0; j<5; j++)
        {
            if (wordList[i][j]==letter)
            {
                wordList[i] = "0";
            }
            
        }
    }
    wordList.erase(std::remove(wordList.begin(), wordList.end(),"0"),wordList.end());
    wordList.shrink_to_fit();
}

void green(char letter, int place)
{
    for(int i = 0; i<wordList.size();i++)
    {
        
        if (wordList[i][place]!=letter)
        {
            wordList[i] = "0";
        }
    }
    wordList.erase(std::remove(wordList.begin(), wordList.end(),"0"),wordList.end());
    wordList.shrink_to_fit();
}

bool isContain(char letter, std::string container)
{
    for (int i = 0; i < 5; i++)
    {
        if(container[i]== letter)
        {
            return true;
        }
    }
    return false;
} 

void orange(char letter, int place)
{
    for(int i = 0; i<wordList.size();i++)
    {
        
        if (wordList[i][place]==letter)
        {
            wordList[i] = "0";
        }
        else if(isContain(letter, wordList[i]) == false)
        {
            wordList[i]= "0";
        }

    }
    wordList.erase(std::remove(wordList.begin(), wordList.end(),"0"),wordList.end());
    wordList.shrink_to_fit();
}

void split(std::string guess, std::string result)
{
    for(int i =0; i<5; i++)
    {
        if (result[i] == 'g')
        {
            green(guess[i], i);
        }
        else if(result[i] == 'o')
        {
            orange(guess[i], i);
        }
        else if(result[i] == 'b')
        {
            blank(guess[i]);
        }
    }
}
