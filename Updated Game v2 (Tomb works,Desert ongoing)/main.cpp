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
            skill2DMGPlayer=0.3;
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
            skill2DMGPlayer=0.3;
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
            cout<<"------------------------------------------------------------- \n\n"<<endl;
            cout<<"Here begins your tomb exploration! "<<endl;
            srand(time(NULL));
            for(int i =0;i<=4;i++)
            {
                random = tombEnemies[rand() % 3];
                cout<<"Your enemy will be a : ";
                cout<<random<<"! \n\n";
                TombEnemy=random;
                EnemyStats(TombEnemy);
            }
            TombEnemy="Necromancer";
            cout<<" "<<endl;
            cout<<"You are facing the Necromancer now! Good luck."<<endl;
            EnemyStats(TombEnemy);
        }

    }
    void EnemyStats(string a)
{

        if (a=="Skeleton")
        {
            HealthE = 100;
            AttackE = 15;
            LuckE = 0;
            MagicE = 5;
            DefenseE = 10;
            skill1DMGEnemy=Attack*0.3 +15;
            std::string EnemySkillsArr[]={"Basic Attack"};
            Battle(Health,Defense,Attack,Magic,HealthE,DefenseE,AttackE,MagicE,skill1DMGPlayer,skill2DMGPlayer,skill3DMGPlayer
                   ,skill4DMGPlayer,skill1DMGEnemy,skill2DMGEnemy,skill3DMGEnemy,PlayerSkillsArr,EnemySkillsArr);
        }
        else if (a=="Lich")
        {
            HealthE = 150;
            AttackE = 5;
            LuckE = 5;
            MagicE = 27;
            DefenseE = 5;
            skill1DMGEnemy = 14 + (0.3*AttackE);
            skill2DMGEnemy = (MagicE*0.6) + 10;
            std::string EnemySkillsArr[]={"Basic Attack","Crystal Lance"};
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
            skill1DMGEnemy = 20+ (AttackE*0.4);
            Defense = DefenseE + (DefenseE*0.4);
            skill2DMGEnemy = (DefenseE*0.8) + 15;
            std::string EnemySkillsArr[]={"Basic Attack","Frost Shield"};
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
            std::string EnemySkillsArr[]={"Basic Attack","Frost Bite","Raise Zombie"};
            Battle(Health,Defense,Attack,Magic,HealthE,DefenseE,AttackE,MagicE,skill1DMGPlayer,skill2DMGPlayer,skill3DMGPlayer
                   ,skill4DMGPlayer,skill1DMGEnemy,skill2DMGEnemy,skill3DMGEnemy,PlayerSkillsArr,EnemySkillsArr);
        }}
    void Battle(double PlayerHP ,double PlayerDef , int PlayerAtk , int PlayerMagic ,double EnemyHp,double EnemyDef,
                int EnemyAtk , int EnemyMagic,double skill1DMGPlayer,double skill2DMGPlayer,double skill3DMGPlayer,
                double skill4DMGPlayer ,double skill1DMGEnemy,double skill2DMGEnemy ,double skill3DMGEnemy
                ,string ar[] , string ar2[])
    {
        cout<<"\n\nEnemy has : "<<HealthE<<" health left!"<<endl;
        int i=0;
        int temp;
        cout<<"\n\n"<<"Type the number representing the ability to activate it , theres no cooldown on your abilities\n\n"<<endl;
        while(HealthE>0&&Health>0){
            for(i;i<4;i++)
            {
                cout<<ar[i]<<endl;
            }
            cin>>temp;
            if ((Player=="Assassin"||Player=="assassin")&&temp==1)
            {
                cout<<"You activated Attack up! Your damage is increased by 50% "<<endl;
                skill3DMGPlayer= 0.5*skill3DMGPlayer+skill3DMGPlayer;
                skill4DMGPlayer= 0.5*skill4DMGPlayer+skill4DMGPlayer;
            }
            else if((Player=="Assassin"||Player=="assassin")&&temp==2)
            {
                if(Health==120||Health>120)
                {
                    cout<<"Your health is already 120! Your health wont be regenerated! "<<endl;
                }
                else
                {
                    cout<<"You activated regenerate health! Your health is regenerated by 30% "<<endl;
                    Health=Health * skill2DMGPlayer+Health;
                    cout<<"Your current health is : "<<Health<<endl;
                }
            }
            else if((Player=="Assassin"||Player=="assassin")&&temp==3)
            {
                cout<<"You have used Heart Stab "<<endl;
                cout<<"Enemy takes "<<(skill3DMGPlayer-DefenseE)<<" damage\n"<<endl;
                HealthE=HealthE-(skill3DMGPlayer-DefenseE);
                if(HealthE<=0)
                    {
                        cout<<"Enemy has died\n"<<endl;
                    }
                else
                    {
                        cout<<"Enemy has "<<HealthE<<" health left!\n"<<endl;
                    }
            }
            else if((Player=="Assassin"||Player=="assassin")&&temp==4)
            {
                cout<<"You have used Throw Dagger! "<<endl;
                HealthE=HealthE-(skill3DMGPlayer-DefenseE);
                cout<<"Enemy takes "<<skill3DMGPlayer-DefenseE<<" damage \n"<<endl;
                 if(HealthE<=0)
                    {
                        cout<<"Enemy has died\n"<<endl;
                    }
                else
                    {
                        cout<<"Enemy has "<<HealthE<<" health left!\n"<<endl;
                    }

            }
            else if ((Player=="Knight"||Player=="knight")&&temp==1)
            {
                cout<<"You activated Defense up! Your defense was increased by 30% "<<endl;
                Defense=(Defense+Defense*0.3);
            }
            else if((Player=="Knight"||Player=="knight")&&temp==2)
            {
                if(Health==120||Health>120)
                {
                    cout<<"Your health is already 120! Your health wont be regenerated! "<<endl;
                }
                else
                {
                    cout<<"You activated regenerate health! Your health is regenerated by 30% "<<endl;
                    Health=Health * skill2DMGPlayer+Health;
                    cout<<"Your current health is : "<<Health<<endl;
                }
            }
            else if((Player=="Knight"||Player=="knight")&&temp==3)
            {
                cout<<"You have used Shield Bash "<<endl;
                cout<<"Enemy takes "<<(skill3DMGPlayer-DefenseE)<<" damage\n"<<endl;
                HealthE=HealthE-(skill3DMGPlayer-DefenseE);
                if(HealthE<=0)
                    {
                        cout<<"Enemy has died\n"<<endl;
                    }
                else
                    {
                        cout<<"Enemy has "<<HealthE<<" health left!\n"<<endl;
                    }

            }
            else if((Player=="Knight"||Player=="knight")&&temp==4)
            {
                cout<<"You have used Spear Throw! "<<endl;
                cout<<"Enemy takes "<<skill3DMGPlayer-DefenseE<<" damage\n"<<endl;
                HealthE=HealthE-(skill3DMGPlayer-DefenseE);
                if(HealthE<=0)
                    {
                        cout<<"Enemy has died\n"<<endl;
                    }
                else
                    {
                        cout<<"Enemy has "<<HealthE<<" health left!\n"<<endl;
                    }

            }
            if ((Player=="Mage"||Player=="mage")&&temp==1)
            {
                cout<<"You activated Magic Up! Your magic is increased by 25% "<<endl;
                skill3DMGPlayer= 0.25*skill3DMGPlayer+skill3DMGPlayer;
                skill4DMGPlayer= 0.25*skill4DMGPlayer+skill4DMGPlayer;
            }
            else if((Player=="Mage"||Player=="mage")&&temp==2)
            {
                Magic=0.35*Magic+Magic;
                cout<<"You activated Magic Penetration ! Your magic is increased by 35% "<<endl;
                skill3DMGPlayer=0.35*skill3DMGPlayer+skill3DMGPlayer;
                skill4DMGPlayer=0.35*skill4DMGPlayer+skill4DMGPlayer;
            }
            else if((Player=="Mage"||Player=="mage")&&temp==3)
            {
                cout<<"You have used Fireball! "<<endl;
                cout<<"Enemy takes "<<(skill3DMGPlayer-DefenseE)<<" damage\n"<<endl;
                HealthE=HealthE-(skill3DMGPlayer-DefenseE);
                    if(HealthE<=0)
                    {
                        cout<<"Enemy has died\n"<<endl;
                    }
                    else
                    {
                        cout<<"Enemy has "<<HealthE<<" health left!\n"<<endl;
                    }

                }
            else if((Player=="Mage"||Player=="mage")&&temp==4)
            {
                cout<<"You have used Wind Shot! "<<endl;
                cout<<"Enemy takes "<<skill3DMGPlayer-DefenseE<<" damage\n"<<endl;
                    HealthE=HealthE-(skill3DMGPlayer-DefenseE);
                        if(HealthE<=0)
                        {
                            cout<<"Enemy has died\n"<<endl;
                        }
                        else
                        {


                            cout<<"Enemy has "<<HealthE<<" health left!\n"<<endl;
                        }


            }
        if(HealthE<=0)
            {
                cout<<"Enemy has died\n\n"<<endl;
            }
        else
            {

            if(TombEnemy=="Skeleton")
            {
                cout<<"\n\nEnemy Skeleton has attacked back using Basic Attack!\n"<<endl;
                if(Defense>skill1DMGEnemy)
                {
                cout<<"Your defense is too high u only take 5 damage\n"<<endl;
                Health=Health-5;
                }
                else
                {
                Health=Health-(skill1DMGEnemy-Defense);
                }
                cout<<"You have : "<<Health<<" health left"<<endl;
            }
            else if(TombEnemy=="DeathKnight")
            {
                string temp4;
                srand(time(NULL));
                temp4 = ar2[rand()%2];
                cout<<"Enemy Death Knight has attacked using "<<temp4<<"."<<endl;
                if(temp4=="Basic Attack")
                {
                    if(Defense>skill1DMGEnemy)
                    {

                        cout<<"You took 5 damage. You have : "<<Health<<" left."<<endl;
                    }
                    else{
                        Health=Health-(skill1DMGEnemy-Defense);
                        cout<<"You took "<<skill1DMGEnemy-Defense<<" damage"<<endl;
                        cout<<"You have : "<<Health<<" health left"<<endl;
                    }
                }
                else if(temp4=="Frost Shield")
                {
                    if(Defense>skill2DMGEnemy)
                    {
                        Health=Health-5;
                        cout<<"You took 5 damage. You have : "<<Health<<" left."<<endl;
                    }
                    else
                    {
                         Health=Health-(skill2DMGEnemy-Defense);
                        cout<<"You took "<<skill2DMGEnemy-Defense<<" damage"<<endl;
                        cout<<"You have : "<<Health<<" health left"<<endl;
                    }
                }
            }
            else if(TombEnemy=="Lich")
            {
                string temp3;
                srand(time(NULL));
                temp3 = ar2[rand()%2];
                cout<<"Enemy Lich has attacked using "<<temp3<<"."<<endl;
                if(temp3=="Basic Attack")
                {
                    if(Defense>skill1DMGEnemy)
                    {
                        Health=Health-5;
                        cout<<"You took 5 damage. You have : "<<Health<<" left."<<endl;
                    }
                      else{
                        Health=Health-(skill1DMGEnemy-Defense);
                        cout<<"You took "<<skill1DMGEnemy-Defense<<" damage"<<endl;
                        cout<<"You have : "<<Health<<" health left"<<endl;
                    }
                }
                else if(temp3=="Crystal Lance")
                {
                     if(Defense>skill2DMGEnemy)
                    {
                        Health=Health-5;
                        cout<<"You took 5 damage. You have : "<<Health<<" left."<<endl;
                    }
                    else
                    {
                         Health=Health-(skill2DMGEnemy-Defense);
                        cout<<"You took "<<skill2DMGEnemy-Defense<<" damage"<<endl;
                        cout<<"You have : "<<Health<<" health left"<<endl;
                    }
                }
            }
            else if(TombEnemy=="Necromancer")
            {
                string temp2;
                srand(time(NULL));
                temp2 = ar2[rand()%3];
                cout<<"Enemy Necromancer has attacked using "<<temp2<<"."<<endl;
                if(temp2=="Basic Attack")
                {
                     if(Defense>skill1DMGEnemy)
                    {
                        Health=Health-5;
                        cout<<"You took 5 damage. You have : "<<Health<<" left."<<endl;
                    }
                    else
                    {
                         Health=Health-(skill1DMGEnemy-Defense);
                        cout<<"You took "<<skill1DMGEnemy-Defense<<" damage"<<endl;
                        cout<<"You have : "<<Health<<" health left"<<endl;
                    }
                }
                else if(temp2=="Frost Bite")
                {
                     if(Defense>skill2DMGEnemy)
                    {
                        Health=Health-5;
                        cout<<"You took 5 damage. You have : "<<Health<<" left."<<endl;
                    }
                    else
                    {
                         Health=Health-(skill2DMGEnemy-Defense);
                        cout<<"You took "<<skill2DMGEnemy-Defense<<" damage"<<endl;
                        cout<<"You have : "<<Health<<" health left"<<endl;
                    }
                }
                else if(temp2=="Raise Zombie")
                {
                     if(Defense>skill3DMGEnemy)
                    {
                        Health=Health-5;
                        cout<<"You took 5 damage. You have : "<<Health<<" left."<<endl;
                    }
                    else
                    {
                         Health=Health-(skill3DMGEnemy-Defense);
                        cout<<"You took "<<skill3DMGEnemy-Defense<<" damage"<<endl;
                        cout<<"You have : "<<Health<<" health left"<<endl;
                    }
                }
            }
        }
        }
        cout<<"NEXT BATTLE IS ABOUT TO BEGIN!\n\n"<<endl;
        system("pause");
        cout<<"--------------------------------------------------------------------"<<endl;



    }
private:
     string Player;
     //Tomb enemies
    string TombEnemy;
    //Desert Enemies
    string DesertEnemy; //End

    string Role;
    std::string EnemySkillsArr[];
    std::string PlayerSkillsArr[];
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
