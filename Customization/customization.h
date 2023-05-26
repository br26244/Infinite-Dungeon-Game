#ifndef CUSTOMIZATION
#define CUSTOMIZATION

#include "customizationModulation.cpp"

class Customization{
    private:
        CustomizationModulation modulation;
    public:
        Customization();
        ~Customization();

        void showFirstOption();
        void showSecondOption();
        void showThirdOption();

        int getUserChoice();

        int getHealth();
        int getStr();
        int getGold();
        int getArm();

    

};

#endif