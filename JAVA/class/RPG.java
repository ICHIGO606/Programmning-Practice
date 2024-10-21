import java.util.HashMap;
import java.util.*;
public class RPG {
    public static Random rand=new Random();
    public static class Character{
        String name;
        int health;
        int attackPower;
        int defense;
        HashMap<String,SpecialAttack>specialAttacks;

        Character(String name,int health,int attackPower,int defense,HashMap<String,SpecialAttack> specialAttacks){
            this.name=name;
            this.health=health;
            this.attackPower=attackPower;
            this.defense=defense;
            this.specialAttacks=specialAttacks;
        }

        public String getName(){return name;}
        public int getHealth(){return health;}
        public int getAttackPower(){return attackPower;}
        public int getDefense(){return defense;}
        public HashMap<String,SpecialAttack>getspecialAttack(){return specialAttacks;}

        public void setHealth(int health){
            this.health=Math.max(0,health);
        }

        public void attack(Character opponent){
            int damage=this.attackPower-opponent.getDefense();
            if(damage>0){
                opponent.setHealth(opponent.getHealth()-damage);
                System.out.println(opponent.getName()+" get Damaged by "+damage+" health reduced to "+opponent.getHealth());
                // defense=defense-(opponent.getAttackPower()/(rand.nextInt(2)+3));
                if(defense-opponent.getAttackPower()>0){
                    defense=defense-opponent.getAttackPower();
                }
            }else{
                System.out.println(opponent.getName()+" not affected by the attack");
                if(defense-opponent.getAttackPower()>0){
                    defense=defense-opponent.getAttackPower();
                }
                // defense=defense-opponent.getAttackPower();
                // defense=defense-(opponent.getAttackPower()/(rand.nextInt(2)+3));
            }

        }

        public void useSpecialAttack(String attackName,Character opponent){
            SpecialAttack attack=this.specialAttacks.get(attackName);
            if(attack!=null){
                int damage=attack.getPower()-opponent.getDefense();
                if(damage>0){
                    opponent.setHealth(opponent.getHealth()-damage);
                    System.out.println(opponent.getName()+" get Damaged by "+attack.getName()+ " the special attack "+damage+" health reduced to "+opponent.getHealth());
                }else{
                    System.out.println(opponent.getName()+" not affected by the special attack");
                }
            }else{
                System.out.println(this.name+" doesn't know this attack");
            }
        }

    }   
    public static class SpecialAttack{
        String name;
        int power;
        String description;
        SpecialAttack(String name,int power,String description){
            this.name=name;
            this.power=power;
            this.description=description;
        }

        public String getName(){return name;}
        public int getPower(){return power;}
        public String getDesc(){return description;}
    }
    public static class Battle{
        Character character1;
        Character character2;
        Battle(Character c1,Character c2){
            this.character1=c1;
            this.character2=c2;
        }

        public void startBattle(){
            System.out.println("Battle Between "+character1.getName()+" and "+character2.getName()+" starts");
            while(character1.getHealth()>0 && character2.getHealth()>0){
                if(character1.getHealth()>0){
                    double rand=Math.random();
                    if(rand>0.9){
                        character1.useSpecialAttack("Chidori", character2);
                    }
                    else if(rand>0.75){
                        character1.useSpecialAttack("Fireball Jutsu", character2);

                    }
                    else{
                    character1.attack(character2);}
            }
                if(character2.getHealth()>0){
                    double rand1=Math.random();
                    if(rand1>0.9){
                        character2.useSpecialAttack("RasenShuriken", character1);
                    }
                    else if(rand1>0.75){
                        character2.useSpecialAttack("Rasengan", character1);

                    }
                    else{
                    character2.attack(character1);}
                }
                
            }
            determineWinner();
        }
        public void determineWinner(){
            if(character1.getHealth()>0){
                System.out.println(character1.getName()+" wins the game");
            }else if(character2.getHealth()>0){
                System.out.println(character2.getName()+" wins the game");
            }else{
                System.out.println("Both the characters have fallen");
            }
        }
    }
    public static void main(String args[]){
        HashMap<String,SpecialAttack> specialAttack1=new HashMap<>();
        specialAttack1.put("Fireball Jutsu",new SpecialAttack("Fireball Jutsu", 25, "Fire Style Fireball Jutsu"));
        specialAttack1.put("Chidori",new SpecialAttack("Chidori", 29, "Lightning Style Chidori"));
        HashMap<String,SpecialAttack> specialAttack2=new HashMap<>();
        specialAttack2.put("Rasengan",new SpecialAttack("Rasengan", 23, "Rasengan"));
        specialAttack2.put("RasenShuriken",new SpecialAttack("RasenShuriken", 27, "Wind Style RasenShuriken"));

        Character sasuke=new Character("Sasuke Uchiha", 100,16, 17, specialAttack1);
        Character naruto=new Character("Naruto Uzumaki", 100,16, 17, specialAttack2);
        Battle battle=new Battle(sasuke, naruto);
        battle.startBattle();
        
        

    }
}
