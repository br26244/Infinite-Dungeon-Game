
#ifndef __GAME_LAYOUT_H__
#define __GAME_LAYOUT_H__

class GameLayout {
private:
    int hp, str, def, exp, level, gold;

public:
    GameLayout();
    GameLayout(int hp, int str, int def, int exp, int level, int gold);
    ~GameLayout();

    int getHp() const;
    int getStr() const;
    int getDef() const;
    int getExp() const;
    int getLevel() const;
    int getGold() const;

    void setHP(int hp);
    void setStr(int str);
    void setDef(int def);
    void setExp(int exp);
    void setLevel(int level);
    void setGold(int gold);
    void setAll(int hp, int str, int def, int exp, int level, int gold);
    
    void printStatus(); 
};

#endif // __GAME_LAYOUT_H__
