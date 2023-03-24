#include "TOFEL.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//set the tofel score, constructor 
ToeflScore :: ToeflScore(int reading_score, int listening_score, int speaking_score, int writing_score, int Tscore)
{
    reading=reading_score;
    listening=listening_score;
    speaking=speaking_score;
    writing=writing_score;
    totalScore=Tscore; 

}
//default constructor - left blank on purpose 
ToeflScore:: ToeflScore()
{

}

// setters
void ToeflScore:: set_Reading(int reading_score)
{
     reading=reading_score;
}
void ToeflScore:: set_Listening(int listening_score)
{
    listening=listening_score;
}
void ToeflScore::set_Speaking(int speaking_score)
{
    speaking=speaking_score;
}
void ToeflScore::set_Writing(int writing_score)
{
    writing=writing_score;
}

// getters
int ToeflScore::get_Reading()const
{
    return this->reading; 
}
int ToeflScore::get_Listening()const
{
    return this->listening; 
}
int ToeflScore::get_Speaking()const
{
    return this->speaking;
}
int ToeflScore:: get_Writing()const
{
    return this->writing;
}
//calculates the total score 
int ToeflScore:: get_TotalScore()const
{
    return writing+reading+listening+speaking;
}


