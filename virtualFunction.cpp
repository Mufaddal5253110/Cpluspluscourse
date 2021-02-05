/*Example of use of virtual function

*/

#include <iostream>
using namespace std;

class MyChannel
{
protected:
    string title;
    float rating;

public:
    MyChannel(string title, float rating)
    {
        this->title = title;
        this->rating = rating;
    }

    virtual void display() {} // virtual function
};

class MyChannelVid : public MyChannel
{
    float vidlen;

public:
    MyChannelVid(string title, float rating, float vidlen) : MyChannel(title, rating)
    {
        this->vidlen = vidlen;
    }
    void display()
    {
        cout << "-----------My Channel Video----------\n"
             << "Title: " << title << endl
             << "Rating: " << rating << endl
             << "Video Length: " << vidlen << " min\n\n";
    }
};

class MyChannelText : public MyChannel
{
    int words;

public:
    MyChannelText(string title, float rating, int words) : MyChannel(title, rating)
    {
        this->words = words;
    }
    void display()
    {
        cout << "-----------My Channel Video Text----------\n"
             << "Title: " << title << endl
             << "Rating: " << rating << endl
             << "Text Length: " << words << " words\n\n";
    }
};

int main()
{
    string titl;
    float rat, vidln;
    int wrd;

    //For video
    titl = "Android BootCamp";
    rat = 4.89;
    vidln = 12.22;
    MyChannelVid my_channel_video_obj(titl, rat, vidln);
    // my_channel_video_obj.display();

    //For video text
    titl = "Android BootCamp";
    rat = 4.89;
    wrd = 552;
    MyChannelText my_channel_video_text_obj(titl, rat, wrd);
    // my_channel_video_obj.display();

    MyChannel *my_channel_pointer[2];
    my_channel_pointer[0] = &my_channel_video_obj;
    my_channel_pointer[1] = &my_channel_video_text_obj;

    my_channel_pointer[0]->display();
    my_channel_pointer[1]->display();

    return 0;
}

/*OUTPUT
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ virtualFunction.cpp -o virtualFunction } ; if ($?) { .\virtualFunction }
-----------My Channel Video----------
Title: Android BootCamp
Rating: 4.89
Video Length: 12.22min

-----------My Channel Video Text----------
Title: Android BootCamp
Rating: 4.89
Text Length: 552 words
*/