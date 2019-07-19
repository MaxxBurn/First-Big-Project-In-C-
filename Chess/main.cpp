#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Rpg{

public:
    Rpg(string x , string y, double r,int c,int b,int f,double g)
    {
        Player = x;
        Role = y;
        Health = r;
        Luck = b;
        Attack = c;
        Magic = f;
        Defense = g;
        Skills(Player);
    }
    void Skills(string a)
    {
        int temp;

        if (a=="Assassin"||a=="assassin")
        {
            cout<<"These are the assassin skills\n\n";
            skill1="1. Attack up";
            skill2="2. Regenerate HP";
            skill3="3. Heart stab";
            skill4="4. Throw Dagger\n\n";
            string PlayerSkillsArr[]={"1.Attack up","2.Regenerate HP","3.Heart stab","4.Throw Dagger"};
            cout<<skill1<<"\n"<<skill2<<"\n"<<skill3<<"\n"<<skill4;
            skill1DMGPlayer=0.5;
            skill2DMGPlayer=0.5;
            skill3DMGPlayer=40;
            skill4DMGPlayer=25;
        }
        else if (a=="Mage"||a=="mage")
        {
            cout<<"These are the mage skills\n\n";
            skill1="1. Magic up";
            skill2="2. Magic penetration up";
            skill3="3. Fireball";
            skill4="4. Wind Shot\n\n";
            string PlayerSkillsArr[]={"1.Magic Up","2.Magic penetration up","3.Fireball","4.Wind Shot"};
            cout<<skill1<<"\n"<<skill2<<"\n"<<skill3<<"\n"<<skill4;
            skill1DMGPlayer=0.25;
            skill2DMGPlayer=0.35;
            skill3DMGPlayer=35;
            skill4DMGPlayer=30;
        }
        else if(a=="Knight"||a=="knight")
        {
            cout<<"These are the knight skills \n\n";
            skill1="1. Defense up";
            skill2="2. Regenerate health";
            skill3="3. Shield bash";
            skill4="4. Spear throw\n\n";
            string PlayerSkillsArr[]={"1.Defense up","2.Regenerate Health","3.Shield Bash","4.Spear Throw"};
            cout<<skill1<<"\n"<<skill2<<"\n"<<skill3<<"\n"<<skill4;
            skill1DMGPlayer=0.35;
            skill2DMGPlayer=0.2;
            skill3DMGPlayer=30;
            skill4DMGPlayer=20;
        }
        cout<<"Where would u like to spawn a tomb or a desert? Press 1 for tomb or 2 for desert.\n\n";
        cin>>temp;
        if(temp==1)
        {
            cout<<"Welcome to the tomb of Nazaric . This dungeon is overpopulated with skeletons and dead humanoid enemies.";
            cout<<"\n\nYou will eventually face the bosses of the tomb so be prepared.";
            cout<<"\n\nThe first boss will be a necromancer which is considered the weakest boss of the dungeon.";
            cout<<"If you manage to beat the \nnecromancer , u can advance further into the tomb. Good luck!\n\n";
            system("pause");
        }
        else if(temp==2)
        {
            cout<<"Welcome to the Black Desert! This place is populated from humanoid and non humanoid creatures";
            cout<<"\n\nYou will be fighting for your life in this place. And at the end of the dungeon a mummy awaits.";
            cout<<"\n\nOnce you beat the mummy you may venture further into the desert";
            cout<<"\n\nLegendary Items and Legendary bosses await you. Good luck!\n\n";
            system("pause");
        }
        Enemies(temp);

    }
    void Enemies(int a)
    {
        if (a==1)
        {
            string random;
            int temp;
            std::string tombEnemies[] = {"Skeleton","Lich","DeathKnight"};
            cout<<"Here begins your tomb exploration! ";
            srand(time(NULL));
            for(int i =0;i<=4;i++)
            {
                random = tombEnemies[rand() % 3];
                cout<<"Your enemy will be a : ";
                cout<<random<<"! \n\n";
                TombEnemy=random;
                EnemyStats(TombEnemy);
            }
            cout<<" "<<endl;
            cout<<"You are facing the Necromancer now! Good luck."<<endl;
            EnemyStats("Necromancer");
        }

    }
    void EnemyStats(string a)
{

        if (a=="Skeleton")
        {
            HealthE = 100;
            AttackE = 10;
            LuckE = 0;
            MagicE = 5;
            DefenseE = 10;
            skill1DMGEnemy=Attack*0.1 +10;
            string EnemySkillsArr[]={"Basic Attack"};
            Battle(Health,Defense,Attack,Magic,HealthE,DefenseE,AttackE,MagicE,skill1DMGPlayer,skill2DMGPlayer,skill3DMGPlayer
                   ,skill4DMGPlayer,skill1DMGEnemy,skill2DMGEnemy,skill3DMGEnemy,PlayerSkillsArr,EnemySkillsArr);
        }
        else if (a=="Lich")
        {
            HealthE = 150;
            AttackE = 5;
            LuckE = 5;
            MagicE = 20;
            DefenseE = 5;
            skill1DMGEnemy = 12 + (0.6*MagicE);
            skill2DMGEnemy = (AttackE*0.3) + 10;
            string EnemySkillsArr[]={"Basic Attack","Crystal Lance"};
            Battle(Health,Defense,Attack,Magic,HealthE,DefenseE,AttackE,MagicE,skill1DMGPlayer,skill2DMGPlayer,skill3DMGPlayer
                   ,skill4DMGPlayer,skill1DMGEnemy,skill2DMGEnemy,skill3DMGEnemy,PlayerSkillsArr,EnemySkillsArr);
        }

        else if (a=="DeathKnight")
        {
            HealthE = 200;
            AttackE = 20;
            LuckE = 0;
            MagicE = 5;
            DefenseE = 20;
            skill1DMGEnemy = 15+ (AttackE*0.4);
            Defense = DefenseE + (DefenseE*0.4);
            skill2DMGEnemy = (AttackE*0.8) + 12;
            string EnemySkillsArr[]={"Basic Attack","Frost Shield"};
            Battle(Health,Defense,Attack,Magic,HealthE,DefenseE,AttackE,MagicE,skill1DMGPlayer,skill2DMGPlayer,skill3DMGPlayer
                   ,skill4DMGPlayer,skill1DMGEnemy,skill2DMGEnemy,skill3DMGEnemy,PlayerSkillsArr,EnemySkillsArr);
        }
        else if (a=="Necromancer")
        {
            HealthE = 300;
            AttackE = 10;
            LuckE=0;
            MagicE = 35;
            DefenseE = 5;
            skill1DMGEnemy = 2.4*(7 + (0.1*AttackE));
            skill2DMGEnemy = 10 + (0.7*MagicE);
            skill3DMGEnemy= 8 + (0.3*AttackE);
            string EnemySkillsArr[]={"Basic Attack","Frost Bite","Raise Zombie"};
            Battle(Health,Defense,Attack,Magic,HealthE,DefenseE,AttackE,MagicE,skill1DMGPlayer,skill2DMGPlayer,skill3DMGPlayer
                   ,skill4DMGPlayer,skill1DMGEnemy,skill2DMGEnemy,skill3DMGEnemy,PlayerSkillsArr,EnemySkillsArr);
        }}
    void Battle(double PlayerHP ,double PlayerDef , int PlayerAtk , int PlayerMagic ,double EnemyHp,double EnemyDef,
                int EnemyAtk , int EnemyMagic,double skill1DMGPlayer,double skill2DMGPlayer,double skill3DMGPlayer,
                double skill4DMGPlayer ,double skill1DMGEnemy,double skill2DMGEnemy ,double skill3DMGEnemy
                ,string ar[] , string ar2[])
    {
        int i=0;
        while(i<=3)
        {
            cout<<PlayerSkillsArr[i]<<endl;
            i++;
        }
    }
private:
     string Player;
     //Tomb enemies
    string TombEnemy;
    //Desert Enemies
    string DesertEnemy; //End

    string Role;
    std::string EnemySkillsArr[];
    std::string PlayerSkillsArr[4];
    string skill1;
    string skill2;
    string skill3;
    string skill4;
    double skill1DMGPlayer;
    double skill2DMGPlayer;
    double skill3DMGPlayer;
    double skill4DMGPlayer;
    double skill1DMGEnemy;
    double skill2DMGEnemy;
    double skill3DMGEnemy;
    double Health;
    double HealthE;
    int AttackE;
    int LuckE;
    int MagicE;
    double DefenseE;
    int Attack;
    int Luck;
    int Magic;
    double Defense;
};




int main(){
const int Health2=100;
const int Attack2=30;
const int Luck2=15;
const int Magic2=0;
const int Defense2=30;

string meme;
string meme2;
cout<<"\nPlease select the name of your character.\n\n";
cin>>meme;
cout<<"\nWelcome User "<<meme<<". Enjoy your dungeon runs!\n\n";
cout<<"Please select the role u want to play as. Assassin/Knight/Mage.\n\n";
cin>>meme2;
if(meme2=="Assassin"||meme2=="assassin")
{
    Rpg player(meme2,meme,Health2+20,Attack2+15,Luck2+15,Magic2,Defense2+10);
}
else if (meme2=="Mage"|| meme2=="mage")
{
    Rpg player(meme2,meme,Health2+10,Attack2+5,Luck2+10,Magic2+30,Defense2+10);
}
else if(meme2=="Knight"||meme2=="knight")
{
    Rpg player(meme2,meme,Health2+35,Attack2+10,Luck2+5,Magic2+5,Defense2+15);
}
else
{
        cout<<"Dont be a dick select a class from those 3 choices. ";
        main();
}
cout<<"\n";
system("pause");

return 0;
}
