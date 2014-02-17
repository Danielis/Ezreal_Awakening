----
#Ezreal: Magic Awakening
![alt text](https://fbcdn-sphotos-e-a.akamaihd.net/hphotos-ak-ash4/463018_281596001934677_452558680_o.jpg "Ezreal")

Note: QT is needed to run this program. Then use Qmake to create the needed executable.
      Also, look at my other project Moodsic, created at the USC vs UCLA Microsoft Hackathon. As a team of four we created this project and took first place. http://www.devonmeyer.com/projects/moodsic/ 

----

##[BackStory](http://na.leagueoflegends.com/champions/81/ezreal_the_prodigal_explorer)
Ezreal was born with the gift of magic flowing through his veins. Ezreal, however, was also born with a much stronger 
sense of wanderlust. Put into school to become a skilled techmaturgist, Ezreal quickly became bored with magical studies. By the time the boy genius was eight years old, he had fully mapped out the underground tunnels of Piltover. The quality of his work was so great that the government of Piltover purchased his maps and salaried his services as Piltover's Grandmaster Explorer. This sealed the deal on Ezreal's path in life - he would eschew the arcane arts in favor of archaeology. Since then, countless of Ezreal's adventures have been written about as romanticized stories.

While exploring the pyramids of Shurima Desert, Ezreal uncovered an amulet of incredible power. Aside from the sheer size of the amulet (it was made for a being easily twice Ezreal's size), it allows the wielder to control and shape magical energy - provided a source of magic is in the vicinity.

Join Ezreal as he battles the awakened monsters at Shurima Desert!!!
###GamePlay
Players will begin the game with basic attack and facing melee minions. Each level is based on a timer, which if 
the player has health at the end of the evel they pass on to the next. Player leveling up depends on the amount on 
the damage that a player deals out. As the game progresses, players will gain abilities that cost mana. At level two, 
players gain mystic shot which will be fired in place of basic attack every 5 shots. The player must now face both 
caster and melee minions. At level 3, players learns Arcane Shift which allows them to teleport to where their mouse 
is located. This ability can only be used every 20 seconds. The player now also fights Seige minions which have more 
health than caster minions and deal more damage. At level 4, players gain Trueshot Barrage which will cost 100 mana and
will be usable by holding down the left click button for more than 3 seconds. After level 4, the player will test his wits
against hordes of enemies until they can no longer survive.

Mana is replenished at a rate of 1 per second. Health can only be replenished by leveling up or picking up a heal icon. 
The clarity icon will replenish mana and ignite will destroy all enemies on the field. Icons are spawned every 30 seconds
at random location on the field.

Minions move and do damage in different ways. The attack of a melee minion will be contact and will inflict every second. The caster minion will 
shoot, a straight shot, if he is within a range of 100. The Seige minion will shoot a curved shot within a range of 150. The shots will move to the
location where Ezreal was standing at the time it was fired. Both Caster and Seige minions will also do damage if they are making contact.
 
---- 
  
### MainWindow
  Holds all the Widgets in a nice format
#####Layout
  0. row0
    * Title - EZREAL: MAGIC AWAKENING
  1. row1
    * Middle - pause/continue button
    * Left   - Start/Restart
    * Quit - Quits the game
    * Level - level 
    * Right  - Score
    
  2. row2
    * View - holds the scene
    * Scene - holds all the monsters, player and attacks
  3. row3
    * Abilities - displays available abilities
    * Health - shows health
    * Mana - shows mana
    
----

### View
  1. GameWindow
    * Derived from QGraphicsView
    * Will be the complete view and will hold all monsters and player
    * Will interact based on mousepressEvents and Keypresseevents for Ezreal Attacks
    * Player will be able to shoot at any angle, monsters will cause damage based on touch and attack spells

----

### IconObject & SceneObject
>IconObject: Class is used in place of QLabel to hold icons on the MainWindow
>Basic Attack, MysticShot, Trueshot Barrage, Mana and Heart icons used here
  
>SceneObject: Class derived from QGraphicsPixmapItem used to derive classes to hold monsters and players in Scene
>All except heart and mana are used here

  1. Derived classes
    * **Monsters**
    
      |Monster   | Ability     |Damage  |Health  | Level | Movement	|
      |:--------:|:-----------:|:------:|:------:|:-----:|:------------:|
      | Melee    | Basic Attack|  10    |  75    | lv1   | Random
      | Caster   | Energy Bolt |  15    |  50    | lv2   | toward player|
      | Siege    | Cannon Shot |  20    |  150   | lv3   | toward player|
    * **Player**
    
       |Level |Health |Mana  |
       |:----:|:-----:|:----:|
       |lv1   |  200  |  50  |
       |lv2   |  300  |  100 |
       |lv3   |  400  |  150 |
       |lv4   |  500  |  200 |
       
       |Movement|Key |
       |--------|:--:|
       |Up	| w  |
       |Down	| s  | 
       |Left	| a  | 
       |Right	| d  |
       
       |Level |Abilities	|Cost |Damage  | Operator   | Movement		|
       |:----:|:---------------:|:---:|:------:|:----------:|:-----------------:|
       |lv1   |Basic Attack     | 0   |  25    |Left Click  | mouseclick direc. |
       |lv2   |Mystic Shot      | 10  |  50    |Left Click  | mouseclick direc.	|
       |lv3   |Arcane Shift     | 25  |  0     |Right Click | mouseclick point	|
       |lv4   |TrueShot Barrage | 100 |  100   |Left Hold   | mouseclick direc.	|
    * **Powerups**
    
       |Object  |Image   |Effect              | Movement	|
       |--------|:------:|:------------------:|:---------------:|
       |[Heal](http://oyster.ignimgs.com/mediawiki/apis.ign.com/league-of-legends/6/6e/Heal.png)|![alt text](http://oyster.ignimgs.com/mediawiki/apis.ign.com/league-of-legends/6/6e/Heal.png "Heal")|Restore Health      | Still	| 
       |[Clarity](http://www.gamereplays.org/community/uploads/post-67977-1321383582.png "Clarity")|![alt text](http://www.gamereplays.org/community/uploads/post-67977-1321383582.png "Ignite")|Restore Mana        | Still	|
       |[Ignite](http://2.bp.blogspot.com/-7Q_vg1vPOoI/TeeTNfoU_uI/AAAAAAAAAB0/JzV7sJta-xY/s1600/Ignite.png)|![alt text](http://2.bp.blogspot.com/-7Q_vg1vPOoI/TeeTNfoU_uI/AAAAAAAAAB0/JzV7sJta-xY/s1600/Ignite.png "Ignite")|Destroy all monsters| Still 	|
    * **Range Attacks:** each is a derived class
    
      |Attack		| Image		|
      |-----------------|:-------------:|
      |**Player**	|		|
      |Basic Attack	|![alt text](http://fc02.deviantart.net/fs46/f/2009/162/7/9/Energy_Blast_by_Kryptid.gif "Basic Attack")|
      |Mystic Shot	|![alt text](http://fc02.deviantart.net/fs46/f/2009/162/7/9/Energy_Blast_by_Kryptid.gif "Mystic Shot")|
      |Trueshot Barrage	|![alt text](http://images1.wikia.nocookie.net/__cb20120501193618/goatcity/images/8/83/Ki-blast.gif "TrueShot Barrage")|
      |**Minions**	|		|
      |Energy Bolt	|![alt text](http://www.ernmphotography.com/Pages/Ball_Lightning/BLPhotos/Special/Gifs_Bars_etc/SimD4.gif "Energy Bolt")|
      |Cannon Shot	|![alt text](http://images4.wikia.nocookie.net/__cb20110711203627/runescapeclassic/images/3/38/Multi_cannon_ball.png "Cannon Shot")|
      |**Other Images**	|Some images have been modified for gameplay|
      |Ezreal	 	|![alt text](http://fc06.deviantart.net/fs70/f/2012/155/2/8/ezreal_sprite_by_gnahzdivad-d52afck.png "Ezreal")|
      |Melee Minion	|<img src="http://2.bp.blogspot.com/_L78zEKWCMII/TQPx8KvY9-I/AAAAAAAABNE/vs8d42KSGXU/s1600/Purple+Warrior+Minion.png" alt="Melee Minion" height="120"></img>|
      |Caster Minion	|<img src="http://25.media.tumblr.com/f9d4cdd48cf2aa5265af2606eca924ff/tumblr_mew63ws1gX1rkinvho1_500.png" alt="Caster Minion" height="120"></img>|
      |Siege Minion	|<img src="http://www.team-dignitas.net/uploads/tinymce/images/minionbasicmelee.png" alt="Seige Minion" height="120"></img>|
      |Heart		|![alt text](http://fc06.deviantart.net/fs71/f/2011/322/4/d/twilight_princess_heart_container_free_icon_by_shattered_earth-d4gjg32.gif "Zelda Heart")|
      |Mana		|![alt text](http://fc00.deviantart.net/fs42/f/2009/069/9/5/potion_by_freedezigner.gif "Zelda Potion")|
      
##NOTE: 
  1. QLabels display health,mana,score and level but are unable to be represented in QLabel after update.
    * Look at terminal for health, mana, level and score
  3. MANA has not been implemented
