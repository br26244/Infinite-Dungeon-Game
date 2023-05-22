#ifndef CUSTOMIZATION
#define CUSTOMIZATION

class Customization{
    private:
       
        int health;
        int gold;
        int arm;
        int str;

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