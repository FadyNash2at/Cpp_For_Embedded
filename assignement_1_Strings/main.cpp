#include<iostream>
#include<string>
#include<sstream>

using namespace std;

/* 
    calculate string function get array of string and the number of array elements 
    and it print the needed output
 */
void calculate_string(string arr[],int num)
{
    int music_bytes=0;      
    int images_bytes=0;
    int movies_bytes=0;
    int other_bytes=0;
    for(int i=0;i<num;i++)
    {
        stringstream s(arr[i]);
        string word;
        string bytes;
        s>>word;
        string extension=word.substr((word.find_last_of("."))+1);   //to get the extension of the string
        s>>bytes;
        bytes=bytes.substr(0,bytes.find("b"));                      //to get the bytes of each type
        if( (extension=="mp3") || (extension=="aac") || (extension=="flac") )
        {
            music_bytes+=stoi(bytes);
        }
        else if( (extension=="jpg") || (extension=="bmp") || (extension=="gif") )
        {
            images_bytes+=stoi(bytes);
        }
        else if( (extension=="mp4") || (extension=="avi") || (extension=="mkv") )
        {
            movies_bytes+=stoi(bytes);
        }
        else
        {
            other_bytes+=stoi(bytes);
        }
    }
    cout<<"music "<<music_bytes<<"b images "<<images_bytes<<"b movies "<<movies_bytes<<"b other "<<other_bytes<<"b"<<endl;
}

int main()
{

    /*
    input format:
        first take the number of test cases. 
        second take the number of lines of each test case. 
        then get the lines of the test case and put them in array and pass the array to the function to get 
        the needed output for every testcase.
    */
    
    int num_of_tests;
    cin>>num_of_tests;
    int num[num_of_tests];
    string **arr = new string*[num_of_tests];
    
    for(int i=0;i<num_of_tests;i++)
    {
        cin>>num[i];
        arr[i]=new string[num[i]];
    }
    for(int i=0;i<num_of_tests;i++)
    {
        for(int j=0;j<num[i];j++)
        {
            cin>>ws;        //to clear the buffer 
            getline(cin,arr[i][j]);
        }
    }

    for(int i=0;i<num_of_tests;i++)
    {
        calculate_string(arr[i],num[i]);
    }

    return 0;
}

