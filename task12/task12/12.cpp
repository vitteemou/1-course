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