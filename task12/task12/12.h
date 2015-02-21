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


class Musician: public Artist
{
   private:
          int albums_Amount;
          char instrument[64];
    
      
           
    public:
         Musician(char*, int, int, char*);
         void showInfo();
    
};