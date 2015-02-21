#include <cstdlib>
#include <iostream>

using namespace std;

class Artist
{
   public: 
        Artist(char*, int);
        virtual void showInfo();
      
   protected:
         char name[256];
         int career_Beginning;
};