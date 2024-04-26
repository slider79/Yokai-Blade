#include<ctime>
#include<iostream>
#include<cstdlib>
#include<time.h>


// SFML 

#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>

using namespace std;
using namespace sf;


// GROUP MEMBERS


// SHUJA JAMAL
// WAZEEA SAJJID
// ZAIGHAM ASIF
// MUHAMMAD MOIZ
// MUHAMMAD RAPHAY

// 45 ACTIVE BOOL COUNT


//  CONTROLS :: A :: D :: SPACE :: ESC :: E






// #Player (Variable Declaration)

int dE ;
int CE;
int i ;
int bonus;
int wave ;
int attackthreshold;
int timeswitch[3]; // Test
int d ;
int maxenemies ;
int enemycount;
Sprite BG_LY_5;
Sprite BG_LY_4;
Sprite BG_LY_3;
Sprite BG_LY_2;
Sprite BG_LY_1;
Sprite Character;
Sprite Night;
Sprite enemy;
Sprite Ebutton;
Sprite Portal;
Sprite Eyefly;
Sprite EXCLAIM;
Sprite Wave1;
Sprite Wave2;
Sprite Wave3;
Sprite ChestBoss;
Sprite Heart;
Sprite Forward;
Sprite HealthBar;
Sprite deadpanel;
Sprite bot;
Sprite END;
Sprite GO;
Texture background5Texture;
Texture background4Texture;
Texture background3Texture;
Texture background2Texture;
Texture background1Texture;
Texture texture_sheet;
Texture Night_Texture;
Texture Enemy_Texture;
Texture Eb_Texture;
Texture Port_Texture;
Texture EyeFly_Texture;
Texture EXCLAIM_Texture;
Texture Wave1_Texture;
Texture Wave2_Texture;
Texture Wave3_Texture;
Texture Chestboss_Texture;
Texture Heart_Texture;
Texture Forward_Texture;
Texture HealthBar_Texture;
Texture dead_panel_texture;
Texture bot_texture;
Texture End_Texture;
Texture GO_Texture;
IntRect currentCharframe;
IntRect currentBG5frame;
IntRect currentBG4frame;
IntRect currentBG3frame;
IntRect currentBG2frame;
IntRect currentBG1frame;
IntRect currentEnemyframe;
IntRect Ebframe;
IntRect Portframe;
IntRect EyeFLYframe;
IntRect EXCLAIMframe;
IntRect Waveframe;
IntRect Chestboss_frame;
IntRect Hear_frame;
IntRect Forward_frame;
IntRect HealthBar_frame;
IntRect bot_frame;
IntRect end_frame;
Clock Animation_Timer;
Clock Enemy_Animation_Timer;
Clock coolDown;
Clock p_Animation_Timer;
Clock ATTACK_1_TIMER;
Clock EF_Animation_Timer;
Clock Eye_Fly_Animation_Timer;
Clock WaveClock;
Clock opacityclock;
Clock Chestboss_Timer;
Clock Heart_Timer;
Clock Dead_Timer;
Clock End_timer;

Color DEAD_opacity(255, 255, 255);
Color waveopacity(255, 255, 255);




// WINDWO


Sprite loadscreen;
Sprite Startbutton;
Sprite HoverTitle;
Texture loadscreen_texture;
Texture startbutton_texture;
Texture Hover_texture;
IntRect start_frame;


bool Titledown;




// Animation

short Animation_Staus;
bool Animation_Switch;

// Physics

Vector2f character_velocity;
Vector2f Enemy_velocity;
vector<Sprite> enemies;
vector<float> enemyVelocities;
vector<float> enemyHP;
vector<IntRect> currentEnemyframes;
vector<bool> deathtoll;
vector<short> EnemyAnimation_Stati;
vector<int> ed;
float max_velocity;
float min_velocity;
float accleration;
float drag;
float gravity;
float Max_Vert_Velocity;
float BGspeed;
float Enemy_speed;
float BeyondSafeZone;
float JUMplimit;
float HP;
float DamageDealt;
float EyeflyHP;
float CHESTHP;
bool BelowJumpLimit;
bool LowJump;
bool DoublePressSpace = true;
bool Attackheld = false;
bool mousePress;
bool allEnemiesOffScreen;
bool RightDrag;
bool LeftDrag;
bool orientation_chk;
bool uplift_chk;
bool rightx;
bool leftx;
bool nox;
bool socialDistance;
bool socialPrivelege;
bool CanDamage;
bool dmgthreshold;
bool thresholddmg;
bool singledeath;
bool extrachk;
bool damageanimation;
bool popthecop;
bool eyeflytrap;
bool Normaleyefly;
bool frmright;
bool bloodspilt;
bool EFdamageanimation;
bool exclamationM;
bool wavefront;
bool bosslvl;
bool BOSSTRAP;
bool BOSSTRAPLVL;
bool walk;
bool CHdamageanimation;
bool bossbloodspilt;
bool hasDied;
bool Rdeadchk;
bool moveDown;
bool Hoccupied;
bool DIF;
bool FEND;
bool GO_Down;



bool START=false;
bool INITIALIZE=true;
bool SINITIALIZE = true;



// #Game (Variable Declaration)

RenderWindow window;
Event ev;

// STATE READ

enum PLAYER_ANIMATION_STATE { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMP, DROP, ATTACK, DEAD };

// FUNCTIONS USED


void BOSSDRAW()
{

	if (bossbloodspilt && !CHdamageanimation && CHESTHP > 0)
	{
		cout << 1 << endl;
		CHdamageanimation = true;
		CE = 0;
	}
	if (CHdamageanimation && CE < 3)
	{
		if (CE == 0 || CE == 2)
		{
			ChestBoss.setColor(Color::Red);
		}
		else
		{
			ChestBoss.setColor(Color::Transparent);
		}
		CE++;
	}
	else
	{
		if (CE == 3)
		{
			bossbloodspilt = false;
		}
		CHdamageanimation = false;
		CE = 0;
		ChestBoss.setColor(Color::White);
	}

	window.draw(ChestBoss);
}

void SPECIALdraw()
{
	if (eyeflytrap)
	{
		if (exclamationM)
		{
			/*Eyefly.getPosition().x + (0.5)*(Eyefly.getGlobalBounds().width)> window.getSize().x*/
			if (frmright)
			{
				EXCLAIM.setPosition(window.getSize().x - EXCLAIM.getGlobalBounds().width - 32, window.getSize().y - EXCLAIM.getGlobalBounds().height - 7 * 16);
			}
			else
			{
				EXCLAIM.setPosition(32, window.getSize().y - EXCLAIM.getGlobalBounds().height - 7*16);
			}

			EXCLAIM.setTextureRect(EXCLAIMframe);

			
			EXCLAIM.setScale(5.f, 5.f);

			window.draw(EXCLAIM);
		}

		if (bloodspilt && !EFdamageanimation && EyeflyHP > 0)
		{
			EFdamageanimation = true;
			dE = 0;
		}
		if (EFdamageanimation && dE < 3)
		{
			if (dE == 0 || dE == 2)
			{
				Eyefly.setColor(Color::Red);
			}
			else
			{
				Eyefly.setColor(Color::Transparent);
			}
			dE++;
		}
		else
		{
			if (dE == 3)
			{
				bloodspilt = false;
			}
			EFdamageanimation = false;
			dE = 0;
			Eyefly.setColor(Color::White);
		}



		window.draw(Eyefly);
	}
}
bool EnemyAnimate(float velo, int timer)
{
	if (timer == 7)
	{
		if (velo == 1)
		{
			return true;
		}
	}
	if (timer == 9)
	{
		if (velo == 2)
		{
			return true;
		}
	}
	if (timer == 11)
	{
		if (velo == 3)
		{
			return true;
		}
	}
}
void EnemyAnim(int timer)
{
	for (auto& enemy : enemies)
	{
		size_t index = &enemy - &enemies[0];
		float& currentEHP = enemyHP[index];
		float& currentEvelocity = enemyVelocities[index];
		IntRect& currentEframe = currentEnemyframes[index];

		if (EnemyAnimate(currentEvelocity, timer))
		{
			int CharacterCenter;
			socialPrivelege = false;

			// DEATH

			if (currentEHP <= 0)
			{
				if (currentEframe.top != 384.f)
				{
					currentEframe.left = 0.f;
				}
				// DEAD
				currentEframe.top = 384.f;
				currentEframe.left += 96.f;
				if (currentEframe.left >= 480)
				{
					enemy.setPosition(0.f, -100.f);
					singledeath = false;
					/*enemies.erase(enemies.begin() + index);*/

				}
				enemy.setTextureRect(currentEframe);
			}
			else
			{
				if (!orientation_chk)
				{
					// FACING LEFT
					CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
					if (((enemy.getPosition().x + 104) < (CharacterCenter - (Character.getGlobalBounds().width - 3 * (64))) || (enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > CharacterCenter + 64))
					{
						socialPrivelege = true;
					}
				}
				else
				{
					// FACING RIGHT
					CharacterCenter = Character.getPosition().x + 64;
					if (((enemy.getPosition().x + 104) < CharacterCenter - 64 || (enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > (CharacterCenter + Character.getGlobalBounds().width - 3 * (64))))
					{
						socialPrivelege = true;
					}
				}
				if (Character.getGlobalBounds().intersects(enemy.getGlobalBounds()) && Animation_Staus == JUMP)
				{
					// IDLE
					if (currentEframe.top != 0.f)
					{
						currentEframe.left = 0.f;
					}

					currentEframe.top = 0.f;
					currentEframe.left += 96.f;
					if (currentEframe.left >= 864)
					{
						currentEframe.left = 0.f;
					}
					enemy.setTextureRect(currentEframe);
				}
				else if (CharacterCenter - (enemy.getPosition().x + 104) > 0 && socialPrivelege)
				{
					// MOVING RIGHT
					if (currentEvelocity <= 2)
					{
						currentEframe.top = 96.f;
					}
					else
					{
						currentEframe.top = 192.f;
					}
					currentEframe.left += 96.f;
					if (currentEvelocity <= 2)
					{
						if (currentEframe.left >= 768)
						{
							currentEframe.left = 0.f;
						}
					}
					else
					{
						if (currentEframe.left >= 672)
						{
							currentEframe.left = 0.f;
						}
					}
					
					enemy.setTextureRect(currentEframe);
					enemy.setScale(2.f, 2.f);
					enemy.setOrigin(0.f, 0.f);

				}
				else if (CharacterCenter - (enemy.getPosition().x + enemy.getGlobalBounds().width - 104) < 0 && socialPrivelege)
				{
					// MOVING LEFT
					if (currentEvelocity <= 2)
					{
						currentEframe.top = 96.f;
					}
					else
					{
						currentEframe.top = 192.f;
					}
					currentEframe.left += 96.f;
					if (currentEvelocity <= 2)
					{
						if (currentEframe.left >= 768)
						{
							currentEframe.left = 0.f;
						}
					}
					else
					{
						if (currentEframe.left >= 672)
						{
							currentEframe.left = 0.f;
						}
					}
					enemy.setTextureRect(currentEframe);
					enemy.setScale(-2.f, 2.f);
					enemy.setOrigin(enemy.getGlobalBounds().width / 2.f, 0.f);
				}
				else
				{
					// ATTACK
					currentEframe.top = 288.f; //480.f
					currentEframe.left += 96.f;
					if (currentEframe.left >= 798 || currentEframe.left >= 384)
					{
						if (currentEframe.left >= 798)
						{
							currentEframe.left = 0.f;
							DamageDealt++;
						}
						else
						{
							DamageDealt++;
						}
						
					}
					enemy.setTextureRect(currentEframe);


					if ((enemy.getPosition().x + 104) < CharacterCenter)
					{
						enemy.setScale(2.f, 2.f);
						enemy.setOrigin(0.f, 0.f);
					}
					else if ((enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > CharacterCenter)
					{
						enemy.setScale(-2.f, 2.f);
						enemy.setOrigin(enemy.getGlobalBounds().width / 2.f, 0.f);
					}

				}

				// DISTANT 

				if (abs(CharacterCenter - enemy.getPosition().x + 96) >= BeyondSafeZone)
				{
					if (currentEframe.top != 0.f)
					{
						currentEframe.left = 0.f;
					}
					
					// IDLE
					currentEframe.top = 0.f;
					currentEframe.left += 96.f;
					if (currentEframe.left >= 864)
					{
						currentEframe.left = 0.f;
					}
					enemy.setTextureRect(currentEframe);
				}
			}



			(timer == 7) ? timeswitch[0] = 0 : 1;
			(timer == 9) ? timeswitch[1] = 0 : 1;
			(timer == 11) ? timeswitch[2] = 0 : 1;
		}


	}
}
vector<Sprite> spawnEnemies(Texture& enemyTexture)
{
	/*int i = (wave)*maxenemies; i < (wave + 1)* maxenemies; ++i */
	/*int i = 0;*/
	int i = 0;
	(wave == 1) ?  i = 0: 1;
	(wave == 2) ? i = 10 : 1;
	(wave == 3) ? i = 20 : 1;

	for (; i < maxenemies; ++i)
	{
		if (wave == 1 && i < 10)
		{
			currentEnemyframe.top = 0.f;
			currentEnemyframe = IntRect(0, 0, 96, 96);
			enemy.setTextureRect(currentEnemyframe);
			enemy.setScale(2.f, 2.f);
			if (rand() % 2 == 0)
			{
				enemy.setPosition(window.getSize().x + i * 200, window.getSize().y - enemy.getGlobalBounds().height - 64);
			}
			else
			{
				enemy.setPosition(4 * (window.getSize().x) + i * 150, window.getSize().y - enemy.getGlobalBounds().height - 64);
			}
			enemies.push_back(enemy);
		}
		else if(wave == 2 && i < 20)
		{
			currentEnemyframe.top = 0.f;
			currentEnemyframe = IntRect(0, 0, 96, 96);
			enemy.setTextureRect(currentEnemyframe);
			enemy.setScale(2.f, 2.f);
			if (currentBG1frame.left <= 5400.f)
			{
				if (rand() % 2 == 0)
				{
					enemy.setPosition(window.getSize().x + i * 200, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
				else
				{
					enemy.setPosition(4 * (window.getSize().x) + i * 150, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
			}
			else if(currentBG1frame.left >= 9000.f)
			{
				if (rand() % 2 == 0)
				{
					enemy.setPosition(-i * 200, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
				else
				{
					enemy.setPosition(-3 * (window.getSize().x) - i * 150, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
				
			}
			else
			{
				if (rand() % 2 == 0)
				{
					enemy.setPosition(window.getSize().x + i * 100, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
				else
				{
					enemy.setPosition( - i * 100, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
			}
			enemies.push_back(enemy);
		}
		else if(wave == 3 && i < 25)
		{
			currentEnemyframe.top = 0.f;
			currentEnemyframe = IntRect(0, 0, 96, 96);
			enemy.setTextureRect(currentEnemyframe);
			enemy.setScale(2.f, 2.f);
			if (currentBG1frame.left <= 5400)
			{
				if (rand() % 2 == 0)
				{
					enemy.setPosition(window.getSize().x + i * 200, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
				else
				{
					enemy.setPosition(4 * (window.getSize().x) + i * 150, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
			}
			else if (currentBG1frame.left >= 9000)
			{
				if (rand() % 2 == 0)
				{
					enemy.setPosition(-i * 200, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
				else
				{
					enemy.setPosition(-3 * (window.getSize().x) - i * 150, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}

			}
			else 
			{
				if (rand() % 2 == 0)
				{
					enemy.setPosition(window.getSize().x + i * 100, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
				else
				{
					enemy.setPosition(-i * 100, window.getSize().y - enemy.getGlobalBounds().height - 64);
				}
			}
			enemies.push_back(enemy);
			
		}

		else
		{
			break;
		}
		
	}
	wave++;
	
	return enemies;
}

void Player_Render(RenderTarget& target)
{
	if (DamageDealt > 0 && !damageanimation && HP > 0)
	{
		damageanimation = true;
		d = 0;
	}
	if (damageanimation && d < 3)
	{
		if (d == 0 || d == 2)
		{
			Character.setColor(Color::Red);
			HealthBar.setColor(Color::Yellow);
		}
		else
		{
			Character.setColor(Color::Transparent);
			HealthBar.setColor(Color::Transparent);
		}
		d++;
	}
	else
	{
		damageanimation = false;
		d = 0;
		Character.setColor(Color::White);
		HealthBar.setColor(Color::White);
	}

	if (HP > 180)
	{
		HealthBar_frame.top = 0.f;
	}
	else if(HP>160)
	{
		HealthBar_frame.top = 128.f;
	}
	else if (HP > 140)
	{
		HealthBar_frame.top = 256.f;
	}
	else if (HP > 120)
	{
		HealthBar_frame.top = 384.f;
	}
	else if (HP > 100)
	{
		HealthBar_frame.top = 512.f;
	}
	else if (HP > 80)
	{
		HealthBar_frame.top = 640.f;
	}
	else if (HP > 60)
	{
		HealthBar_frame.top = 768.f;
	}
	else if (HP > 40)
	{
		HealthBar_frame.top = 896.f;
	}
	else if (HP > 20)
	{
		HealthBar_frame.top = 1024.f;
	}
	else 
	{
		HealthBar_frame.top = 1152.f;
	}



	HealthBar.setPosition(30.f,30.f);
	HealthBar.setTextureRect(HealthBar_frame);
	HealthBar.setScale(0.75f,0.75f);

	target.draw(HealthBar);
	target.draw(Character);

	
}

const bool& getAnimation_Switch()
{
	bool Anim_S = Animation_Switch;
	if (Animation_Switch)
	{
		Animation_Switch = false;
	}
	return Anim_S;
	// TODO: insert return statement here
}

bool canJump()
{
	if (Character.getGlobalBounds().top == window.getSize().y - Character.getGlobalBounds().height - 64)
	{
		LowJump = false;

	}
	if (!BelowJumpLimit)
	{
		if (Character.getGlobalBounds().top == window.getSize().y - Character.getGlobalBounds().height - 64)
		{
			BelowJumpLimit = true;
		}
	}
	if (Character.getGlobalBounds().top < JUMplimit)
	{
		BelowJumpLimit = false;
		return false;
	}
	return true;


}

void Motion(const float dir_x, const float dir_y)
{
	// ACCLEARATION 
	character_velocity.x += dir_x * accleration;


	// LIMT VELOCITY
	if (abs(character_velocity.x) > max_velocity)
	{
		character_velocity.x = max_velocity * ((character_velocity.x < 0.f) ? -1.0f : 1.0f);
	}


}

const RenderWindow& getwindow()
{
	// TODO: insert return statement here
	return window;
}

// MAIN SOURCE CODE

int main()
{
	// TIME READER

	srand((static_cast<unsigned>(time(0))));

	// WINDOW INITILIZATION

	window.create(VideoMode::VideoMode(1800, 800), "HURDLE HAVOC!!", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	// STATUS INITIALIZATION

	Animation_Staus = IDLE;

	// TEXTURE INITIALIZATION


	if (!Night_Texture.loadFromFile("Textures/NIGHT.png"))
	{
		cout << "ERROR!" << endl;
	}



	if (!background5Texture.loadFromFile("Textures/M_BACKGROUND_LAYER_5.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!background4Texture.loadFromFile("Textures/M_BACKGROUND_LAYER_4.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!background3Texture.loadFromFile("Textures/M_BACKGROUND_LAYER_3.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!background2Texture.loadFromFile("Textures/M_BACKGROUND_LAYER_2.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!background1Texture.loadFromFile("Textures/M_BACKGROUND_LAYER_2.png"))
	{
		cout << "ERROR!" << endl;
	}


	if (!texture_sheet.loadFromFile("Textures/sprites.png"))
	{
		cout << "ERROR!" << endl;
	}

	if (!Enemy_Texture.loadFromFile("Textures/N_ENEMY.png"))
	{
		cout << "ERROR!" << endl;
	}

	if (!Eb_Texture.loadFromFile("Textures/E_BUTTON.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Port_Texture.loadFromFile("Textures/PORTAL.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!EyeFly_Texture.loadFromFile("Textures/EYE_FLY.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!EXCLAIM_Texture.loadFromFile("Textures/EXCLAIM.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Wave1_Texture.loadFromFile("Textures/WAVE_1.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Wave2_Texture.loadFromFile("Textures/WAVE_2.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Wave3_Texture.loadFromFile("Textures/WAVE_3.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Chestboss_Texture.loadFromFile("Textures/CHEST_BOSS.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Heart_Texture.loadFromFile("Textures/HEART.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Forward_Texture.loadFromFile("Textures/FORWARD.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!HealthBar_Texture.loadFromFile("Textures/HEALTH_BAR.png"))
	{
		cout << "ERROR!" << endl;	
	}

	if (!loadscreen_texture.loadFromFile("Textures/PEAK.png"))
	{
		cout << "ERROR!" << endl;
	}

	if (!startbutton_texture.loadFromFile("Textures/START.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!Hover_texture.loadFromFile("Textures/HOVER.png"))
	{
		cout << "ERROR!" << endl;
	}
	if(!dead_panel_texture.loadFromFile("Textures/sky.png"))
	{
		cout << "ERROR!" << endl;
	}
	if (!bot_texture.loadFromFile("Textures/START.png"))
	{
		cout << "ERROR!" << endl;
	}
	if(!End_Texture.loadFromFile("Textures/END.png"))
	{
		cout << "ERROR!" << endl;
	}
	if(!GO_Texture.loadFromFile("Textures/GO.png"))
	{
		cout << "ERROR!" << endl;
	}



	// GAME LOOP

	while (getwindow().isOpen())
	{




		// POLL EVENT CHECK / POLLING

		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				window.close();
			}
			else if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
			{
				window.close();
			}
			if (ev.type == Event::KeyReleased && (
				ev.key.code == Keyboard::W ||
				ev.key.code == Keyboard::A ||
				ev.key.code == Keyboard::S ||
				ev.key.code == Keyboard::D ||
				ev.key.code == Keyboard::Space ||
				ev.key.code == Mouse::Left))
			{
				Animation_Timer.restart();
				Animation_Switch = true;
			}
		}

		if (!START)
		{
			if (SINITIALIZE)
			{
				Titledown = false;
				loadscreen.setTexture(loadscreen_texture);
				loadscreen.setTextureRect(IntRect(0, 0, 1800, 800));
				Startbutton.setTexture(startbutton_texture);
				
				start_frame = IntRect(0,0,575,191);
				Startbutton.setScale(0.75f,0.75f);
				Startbutton.setPosition(300, window.getSize().y - Startbutton.getGlobalBounds().height - 150);
				HoverTitle.setTexture(Hover_texture);
				HoverTitle.setTextureRect(IntRect(0, 0, 600, 320));
				HoverTitle.setScale(1.5f,1.5f);
				HoverTitle.setOrigin(0.f, 0.f);
				HoverTitle.setPosition(60,0);
				SINITIALIZE = false;
			}


			if (HoverTitle.getGlobalBounds().top <= 0.f)
			{
				Titledown = true;
			}
			else if (HoverTitle.getGlobalBounds().top >= 50.f)
			{
				Titledown = false;
			}

			if (Titledown)
			{
				HoverTitle.move(0.f, 0.5f);
			}
			else
			{
				HoverTitle.move(0.f, -0.5f);
			}


			if (Startbutton.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x), static_cast<float>(Mouse::getPosition(window).y)))
			{
				start_frame.left = 0.f;
				Startbutton.setTextureRect(start_frame);
			}
			else
			{
				start_frame.left = 575.f;
				Startbutton.setTextureRect(start_frame);
			}

			if (HoverTitle.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x), static_cast<float>(Mouse::getPosition(window).y)))
			{
				HoverTitle.setColor(Color::Yellow);
			}
			else
			{
				HoverTitle.setColor(Color::White);
			}

			window.clear();

			
			window.draw(loadscreen);
			window.draw(HoverTitle);
			window.draw(Startbutton);


			if (Startbutton.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x), static_cast<float>(Mouse::getPosition(window).y)) && Mouse::isButtonPressed(Mouse::Left))
			{
				START = true;
			}
			/*window.display();*/
		}


		if (START)
		{

			if (INITIALIZE)
			{
				// PHYSICS INITIALIZATION

				
				dE = 0;
				CE = 0;
				i = 0;
				bonus = 0;
				wave = 1;
				attackthreshold; // Test
			    d = 0;
				maxenemies = 25;
				enemycount = 0;



				max_velocity = 22.f;
				min_velocity = 2.f;
				accleration = 3.f;
				drag = 0.80f;
				gravity = 9.8f;
				Max_Vert_Velocity = 30.f;
				BGspeed = 20.f;
				BeyondSafeZone = 1000.f;
				JUMplimit = 200.f;
				CHESTHP = 100.f;

				// SPRITE INITIALIZATION

				Character.setTexture(texture_sheet);
				currentCharframe = IntRect(640, 0, 128, 128);
				Character.setTextureRect(currentCharframe);
				Character.setScale(2.f, 2.f);
				Character.setPosition(0.f, 0.f);

				// ENEMIES

				enemy.setTexture(Enemy_Texture);
				currentEnemyframe = IntRect(0, 0, 96, 96);

				Eyefly.setTexture(EyeFly_Texture);
				EyeFLYframe = IntRect(0, 0, 150, 48);

				ChestBoss.setTexture(Chestboss_Texture);
				Chestboss_frame = IntRect(0, 0, 108, 32);
				ChestBoss.setTextureRect(Chestboss_frame);
				ChestBoss.setScale(-4.f, 4.f);
				ChestBoss.setPosition(14400 - 700, window.getSize().y - ChestBoss.getGlobalBounds().height - 4 * 16);
				// NIGHT

				Night.setTexture(Night_Texture);
				Night.setTextureRect(IntRect(0, 0, 1800, 800));
				deadpanel.setTexture(dead_panel_texture);
				deadpanel.setTextureRect(IntRect(0, 0, 1800, 800));

				// BACKGROUND

				BG_LY_5.setTexture(background5Texture);
				currentBG5frame = IntRect(0, 0, 1800, 800);
				BG_LY_4.setTexture(background4Texture);
				currentBG4frame = IntRect(0, 0, 1800, 800);
				BG_LY_3.setTexture(background3Texture);
				currentBG3frame = IntRect(0, 0, 1800, 800);
				BG_LY_2.setTexture(background2Texture);
				currentBG2frame = IntRect(0, 0, 1800, 800);
				BG_LY_1.setTexture(background1Texture);
				currentBG1frame = IntRect(0, 0, 1800, 800);


				// BUTTON

				Ebutton.setTexture(Eb_Texture);
				Ebframe = IntRect(0, 0, 32, 32);
				EXCLAIM.setTexture(EXCLAIM_Texture);
				EXCLAIMframe = IntRect(0, 0, 16, 16);
				Wave1.setTexture(Wave1_Texture);
				Wave2.setTexture(Wave2_Texture);
				Wave3.setTexture(Wave3_Texture);
				Waveframe = IntRect(0, 0, 412, 148);
				Heart.setTexture(Heart_Texture);
				Hear_frame = IntRect(0, 0, 64, 64);
				Forward.setTexture(Forward_Texture);
				Forward_frame = IntRect(0, 0, 96, 32);
				bot.setTexture(bot_texture);
				bot_frame= IntRect(0, 0, 575, 191);
				bot.setScale(0.75f, 0.75f);
				bot.setPosition(900- (0.5) * bot.getGlobalBounds().width + 200, (0.5)*window.getSize().y - (0.5)*bot.getGlobalBounds().height );
				GO.setTexture(GO_Texture);
				GO.setTextureRect(IntRect(0, 0, 664, 330));
				GO.setPosition(552,234);

				// PORTAL

				Portal.setTexture(Port_Texture);
				Portframe = IntRect(0, 0, 192, 272);
				HealthBar.setTexture(HealthBar_Texture);
				HealthBar_frame = IntRect(0, 0, 448, 128);
				END.setTexture(End_Texture);
				end_frame= IntRect(0, 0, 1800, 800);

				/*HealthBar.setPosition(30,HealthBar.getGlobalBounds().height + 10);*/


				// ANIMATION INITIALIZATION

				Animation_Timer.restart();
				Enemy_Animation_Timer.restart();
				p_Animation_Timer.restart();
				ATTACK_1_TIMER.restart();
				EF_Animation_Timer.restart();
				Eye_Fly_Animation_Timer.restart();
				WaveClock.restart();
				opacityclock.restart();
				Chestboss_Timer.restart();
				Heart_Timer.restart();
				Dead_Timer.restart();
				End_timer.restart();
				DEAD_opacity.a = 0.f;
				

				// VELOCITY INITIALIZATION FOR ENEMIES


				enemyVelocities.clear();
				currentEnemyframes.clear();
				enemyHP.clear();
				deathtoll.clear();
				EnemyAnimation_Stati.clear();
				ed.clear();
				enemies.clear();


				for (int i = 0; i < maxenemies; ++i)
				{
					Enemy_speed = static_cast<float>(rand() % 3 + 1);
					enemyVelocities.push_back(Enemy_speed);
					currentEnemyframe = IntRect(0, 0, 96, 96);
					currentEnemyframes.push_back(currentEnemyframe);
					enemyHP.push_back(10);
					deathtoll.push_back(false);
					EnemyAnimation_Stati.push_back(IDLE);
					ed.push_back(0);
				}
				for (int i = 0; i < 3; i++)
				{
					timeswitch[i] = 0;
				}

				// HEALTH

				DamageDealt = 2;
				HP = 200;

				// BOOL
				Animation_Switch = true;
				damageanimation = false;
				popthecop = false;
				eyeflytrap = false;
				Normaleyefly = false;
				frmright = false;
			    bloodspilt = false;
			    EFdamageanimation = false;
				exclamationM = false;
				wavefront = false;
			    bosslvl = false;
				BOSSTRAP = false;
				BOSSTRAPLVL = false;
				walk = false;
				CHdamageanimation = false;
				bossbloodspilt = false;
				hasDied = false;
				Rdeadchk = false;
				moveDown = false;
				Hoccupied = false;
				DIF = false;
				BelowJumpLimit = true;
				LowJump = false;
				DoublePressSpace = true;
				Attackheld = false;
				mousePress = false;
				allEnemiesOffScreen = false;
			    RightDrag=false;
				LeftDrag=false;
				orientation_chk=false;
				uplift_chk=false;
				rightx=false;
			    leftx = false;
				nox=false;
				socialDistance=false;
				socialPrivelege=false;
				CanDamage=false;
				dmgthreshold=false;
				thresholddmg=false;
				singledeath=false;
				extrachk=false;
				FEND = false;
				GO_Down = false;

				// BOOL

				INITIALIZE = false;
			}

			// UPDATE PLAYER 

			// UPDATE MOVEMENT

			if (Keyboard::isKeyPressed(Keyboard::Key::A) && !Attackheld) //LEFT
			{
				if (!rightx && !DIF )
				{

					Motion(-1.f, 0.f);
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::D) && !Attackheld) //RIGHT
			{
				if (!leftx && !DIF)
				{
					Motion(1.f, 0.f);
				}

			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Space)&&!DIF)
			{
				if (canJump() && BelowJumpLimit && !LowJump && DoublePressSpace)
				{
					character_velocity.y = -500.f;
					currentCharframe.left = 0.f;
				}
				else
				{
					DoublePressSpace = false;
				}
			}
			if (!Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				if (Character.getGlobalBounds().top < window.getSize().y - Character.getGlobalBounds().height - 64)
				{
					LowJump = true;
				}
				else
				{
					DoublePressSpace = true;
				}

			}


			// UPDATE BACKGROUND

			if (RightDrag)
			{
				RightDrag = false;
			}
			if (LeftDrag)
			{
				LeftDrag = false;
			}

			if (Character.getPosition().x < 200 && character_velocity.x < 0.f)
			{
				float BACKSPEED;

				if (walk)
				{
					BACKSPEED = (0.33) * BGspeed;
				}
				else
				{
					BACKSPEED = BGspeed;
				}

				currentBG1frame.left -= BACKSPEED;
				currentBG2frame.left -= (0.5) * BACKSPEED;
				currentBG3frame.left -= (0.3) * BACKSPEED;
				currentBG4frame.left -= (0.2) * BACKSPEED;
				currentBG5frame.left -= (0.1) * BACKSPEED;

				if (currentBG1frame.left <= 0)
				{
					currentBG1frame.left = 0.f;
					currentBG2frame.left = 0.f;
					currentBG3frame.left = 0.f;
					currentBG4frame.left = 0.f;
					currentBG5frame.left = 0.f;
				}

				RightDrag = true;

				BG_LY_1.setTextureRect(currentBG1frame);
				BG_LY_2.setTextureRect(currentBG2frame);
				BG_LY_3.setTextureRect(currentBG3frame);
				BG_LY_4.setTextureRect(currentBG4frame);
				BG_LY_5.setTextureRect(currentBG5frame);

				// CHARACTER SET BACK

				Motion(1.f, 0.f);


			}
			else if (Character.getPosition().x > 1344 && character_velocity.x > 0.f)
			{
				float BACKSPEED;

				if (walk)
				{
					BACKSPEED = (0.33) * BGspeed;
				}
				else
				{
					BACKSPEED = BGspeed;
				}


				currentBG1frame.left += BACKSPEED;
				currentBG2frame.left += (0.5) * BACKSPEED;
				currentBG3frame.left += (0.3) * BACKSPEED;
				currentBG4frame.left += (0.2) * BACKSPEED;
				currentBG5frame.left += (0.1) * BACKSPEED;

				if (currentBG1frame.left >= 10800.f + (bonus) * 1800)
				{
					currentBG1frame.left = 10800.f + (bonus) * 1800;
					currentBG2frame.left = currentBG2frame.left - (0.5) * BACKSPEED;
					currentBG3frame.left = currentBG3frame.left - (0.3) * BACKSPEED;
					currentBG4frame.left = currentBG4frame.left - (0.2) * BACKSPEED;
					currentBG5frame.left = currentBG5frame.left - (0.1) * BACKSPEED;

				}
				LeftDrag = true;

				BG_LY_1.setTextureRect(currentBG1frame);
				BG_LY_2.setTextureRect(currentBG2frame);
				BG_LY_3.setTextureRect(currentBG3frame);
				BG_LY_4.setTextureRect(currentBG4frame);
				BG_LY_5.setTextureRect(currentBG5frame);

				// CHARACTER SET BACK

				Motion(-1.f, 0.f);

			}
			else
			{
				BG_LY_1.setTextureRect(currentBG1frame);
				BG_LY_2.setTextureRect(currentBG2frame);
				BG_LY_3.setTextureRect(currentBG3frame);
				BG_LY_4.setTextureRect(currentBG4frame);
				BG_LY_5.setTextureRect(currentBG5frame);
			}

			// STATUS UPDATE

			//if (Animation_Staus == MOVING_RIGHT || Animation_Staus == MOVING_LEFT)
			//{
			//	smoke = true;
			//}

			if (Animation_Staus != JUMP)
			{
				uplift_chk = true;
			}



			if (character_velocity.x > 0.f)
			{
				Animation_Staus = MOVING_RIGHT;

			}
			else if (character_velocity.x < 0.f)
			{
				Animation_Staus = MOVING_LEFT;
			}
			else
			{
				if (Character.getPosition().x <= 200 && Keyboard::isKeyPressed(Keyboard::Key::A))
				{
					Animation_Staus = MOVING_LEFT;
				}
				else if (Character.getPosition().x >= 1344 && Keyboard::isKeyPressed(Keyboard::Key::D))
				{
					Animation_Staus = MOVING_RIGHT;
				}
				else
				{
					Animation_Staus = IDLE;
				}

			}
			if (Character.getGlobalBounds().top < window.getSize().y - Character.getGlobalBounds().height - 64)
			{
				Animation_Staus = JUMP;
			}
			if (Mouse::isButtonPressed(Mouse::Button::Left) && Character.getGlobalBounds().top >= window.getSize().y - Character.getGlobalBounds().height - 64 && !mousePress)
			{
				Animation_Staus = ATTACK;
				Attackheld = true;
				currentCharframe.left = 0.f;
			}
			if (Attackheld)
			{
				Animation_Staus = ATTACK;
				Attackheld = true;
				if (Mouse::isButtonPressed(Mouse::Button::Left))
				{
					mousePress = true;
				}
				else
				{
					mousePress = false;
				}
			}
			if (!Attackheld)
			{
				if (!Mouse::isButtonPressed(Mouse::Button::Left))
				{
					mousePress = false;
				}
			}



			if (Animation_Staus == ATTACK)
			{
				if (currentCharframe.left == 512.f)
				{
					Attackheld = false;
					Animation_Staus = IDLE;
				}
			}

			if (uplift_chk)
			{
				if (Animation_Staus == JUMP)
				{
					if (character_velocity.x > 0)
					{
						rightx = true;
					}
					else if (character_velocity.x < 0)
					{
						leftx = true;
					}
					else
					{
						nox = true;
					}
				}
				else
				{
					rightx = false;
					leftx = false;
					nox = false;
				}
			}
			if (HP <= 0)
			{
				if (!Animation_Staus == DEAD)
				{
					currentCharframe.left = 0;
				}
				Animation_Staus = DEAD;

			}


			// UPDATE ANIMATIONS

			if (Animation_Staus != ATTACK)
			{
				attackthreshold = 0;
			}


			if (Animation_Staus == MOVING_RIGHT)
			{
				orientation_chk = true;
			}

			if (Animation_Staus == IDLE)
			{
				if (Animation_Timer.getElapsedTime().asSeconds() >= 0.2f || getAnimation_Switch())
				{
					//IDLE STATE
					currentCharframe.top = 640.f;
					currentCharframe.left += 128.f;
					if (currentCharframe.left >= 640)
					{
						currentCharframe.left = 0.f;
					}
					Animation_Timer.restart();
					Character.setTextureRect(currentCharframe);
				}

			}
			else if (Animation_Staus == MOVING_RIGHT)
			{
				if (Animation_Timer.getElapsedTime().asSeconds() >= 0.1f || getAnimation_Switch())
				{
					// MOVING_RIGHT STATE

					if (!walk)
					{
						currentCharframe.top = 1024;
					}
					else
					{
						currentCharframe.top = 1152;
					}


					currentCharframe.left += 128.f;
					if (currentCharframe.left >= 1024)
					{
						currentCharframe.left = 0.f;
					}
					Animation_Timer.restart();
					Character.setTextureRect(currentCharframe);
				}
				Character.setScale(2.f, 2.f);
				Character.setOrigin(0.f, 0.f);

			}
			else if (Animation_Staus == MOVING_LEFT)
			{
				if (Animation_Timer.getElapsedTime().asSeconds() >= 0.1f || getAnimation_Switch())
				{
					// MOVING_LEFT STATE
					if (!walk)
					{
						currentCharframe.top = 1024;
					}
					else
					{
						currentCharframe.top = 1152;
					}
					currentCharframe.left += 128.f;
					if (currentCharframe.left >= 1024)
					{
						currentCharframe.left = 0.f;
					}
					Animation_Timer.restart();
					Character.setTextureRect(currentCharframe);

				}
				Character.setScale(-2.f, 2.f);
				Character.setOrigin(Character.getGlobalBounds().width / 2.f, 0.f);
			}
			else if (Animation_Staus == JUMP)
			{
				if (Animation_Timer.getElapsedTime().asSeconds() >= 0.1f || getAnimation_Switch())
				{
					// JUMP STATE
					currentCharframe.top = 768;
					currentCharframe.left += 128.f;
					if (currentCharframe.left >= 1152)
					{
						currentCharframe.left = 0.f;
					}
					Animation_Timer.restart();
					Character.setTextureRect(currentCharframe);

				}
				if (character_velocity.x > 0.f)
				{
					Character.setScale(2.f, 2.f);
					Character.setOrigin(0.f, 0.f);
				}
				else if (character_velocity.x < 0.f)
				{
					Character.setScale(-2.f, 2.f);
					Character.setOrigin(Character.getGlobalBounds().width / 2.f, 0.f);
				}
			}
			else if (Animation_Staus == ATTACK)
			{
				if (Animation_Timer.getElapsedTime().asSeconds() >= 0.09f || getAnimation_Switch())
				{
					// JUMP STATE
					if (currentCharframe.top != 0.f && currentCharframe.top != 128.f && currentCharframe.top != 256.f)
					{
						currentCharframe.left = 0.f;
					}

					if (currentCharframe.left == 0)
					{
						if (rand() % 3 == 0)
						{
							currentCharframe.top = 128.f;
						}
						else if (rand() % 3 == 1)
						{
							currentCharframe.top = 256.f;
						}
						else
						{
							currentCharframe.top = 0.f;
						}
					}
					currentCharframe.left += 128.f;
					if (currentCharframe.left >= 640)
					{

						currentCharframe.left = 0.f;
					}
					Animation_Timer.restart();
					Character.setTextureRect(currentCharframe);
				}
			}
			else if (Animation_Staus == DEAD)
			{
				if (Animation_Timer.getElapsedTime().asSeconds() >= 0.8f || getAnimation_Switch())
				{
					// JUMP STATE
					DIF = true;
					currentCharframe.top = 384;
					currentCharframe.left += 128.f;
					if (currentCharframe.left >= 768)
					{
						currentCharframe.left -= 128.f;
						DIF = true;
						walk = true;
					}
					Animation_Timer.restart();
					Character.setTextureRect(currentCharframe);
				}
			}
			else
			{
				currentCharframe.left = 0.f;
				Animation_Timer.restart();
			}
			if (Animation_Staus == MOVING_LEFT)
			{
				orientation_chk = false;
			}

			if (Animation_Staus == ATTACK)
			{
				attackthreshold++;
			}

			// UPDATE ENEMIES

			int wtemp = wave;

			if (!allEnemiesOffScreen)
			{
				enemies = spawnEnemies(Enemy_Texture);
				allEnemiesOffScreen = true;
			}
			enemycount = 0;
			for (const auto& enemy : enemies)
			{
				if (enemy.getPosition().y < 0)
				{
					enemycount++;
				}
			}
			if (!(enemycount == 10 || enemycount == 20))
			{
				popthecop = false;
			}
			if ((enemycount == 10 || enemycount == 20) && !popthecop)
			{
				enemies = spawnEnemies(Enemy_Texture);
				popthecop = true;
			}

			if (!bosslvl)
			{
				if (enemycount == maxenemies)
				{
					bosslvl = true;
					bonus = 1;
					walk = true;
				}
			}

			if (wtemp != wave && !wavefront)
			{
				opacityclock.restart();
				WaveClock.restart();
				wavefront = true;
			}

			for (auto& enemy : enemies)
			{

				size_t index = &enemy - &enemies[0];
				float& currentEvelocity = enemyVelocities[index];
				float& currentEHP = enemyHP[index];
				int& ced = ed[index];


				// COLLISION CHECK

				if (enemy.getPosition().y + enemy.getGlobalBounds().height >= window.getSize().y)
				{
					enemy.setPosition(enemy.getPosition().x, window.getSize().y - enemy.getGlobalBounds().height);
				}

				// 

				int temp = currentEHP;

				if (Animation_Staus == ATTACK && attackthreshold == 12) // 19
				{
					if (!orientation_chk)
					{
						// FACING LEFT
						int CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
						if ((enemy.getPosition().x + 104 < CharacterCenter && enemy.getPosition().x + 104 > CharacterCenter - Character.getGlobalBounds().width + 32 - 16) || ((enemy.getPosition().x + enemy.getGlobalBounds().width - 104) < CharacterCenter && enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > CharacterCenter - Character.getGlobalBounds().width + 32 - 16)
						{
							if (!singledeath)
							{
								currentEHP -= 5;
								if (currentEHP <= 0)
								{
									singledeath = true;
								}
							}
							else
							{
								if (currentEHP > 5)
								{
									currentEHP -= 5;
								}
							}

						}
					}
					else
					{
						// FACING RIGHT
						int CharacterCenter = Character.getPosition().x + 64;
						if ((enemy.getPosition().x + 104 > CharacterCenter && enemy.getPosition().x + 104 < CharacterCenter + Character.getGlobalBounds().width - 32 + 16) || ((enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > CharacterCenter && (enemy.getPosition().x + enemy.getGlobalBounds().width - 104) < CharacterCenter + Character.getGlobalBounds().width - 32 + 16))
						{
							if (!singledeath)
							{
								currentEHP -= 5;
								if (currentEHP <= 0)
								{
									singledeath = true;
								}
							}
							else
							{
								if (currentEHP > 5)
								{
									currentEHP -= 5;
								}
							}

						}
					}
				}

				if (currentEHP < temp && !deathtoll[index])
				{
					deathtoll[index] = true;
					ced = 0;
				}
				if (deathtoll[index] && ced < 3)
				{
					if (ced == 0 || ced == 2)
					{
						enemy.setColor(Color::Red);
					}
					else
					{
						enemy.setColor(Color::Transparent);
					}
					ced++;
				}
				else
				{
					deathtoll[index] = false;
					ced = 0;
					enemy.setColor(Color::White);
				}

				if (!(enemy.getGlobalBounds().intersects(Character.getGlobalBounds()) && Animation_Staus == JUMP))
				{
					if (!orientation_chk)
					{
						// FACING LEFT
						int CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
						socialDistance = false;
						if (((enemy.getPosition().x + 104) < (CharacterCenter - (Character.getGlobalBounds().width - 3 * (64))) || (enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > CharacterCenter + 64))
						{
							socialDistance = true;
						}
						if (socialDistance && (abs(CharacterCenter - enemy.getPosition().x + 96) <= BeyondSafeZone))
						{
							if (enemy.getPosition().x + 104 < CharacterCenter)
							{
								// MOVING RIGHT
								enemy.move(currentEvelocity, 0.f);
							}
							else if (enemy.getPosition().x + enemy.getGlobalBounds().width - 104 > CharacterCenter)
							{
								// MOVING LEFT
								enemy.move(-currentEvelocity, 0.f);
							}
						}
					}
					else
					{
						// FACING RIGHT
						int CharacterCenter = Character.getPosition().x + 64;
						socialDistance = false;
						if (((enemy.getPosition().x + 104) < CharacterCenter - 64 || (enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > (CharacterCenter + Character.getGlobalBounds().width - 3 * (64))))
						{
							socialDistance = true;
						}
						if (socialDistance && (abs(CharacterCenter - enemy.getPosition().x + 96) <= BeyondSafeZone))
						{
							if ((enemy.getPosition().x + 52) < CharacterCenter)
							{
								// MOVING RIGHT
								enemy.move(currentEvelocity, 0.f);
							}
							else if ((enemy.getPosition().x + enemy.getGlobalBounds().width - 104) > CharacterCenter)
							{
								// MOVING LEFT
								enemy.move(-currentEvelocity, 0.f);
							}
						}
					}
				}

				// MOVING ALONG WITH BACKGROUND

				float BACKSPEED;

				if (walk)
				{
					BACKSPEED = (0.33) * BGspeed;
				}
				else
				{
					BACKSPEED = BGspeed;
				}

				if (RightDrag && currentBG1frame.left > 0.f)
				{
					enemy.move(BACKSPEED, 0);
				}
				else if (LeftDrag && currentBG1frame.left < 10800.f + (bonus) * 1800)
				{
					enemy.move(-BACKSPEED, 0);
				}

				// RELOCATE



				if (currentBG1frame.left >= 10800.f && enemy.getPosition().x > window.getSize().x)
				{
					enemy.setPosition(-2000.f, window.getSize().y - enemy.getGlobalBounds().height - 64);

				}


				if (currentBG1frame.left <= 0.f && enemy.getPosition().x < 0.f)
				{
					enemy.setPosition(-2000.f, window.getSize().y - enemy.getGlobalBounds().height - 64);

				}

			}


			DamageDealt = 0.f;

			for (int i = 0; i < 3; i++)
			{
				timeswitch[i]++;
			}


			if (timeswitch[0] == 7)
			{
				EnemyAnim(timeswitch[0]);
			}
			else if (timeswitch[1] == 9)
			{
				EnemyAnim(timeswitch[1]);
			}
			else if (timeswitch[2] == 11)
			{
				EnemyAnim(timeswitch[2]);
			}


			if (ATTACK_1_TIMER.getElapsedTime().asSeconds() >= 5 && !eyeflytrap && !bosslvl)
			{
				if (rand() % 2 == 0)
				{
					Eyefly.setPosition(window.getSize().x + 10 * 500.f, window.getSize().y - Eyefly.getGlobalBounds().height - 6 * 16);
					Eyefly.setScale(-3.f, 3.f);
					frmright = true;
				}
				else
				{
					Eyefly.setPosition(-10 * 500.f, window.getSize().y - Eyefly.getGlobalBounds().height - 6 * 16);
					Eyefly.setScale(3.f, 3.f);
					frmright = false;
				}
				eyeflytrap = true;
				EyeflyHP = 20;
			}

			if (eyeflytrap && !Normaleyefly)
			{
				int CharacterCenter;
				int EYEFLYCenter;


				if (EF_Animation_Timer.getElapsedTime().asSeconds() >= 0.1f)
				{
					//IDLE STATE
					EyeFLYframe.top = 0.f;
					EyeFLYframe.left += 150.f;
					if (EyeFLYframe.left >= 1200)
					{
						EyeFLYframe.left = 0.f;
					}
					Eyefly.setTextureRect(EyeFLYframe);
					EF_Animation_Timer.restart();
				}
				if (frmright)
				{
					Eyefly.setScale(-3.f, 3.f);
				}
				else
				{
					Eyefly.setScale(3.f, 3.f);
				}


				if (frmright)
				{
					if (Eyefly.getPosition().x > -Eyefly.getGlobalBounds().width)
					{
						Eyefly.move(-30.f, 0);
					}
					else
					{
						Normaleyefly = true;

					}
					EYEFLYCenter = Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width;
				}
				else
				{
					if (Eyefly.getPosition().x < window.getSize().x + Eyefly.getGlobalBounds().width)
					{
						Eyefly.move(30.f, 0);
					}
					else
					{
						Normaleyefly = true;
					}
					EYEFLYCenter = Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width;
				}

				if (!orientation_chk)
				{
					// FACING LEFT
					CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;

				}
				else
				{
					// FACING RIGHT
					CharacterCenter = Character.getPosition().x + 64;
				}

				if (CharacterCenter >= EYEFLYCenter - (0.33) * Eyefly.getGlobalBounds().width && CharacterCenter <= EYEFLYCenter + (0.33) * Eyefly.getGlobalBounds().width)
				{
					if ((Character.getGlobalBounds().top + Character.getGlobalBounds().height) >= Eyefly.getGlobalBounds().top + (0.5) * Eyefly.getGlobalBounds().height)
					{
						DamageDealt += 2.5;
					}
				}

				exclamationM = false;
				if (frmright)
				{
					if (EYEFLYCenter > window.getSize().x)
					{
						exclamationM = true;
					}
				}
				else
				{
					if (EYEFLYCenter < 0.f)
					{
						exclamationM = true;
					}
				}


			}
			else
			{
				exclamationM = false;
			}

			if (Normaleyefly)
			{
				// DAMAGE CHK


				if (Animation_Staus == ATTACK && attackthreshold == 12) // 19
				{
					if (!orientation_chk)
					{
						// FACING LEFT
						int CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
						if ((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width < CharacterCenter && Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width > CharacterCenter - Character.getGlobalBounds().width + 32 - 16))
						{
							EyeflyHP -= 5;
							bloodspilt = true;

						}
					}
					else
					{
						// FACING RIGHT
						int CharacterCenter = Character.getPosition().x + 64;
						if ((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width > CharacterCenter) && (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width < CharacterCenter + Character.getGlobalBounds().width - 32 + 16))
						{
							EyeflyHP -= 5;
							bloodspilt = true;
						}
					}
				}

				// MOVEMENT

				if (!(Eyefly.getGlobalBounds().intersects(Character.getGlobalBounds()) && Animation_Staus == JUMP))
				{
					if (!orientation_chk)
					{
						// FACING LEFT
						int CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
						socialDistance = false;
						if ((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) < (CharacterCenter - (Character.getGlobalBounds().width - 3 * (64))) || (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width > CharacterCenter + 64))
						{
							socialDistance = true;
						}
						if (socialDistance)
						{
							if (Eyefly.getPosition().x + 3 * 80 < CharacterCenter)
							{
								// MOVING RIGHT
								Eyefly.move(3.f, 0.f);
							}
							else if (Eyefly.getPosition().x + Eyefly.getGlobalBounds().width - 3 * 80 > CharacterCenter)
							{
								// MOVING LEFT
								Eyefly.move(-3.f, 0.f);
							}
						}
					}
					else
					{
						// FACING RIGHT
						int CharacterCenter = Character.getPosition().x + 64;
						socialDistance = false;
						if ((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width  < CharacterCenter - 64 || Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width >(CharacterCenter + Character.getGlobalBounds().width - 3 * (64))))
						{

							socialDistance = true;
						}
						if (socialDistance)
						{
							if ((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) < CharacterCenter)
							{
								// MOVING RIGHT
								Eyefly.move(3, 0.f);
							}
							else if ((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) > CharacterCenter)
							{
								// MOVING LEFT
								Eyefly.move(-3, 0.f);
							}
						}
					}
				}

				// MOVING ALONG WITH BACKGROUND


				float BACKSPEED;

				if (walk)
				{
					BACKSPEED = (0.33) * BGspeed;
				}
				else
				{
					BACKSPEED = BGspeed;
				}

				if (RightDrag && currentBG1frame.left > 0.f)
				{
					Eyefly.move(BACKSPEED, 0);
				}
				else if (LeftDrag && currentBG1frame.left < 10800.f + (bonus) * 1800)
				{
					Eyefly.move(-BACKSPEED, 0);
				}

				// ANIMATE

				if (EF_Animation_Timer.getElapsedTime().asSeconds() >= 0.2f)
				{
					int CharacterCenter;
					socialPrivelege = false;

					if (!orientation_chk)
					{
						// FACING LEFT
						CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
						if (((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) < (CharacterCenter - (Character.getGlobalBounds().width - 3 * (64))) || (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) > CharacterCenter + 64))
						{
							socialPrivelege = true;
						}
					}
					else
					{
						// FACING RIGHT
						CharacterCenter = Character.getPosition().x + 64;
						if (((Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) < CharacterCenter - 64 || (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) > (CharacterCenter + Character.getGlobalBounds().width - 3 * (64))))
						{
							socialPrivelege = true;
						}
					}

					if (EyeflyHP <= 0)
					{
						if (EyeFLYframe.top != 96.f)
						{
							EyeFLYframe.left = 0.f;
						}
						// DEAD
						EyeFLYframe.top = 96.f;
						EyeFLYframe.left += 150.f;
						if (EyeFLYframe.left >= 600)
						{
							Eyefly.setPosition(0.f, -100.f);
							Normaleyefly = false;
							eyeflytrap = false;
							ATTACK_1_TIMER.restart();

						}
						Eyefly.setTextureRect(EyeFLYframe);
						if (CharacterCenter - (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) < 0.f)
						{
							Eyefly.setScale(3.f, 3.f);
							Eyefly.setOrigin(0.f, 0.f);
						}
						else
						{
							Eyefly.setScale(-3.f, 3.f);
							Eyefly.setOrigin(Eyefly.getGlobalBounds().width / 3.f, 3.f);
						}
						Eyefly.move(0.f, 12.f);
						EF_Animation_Timer.restart();
					}
					else
					{

						if (CharacterCenter - (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) > 0 && socialPrivelege)
						{
							// MOVING RIGHT
							EyeFLYframe.top = 0.f;
							EyeFLYframe.left += 150.f;
							if (EyeFLYframe.left >= 1200)
							{
								EyeFLYframe.left = 0.f;
							}

							Eyefly.setTextureRect(EyeFLYframe);
							Eyefly.setScale(3.f, 3.f);
							Eyefly.setOrigin(0.f, 0.f);

						}
						else if (CharacterCenter - (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) < 0 && socialPrivelege)
						{
							// MOVING LEFT
							EyeFLYframe.top = 0.f;
							EyeFLYframe.left += 150.f;
							if (EyeFLYframe.left >= 1200)
							{
								EyeFLYframe.left = 0.f;
							}
							Eyefly.setTextureRect(EyeFLYframe);
							Eyefly.setScale(-3.f, 3.f);
							Eyefly.setOrigin(Eyefly.getGlobalBounds().width / 3.f, 3.f);
						}
						else
						{
							if (Animation_Staus != JUMP)
							{
								// ATTACK
								EyeFLYframe.top = 48.f; //480.f
								EyeFLYframe.left += 150.f;
								if (EyeFLYframe.left >= 1200)
								{
									EyeFLYframe.left = 0.f;
									if (Animation_Staus != JUMP)
									{
										DamageDealt++;
									}
								}
								Eyefly.setTextureRect(EyeFLYframe);

								if (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width < CharacterCenter)
								{
									Eyefly.setScale(3.f, 3.f);
									Eyefly.setOrigin(0.f, 0.f);

								}
								else if (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width > CharacterCenter)
								{
									Eyefly.setScale(-3.f, 3.f);
									Eyefly.setOrigin(Eyefly.getGlobalBounds().width / 3.f, 3.f);
								}
							}
							else
							{

								if (CharacterCenter - (Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width) > 0 && socialPrivelege)
								{
									// MOVING RIGHT
									EyeFLYframe.top = 0.f;
									EyeFLYframe.left += 150.f;
									if (EyeFLYframe.left >= 1200)
									{
										EyeFLYframe.left = 0.f;
									}

									Eyefly.setTextureRect(EyeFLYframe);
									Eyefly.setScale(3.f, 3.f);
									Eyefly.setOrigin(0.f, 0.f);

								}
								else
								{
									// MOVING LEFT
									EyeFLYframe.top = 0.f;
									EyeFLYframe.left += 150.f;
									if (EyeFLYframe.left >= 1200)
									{
										EyeFLYframe.left = 0.f;
									}
									Eyefly.setTextureRect(EyeFLYframe);
									Eyefly.setScale(-3.f, 3.f);
									Eyefly.setOrigin(Eyefly.getGlobalBounds().width / 3.f, 3.f);
								}
							}




						}

						EF_Animation_Timer.restart();


					}
				}
			}

			// MIMIC BOSS


			if (!BOSSTRAPLVL)
			{

				if (ChestBoss.getGlobalBounds().intersects(Character.getGlobalBounds()))
				{
					// REVEAL CHEST
					if (Chestboss_Timer.getElapsedTime().asSeconds() >= 0.5f)
					{
						//IDLE STATE
						Chestboss_frame.top = 64.f;
						Chestboss_frame.left += 108.f;
						if (Chestboss_frame.left >= 432)
						{
							Chestboss_frame.left = 0.f;
						}
						ChestBoss.setScale(-4.f, 4.f);
						ChestBoss.setOrigin(0.f, 0.f);
						ChestBoss.setTextureRect(Chestboss_frame);
						Chestboss_Timer.restart();
					}

				}
				else
				{
					// NORMAL CHEST
					if (Chestboss_Timer.getElapsedTime().asSeconds() >= 0.5f)
					{
						//IDLE STATE
						Chestboss_frame.left = 0;
						Chestboss_frame.top = 0.f;
						ChestBoss.setScale(-4.f, 4.f);
						ChestBoss.setOrigin(0.f, 0.f);
						ChestBoss.setTextureRect(Chestboss_frame);
						Chestboss_Timer.restart();
					}
				}

				if (ChestBoss.getGlobalBounds().intersects(Character.getGlobalBounds()) && Keyboard::isKeyPressed(Keyboard::E) && Animation_Staus == IDLE)
				{
					BOSSTRAPLVL = true;
					walk = false;
				}

			}


			float BACKSPEED;

			if (walk)
			{
				BACKSPEED = (0.33) * BGspeed;
			}
			else
			{
				BACKSPEED = BGspeed;
			}

			if (RightDrag && currentBG1frame.left > 0.f)
			{
				ChestBoss.move(BACKSPEED, 0);
			}
			else if (LeftDrag && currentBG1frame.left < 10800.f + (bonus) * 1800)
			{
				ChestBoss.move(-BACKSPEED, 0);
			}


			if (BOSSTRAPLVL)
			{
				// DAMAGE CHK

				if (!extrachk)
				{
					ChestBoss.setScale(-6.f, 6.f);
					ChestBoss.setPosition(ChestBoss.getPosition().x, window.getSize().y - ChestBoss.getGlobalBounds().height - 4 * 16);
					ChestBoss.setOrigin(0.f, 0.f);
					ChestBoss.setTextureRect(Chestboss_frame);
					extrachk = true;
				}



				if (Animation_Staus == ATTACK && attackthreshold == 12) // 19
				{
					if (!orientation_chk)
					{
						// FACING LEFT
						int CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
						if (((ChestBoss.getPosition().x - (0.375) * ChestBoss.getGlobalBounds().width) < CharacterCenter && (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width) > CharacterCenter - Character.getGlobalBounds().width + 32 - 16) || (ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width) < CharacterCenter && (ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width > CharacterCenter - Character.getGlobalBounds().width + 32 - 16))
						{
							CHESTHP -= 5;
							bossbloodspilt = true;

						}
					}
					else
					{
						// FACING RIGHT
						int CharacterCenter = Character.getPosition().x + 64;
						if (((ChestBoss.getPosition().x - (0.375) * ChestBoss.getGlobalBounds().width) > CharacterCenter) && ((ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width) < CharacterCenter + Character.getGlobalBounds().width - 32 + 16) || ((ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width) > CharacterCenter) && ((ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width) < CharacterCenter + Character.getGlobalBounds().width - 32 + 16))
						{
							CHESTHP -= 5;
							bossbloodspilt = true;
						}
					}
				}




				// MOVEMENT

				if (!hasDied)
				{
					if (!(ChestBoss.getGlobalBounds().intersects(Character.getGlobalBounds()) && Animation_Staus == JUMP))
					{
						if (!orientation_chk)
						{
							// FACING LEFT
							int CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
							socialDistance = false;


							if ((ChestBoss.getPosition().x - (0.375) * ChestBoss.getGlobalBounds().width) < (CharacterCenter - (Character.getGlobalBounds().width - 3 * (64))) || ((ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width) > CharacterCenter + 64))
							{
								socialDistance = true;
							}
							if (socialDistance)
							{
								if (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width < CharacterCenter)
								{
									// MOVING RIGHT
									ChestBoss.move(3.f, 0.f);
								}
								else if (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width > CharacterCenter)
								{
									// MOVING LEFT
									ChestBoss.move(-3.f, 0.f);
								}
							}
						}
						else
						{
							// FACING RIGHT
							int CharacterCenter = Character.getPosition().x + 64;
							socialDistance = false;
							if ((ChestBoss.getPosition().x - (0.375) * ChestBoss.getGlobalBounds().width) < CharacterCenter - 64 || (ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width) > (CharacterCenter + Character.getGlobalBounds().width - 3 * (64)))
							{

								socialDistance = true;
							}
							if (socialDistance)
							{
								if (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width < CharacterCenter)
								{
									// MOVING RIGHT
									ChestBoss.move(3, 0.f);
								}
								else if (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width > CharacterCenter)
								{
									// MOVING LEFT
									ChestBoss.move(-3, 0.f);
								}
							}
						}
					}

				}

				// ANIMATE

				if (Chestboss_Timer.getElapsedTime().asSeconds() >= 0.2f)
				{
					if (!hasDied)
					{
						int CharacterCenter;
						socialPrivelege = false;

						if (!orientation_chk)
						{
							// FACING LEFT
							CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
							if ((ChestBoss.getPosition().x - (0.375) * ChestBoss.getGlobalBounds().width) < (CharacterCenter - (Character.getGlobalBounds().width - 3 * (64))) || ((ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width) > CharacterCenter + 64))
							{
								socialPrivelege = true;
							}
						}
						else
						{
							// FACING RIGHT
							CharacterCenter = Character.getPosition().x + 64;
							if ((ChestBoss.getPosition().x - (0.375) * ChestBoss.getGlobalBounds().width) < CharacterCenter - 64 || (ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width) > (CharacterCenter + Character.getGlobalBounds().width - 3 * (64)))
							{
								socialPrivelege = true;
							}
						}

						if (CHESTHP <= 0)
						{
							if (Chestboss_frame.top != 160.f)
							{
								Chestboss_frame.left = 0.f;
							}
							// DEAD
							Chestboss_frame.top = 160.f;
							Chestboss_frame.left += 108.f;
							if (Chestboss_frame.left >= 432)
							{
								hasDied = true;
								Chestboss_Timer.restart();
							}
							ChestBoss.setTextureRect(Chestboss_frame);
							if (CharacterCenter - (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width) < 0.f)
							{
								ChestBoss.setScale(6.f, 6.f);
								ChestBoss.setOrigin(ChestBoss.getGlobalBounds().width / 6.f, 0.f);

							}
							else
							{
								ChestBoss.setScale(-6.f, 6.f);
								ChestBoss.setOrigin(0.f, 0.f);

							}
							Chestboss_Timer.restart();
						}
						else
						{

							if (CharacterCenter - (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width) > 0 && socialPrivelege)
							{
								// MOVING RIGHT
								Chestboss_frame.top = 96.f;
								Chestboss_frame.left += 108.f;
								if (Chestboss_frame.left >= 432)
								{
									Chestboss_frame.left = 0.f;
								}

								ChestBoss.setTextureRect(Chestboss_frame);
								ChestBoss.setScale(6.f, 6.f);
								ChestBoss.setOrigin(ChestBoss.getGlobalBounds().width / 6.f, 0.f);

							}
							else if (CharacterCenter - (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width) < 0 && socialPrivelege)
							{
								// MOVING LEFT
								Chestboss_frame.top = 96.f;
								Chestboss_frame.left += 108.f;
								if (Chestboss_frame.left >= 432)
								{
									Chestboss_frame.left = 0.f;
								}
								ChestBoss.setTextureRect(Chestboss_frame);
								ChestBoss.setScale(-6.f, 6.f);
								ChestBoss.setOrigin(0.f, 0.f);

							}
							else
							{
								if (Animation_Staus != JUMP)
								{
									// ATTACK
									Chestboss_frame.top = 128.f; //480.f
									Chestboss_frame.left += 108.f;
									if (Chestboss_frame.left >= 432)
									{
										Chestboss_frame.left = 0.f;
										if (Animation_Staus != JUMP)
										{
											DamageDealt += 5;
										}
									}
									ChestBoss.setTextureRect(Chestboss_frame);

									if (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width < CharacterCenter)
									{
										ChestBoss.setScale(6.f, 6.f);
										ChestBoss.setOrigin(ChestBoss.getGlobalBounds().width / 6.f, 0.f);


									}
									else if (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width > CharacterCenter)
									{
										ChestBoss.setScale(-6.f, 6.f);
										ChestBoss.setOrigin(0.f, 0.f);

									}
								}
								else
								{

									if (CharacterCenter - (ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width) > 0 && socialPrivelege)
									{
										// MOVING RIGHT
										Chestboss_frame.top = 96.f;
										Chestboss_frame.left += 108.f;
										if (Chestboss_frame.left >= 432)
										{
											Chestboss_frame.left = 0.f;
										}

										ChestBoss.setTextureRect(Chestboss_frame);
										ChestBoss.setScale(6.f, 6.f);
										ChestBoss.setOrigin(ChestBoss.getGlobalBounds().width / 6.f, 0.f);


									}
									else
									{
										// MOVING LEFT
										Chestboss_frame.top = 96.f;
										Chestboss_frame.left += 108.f;
										if (Chestboss_frame.left >= 432)
										{
											Chestboss_frame.left = 0.f;
										}
										ChestBoss.setTextureRect(Chestboss_frame);
										ChestBoss.setScale(-6.f, 6.f);
										ChestBoss.setOrigin(0.f, 0.f);

									}
								}




							}

							Chestboss_Timer.restart();


						}

					}
					else
					{
						if (Chestboss_Timer.getElapsedTime().asSeconds() >= 0.3f)
						{
							if (!Rdeadchk)
							{
								Chestboss_frame.left = 216.f;
								Rdeadchk = true;
							}
							Chestboss_frame.top = 160.f;
							Chestboss_frame.left += 108.f;
							if (Chestboss_frame.left >= 432)
							{
								Chestboss_frame.left = 216.f;
							}

							ChestBoss.setTextureRect(Chestboss_frame);
							Chestboss_Timer.restart();
						}

					}
				}


			}



			// UPDATE PHYSICS

			// GRAVITY RUN

			character_velocity.y += 1.0f * gravity;


			if (abs(character_velocity.y) > Max_Vert_Velocity)
			{
				character_velocity.y = Max_Vert_Velocity * ((character_velocity.y < 0.f) ? -1.0f : 1.0f);
			}

			// DECELARATION

			character_velocity *= drag; // drag ,multiplying with both vector2f

			// LIMIT DECELARATION

			if (abs(character_velocity.x) < min_velocity)
			{
				character_velocity.x = 0.f;
			}
			if (abs(character_velocity.y) < min_velocity)
			{
				character_velocity.y = 0.f;
			}

			if (abs(character_velocity.x) <= 1.f)
			{
				character_velocity.x = 0.f;
			}
			if (walk)
			{
				character_velocity.x = (0.77) * character_velocity.x;
			}

			Character.move(character_velocity);

			// UPDATE SMOKE

			/*if (smoke && Animation_Staus==IDLE)
			{

			}*/

			// UPDATE COLLISIONS


			character_velocity.y = 0.f;

			if ((Character.getPosition().y + Character.getGlobalBounds().height >= window.getSize().y - 64))
			{
				Character.setPosition(Character.getPosition().x, window.getSize().y - Character.getGlobalBounds().height - 64);
			}

			// HEALTH DAMAGE DEALT

			// PLAYER

			/*cout << DamageDealt << endl;*/

			HP -= DamageDealt;

			/*cout << HP << endl;*/


			// CLEAR WINDOW

			window.clear();

			// RENDER BACKGROUND

			window.draw(Night);
			window.draw(BG_LY_5);
			window.draw(BG_LY_4);
			window.draw(BG_LY_3);
			window.draw(BG_LY_2);
			window.draw(BG_LY_1);


			if (Animation_Staus == ATTACK || Animation_Staus == DEAD)
			{
				// RENDER ENEMIES

				SPECIALdraw();
				BOSSDRAW();


				for (const auto& enemy : enemies)
				{
					window.draw(enemy);
				}


				// RENDER PLAYER

				Player_Render(window);
			}
			else
			{
				// RENDER PLAYER

				Player_Render(window);

				// RENDER ENEMIES

				BOSSDRAW();
				SPECIALdraw();

				for (const auto& enemy : enemies)
				{
					window.draw(enemy);
				}

			}



			// EBUTTON

			if (!orientation_chk)
			{
				// FACING LEFT
				int CharacterCenter = Character.getPosition().x + Character.getGlobalBounds().width - 64;
				Ebutton.setPosition(CharacterCenter - 32, window.getSize().y - Character.getGlobalBounds().height - 16);

			}
			else
			{
				// FACING RIGHT
				int CharacterCenter = Character.getPosition().x + 64;
				Ebutton.setPosition(CharacterCenter - 16, window.getSize().y - Character.getGlobalBounds().height - 16);
			}

			if (Keyboard::isKeyPressed(Keyboard::Key::E))
			{
				Ebframe.left = 32.f;
				Ebutton.setTextureRect(Ebframe);
			}
			else
			{
				Ebframe.left = 0.f;
				Ebutton.setTextureRect(Ebframe);
			}

			/*window.draw(Ebutton);*/
			if (!BOSSTRAPLVL)
			{
				if (ChestBoss.getGlobalBounds().intersects(Character.getGlobalBounds()) && Animation_Staus == IDLE)
				{
					window.draw(Ebutton);
				}
			}

			if (Animation_Staus == IDLE && hasDied && Portal.getGlobalBounds().intersects(Character.getGlobalBounds()))
			{
				if (Keyboard::isKeyPressed(Keyboard::Key::E))
				{
					FEND = true;
				}



				window.draw(Ebutton);
			}



			if (hasDied)
			{
				if (currentBG1frame.left == 12600 && Portal.getPosition().x > window.getSize().x - 200.f)
				{
					Portal.move(-20.f, 0.f);
				}

				if (RightDrag && currentBG1frame.left > 0.f)
				{
					Portal.move(BACKSPEED, 0);
				}
				else if (LeftDrag && currentBG1frame.left < 10800.f + (bonus) * 1800)
				{
					Portal.move(-BACKSPEED, 0);
				}


				if (p_Animation_Timer.getElapsedTime().asSeconds() >= 0.09f)
				{
					//IDLE STATE
					Portframe.top = 0.f;
					Portframe.left += 192.f;
					if (Portframe.left >= 1728)
					{
						Portframe.left = 0.f;
					}
					p_Animation_Timer.restart();
				}
				Portal.setTextureRect(Portframe);

				window.draw(Portal);

			}
			else
			{
				Portal.setPosition(2 * window.getSize().x, window.getSize().y - Portal.getGlobalBounds().height - 64);
			}

			if (wavefront)
			{
				if (WaveClock.getElapsedTime().asSeconds() <= 4.f)
				{
					if (opacityclock.getElapsedTime().asSeconds() >= 0.2f)
					{
						waveopacity.a -= 12.5f;
						opacityclock.restart();
					}

					if (wave == 2)
					{
						Wave1.setPosition((0.5) * window.getSize().x - (0.5) * Wave1.getGlobalBounds().width, Wave1.getGlobalBounds().height + 50);
						Wave1.setTextureRect(Waveframe);
						Wave1.setColor(waveopacity);
						window.draw(Wave1);
					}
					if (wave == 3)
					{
						Wave2.setPosition((0.5) * window.getSize().x - (0.5) * Wave2.getGlobalBounds().width, Wave2.getGlobalBounds().height + 50);
						Wave2.setTextureRect(Waveframe);
						Wave2.setColor(waveopacity);
						window.draw(Wave2);
					}
					if (wave == 4)
					{
						Wave3.setPosition((0.5) * window.getSize().x - (0.5) * Wave3.getGlobalBounds().width, Wave3.getGlobalBounds().height + 50);
						Wave3.setTextureRect(Waveframe);
						Wave3.setColor(waveopacity);
						window.draw(Wave3);
					}
				}
				else
				{
					wavefront = false;
					waveopacity.a = 255;
				}
			}


			CircleShape c1;
			CircleShape c2;
			CircleShape c3;
			CircleShape c4;

			c1.setFillColor(Color::Red);
			c1.setRadius(2.f);
			c1.setPosition(Eyefly.getPosition().x + (0.5) * Eyefly.getGlobalBounds().width, (0.5) * window.getSize().y);
			window.draw(c1);

			c2.setFillColor(Color::Red);
			c2.setRadius(2.f);
			c2.setPosition(ChestBoss.getPosition().x - (0.375) * ChestBoss.getGlobalBounds().width, window.getSize().y - ChestBoss.getGlobalBounds().height - 4 * 16);
			window.draw(c2);

			c3.setFillColor(Color::Red);
			c3.setRadius(2.f);
			c3.setPosition(ChestBoss.getPosition().x - ChestBoss.getGlobalBounds().width + (0.375) * ChestBoss.getGlobalBounds().width, window.getSize().y - ChestBoss.getGlobalBounds().height - 4 * 16);
			window.draw(c3);


			/*c4.setFillColor(Color::Red);
			c4.setRadius(2.f);
			c4.setPosition(ChestBoss.getPosition().x + ChestBoss.getGlobalBounds().width, window.getSize().y -  16);
			target.draw(c4);*/


			if ((bosslvl && !BOSSTRAPLVL) || hasDied)
			{
				Forward.setPosition(window.getSize().x - (1.5) * Forward.getGlobalBounds().width, (1.5) * Forward.getGlobalBounds().height);

				if (Keyboard::isKeyPressed(Keyboard::Key::Space))
				{
					Forward_frame.left = 96.f;
					Forward.setTextureRect(Forward_frame);
				}
				else
				{
					Forward_frame.left = 0.f;
					Forward.setTextureRect(Forward_frame);
				}

				window.draw(Forward);
			}

			if (hasDied)
			{
				if (!BOSSTRAP)
				{
					Heart.setPosition(ChestBoss.getPosition().x - (0.5) * ChestBoss.getGlobalBounds().width - (0.20) * Heart.getGlobalBounds().width, window.getSize().y - Heart.getGlobalBounds().height - 4 * 64);
					BOSSTRAP = true;
				}

				float BACKSPEED;

				if (walk)
				{
					BACKSPEED = (0.33) * BGspeed;
				}
				else
				{
					BACKSPEED = BGspeed;
				}

				if (RightDrag && currentBG1frame.left > 0.f)
				{
					Heart.move(BACKSPEED, 0);
				}
				else if (LeftDrag && currentBG1frame.left < 10800.f + (bonus) * 1800)
				{
					Heart.move(-BACKSPEED, 0);
				}


				// HOVER

				if (Heart.getPosition().y <= window.getSize().y - Heart.getGlobalBounds().height - 4 * 64)
				{
					moveDown = true;
				}
				else if (Heart.getPosition().y >= window.getSize().y - Heart.getGlobalBounds().height - 3 * 64)
				{
					moveDown = false;
				}
				if (moveDown)
				{
					Heart.move(0.f, 0.5f);
				}
				else
				{
					Heart.move(0.f, -0.5f);
				}

				if (Heart.getGlobalBounds().intersects(Character.getGlobalBounds()) && Animation_Staus == JUMP)
				{
					HP = 200;
					Hoccupied = true;
				}



				if (Heart_Timer.getElapsedTime().asSeconds() >= 0.1f)
				{
					Hear_frame.top = 0.f;
					Hear_frame.left += 64.f;
					if (Hear_frame.left >= 512)
					{
						Hear_frame.left = 0.f;
					}

					Heart.setTextureRect(Hear_frame);
					Heart_Timer.restart();
				}
				Heart.setScale(2.f, 2.f);
				if (!Hoccupied)
				{
					window.draw(Heart);
				}


				

			}
			if (DIF)
			{

				if (Dead_Timer.getElapsedTime().asSeconds() >= 0.09f && static_cast<float>(DEAD_opacity.a) < 255.f)
				{

					DEAD_opacity.a += 5.f;
					Dead_Timer.restart();
				}

				deadpanel.setColor(DEAD_opacity);

				window.draw(deadpanel);

				if (DEAD_opacity.a == 255)
				{

					if (bot.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x), static_cast<float>(Mouse::getPosition(window).y)))
					{
						bot_frame.left = 0.f;
						bot.setTextureRect(bot_frame);
					}
					else
					{
						bot_frame.left = 575.f;
						bot.setTextureRect(bot_frame);
					}

					window.draw(bot);

					if (bot.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x), static_cast<float>(Mouse::getPosition(window).y)) && Mouse::isButtonPressed(Mouse::Left))
					{
						INITIALIZE = true;
					}

				}
				
			}
			if (FEND)
			{

				if (End_timer.getElapsedTime().asSeconds() >= 0.2f)
				{
					end_frame.left += 1800;
					if (end_frame.left >= 3600)
					{
						end_frame.left = 0.f;
					}

					END.setTextureRect(end_frame);
					End_timer.restart();
				}

				if (Dead_Timer.getElapsedTime().asSeconds() >= 0.09f && static_cast<float>(DEAD_opacity.a) < 255.f)
				{

					DEAD_opacity.a += 5.f;
					Dead_Timer.restart();
				}

				END.setColor(DEAD_opacity);

				window.draw(END);

				if (DEAD_opacity.a == 255)
				{
					if (GO.getGlobalBounds().top <= 134.f)
					{
						GO_Down= true;
					}
					else if (GO.getGlobalBounds().top >= 334.f)
					{
						GO_Down = false;
					}

					if (GO_Down)
					{
						GO.move(0.f, 0.5f);
					}
					else
					{
						GO.move(0.f, -0.5f);
					}

				     
					window.draw(GO);


				}


			}

		}

		// DISPLAY FRAME

		window.display();
	}
	

	system("pause");
	return 0;
}