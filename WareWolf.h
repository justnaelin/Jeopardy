#ifndef WAREWOLF_H_INCLUDED
#define WAREWOLF_H_INCLUDED

class WareWolf: public Human, public Wolf
{
    private:
        bool isTransformed,
             isHungry,
             isFullMoon,
             isWalking;
        static int num_wereWolves  = 1;
    public:
        WareWolf();
        WareWolf(char gender, int attack, int defense, int hp, int speed,string race, string hair_color, int age
                string fur_color, string ranking, int wolf_pack_size, bool isHunting, bool isAlpha,
                bool isTrasformed, bool isHungry, bool isFullMoon, bool isWalking);
        //mutators and Accessors


};


#endif // WAREWOLF_H_INCLUDED
