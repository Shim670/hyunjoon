#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
void main()
{
	
	srand(time(NULL));
	int me, your, game, police;          
	char turnrole[6][10] = { "Killer1", "Citizen1", "Police1", "Killer2", "Citizen2", "Police2" }; // 순서대로 정리해놓은  
	me = rand() % 6 + 1;
	your = rand() % 6 + 1;
	while (me == your)
		me = rand() % 6 + 1;
	char check[10];
	printf("'Killer' Game Start?(Push Enter to start)");
	gets_s(check);
	printf("Police:2\tKiller:2\tCitizen:2");
	gets_s(check);
	printf("Now let's randomly assign the roles");
	gets_s(check);
	printf("Your player number:%d\nYour friend player number:%d", me, your);
	gets_s(check);
	printf("Now Check your role..\nOther Player look away please.");
	gets_s(check);

	if (me < your)
	{
		printf("Player%d turn, Check your role\n", me);
		gets_s(check);
		printf("Player%d role:%s\n\n", me, turnrole[me - 1]);
		printf("Please Enter to continue");
		gets_s(check);
		for (int i = 0; i < 30; i++)
			printf("\n");
		printf("Player%d turn, Check your role\n", your);
		gets_s(check);
		printf("Player%d role:%s\n\n", your, turnrole[your - 1]);
		printf("Please Enter to continue");
		gets_s(check);
		for (int i = 0; i < 30; i++)
			printf("\n");
		gets_s(check);
	}
	else if (me > your)
	{
		
		printf("Player%d turn, Check your role\n", your);
		gets_s(check);
		printf("Player%d role:%s", your, turnrole[your - 1]);
		gets_s(check);
		for (int i = 0; i < 30; i++)
			printf("\n");
		gets_s(check);
		printf("Player%d turn, Check your role\n", me);
		gets_s(check);
		printf("Player%d role:%s", me, turnrole[me - 1]);
		gets_s(check);
		for (int i = 0; i < 30; i++)
			printf("\n");
	}
	// 여기까지 모든 플레이어의 역할 부여 종료

		

	printf("Now,in the given order, each player will take their turn to choose\nWait a minute..\n");
	Sleep(2000);
	printf("Game Start!!");
	gets_s(check);  
	for (int i = 0; i < 30; i++)
		printf("\n");
	//여기까지 왼벽
	int a;
	int my_knownKiller = 0,your_knownKiller=0;
	int alive[6] = { 1,1,1,1,1,1 };  

	int my_potion = 0, your_potion = 0, my_share = 0, your_share = 0;
	int Citizen1_potion = 0, Citizen2_potion = 0, Citizen1_share = 0, Citizen2_share = 0;
	int Citizen1_info = 0, Citizen2_info = 0;
	int A = 0; //시민게임에 사용하는 
	int Killer1_lasttarget = 0;
	int Killer1_wasCitizen=0;  
	int Killer2_lasttarget=0;
	int Killer2_wasCitizen = 0; 
	int killreason[6] = { 0,0,0,0,0,0 };
	int police_lasttarget = 0;
	int Police_wasKiller = 0;
	int police_lastaction = 0;
	int in_prison[6] = { 0,0,0,0,0, };
	int my_wasSave = 0, your_wasSave = 0;
	int my_gum=0, your_gum=0, Citizen1_gum=0, Citizen2_gum=0;
	int my_gumtarget = 0, your_gumtarget = 0, Citizen1_gumtarget = 0, Citizen2_gumtarget = 0;
	int my_gumKiller = 0, your_gumKiller = 0, Citizen1_gumKiller = 0, Citizen2_gumKiller = 0;

	// ---------------------------------------------------------------------------
	while (1)
	{
		
		a = 0;
		//A=0부터 시작

		printf("----------------------------------------------------------\n");
		for (int i = 0; i < 6; i++)
		{
			if (alive[i] == 0)
			{
				if (killreason[i] == 1)
				{
					printf("Player%d's role: %s(Killed by Killer)\n", i + 1, turnrole[i]);
				}
				else if (killreason[i] == 2)
				{
					printf("Player%d's role: %s(Arrested by Police)\n", i + 1, turnrole[i]);
				}
				else if (killreason[i] == 3) //귀살대에게 죽었을 경우
				{
					printf("Player%d's role: %s(Killed by Slayer)\n", i + 1, turnrole[i]);
				}
				gets_s(check);

			}
		}


		printf("Alive Players\n");
		for (int i = 0; i < 6; i++)
		{

			if (alive[i] == 1)
				printf("Player%d   ", i + 1);
		}
		gets_s(check);

		for (int z = 0; z < 30; z++)
			printf("\n");


		for (int i = 0; i < 6; i++)
		{  //여기서부터 라운드 시작
			if (i == 0)
			{
				printf("Nighttime has come!!");
				gets_s(check);
			}
			//여기까지는 완벽
			//-------------------------------------------------------------
			for (int i = 0; i < 60; i++)
				printf("\n");

			if (alive[i] == 0)
			{
				if (i + 1 == me || i + 1 == your)
				{
					printf("Player%d turn", i + 1);
					gets_s(check);
					if (killreason[i] == 1)
					{
						printf("But you are dead..\nYou are killed by a Killer\n");
						printf("\nPush Enter to contine..");
					
					}
					else if (killreason[i] == 2)
					{
						printf("But you are dead..\nYou are arrested by the Police\n");
						printf("\nPush Enter to contine..");
					}
					else if (killreason[i] == 3)  //칼로 죽음
					{
						printf("But you are dead..\nYou are killed by the Citizen\n");
						printf("\nPush Enter to continue..");
					}
					gets_s(check);
				}
				continue;
			}

			if (in_prison[i] == 1)
			{
				if (i + 1 == me || i + 1 == your)
				{
					printf("Player%d turn", i + 1);
					gets_s(check);
					printf("You are currently in prison for Wrongful arrest!!\n");
				}
				else
					printf("Player%d is in prison for Wrongful arrest!!\n", i + 1);
				in_prison[i] = 0;
				continue;
			}


			if (i + 1 == me)                //내차례
			{
				if (my_wasSave == 1)
				{
					printf("Your was attacked by the Killer,But you survived thanks to the Defense potion!\n");
					gets_s(check);
					getchar();
					my_wasSave = 0;
				}
				printf("Player%d turn(other player look away..)", i + 1);
				gets_s(check);

				if (strcmp(turnrole[me - 1], "Killer1") == 0 || strcmp(turnrole[me - 1], "Killer2") == 0)// 나의 역할이 킬러일때
				{
					if (strcmp(turnrole[me - 1], "Killer1") == 0)   //내가 만약 킬러1이고 직전에 킬러2가 누굴 지목했는지 공유 받을때
					{
						if (Killer2_lasttarget != 0)
						{
							if (Killer2_wasCitizen == 1)
								printf("Killer2 kill Player%d(Player%d: Citizen)\n", Killer2_lasttarget, Killer2_lasttarget);
							else if (Killer2_wasCitizen == 0)
								printf("Killer2 tried to kill Player%d(Player%d: Not a Citizen)\n", Killer2_lasttarget, Killer2_lasttarget);
						}
						
					}
					else if (strcmp(turnrole[me - 1], "Killer2") == 0)   //내가 만약 킬러2이고 직전에 킬러1이 누굴 지목했는지 공유 받을때
					{
						if (Killer1_lasttarget != 0)// 0이 아니라는것은 무조건 지목을 했다는 것을 의미
						{
							if (Killer1_wasCitizen == 1)  //시민을 죽임
								printf("Killer1 kill Player%d(Player%d: Citizen)\n", Killer1_lasttarget, Killer1_lasttarget);
							else if (Killer1_wasCitizen == 0)
								printf("Killer1 tried to kill Player%d(Player%d: Not a Citizen)\n", Killer1_lasttarget, Killer1_lasttarget);
						}
						
					}

					printf("Choose a player to kill. Enter the player's number: ");
					scanf_s("%d", &a);

					if (alive[a - 1] == 0) // 이미 죽은사람을 지목하면 패스
					{
						printf("Already killed");
						gets_s(check);
						if (strcmp(turnrole[me - 1], "Killer1") == 0)
						{
							Killer1_lasttarget = a;
							if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)
								Killer1_wasCitizen = 1;
							else
								Killer1_wasCitizen = 0;
						}
						else
						{
							Killer2_lasttarget = a;
							if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)
								Killer2_wasCitizen = 1;
							else
								Killer2_wasCitizen = 0;
						}

					}

					if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)  //만약 시민을 죽이면
					{
						alive[a - 1] = 0;
						killreason[a - 1] = 1;


						if (a == your && your_potion == 1)   //만약 your가 시민이면서 동시에 물약이 있다면
						{
							printf("Player%d is Citizen, But Player%d survived thanks to the Defense potion!", a, a);
							gets_s(check);
							getchar();
							alive[a - 1] = 1;
							your_potion = 0;
							your_wasSave = 1;
						}
						else
						{
							printf("Player%d is Citizen. You successfully killed the player!", a);
							gets_s(check);
							getchar();
						}
						if (strcmp(turnrole[me - 1], "Killer1") == 0)
						{
							Killer1_wasCitizen = 1;
							Killer1_lasttarget = a;
						}
						else
						{
							Killer2_wasCitizen = 1;
							Killer2_lasttarget = a;
						}

					}
					else  //경찰이나 같은 킬러를 죽이면
					{
						printf("Player%d is not Citizen, You kill attempt failed!", a);
						gets_s(check);
						getchar();

						if (strcmp(turnrole[me - 1], "Killer1") == 0)
						{
							Killer1_lasttarget = a;
							Killer1_wasCitizen = 0;
						}
						else
						{
							Killer2_lasttarget = a;
							Killer2_wasCitizen = 0;
						}
					}
					continue;
				
			}  // 내역할이 킬러일때 반복문 끝나는 문

			else if (strcmp(turnrole[me - 1], "Citizen1") == 0 || strcmp(turnrole[me - 1], "Citizen2") == 0 ) // 내역할이 시민일때
			{ 
					if (my_gum != 1)
					{
						printf("Remember,You are the police team's helper..\nThis chance could become real help for them.");
						gets_s(check);
						printf("Now Game Start\nif you win,you can choose an ability. if you lose,nothing happen");
						gets_s(check);
						printf("Wait a minute..\n");
						Sleep(2000);

						printf("Game1.Odd or Even\nGame2.Up&Down\nChoose one Game:");
						scanf_s("%d", &game);
						getchar();

						if (game == 1)
						{
							int num = 0, random = 0;
							printf("'Odd or Even' Game start!");
							gets_s(check);
							printf("Wait a minute..");
							Sleep(2000);
							//게임 시작
							random = rand() % 50 + 1;
							printf("A random number has been chosen\nIs it Odd(1) or Even(2)?\n");
							scanf_s("%d", &num);
							if (random % 2 == 0)// 랜덤숫자가 짝수일때
							{
								if (num == 2) // 만약 미니게임에서 시민이 승리했을 떄
								{
									int abilities = 0;
									abilities = rand() % 20 + 1;
									if (abilities <= 6)
										abilities = 1;
									else if (abilities <= 12)
										abilities = 2;
									else if (abilities <= 18)
										abilities = 3;
									else
										abilities = 4;
									printf("Win!!");
									//능력 선택하기
									gets_s(check);
									printf("You win,You will randomly receive one of the three abilities!");
									gets_s(check);
									printf("1.Defense potion(survive even if the killer targets you next turn)\n2.Killer Info(find out the identity of one of the two Killers)\n3.Report to Police(share the Killer's identity with the Police)\n4.Swordsman(Become a swordsman and kill the Killer)");
									gets_s(check);
									printf("Wait a minute..\n");
									Sleep(2000);
									if (abilities == 1)   /// 수비 물약
									{
										printf("You have obtained the Defense potion(survived one time)\n");
										gets_s(check);
										my_potion = 1;   //내가 물약을 가지고 있다는 의미
									}
									else if (abilities == 2)  //킬러의 정보를 알아냄
									{

										int random_killer = 0;
										printf("You have obtained the Killer Info ability(if you have 'Report to Police', Report to Police)\n");
										gets_s(check);
										random_killer = rand() % 2 + 1;  //랜덤으로 두명의 킬러중 한명만 알려주기

										if (random_killer == 1)
										{
											printf("Player1 is Killer1");
											gets_s(check);
											my_knownKiller = 1;  //플레이어1이 킬러라는 것을 알아냄
										}
										else
										{
											printf("Player4 is Killer2");
											gets_s(check);
											my_knownKiller = 4;  //플레이어4가 킬러라는 것을 알아냄
										}
									}
									else if (abilities == 3)// 경찰에게 정보를 공유
									{
										printf("You have obtained the ability to Report to Police(if you have 'Killer Info', Report to Police)\n");
										gets_s(check);
										my_share = 1;
									}
									else       //귀살대가 되는 능력
									{
										printf("You have obtained the ability to become a Swordsman and kill the Killer(You are now a Swordsman, not just a Citizen)\n");
										gets_s(check);
										my_gum = 1;
									}
								}
								else if (num == 1)  //게임에서 졌을 경우
								{
									printf("Lose,You couldn't become a help to the Police team");
									gets_s(check);
									getchar();
								}
							}
							else if (random % 2 != 0) // 랜덤숫자가  홀수일때
							{
								int abilities = 0;
								if (num == 2)
								{
									printf("Lose, You couldn't become a help to the Police team");
									gets_s(check);
									getchar();
								}
								else if (num == 1)
								{
									abilities = rand() % 20 + 1;
									if (abilities <= 6)
										abilities = 1;
									else if (abilities <= 12)
										abilities = 2;
									else if (abilities <= 18)
										abilities = 3;
									else
										abilities = 4;

									printf("Win!!");
									//능력 선택하기
									gets_s(check);
									printf("You win,You will randomly receive one of the three abilities!\n");
									gets_s(check);
									printf("1.Defense potion(survive even if the killer targets you next turn)\n2.Killer Info(find out the identity of one of the two Killers)\n3.Report to Police(share the Killer's identity with the Police)\n4.Swordsman(Become a swordsman and kill the Killer)");
									gets_s(check);
									printf("Wait a minute..\n");
									Sleep(2000);
									if (abilities == 1)   /// 수비 물약
									{
										printf("You have obtained the Defense potion\n");
										gets_s(check);
										my_potion = 1;
									}
									else if (abilities == 2)  //킬러의 정보를 알아냄
									{

										int random_killer = 0;
										printf("You have obtained the Killer Info ability\n");
										gets_s(check);
										random_killer = rand() % 2 + 1;  //랜덤으로 두명의 킬러중 한명만 알려주기

										if (random_killer == 1)
										{
											printf("Player1 is Killer1");
											gets_s(check);
											my_knownKiller = 1;  //플레이어1이 킬러라는 것을 알아냄
										}
										else
										{
											printf("Player4 is Killer2");
											gets_s(check);
											my_knownKiller = 4;  //플레이어4가 킬러라는 것을 알아냄
										}
									}
									else if (abilities == 3)// 경찰에게 정보를 공유
									{
										printf("You have obtained the ability to Report to Police\n");
										gets_s(check);
										my_share = 1;
									}
									else       //귀살대가 되는 능력
									{
										printf("You have obtained the ability to become a Swordsman and kill the Killer(You are now a Swordsman, not just a Citizen)\n");
										gets_s(check);
										my_gum = 1;
									}
								}
							}
						} // if(game==1) 끝나는 문 (여기가 추가된 중괄호 1번째)
						else if (game == 2)
						{
							int Num = 0;
							int TRY = 0;
							int Check = 0;
							printf("'Up&Down' Game start!");
							gets_s(check);
							printf("Wait a minute..\n");
							Sleep(2000);
							Num = rand() % 30 + 1;
							printf("A random numner between 1~30 has been chosen. You have 5 tries to guess it\n");
							gets_s(check);

							for (int i = 0; i < 5; i++)
							{
								printf("Try%d ", i + 1);
								scanf_s("%d", &TRY);
								if (TRY < Num)
								{
									if (i == 4)
									{
										printf("Lose, You couldn't become a help to the Police team");
										gets_s(check);
										getchar();
									}
									else
										printf("Up!\n");
								}
								else if (TRY > Num)
								{
									if (i == 4)
									{
										printf("Lose, You couldn't become a help to the Police team");
										gets_s(check);
										getchar();
									}
									else
										printf("Down!\n");
								}
								else
								{
									int abilities = 0;
									printf("Win!!\n");
									{
										gets_s(check);
										Check = 1;
										abilities = rand() % 20 + 1;
										if (abilities <= 6)
											abilities = 1;
										else if (abilities <= 12)
											abilities = 2;
										else if (abilities <= 18)
											abilities = 3;
										else
											abilities = 4;
										gets_s(check);
										printf("You win,You will randomly receive one of the three abilities!\n");
										gets_s(check);
										printf("1.Defense potion(survive even if the killer targets you next turn)\n2.Killer Info(find out the identity of one of the two Killers)\n3.Report to Police(share the Killer's identity with the Police)\n4.Swordsman(Become a swordsman and kill the Killer)");
										gets_s(check);
										printf("Wait a minute..\n");
										Sleep(2000);
										if (abilities == 1)   /// 수비 물약
										{
											printf("You have obtained the Defense potion(survive one time)\n");
											gets_s(check);
											my_potion = 1;
										}
										else if (abilities == 2)  //킬러의 정보를 알아냄
										{

											int random_killer = 0;
											printf("You have obtained the Killer Info ability(if you have 'Report to Police', Report to Police)\n");
											gets_s(check);
											random_killer = rand() % 2 + 1;  //랜덤으로 두명의 킬러중 한명만 알려주기

											if (random_killer == 1)
											{
												printf("Player1 is Killer1");
												gets_s(check);
												my_knownKiller = 1;  //플레이어1이 킬러라는 것을 알아냄
											}
											else
											{
												printf("Player4 is Killer2");
												gets_s(check);
												my_knownKiller = 4;  //플레이어4가 킬러라는 것을 알아냄
											}
										}
										else if (abilities == 3) // 경찰에게 정보를 공유
										{
											printf("You have obtained the ability to Report to Police(if you have 'Killer Info', Report to Police)\n");
											gets_s(check);
											my_share = 1;
										}
										else       //귀살대가 되는 능력
										{
											printf("You have obtained the ability to become a Swordsman and kill the Killer(You are now a Swordsman, not just a Citizen)");
											gets_s(check);
											my_gum = 1;
										}
									}

									if (Check == 1)
										break;
									if (i == 4)
									{
										printf("Lose, You couldn't become a help to the Police team");
										gets_s(check);
										getchar();
									}
								}
							}// for문 종료
						}
						

					}  //보통 시민일 경우 끝나는 문

					else if (my_gum != 0)  //귀살대가 되었을 경우
					{
						my_gum++;

						if (my_gum == 2 )   //처음 귀살대가 되었을떄만 알려주기
						{
							printf("Now you become a Swordsman, Let's go kill the Killer!!");
							gets_s(check);
						}
						printf("With your blade, Choose the Player's number you wish to slay(But if you kill someone who is not the Killer, you will die..): "); 
						scanf_s("%d", &my_gumtarget);
						printf("Wait a minute..\n");
						Sleep(2000);

						if (my_gumtarget == 1 || my_gumtarget == 4)   //만약 킬러를 죽일시
						{
							printf("You have killed the Killer!!\nPlayer%d is dead",my_gumtarget);
							gets_s(check);
							getchar();
							alive[my_gumtarget - 1] = 0;
							my_gumKiller = 1;
							killreason[my_gumtarget-1] = 3;
						}
						else
						{
							printf("Player%d is not a Killer, So you have died instead", my_gumtarget);
							gets_s(check);
							getchar();
							alive[me - 1] = 0;
							my_gumKiller = 0;
							killreason[me-1] = 3;
						}
						
					}

			}  //내역할이 시민일 떄 반복문 끝나는 문 (여기가 추가된 중괄호 2번째)
			

			else if (strcmp(turnrole[me - 1], "Police1") == 0 || strcmp(turnrole[me - 1], "Police2") == 0) //내 역할이 경찰
			{
					if (police_lasttarget != 0)
					{
						if (police_lastaction != 0)
						{
							if (police_lastaction == 1)
							{
								if (Police_wasKiller == 1)
									printf("Ourt team investigated Player%d(Player%d: Killer)\n", police_lasttarget, police_lasttarget);
								else
									printf("Ourt team investigated Player%d(Player%d: Not a Killer)\n", police_lasttarget, police_lasttarget);
							}
							else if (police_lastaction == 2)
							{
								if (Police_wasKiller == 1)
									printf("Ourt team Arrested Player%d(Player%d: Killer)\n", police_lasttarget, police_lasttarget);
								else
									printf("Ourt team tried to Arrest Player%d(Player%d: Not a Killer)\n", police_lasttarget, police_lasttarget);
							}

						}
						gets_s(check);
					
					}

				if (strcmp(turnrole[me - 1], "Police1") == 0) //만약 police1이라면
				{
					if (your_share == 1 && your_knownKiller != 0) //시민이 공유 능력을 사용할 경우
					{
						printf("Citizen has shared killer info with you: Player%d is a Killer\n", your_knownKiller);
						your_share = 0;
						your_knownKiller = 0;
					}
					if (Citizen1_share == 1 && Citizen1_info != 0)
					{
						printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen1_info);
						Citizen1_info = 0;
						Citizen1_share = 0;
					}
					if (Citizen2_share == 1 && Citizen2_info != 0)
					{
						printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen2_info);
						Citizen2_info = 0;
						Citizen2_share = 0;
					}
				}
				else if (strcmp(turnrole[me - 1], "Police2") == 0) //police2라면
				{

					if (your_share == 1 && your_knownKiller != 0)   //시민이 공유 능력을 사용할 경우
					{
						printf("Citizen has shared killer info with you : Player%d is a Killer\n", your_knownKiller);
						your_share = 0;
						your_knownKiller = 0;
					}
					if (Citizen1_share == 1 && Citizen1_info != 0)
					{
						printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen1_info);
						Citizen1_info = 0;
						Citizen1_share = 0;
					}
					if (Citizen2_share == 1 && Citizen2_info != 0)
					{
						printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen2_info);
						Citizen2_info = 0;
						Citizen2_share = 0;
					}
				}

				printf("\n1.Investigate\n2.Arrest\nChoose one:");  //조사할지 체포할지 결정
				scanf_s("%d", &police);
				if (police == 1)   //조사
				{
					printf("Choose a player to investigate. Enter the player's number: ");
					scanf_s("%d", &a);

					police_lasttarget = a;
					police_lastaction = 1;


					if (alive[a - 1] == 0)
					{
						printf("Already killed\n");

					}
					if (strcmp(turnrole[a - 1], "Killer1") == 0 || strcmp(turnrole[a - 1], "Killer2") == 0)
					{
						printf("Player%d is Kiler", a);
						gets_s(check);
						getchar();
						Police_wasKiller = 1;
					}
					else
					{
						printf("Player%d is not killer", a);
						gets_s(check);
						getchar();
						Police_wasKiller = 0;
					}
				}
				else if (police == 2)
				{
					printf("Choose a player to Arrest. Enter the player's number: ");
					scanf_s("%d", &a);
					police_lasttarget = a;
					police_lastaction = 2;

					if (alive[a - 1] == 0)
					{
						printf("Already killed\n");

					}
					if (strcmp(turnrole[a - 1], "Killer1") == 0 || strcmp(turnrole[a - 1], "Killer2") == 0)
					{
						printf("Player%d is Killer, Arrest successful!!", a);
						gets_s(check);
						getchar();
						alive[a - 1] = 0;
						killreason[a - 1] = 2; //경찰에게 체포를 당해 죽음
						Police_wasKiller = 1;
					}

					else   // 킬러가 아닌 다른 사람을 체포했을때
					{
						printf("Player%d is not a Killer!!\nWrongful arrest,You are sent to Prison for 1 turn!!", a);
						gets_s(check);
						getchar();
						in_prison[me - 1] = 1;
						Police_wasKiller = 0;
					}

				}
			} // 내역할이 경찰일떄 반복문 끝나는 문

			for (int i = 0; i < 30; i++)
				printf("\n");
		} //내차례 끝나는 문

		




		

			
	
			else if (i + 1 == your)  //친구차례
			{
				if (your_wasSave == 1)
				{
					printf("You was attacked by the Killer,But you survived thanks to the Defense potion!\n");
					gets_s(check);
					getchar();
					your_wasSave = 0;
				}
				printf("Player%d turn(other player looke away..)", your);
				gets_s(check);

				if (strcmp(turnrole[your - 1], "Killer1") == 0 || strcmp(turnrole[your - 1], "Killer2") == 0)   //친구의 역할이 킬러일때
				{
					if (strcmp(turnrole[your - 1], "Killer1") == 0)
					{
						if (Killer2_lasttarget != 0)
						{
							if (Killer2_wasCitizen == 1)
								printf("Killer2 kill Player%d(Player%d: Citizen)", Killer2_lasttarget, Killer2_lasttarget);
							else
								printf("Killer2 tried to kill Player%d(Player%d: Not a Citizen)", Killer2_lasttarget, Killer2_lasttarget);
							gets_s(check);
						}


					}
					else if (strcmp(turnrole[your - 1], "Killer2") == 0)
						if (Killer1_lasttarget != 0)
						{
							if(Killer1_wasCitizen==1)
								printf("Killer1 kill Player%d(Player%d: Citizen)", Killer1_lasttarget, Killer1_lasttarget);
							else
								printf("Killer1 tried to kill Player%d(Player%d: Not a Citizen)", Killer1_lasttarget, Killer1_lasttarget);
							gets_s(check);
						}

				

					printf("Choose a player to kill. Enter the player's number: ");
					scanf_s("%d", &a);
					if (alive[a - 1] == 0)
					{
						printf("Already killed");
						if (strcmp(turnrole[your - 1], "Killer1") == 0)
						{
							Killer1_lasttarget = a;
							if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)
								Killer1_wasCitizen = 1;
							else
								Killer1_wasCitizen = 0;
						}
						else
						{
							Killer2_lasttarget = a;
							if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)
								Killer2_wasCitizen = 1;
							else
								Killer2_wasCitizen = 0;
						}

					
					}
					if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)
					{
						alive[a - 1] = 0;
						if (strcmp(turnrole[your - 1], "Killer1") == 0)
						{
							if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)
							{
								Killer1_wasCitizen = 1;
								Killer1_lasttarget = a;
							}
							else
							{
								Killer1_wasCitizen = 0;
								Killer1_lasttarget = a;
							}
						}
						else
						{
							if (strcmp(turnrole[a - 1], "Citizen1") == 0 || strcmp(turnrole[a - 1], "Citizen2") == 0)
							{
								Killer2_wasCitizen = 1;
								Killer2_lasttarget = a;
							}
							else
							{
								Killer2_wasCitizen = 0;
								Killer2_lasttarget = a;
							}
						}

						if (a == me && my_potion == 1)
						{
							printf("Player%d is Citizen, But Player%d survived thanks to the Defense potion!\n", a, a);
							gets_s(check);
							getchar();
							alive[a - 1] = 1;
							my_potion = 0;
							my_wasSave = 1;
						}
						else
						{
							printf("Player%d is Citizen, You successfully killed the player!", a);
							gets_s(check);
							getchar();
							killreason[a - 1] = 1;
						}
					}
					else   //죽인 사람이 같은 킬러이거나 경찰일때
					{
						printf("Player%d is not Citizen, You kill attempt failed!", a);
						gets_s(check);
						getchar();

						if (strcmp(turnrole[your - 1], "Killer1") == 0)
						{
							Killer1_lasttarget = a;
							Killer1_wasCitizen = 0;
						}
						else
						{
							Killer2_lasttarget = a;
							Killer2_wasCitizen = 0;
						}
						continue;
					}
				}
				
				else if (strcmp(turnrole[your - 1], "Citizen1") == 0 || strcmp(turnrole[your - 1], "Citizen2") == 0)  //친구의 역할이 시민일때
				{
					if (your_gum == 0)
					{
						printf("Remember,You are the police team's helper..\nThis chance could become real help for them.");
						gets_s(check);

						printf("Now Game Start!");
						gets_s(check);
						printf("Game1.Odd or Even\nGame2.Up&Down\nChoose one Game:");
						scanf_s("%d", &game);
						getchar();
						if (game == 1)
						{
							int num = 0, random = 0;
							printf("if you win,you can choose an ability. if you lose,nothing happen\n'Odd or Even' Game start!");
							gets_s(check);
							printf("Wait a minute..\n");
							Sleep(2000);

							random = rand() % 50 + 1;
							printf("A random number has been chosen\nIs it Odd(1) or Even(2)?\n");
							scanf_s("%d", &num);
							if (random % 2 == 0)// 랜덤숫자가 짝수일때
							{
								if (num == 2)
								{
									int abilities = 0;
									abilities = rand() % 20 + 1;
									if (abilities <= 6)
										abilities = 1;
									else if (abilities <= 12)
										abilities = 2;
									else if (abilities <= 18)
										abilities = 3;
									else
										abilities = 4;
									printf("Win!!");
									//능력 선택하기
									gets_s(check);
									printf("You win,You will randomly receive one of the three abilities!\n");
									gets_s(check);
									printf("1.Defense potion(survive even if the killer targets you next turn)\n2.Killer Info(find out the identity of one of the two Killers)\n3.Report to Police(share the Killer's identity with the Police)\n4.Swordsman(Become a swordsman and kill the Killer)");
									gets_s(check);
									printf("Wait a minute..\n");
									Sleep(2000);
									if (abilities == 1)   /// 수비 물약
									{
										printf("You have obtained the Defense potion(survive one time)\n");
										your_potion = 1;
									}
									else if (abilities == 2)  //킬러의 정보를 알아냄
									{

										int random_killer = 0;
										printf("You have obtained the Killer Info ability(if you have 'Report to Police', Report to Police)\n");
										random_killer = rand() % 2 + 1;  //랜덤으로 두명의 킬러중 한명만 알려주기

										if (random_killer == 1)
										{
											printf("Player1 is Killer1");
											your_knownKiller = 1;  //플레이어1이 킬러라는 것을 알아냄
										}
										else
										{
											printf("Player4 is Killer2");
											your_knownKiller = 4;  //플레이어4가 킬러라는 것을 알아냄
										}
									}
									else if (abilities == 3) // 경찰에게 정보를 공유
									{
										printf("You have obtained the ability to Report to Police(if you have 'Killer Info', Report to Police)\n");
										your_share = 1;
									}
									else       //귀살대가 되는 능력
									{
										printf("You have obtained the ability to become a Swordsman and kill the Killer(You are now a Swordsman, not just a Citizen)");
										gets_s(check);
										your_gum = 1;
									}
								}
								else if (num == 1)
								{
									printf("Lose, You couldn't become a help to the Police team");
									gets_s(check);
									getchar();
								}
							}
							else if (random % 2 != 0) // 랜덤숫자가  홀수일때
							{
								int abilities = 0;
								if (num == 2)
								{
									printf("Lose, You couldn't become a help to the Police team");
									gets_s(check);
								}
								else if (num == 1)
								{
									abilities = rand() % 20 + 1;
									if (abilities <= 6)
										abilities = 1;
									else if (abilities <= 12)
										abilities = 2;
									else if (abilities <= 18)
										abilities = 3;
									else
										abilities = 4;
									printf("Win!!");
									//능력 선택하기
									gets_s(check);
									printf("You win,You will randomly receive one of the three abilities!\n");
									gets_s(check);
									printf("1.Defense potion(survive even if the killer targets you next turn)\n2.Killer Info(find out the identity of one of the two Killers)\n3.Report to Police(share the Killer's identity with the Police)\n4.Swordsman(Become a swordsman and kill the Killer)");
									gets_s(check);
									printf("Wait a minute..\n");
									Sleep(2000);
									if (abilities == 1)   /// 수비 물약
									{
										printf("You have obtained the Defense potion\n");
										your_potion = 1;
									}
									else if (abilities == 2)  //킬러의 정보를 알아냄
									{

										int random_killer = 0;
										printf("You have obtained the Killer Info ability\n");
										random_killer = rand() % 2 + 1;  //랜덤으로 두명의 킬러중 한명만 알려주기

										if (random_killer == 1)
										{
											printf("Player1 is Killer1");
											your_knownKiller = 1;  //플레이어1이 킬러라는 것을 알아냄
										}
										else
										{
											printf("Player4 is Killer2");
											your_knownKiller = 4;  //플레이어4가 킬러라는 것을 알아냄
										}
									}
									else if (abilities == 3) // 경찰에게 정보를 공유
									{
										printf("You have obtained the ability to Report to Police\n");
										your_share = 1;
									}
									else       //귀살대가 되는 능력
									{
										printf("You have obtained the ability to become a Swordsman and kill the Killer(You are now a Swordsman, not just a Citizen)");
										gets_s(check);
										your_gum = 1;
									}
								}
							}
						} // if(game==1) 끝나는 문 (여기가 추가된 중괄호 3번째)
						else if (game == 2)
						{
							int Num = 0;
							int TRY = 0;
							int Check = 0;
							printf("if you win,you can choose an ability. if you lose,nothing happen\n'Up&Down' Game start!");
							gets_s(check);
							printf("Wait a minute..\n");
							Sleep(2000);

							Num = rand() % 30 + 1;
							printf("A random numner between 1~30 has been chosen. You have 5 tries to guess it\n");
							gets_s(check);

							for (int i = 0; i < 5; i++)
							{
								printf("Try%d ", i + 1);
								scanf_s("%d", &TRY);
								if (TRY < Num)
								{
									if (i == 4)
									{
										printf("Lose, You couldn't become a help to the Police team");
										gets_s(check);
										getchar();
									}
									else
										printf("Up!\n");
								}
								else if (TRY > Num)
								{
									if (i == 4)
									{
										printf("Lose");
										gets_s(check);
									}
									else
										printf("Down!\n");
								}
								else
								{
									int abilities = 0;
									printf("Win!!\n");
									{
										gets_s(check);
										Check = 1;
										abilities = rand() % 20 + 1;
										if (abilities <= 6)
											abilities = 1;
										else if (abilities <= 12)
											abilities = 2;
										else if (abilities <= 18)
											abilities = 3;
										else
											abilities = 4;
										gets_s(check);
										printf("You win,You will randomly receive one of the three abilities!\n\n");
										gets_s(check);
										printf("1.Defense potion(survive even if the killer targets you next turn)\n2.Killer Info(find out the identity of one of the two Killers)\n3.Report to Police(share the Killer's identity with the Police)\n4.Swordsman(Become a swordsman and kill the Killer)");
										gets_s(check);
										printf("Wait a minute..\n");
										Sleep(2000);
										if (abilities == 1)   /// 수비 물약
										{
											printf("You have obtained the Defense potion(survive one time)\n");
											your_potion = 1;
										}
										else if (abilities == 2)  //킬러의 정보를 알아냄
										{

											int random_killer = 0;
											printf("You have obtained the Killer Info ability(if you have 'Report to Police', Report to Police)\n");
											random_killer = rand() % 2 + 1;  //랜덤으로 두명의 킬러중 한명만 알려주기

											if (random_killer == 1)
											{
												printf("Player1 is Killer1");
												your_knownKiller = 1;  //플레이어1이 킬러라는 것을 알아냄
											}
											else
											{
												printf("Player4 is Killer2");
												your_knownKiller = 4;  //플레이어4가 킬러라는 것을 알아냄
											}
										}
										else if (abilities == 3)// 경찰에게 정보를 공유
										{
											printf("You have obtained the ability to Report to Police(if you have 'Killer Info', Report to Police)\n");
											your_share = 1;
										}
										else       //귀살대가 되는 능력
										{
											printf("You have obtained the ability to become a Swordsman and kill the Killer(You are now a Swordsman, not just a Citizen)");
											gets_s(check);
											your_gum = 1;
										}
									}
									if (Check == 1)
										break;
									if (i == 4)
									{
										printf("Lose, You couldn't become a help to the Police team");
										gets_s(check);
										getchar();

									}
								}
							}// for문 종료
						}
					}
					else if (your_gum != 0)  //귀살대가 되었을 경우
					{
						your_gum++;

						if (your_gum == 2)   //처음 귀살대가 되었을떄만 알려주기
						{
							printf("Now you become a Swordsman, Let's go kill the Killer!!");
							gets_s(check);
						}
						printf("With your blade, Choose the Player's number you wish to slay(But if you kill someone who is not the Killer, you will die..): ");
						scanf_s("%d", &your_gumtarget);
						printf("Wait a minute..\n");
						Sleep(2000);

						if (your_gumtarget == 1 || your_gumtarget == 4)   //만약 킬러를 죽일시
						{
							printf("You have killed the Killer!!\nPlayer%d is dead", your_gumtarget);
							gets_s(check);
							getchar();
							alive[your_gumtarget - 1] = 0;
							your_gumKiller = 1;
							killreason[your_gumtarget - 1] = 3;
						}
						else
						{
							printf("Player%d is not a Killer, So you have died instead", your_gumtarget);
							gets_s(check);
							getchar();
							alive[your - 1] = 0;
							your_gumKiller = 0;
							killreason[your - 1] = 3;
						}

					}
				
				}  //친구 역할이 시민일 떄 반복문 끝나는 문 (여기가 추가된 중괄호 4번째)

				else if (strcmp(turnrole[your - 1], "Police1") == 0 || strcmp(turnrole[your - 1], "Police2") == 0) //내 친구의 역할이 경찰
				{
					if (police_lasttarget != 0)
					{
						if (police_lastaction == 1)
						{
							if (Police_wasKiller == 1)
								printf("Our team investigated Player%d(Player%d: Killer)\n", police_lasttarget, police_lasttarget);
							else
								printf("Our team investigated Player%d(Player%d: Not a Killer)\n", police_lasttarget, police_lasttarget);
						}
						else if (police_lastaction == 2)
						{
							if (Police_wasKiller == 1)
								printf("Our team Arrested Player%d(Player%d: Killer)\n", police_lasttarget, police_lasttarget);
							else
								printf("Our team tried to Arrest Player%d(Player%d: Not a Killer)\n", police_lasttarget, police_lasttarget);
						}
					}	
					if (strcmp(turnrole[your - 1], "Police1") == 0)
					{
						if (my_share == 1 && my_knownKiller != 0)
						{
							printf("Citizen has shared killer info with you: Player%d is a Killer\n", my_knownKiller);
							my_share = 0;
						}
						 if (Citizen1_share == 1 && Citizen1_info != 0)
						{
							printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen1_info);
							Citizen1_info = 0;
							Citizen1_share = 0;
						}
						 if (Citizen2_share == 1 && Citizen2_info != 0)
						{
							printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen2_info);
							Citizen2_info = 0;
							Citizen2_share = 0;
						}
					}
					else if (strcmp(turnrole[your - 1], "Police2") == 0)
					{
						if (my_share == 1 && my_knownKiller != 0)
						{
							printf("Citizen has shared killer info with you: Player%d is a Killer\n", my_knownKiller);
							my_share = 0;
						}	
						 if (Citizen1_share == 1 && Citizen1_info != 0)
						{
							printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen1_info);
							Citizen1_info = 0;
							Citizen1_share = 0;
						}
						 if (Citizen2_share == 1 && Citizen2_info != 0)
						{
							printf("Citizen has shared killer info with you: Player%d is a Killer\n", Citizen2_info);
							Citizen2_info = 0;
							Citizen2_share = 0;
						}
					}
					printf("1.Investigate\n2.Arrest\nChoose one:");
					scanf_s("%d", &police);
					if (police == 1) // 조사를 선택
					{
						printf("Choose a player to investigate. Enter the player's number: ");
						scanf_s("%d", &a);
						police_lasttarget = a;
						police_lastaction = 1;
						if (alive[a - 1] == 0)
						{
							printf("Already killed\n");
						
						}
						if (strcmp(turnrole[a - 1], "Killer1") == 0 || strcmp(turnrole[a - 1], "Killer2") == 0)
						{
							printf("Player%d is Kiler", a);
							gets_s(check);
							getchar();
							Police_wasKiller = 1;
						}
						else
						{
							printf("Player%d is not killer", a);
							gets_s(check);
							getchar();
							Police_wasKiller = 0;
						}
					}
					else if (police == 2) //체포를 선택
					{
						printf("Choose a player to Arrest. Enter the player's number: ");
						scanf_s("%d", &a);
						police_lasttarget = a;
						police_lastaction = 2;
						if (alive[a - 1] == 0)
						{
							printf("Already killed\n");
						
						}
						if (strcmp(turnrole[a - 1], "Killer1") == 0 || strcmp(turnrole[a - 1], "Killer2") == 0)
						{
							printf("Player%d is Killer,Arrest successful!!", a);
							gets_s(check);
							getchar();

							alive[a - 1] = 0;
							killreason[a-1] = 2;   //경찰에게 체포당해 죽음
							Police_wasKiller = 1;
						}
						else  //잘못 체포헀을때
						{
							printf("Player%d is not a Killer..\nWrongful arrest,You are sent to prison for 1 turn!!", a);
							gets_s(check);
							getchar();
							in_prison[your-1] = 1;
							Police_wasKiller = 0;
						}
					}
				} // 내역할이 경찰일떄 반복문 끝나는 문

				for (int i = 0; i < 30; i++)
					printf("\n");
			}  //친구 차례 끝나는 문





			else //플레이어가 컴퓨터일때
			{

				gets_s(check);
				printf("Player%d turn\n", i + 1);
				printf("Wait a minute..\n");
				Sleep(3000);


				if (strcmp(turnrole[i], "Killer1") == 0 || strcmp(turnrole[i], "Killer2") == 0) //만약 컴퓨터가 킬러일떄
				{

					int target = rand() % 6 + 1;
					while (target == i + 1 || alive[target - 1] == 0) //만약 타켓이 자기 자신이거나 죽어있는 사람일 경우 계속해서 아닐떄까지 돌림
						target = rand() % 6 + 1;

					if (strcmp(turnrole[target - 1], "Citizen1") == 0 || strcmp(turnrole[target - 1], "Citizen2") == 0) //만약 타겟이 시민일 경우
					{
						if (strcmp(turnrole[i], "Killer1") == 0)
						{
							Killer1_lasttarget = target;
							Killer1_wasCitizen = 1;
						}
						else
						{
							Killer2_lasttarget = target;
							Killer2_wasCitizen = 1;
						}
						alive[target - 1] = 0;
						killreason[target - 1] = 1;


						if (target == me && my_potion == 1)  //타겟이 나인데 내가 물약을 가지고 있을 경우
						{
							alive[target - 1] = 1;
							my_potion = 0;
							my_wasSave = 1;

						}
						else if (target == your && your_potion == 1)  //타겟이 너인데 너가 물약을 가지고 있을 경우
						{
							alive[target - 1] = 1;
							your_potion = 0;
							your_wasSave = 1;
						}
						else if (strcmp(turnrole[target - 1], "Citizen1") == 0 && Citizen1_potion == 1)  //타겟이 시민인데 시민이 물약을 가지고 있을 경우 
						{
							alive[target - 1] = 1;
							Citizen1_potion = 0;
						}
						else if (strcmp(turnrole[target - 1], "Citizen2") == 0 && Citizen2_potion == 1)   //타겟이 시민인데 시민이 물약을 가지고 있을 경우 
						{
							alive[target - 1] = 1;
							Citizen2_potion = 0;
						}

					}
					else   //죽인 사람이 경찰이거나 같은 킬러일떄
					{
						if (strcmp(turnrole[i], "Killer1") == 0)
						{
							Killer1_lasttarget = target;
							Killer1_wasCitizen = 0;
						}
						else if (strcmp(turnrole[i], "Killer2") == 0)
						{
							Killer2_lasttarget = target;
							Killer2_wasCitizen = 0;
						}
					}


				} //컴퓨터가 킬러일떄 끝나는 문
				else if (strcmp(turnrole[i], "Citizen1") == 0 || strcmp(turnrole[i], "Citizen2") == 0)    //만약 컴퓨터가 시민일 경우
				{
					
					 if (strcmp(turnrole[i], "Citizen1") == 0)  // 컴퓨터가 시민1일 경우
					{
						 if (Citizen1_gum != 0)  //시민1이 귀살대가 되었을 떄
						 {
							 Citizen1_gum++;
							 Citizen1_gumtarget = rand() % 6 + 1;
							 if (Citizen1_gumtarget == 1 || Citizen1_gumtarget == 4)  //만약 킬러를 죽였을 경우
							 {
								 alive[Citizen1_gumtarget - 1] = 0;
								 killreason[Citizen1_gumtarget - 1] = 3;
								 Citizen1_gumKiller = 1;
							 }
							 else   //킬러가 아닌 사람을 잘못 죽였을 경우
							 {
								 alive[i] = 0;
								 killreason[i] = 3;
								 Citizen1_gumKiller = 0;

							 }
							 
						 }
						 else if(Citizen1_gum==0)  //귀살대가 아닌 경우
						 {
							 int result = rand() % 2 + 1; // 시민게임에서 이기면 1, 지면 0

							 if (result == 1) // 시민게임에서 이겼다면
							 {
								 int abilities = rand() % 20 + 1;
								 if (abilities <= 6)
									 abilities = 1;
								 else if (abilities <= 12)
									 abilities = 2;
								 else if (abilities <= 18)
									 abilities = 3;
								 else
									 abilities = 4;

								 if (strcmp(turnrole[i], "Citizen1") == 0)
								 {
									 if (abilities == 1) //물약 획득
										 Citizen1_potion = 1;
									 else if (abilities == 2) //킬러가 누군지 알아냄
									 {
										 Citizen1_info = rand() % 2 + 1;
										 if (Citizen1_info == 1)
											 Citizen1_info = 1;
										 else if (Citizen1_info == 2)
											 Citizen1_info = 4;
									 }
									 else if (abilities == 3)//경찰에게 킬러 정보를 공유
										 Citizen1_share = 1;

									 else       //귀살대가 되는 능력
									 {
										 Citizen1_gum = 1;
									 }
								 }

							 }
						 }
					}
					else if (strcmp(turnrole[i], "Citizen2") == 0)  //컴퓨터가 시민2일 경우
					{
						 if (Citizen2_gum != 0)  //시민2가 귀살대가 되었을 떄
						 {
							 Citizen2_gum++;
							 Citizen2_gumtarget = rand() % 6 + 1;
							 if (Citizen2_gumtarget == 1 || Citizen2_gumtarget == 4)  //만약 킬러를 죽였을 경우
							 {
								 alive[Citizen2_gumtarget - 1] = 0;
								 killreason[Citizen2_gumtarget - 1] = 3;
								 Citizen2_gumKiller = 1;
							 }
							 else   //킬러가 아닌 사람을 잘못 죽였을 경우
							 {
								 alive[i] = 0;
								 killreason[i] = 3;
								 Citizen2_gumKiller = 0;

							 }

						 }
						 else if (Citizen2_gum == 0)
						 {
							 int result = rand() % 2 + 1; // 시민게임에서 이기면 1, 지면 0

							 if (result == 1) // 시민게임에서 이겼다면
							 {
								 int abilities = rand() % 20 + 1;
								 if (abilities <= 6)
									 abilities = 1;
								 else if (abilities <= 12)
									 abilities = 2;
								 else if (abilities <= 18)
									 abilities = 3;
								 else
									 abilities = 4;

								 if (abilities == 1)
									 Citizen2_potion = 1;
								 else if (abilities == 2) //킬러가 누군지 알아냄
								 {
									 Citizen2_info = rand() % 2 + 1;
									 if (Citizen2_info == 1)
										 Citizen2_info = 1;
									 else
										 Citizen2_info = 4;
								 }
								 else if (abilities == 3)
									 Citizen2_share = 1;
								 else       //귀살대가 되는 능력						
									 Citizen2_gum = 1;
							 }
						 }
					}  //컴퓨터가 시민2일경우 끝나는 문
	
				} //컴퓨터가 시민일경우 끝나는 문

						else if (strcmp(turnrole[i], "Police1") == 0 || strcmp(turnrole[i], "Police2") == 0)    //만약 컴퓨터가 경찰일 경우
				{
					int police_target = 0;  //컴퓨터 경찰이 조사나 체포 대상 
					int police_infoed = 0; //컴퓨터 경찰이 시민에게 공유받은 킬러 플레이어 정보

					if (my_share == 1 && my_knownKiller != 0)   //me 에게서 킬러에 대한 정보를 공유 받았는가
					{
						police_target = my_knownKiller;
						police_infoed = 1;

					}
					else if (your_share == 1 && your_knownKiller != 0)   //your 에게서 킬러에 대한 정보를 공유 받았는가
					{
						police_target = your_knownKiller;
						police_infoed = 1;

					}
					else if (Citizen1_share == 1 && Citizen1_info != 0)  //시민1에게서 킬러에 대한 정보를 공유 받았는가
					{
						police_target = Citizen1_info;
						police_infoed = 1;
					}
					else if (Citizen2_share== 1 && Citizen2_info != 0)  //시민2에게서 킬러에 대한 정보를 공유 받았는가
					{
						police_target = Citizen2_info;
						police_infoed = 1;
					}

					if (police_infoed == 1) //공유받은 킬러에 대한 정보를 알고 있다면 바로 체포
					{
						alive[police_target - 1] = 0; //바로 체포
						killreason[police_target - 1] = 2;

						police_lasttarget = police_target;
						police_lastaction = 2;
						Police_wasKiller = 1;

						if (police_target == my_knownKiller)   //내가 알아낸 킬러를 체포
							my_share = 0;
						else if (police_target == your_knownKiller)  //너가 알아낸 킬러를 체포
							your_share = 0;
						else if (police_target == Citizen1_info)   //시민1이 알아낸 킬러를 체포
							Citizen1_share = 0;
						else if (police_target == Citizen2_info)    //시민2가 알아낸 킬러를 체포
							Citizen2_share = 0;
						
					}
					else if (police_lasttarget != 0 && Police_wasKiller == 1 &&alive[police_lasttarget-1]==1)   // 경찰이 조사한 사람이 킬러일 경우
					{
						alive[police_lasttarget - 1] = 0;
						killreason[police_lasttarget - 1] = 2;
						police_lastaction = 2;
						Police_wasKiller = 1;
						

					}

					else   // 공유받은 정보가 없어 컴퓨터 경찰이 조사해야할 상황
					{
						if (police_lasttarget != 0 && alive[police_lasttarget - 1] == 0)
						{
							police_lasttarget = 0; 
							police_lastaction = 0;
							Police_wasKiller = 0;
						}
						police_target = rand() % 6 + 1;
						while (police_target == i + 1 || alive[police_target - 1] == 0) //만약 경찰의 타켓이 자기 자신이거나 죽어있는 사람일 경우 계속해서 아닐떄까지 돌림
							police_target = rand() % 6 + 1;
							
						police_lasttarget = police_target;
						police_lastaction = 1;

						if (strcmp(turnrole[police_target - 1], "Killer1") == 0 || strcmp(turnrole[police_target - 1], "Killer2") == 0)
							Police_wasKiller = 1;

						else   //킬러가 아닌 사람을 잘못 체포했을떄				
							Police_wasKiller = 0;
		
					}



					
				} //컴퓨터가 경찰일 경우 끝나는 문

				printf("Enter to continue..");
				gets_s(check);	
			
			}
		
			if (i == 5)
			{
				for (int v = 0; v < 30; v++)
					printf("\n");
				printf("Morning has come!!");
				gets_s(check);
			}
		}  //for문 종료(6명의 플레이어가 모두 순서를 마침)

		A++; // 시민게임에 사용하는

		if (alive[0] == 0 && alive[3] == 0)  /// killer가 모두 죽은 경우
		{
			printf("\nAll Killer Arrest! Citizen&Police team Win!!!\n");
			break;
		}
		else if (alive[1] == 0 && alive[4] == 0)  // 시민이 모두 죽은 경우
		{
			printf("\nAll Citizen Killed! Killer team WIn!!!\n");
			break;
		}


	} // while문 종료 

}








		