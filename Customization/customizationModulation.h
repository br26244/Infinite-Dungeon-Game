#ifndef CUSTOMIZATIONMODULATION
#define CUSTOMIZATIONMODULATION

class CustomizationModulation{
    private:
       
        int health;
        int gold;
        int arm;
        int str;

    public:
        CustomizationModulation();
        ~CustomizationModulation();

        void increaseHealth(int vHealth);
        void increaseStr(int vStr);
        void increaseGold(int vGold);
        void increaseArm(int vArm);

        int getHealth();
        int getStr();
        int getGold();
        int getArm();

    

};

#endif