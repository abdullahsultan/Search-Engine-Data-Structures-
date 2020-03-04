#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Node
{
private:
    string name;
    float rating;
    int votes;
    Node *next;
public:
    Node()
    {
        next=nullptr;
    }

    Node(string n,float r,int v)
    {
        name=n;
        rating=r;
        votes=v;
        next=nullptr;
    }
    void set_name(string n)
    {
        name=n;
    }
    string get_name()
    {
        return name;
    }
    void set_rating(float r)
    {
        rating=r;
    }
    float get_rating()
    {

        return rating;
    }
    void set_votes(int v)
    {
        votes=v;
    }
    int get_votes()
    {
        return votes;
    }
    void setnext(Node *nex)
    {
        next=nex;
    }

    Node* getnext()
    {
        return next;
    }

};

class Search_Engine
{
private:
    Node *head;
public:

    //***********************************Reading File******************************************//
    Node* get_head()
    {
        return head;
    }
    Search_Engine()
    {
        head=nullptr;
    }
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
            //cout<<votes<<"   "<<movie_name<<"     "<<votes<<endl;
            stringstream r(rating);
            stringstream v(votes);
            int int_votes;
            float int_rating;
            r>>int_rating;
            v>>int_votes;
            add_data(new Node(movie_name,int_rating,int_votes));
        }
        cout<<"Done file reading\n";
    }
    //***************************************************End**********************************************************//
    //********************//
    //********************************************Add at start Linked List*************************************//

    void add_data(Node *x)  //Add at start
    {
        x->setnext(head);
        head=x;
    }
    //***************************************************End**********************************************************//
    //********************//
    //*********************************************Search Functions****************************************************//
    Node* q1(Node *x)
    {
        Node *d=new Node;
        d ->set_rating(0.0);
        while(x!=nullptr)
        {
            if(x->get_rating() > d->get_rating())
                d=x;
            x=x->getnext();
        }
        return d;
    }
    Node* q2(Node *x)
    {
        Node *d=new Node;
        d ->set_rating(10.0);
        while(x!=nullptr)
        {
            if(x->get_rating() < d->get_rating())
                d=x;
            x=x->getnext();
        }
        return d;
    }
    Node* q3(Node *x)
    {
        Node *d=new Node;
        d->set_votes(0);
        while(x !=nullptr)
        {
            if(x->get_votes() > d->get_votes())
                d=x;
            x=x->getnext();
        }
        return d;
    }
    Node* q4(Node *x)
    {
        Node *d=new Node;
        d->set_votes(9999);
        while(x!=nullptr)
        {
            if(x->get_votes() < d->get_votes())
                d=x;
            x=x->getnext();
        }
        return d;
    }
    float q5(Node *x)
    {
        int c=0;
        float d=0.0;
        while(x!=nullptr)
        {
            d=d+x->get_rating();
            c++;
            x=x->getnext();
        }
        return d/c;
    }
    Node* q6(Node *x,string n)
    {
        while(x!=nullptr)
        {
            if(x->get_name()==n)
            {

                return x;
            }
            x=x->getnext();
        }
        cout<<"Not found\n";
        return nullptr;
    }
    void q7(Node *x,float d)
    {
        while(x!=nullptr)
        {
            if(x->get_rating()==d)
            {

                cout<<x->get_name()<<"      ";
            }
            x=x->getnext();
        }
        cout<<endl;
    }
};


    int main()
    {
        Search_Engine se;
        se.reader();
        while(true)
        {
            int choice;
            cout<<"Enter\n1 to display movie with highest rating\n2 to display movie with lowest rating\n3 to display most popular movie\n4 to display least popular movie\n5 to get average rating\n6 to search a movie\n7 to search movie with rating\n";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<se.q1(se.get_head())->get_name()<<endl;
                break;
            case 2:
                cout<<se.q2(se.get_head())->get_name()<<endl;
                break;
            case 3:
                cout<<se.q3(se.get_head())->get_name()<<endl;
                break;
            case 4:
                cout<<se.q4(se.get_head())->get_name()<<endl;
                break;
            case 5:
                cout<<se.q5(se.get_head())<<endl;
                break;
            case 6:
            {
                string name;
                cout<<"Enter name of movie:";
                cin>>name;
                Node* temp = se.q6(se.get_head(),name);
                if(temp != nullptr)
                    cout<<"Movie "<<temp->get_name()<<" has rating "<<temp->get_rating()<<" and votes "<<temp->get_votes()<<endl;
            }
            break;
            case 7:
            {
                float r;
                cout<<"Enter rating  ";
                cin>>r;
                se.q7(se.get_head(),r);
            }

            }

        }


        return 0;
    }

