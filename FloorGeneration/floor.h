#include <iostream>
#include <vector>

using namespace std;

class Floor{
    public:
        Floor();

        void loadFloor(string file);
        void clearFloor();
        void printFloor();
        

    private:
        vector <string> floorData;

};