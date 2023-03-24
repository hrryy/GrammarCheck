//TOFEL.hpp to implement ToeflScore class
#ifndef TOEFLSCORE_HPP
#define TOEFLSCORE_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;


class ToeflScore 
{
    public:
    //constructors 
    ToeflScore(int reading_score, int listening_score, int speaking_score, int writing_score, int Tscore);
    ToeflScore();

    // setters
    void set_Reading(int reading_score);
    void set_Listening(int listening_score);
    void set_Speaking(int speaking_score);
    void set_Writing(int writing_score);

    // getters
    int get_Reading()const;
    int get_Listening()const;
    int get_Speaking()const ;
    int get_Writing()const;
    int get_TotalScore()const;

private:
    // each field had a score from 0 to 30
    int reading;
    int listening;
    int speaking;
    int writing;
    int totalScore; // out of 120
};

#endif