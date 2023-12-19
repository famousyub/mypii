

#include <vector>
#include<string>
#include<iostream>
#include<cstdlib>

#include<algorithm>
#include <functional>


using namespace std ;



void erase_firsrt_occur(string  & mainStr , const string & toErase)
{

    size_t pos =  mainStr.find(toErase);

    if(pos != std::string::npos)
    {
        mainStr.erase(pos, toErase.length());

    }
}

void _eraseall(string &mainStr , const string &toErase)
{

    size_t pos= string::npos;

    while((pos =mainStr.find(toErase) ) != string::npos) {

        mainStr.erase(pos, toErase.length());


    }
}







/*
 * Erase First Occurrence of given  substring from main string.
 */
void eraseSubStr(std::string & mainStr, const std::string & toErase)
{
    // Search for the substring in string
    size_t pos = mainStr.find(toErase);

    if (pos != std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

/*
 * Erase all Occurrences of given substring from main string.
 */
void eraseAllSubStr(std::string & mainStr, const std::string & toErase)
{
    size_t pos = std::string::npos;

    // Search for the substring in string in a loop untill nothing is found
    while ((pos  = mainStr.find(toErase) )!= std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

/*
 * Erase all Occurrences of all given substrings from main string using C++11 stuff
 */
void eraseSubStrings(std::string & mainStr, const std::vector<std::string> & strList)
{
    // Iterate over the given list of substrings. For each substring call eraseAllSubStr() to
    // remove its all occurrences from main string.
    std::for_each(strList.begin(), strList.end(), std::bind(eraseAllSubStr, std::ref(mainStr), std::placeholders::_1));
}

/*
 * Erase all Occurrences of all given substrings from main string using Pre C++11 stuff
 */
void eraseSubStringsPre(std::string & mainStr, const std::vector<std::string> & strList)
{
    // Iterate over the given list of substrings. For each substring call eraseAllSubStr() to
    // remove its all occurrences from main string.
    for (std::vector<std::string>::const_iterator it = strList.begin(); it != strList.end(); it++)
    {
        eraseAllSubStr(mainStr, *it);
    }

}



/*
 * Erase all Occurrences of all given substrings from main string using C++11 stuff
 */
void eraseSubStrings(std::string & mainStr, const std::vector<std::string> & strList)
{
    // Iterate over the given list of substrings. For each substring call eraseAllSubStr() to
    // remove its all occurrences from main string.
    std::for_each(strList.begin(), strList.end(), std::bind(eraseAllSubStr, std::ref(mainStr), std::placeholders::_1));
}

int main (int argc , const char *argv[])

{
 


    cout << "enter  phrase" <<endl;

    string _enter , fg ;
    cin>>  _enter ;

   
     cout << "enter  erase" <<endl;

    eraseAllSubStr(_enter, fg);
    std::cout << _enter << std::endl;
    eraseSubStringsPre(_enter, { "for", "is", "testing" });
    std::cout << _enter << std::endl;
    return 0;

}