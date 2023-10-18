#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    /*
    
    (10 pts) Create a new std::map
    (10 pts) Insert all Twitter data into the std::map. Use a proper data
    member in TwitterData class to be the key. Use TwitterData class as
    the value.
    (10 pts) Iterate through the std::map and print the key-value pairs line
    by line
    (10 pts) Find the person whose username is savage1 and print out the
    entire record
    (10 pts) Remove this person from the map
    
    */

    cout << endl << "Twitter1 Data" << endl;
    map<string, TwitterData> twitter_map;
    for (int i = 0; i < 5; ++i)
    {
        twitter_map.insert(pair<string, TwitterData>(twitter_data[i].getUserName(), twitter_data[i]));
    }

    for (auto it = twitter_map.begin(); it != twitter_map.end(); ++it)
    {
        cout << "Key: " << it->first << " " << it->second << endl;
    }

    auto it = twitter_map.find("savage1");
    if (it != twitter_map.end())
    {
        cout << "Search for savage1: " << it->second << endl;
        twitter_map.erase(it);
    }

    /*
    (40 pts) Map Scenario 2: Search based on EmailAddress
    (10 pts) Create a new std::map
    (10 pts) Insert all Twitter data into the std::map. Use a proper data
    member in TwitterData class as the key. Use TwitterData class as the
    value.
    (10 pts) Iterate through the std::map and print the key-value pairs line
    by line
    (5 pts) Find the person whose email is kat@gmail.com and print out
    the entire record
    (5 pts) Remove this person from the map
    */

    cout << endl << "Twitter2 Data" << endl;
    map<string, TwitterData> twitter_map2;
    for (int i = 0; i < 5; ++i)
    {
        twitter_map2.insert(pair<string, TwitterData>(twitter_data[i].getEmail(), twitter_data[i]));
    }

    for (auto it = twitter_map2.begin(); it != twitter_map2.end(); ++it)
    {
        cout << "Key: " << it->first << " " << it->second << endl;
    }

    auto it2 = twitter_map2.find("kat@gmail.com");
    if (it2 != twitter_map2.end())
    {
        cout <<  "Search For kat: " << it2->second << endl;
        twitter_map2.erase(it2);
    }



    return 0;
}