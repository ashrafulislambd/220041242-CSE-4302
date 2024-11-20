#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class CharacterActions {
public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() = 0;
};

class BaseCharacter : public CharacterActions {
protected:
    string name;
    double health;
    double mana;
public:
    BaseCharacter(string name, double health) : name(name), health(health), mana(0) {}

    void attack(int power, BaseCharacter& enemy) {
        cout << name << " attacks with power " << power << "!" << endl;
        enemy.setHealth(enemy.getHealth() - power);
        cout << enemy.getName() << " takes " << power << " damage! Health now: " <<
            enemy.getHealth() << endl;
        mana += 50;
    }

    void useSpecialAbility(int power, BaseCharacter& enemy) {
        if(mana < 100) return;
        enemy.setHealth(enemy.getHealth() - power);
        cout << enemy.getName() << " takes " << power << " damage! Health now: " <<
            enemy.getHealth() << endl;
        mana = 0;
    }

    void defend() {
        cout << "Attack defended!" << endl;
    }

    void displayStats() {
        cout << "--------------------------------" << endl;
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Mana   : " << mana << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
    }

    double getHealth() {
        return health;
    }

    void setHealth(double value) {
        health = value;
    }

    string getName() {
        return name;
    }
};

BaseCharacter* boss;

class Warrior : public BaseCharacter {
public:
    Warrior() : BaseCharacter("Warrior", 100) {}

    void attack(BaseCharacter& enemy) {
        BaseCharacter::attack(25, enemy);
    }

    void attack() {
        attack(*boss);
    }

    void useSpecialAbility() {
        useSpecialAbility(*boss);
    }

    void useSpecialAbility(BaseCharacter& enemy) {
        cout << name << " uses Arcance Blast with power 30!" << endl;
        BaseCharacter::useSpecialAbility(30, enemy);
    }
};

class Mage : public BaseCharacter {
public:
    Mage() : BaseCharacter("Mage", 120) {}

    void attack(BaseCharacter& enemy) {
        BaseCharacter::attack(20, enemy);
    }

    void attack() {
        attack(*boss);
    }

    void useSpecialAbility() {
        useSpecialAbility(*boss);
    }

    void useSpecialAbility(BaseCharacter& enemy) {
        cout << name << " uses Arcance Blast with power 30!" << endl;
        BaseCharacter::useSpecialAbility(30, enemy);
    }
};

class Archer : public BaseCharacter {
public:
    Archer() : BaseCharacter("Archer", 90) {}

    void attack(BaseCharacter& enemy) {
        BaseCharacter::attack(20, enemy);
    }

    void attack() {
        attack(*boss);
    }

    void useSpecialAbility() {
        useSpecialAbility(*boss);
    }

    void useSpecialAbility(BaseCharacter& enemy) {
        cout << name << " uses Fire Arrow with power 35!" << endl;
        BaseCharacter::useSpecialAbility(35, enemy);
    }
};

class BossEnemy : public BaseCharacter {
private:
    vector<BaseCharacter*> enemies;
public:
    BossEnemy(vector<BaseCharacter*> enemies) : BaseCharacter("Boss", 150), enemies(enemies) {}

    void attack() {
        for(BaseCharacter* enemy : enemies) {
            BaseCharacter::attack(30, *enemy);
        }
    }

    void useSpecialAbility() {
        
    }
};

class GameEngine {
private:
    vector<BaseCharacter*> characters; 
public:
    GameEngine() {
        characters.push_back(new Warrior());
        characters.push_back(new Mage());
        characters.push_back(new Archer());

        boss = new BossEnemy(characters);
    }

    bool checkGameStatus() {
        if(boss->getHealth() <= 0) {
            cout << "Boss defeated! Players win!" << endl;
            return true;
        }
        for(BaseCharacter* character: characters) {
            if(character->getHealth() <= 0) {
                cout << "Players defeated! Boss wins!" << endl;
                return true;
            }
        }
        return false;
    }

    void run() {
        while(true) {
            for(BaseCharacter* character : characters) {
                CharacterActions* action = (CharacterActions*)character;
                action->attack();
                if(checkGameStatus()) return; 
                action->useSpecialAbility();
                if(checkGameStatus()) return;
            }

            for(BaseCharacter* character : characters) {
                CharacterActions* action = (CharacterActions*)character;
                action->attack();
                if(checkGameStatus()) return;
            }
        }
    }
};

int main() {
    GameEngine engine;
    engine.run();
    return 0;
}