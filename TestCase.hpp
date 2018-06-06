//
// Created by shosh on 6/6/18.
//

#ifndef TESTCASE_TESTCASE_H
#define TESTCASE_TESTCASE_H
#include <sstream>
#include <string>
#include <iostream>

//spaciel massge:

#define  failedfunc1 " Function should return "
#define failedfunc2 " but returned "
#define failedeq " should equal "
#define  failednoequal " should not equal "
#define oupfailed1 " string value should be "
#define oupfailed2 " but is "
class TestCase {
public:
    //ctor
    TestCase(std::string s,std::ostream &error):
            numOfFailed(0),numOfPassed(0), Total_Cheaks(0),case_name(s){}

// cheak for errors:
    template <typename T> TestCase& check_equal (T a, T b) {
        Total_Cheaks++;
        if (a == b) {
            numOfPassed++;
        } else {
            std::cout << failedmsg << Total_Cheaks << ": " << a << failedeq << b<< "!\n";
            numOfFailed++;
        }
        return *this;
    }
    template <typename T> TestCase& check_different (T a, T b){
        Total_Cheaks++;
        if (a!=b){
            numOfPassed++;
        }else{
            std::cout <<failedmsg << Total_Cheaks <<": "<< a << failednoequal << b<<"!\n";
            numOfFailed++;
        }
        return *this;
    }
    template <typename Func,typename T1,typename T2> TestCase& check_function (Func foo ,T1 a, T2 b){
        Total_Cheaks++;
        if ((*foo)(a)==b){
            numOfPassed++;
        }else{
            numOfFailed++;
            std::cout <<failedmsg << Total_Cheaks <<":"<<failedfunc1 << b << failedfunc2 << (*foo)(a)<<"!\n";

        }
        return *this;
    }
    template <typename T> TestCase& check_output (T a, std::string b){
        std::stringstream sstream;
        sstream << a;
        Total_Cheaks++;
        if(sstream.str() == b){
            numOfPassed++;
        }else{
            numOfFailed++;
            std::cout <<failedmsg << Total_Cheaks <<":"<< oupfailed1<<b<<oupfailed2<< a<<"!\n";

        }
        return *this;
    }
    void print()
    {
        std::cout << case_name << ": " << numOfFailed << " failed, " << numOfPassed << " passed, " << Total_Cheaks << " total." << "\n"<<"---\n";
    }


private:
    //body
    std::string case_name;
    int numOfFailed,numOfPassed, Total_Cheaks;
    //spaciel massge:
    std::string failedmsg=case_name +": Failure in test #";

    //


};


#endif //TESTCASE_TESTCASE_H
