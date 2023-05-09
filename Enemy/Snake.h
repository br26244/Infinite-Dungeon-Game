#ifndef __SNAKE_H__
#define __SNAKE_H__

class Snake : public Enemy {
public:
    Snake(int health, int damage);

    char getSymbol() const override;    // Override the getSymbol function to return 's'
};
#endif