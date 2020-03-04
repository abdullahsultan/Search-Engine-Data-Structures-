#include <iostream>
#include<string>
#include<fstream>
#include <sstream>
#include <cmath>

using namespace std;

class Node
{
public:
    string name;
    double rating;
    int votes;
    Node *next;


    Node()
    {
        next =nullptr;
    }
    Node(string n, float r, int v)
    {
        name=n;
        rating=r;
        votes=v;
        next=nullptr;
    }

};

class Search
{
public:
    Node *my_array[1000];
    Search()
    {
        for(int x=0; x<1000; x++)
            my_array[x]=nullptr;
    }

    //***********************************Reading File******************************************//
    void reader()
    {
        ifstream in;
        in.open("data.txt");
        string movie_name;
        string rating;
        string votes;
        string line;
        while(getline(in, line))
        {
            movie_name="";
            rating="";
            votes="";
            int choice=0;
            for(int x=0; line[x]!='\0' ; x++)
            {
                if(line[x]==9)
                    choice++;
                if(line[x] !=9 && line[x] != 32)
                {
                    if(choice==0)
                        movie_name=movie_name+line[x];
                    else if(choice==1)
                        rating=rating+line[x];
                    else if(choice==2)
                        votes=votes+line[x];
                }
            }

            stringstream r(rating);
            stringstream v(votes);
            int int_votes;
            float int_rating;
            r>>int_rating;
            v>>int_votes;
            add_data(movie_name,int_rating,int_votes);
        }
        cout<<"Done file reading\n";
    }

    //***************************************************End**********************************************************//
    //********************//
    //********************************************Add at start Seprate Chaining*************************************//

    void add_data(string movie_name,float rating,int votes)
    {
        int place=abs((rating*100)-1);

        if(my_array[place]==nullptr)
        {
            my_array[place] = new Node(movie_name,rating,votes);
        }
        else
        {
            Node *temp = my_array[place];
            Node *temp1=new Node(movie_name,rating,votes);
            temp1->next=temp->next;
            temp->next=temp1;


        }

    }

    //***************************************************End**********************************************************//
    //********************//
    //*********************************************Search Functions****************************************************//

    void q1()
    {
        int place=abs((10.0*100)-1);
        Node *temp = my_array[place];
        while(temp != nullptr)
        {
            cout<<temp->name;
            temp=temp->next;
        }
    }
    void q2()
    {
        int place=abs((1.0*100)-1);
        Node *temp = my_array[place];
        while(temp != nullptr)
        {
            cout<<temp->name;
            temp=temp->next;
        }
    }
    void q3()
    {
        Node *temp1=new Node();
        temp1->votes=0;
        for(int x=0; x<1000; x++)
        {
            if(my_array[x] != nullptr)
            {
                Node *temp = my_array[x];
                while(temp != nullptr)
                {
                    if(temp->votes>temp1->votes)
                    {
                        temp1=temp;
                    }
                    temp=temp->next;

                }


            }
        }
        cout<<"Movie Name   "<<temp1->name<<"With rating "<<temp1->rating;
    }
    void q4()
    {
        Node *temp1=new Node();
        temp1->votes=99999;
        for(int x=0; x<1000; x++)
        {
            if(my_array[x] != nullptr)
            {
                Node *temp = my_array[x];
                while(temp != nullptr)
                {
                    if(temp->votes<temp1->votes)
                    {
                        temp1=temp;
                    }
                    temp=temp->next;

                }


            }
        }
        cout<<"Movie Name   "<<temp1->name<<" With votes"<<temp1->votes<<endl;
    }
    void q5()
    {
        int counter=0;
        float r=0.0;
        for(int x=0; x<1000; x++)
        {
            if(my_array[x] != nullptr)
            {
                Node *temp = my_array[x];
                while(temp != nullptr)
                {
                    r=r+temp->rating;
                    counter++;
                    temp=temp->next;
                }
            }
        }
        cout<<"Average Rating: "<<r/counter<<endl;
    }

    void q6(string n)
    {
        for(int x=0; x<1000; x++)
        {
            if(my_array[x] != nullptr)
            {
                Node *temp = my_array[x];
                while(temp != nullptr)
                {
                    if(n==temp->name)
                        cout<<n<<" has rating: "<<temp->rating<<" and votes: "<<temp->votes<<endl;

                    temp=temp->next;
                }


            }
        }
    }



    void disp()
    {
        int counter=0;
        for(int x=0; x<1000; x++)
        {
            if(my_array[x] != nullptr)
            {
                Node *temp = my_array[x];
                while(temp != nullptr)
                {
                    cout<<temp->name;
                    temp=temp->next;
                    counter++;
                }


            }
        }
    }

};



int main()
{
    Search se;
    se.reader();
    while(true)
    {
        int choice;
        cout<<"Enter\n1 to display movie with highest rating\n2 to display movie with lowest rating\n3 to display most popular movie\n4 to display least popular movie\n5 to get average rating\n6 to search by movie name\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            se.q1();
            break;
        case 2:
            se.q2();
            break;
        case 3:
            se.q3();
            break;
        case 4:
            se.q4();
            break;
        case 5:
            se.q5();
            break;
        case 6:
            {
                string name; cout<<"Enter name of movie : "; cin>>name;
                se.q6(name);

            }

        }

    }





    return 0;
}
