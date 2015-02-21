# include "12.h"

int main()
{
    Artist actor("Johnny Depp", 1984);
    actor.showInfo();  

	Musician guitarist("Brian May", 1964, 3, "Guitar");
    guitarist.showInfo();  
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

