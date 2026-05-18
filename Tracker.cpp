#include "Tracker.h"
#include <fstream>

void Tracker::addProblem()
{
    Problem p;

    cout<<"Enter title: ";
    cin.ignore();
    getline(cin,p.title);

    cout<<"Enter topic: ";
    getline(cin,p.topic);

    cout<<"Enter difficulty: ";
    getline(cin,p.difficulty);

    cout<<"Solved? (1/0): ";
    cin>>p.solved;

    problems.push_back(p);
    saveToFile();
    cout<<"Problem Added Successfully\n";
}

void Tracker::viewProblems()
{
    for(auto p:problems)
    {
        cout<<p.title<<" | "
            <<p.topic<<" | "
            <<p.difficulty<<" | ";

        if(p.solved)
            cout<<"Solved\n";

        else
            cout<<"Pending\n";
    }
}

void Tracker::saveToFile()
{
    ofstream fout("problems.txt");

    for(auto p:problems)
    {
        fout<<p.title<<endl;
        fout<<p.topic<<endl;
        fout<<p.difficulty<<endl;
        fout<<p.solved<<endl;
    }

    fout.close();
}
void Tracker::loadFromFile()
{
    ifstream fin("problems.txt");

    Problem p;

    while(getline(fin,p.title))
    {
        getline(fin,p.topic);
        getline(fin,p.difficulty);

        fin>>p.solved;
        fin.ignore();

        problems.push_back(p);
    }

    fin.close();
}
void Tracker::searchProblem()
{
    string topic;

    cin.ignore();

    cout<<"Enter topic: ";

    getline(cin,topic);

    for(auto p:problems)
    {
        if(p.topic==topic)
        {
            cout<<p.title<<" | "
                <<p.topic<<" | "
                <<p.difficulty<<" | ";

            if(p.solved)
                cout<<"Solved\n";

            else
                cout<<"Pending\n";
        }
    }
}