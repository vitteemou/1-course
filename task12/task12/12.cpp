# include "12.h"

Artist::Artist(char *ar_name, int ar_career)
{
     strcpy(name, ar_name);
     career_Beginning=ar_career;
}

void Artist::showInfo()
{
     cout<<"Artist: "<<endl;
     cout<<endl;
     
     cout<<"Name: "<<name<<endl;
     cout<<"Beginning of the career: "<<career_Beginning<<endl;
     cout<<endl;
}

Musician::Musician(char* ar_name, int ar_career,  int ar_amount, char* ar_instrument, char* al_title, int al_year) : Artist(ar_name, ar_career)
{
      strcpy(name, ar_name);
      career_Beginning = ar_career;
      albums_Amount = ar_amount;
      strcpy(instrument, ar_instrument);
      
}


void Musician::showInfo()
{
     cout<<"Musician: "<<endl;
     cout<<endl;
     
     cout<<"Name: "<<name<<endl;
     cout<<"Beginning of the career: "<<career_Beginning<<endl;
     cout<<"Instrument: "<<instrument<<endl;
     cout<<"Amount of the albums: "<<albums_Amount<<endl;
}

