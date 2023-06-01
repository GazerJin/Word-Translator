/***************************************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself.The 
program was run, tested and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
															BAUTISTA, SAMANTHA MICHAELA ORIGEN, 12111087
***************************************************************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>



int Main_Menu(int);
int Manage_Data_Menu(int);


struct Gets_Translations 
{
	char Read_Gets_Language[20];
	char Read_Gets_Translation[20];
	char pair[50];
};

struct Pair
{
	struct Gets_Translations Translations[10];
	int num_trans;
	
}Structure[150];

struct File_Read 
{
	char Read_File_Line[50];
	
	
}RFile[150];


struct sentece 
{
	char Word[20];
	char Translated_Word[20];
	int Found_Translation;
	
}Word[150];

struct Translated
{
	char Trans_Language[20];
	char Trans_Word[20];
	 
};

struct Translation
{
	int Entry;
	int Number_Translation; 
	int Number_For_Translation; 

	char Language[20]; 
	char Word[20]; 
	struct Translated translate[10]; 
	int Sorted; 
	 
} entry [150];


/*
	This Function splits the sentence that the User has input word by word ,
	it also get rids of the ","  "."  "?" "!".
	
	@param (int) i is use for looping 
	@param (int) j is the row to the 2d array
	@param (int) k is the column to the 2d array
	@param (int) f is use for looping 
	@param (char) p is to store the string character by character
	
*/
void Tokenization(char Input_Sentence[150], int *num_words) 
{
	int i; //for looping

	int j = 0; 
	int k = 0;
	char p[20][20];
	int f;
	

	
	for(i = 0; i <= strlen(Input_Sentence); i++)
	{
		if (Input_Sentence[i] == ' ' || Input_Sentence[i] == '\0')
		{
			p[j][k] = '\0';
			
			j++;
			
			k = 0;
		}
		else if (Input_Sentence[i] == '\n')
		{
			//do nothing
		}
		else
		{
			p[j][k] = Input_Sentence[i];
			
			k++;
		}
	}
	
	for(i = 0; i < j; i++)
	{
		strcpy(Word[i].Word,p[i]);
	}
	
	for(f = 0; f < j; f++)
	{
		for(i = 0; i <strlen(Word[f].Word); i++)
		{
			if (Word[f].Word[i] == '.' || Word[f].Word[i] == '?' || Word[f].Word[i] == ','|| Word[f].Word[i] == '!')
			{
				Word[f].Word[i] = '\0';
			}
		}
	}
	
	*num_words = j;
	
	

}

/*
	This Function tokenize word by word the string read in the text file line by line
	and copies/puts the Language and translation to struct Gets_Translations.
	
	@param (int) i is use for looping 
	@param (int) j is the row to the 2d array
	@param (int) k is the column to the 2d array
	@param (int) f is use for looping 
	@param (char) p is to store the string character by character
	@param (int) line is indication on what line is being read 
	@param (int) num_trans is the indication what is the number of translation 
	@param (int) num_pair is the indication what is the number of pair
	
*/
void token(int line, int num_trans, int num_pair)
{
	int i; 
	int j = 0; 
	int k = 0;
	char p[20][20];
	int f;
	
	
	for(i = 0; i <= strlen(RFile[line].Read_File_Line); i++)
	{
		if (RFile[line].Read_File_Line[i] == ':')
		{
			p[j][k] = '\0';
			
			j++;
			
			k = 0;
		}
		else if (RFile[line].Read_File_Line[i] == ' ' || RFile[line].Read_File_Line[i] == '\n' )
		{
			//do nothing
		}
		else
		{
			p[j][k] = RFile[line].Read_File_Line[i];
			
			k++;
		}
	}

	strcpy(Structure[num_pair].Translations[num_trans].Read_Gets_Language, p[0]);
	strcpy(Structure[num_pair].Translations[num_trans].Read_Gets_Translation, p[1]);

}
/*
	This Function sorts the entries alphabetically (according to their ASCII values)
	
	@param (int) i is use for looping 
	@param (int) j is use for looping 
	@param (int) k is use for looping 
	@param (int) temp_num_Entry is use for temporarily put the number of entry
	@param (int) temp_num_Trans is use for temporarily put the number of translation
	@param (int) temp_num_FTrans is use for temporarily put the number for translation
	@param (int) temp_num_sort is use for temporarily put the number of sort
	@param (char) temp[20] is use for temporarily put entry language
	@param (char) temp2[20] is use for temporarily put entry word
	@param (char) temp_trans_Lang[20] is use for temporarily put the translation laguages
	@param (char) temp_trans_Word[20] is use for temporarily put translation words
	
*/

void Entry_Sorting(int *Entry_NImport)
{
	int i, j, k;
	int temp_num_Entry, temp_num_Trans;
	int temp_num_FTrans, temp_num_sort;
	char temp[20];
	char temp2[20];
	char temp_trans_Lang[20];
	char temp_trans_Word[20];
	
	for (i = 0; i < *Entry_NImport - 1; i++ )
	{
		for (j = i + 1; j < *Entry_NImport ; j++)
		{
			
			if( strcmp(entry[i].Language, entry[j].Language) > 0) 
			{
				//switch language and word
				strcpy(temp, entry[i].Language);
				strcpy(temp2, entry[i].Word);
				
				strcpy(entry[i].Language, entry[j].Language);
				strcpy(entry[i].Word, entry[j].Word);
				
				strcpy(entry[j].Language, temp);
				strcpy(entry[j].Word, temp2);
				
				// switch trans language and word
				for (k = 0; k < 10; k++)
				{
				
					strcpy(temp_trans_Lang, entry[i].translate[k].Trans_Language);
					strcpy(temp_trans_Word, entry[i].translate[k].Trans_Word);
					
					strcpy(entry[i].translate[k].Trans_Language, entry[j].translate[k].Trans_Language);
					strcpy(entry[i].translate[k].Trans_Word, entry[j].translate[k].Trans_Word);
					
					strcpy(entry[j].translate[k].Trans_Language, temp_trans_Lang);
					strcpy(entry[j].translate[k].Trans_Word, temp_trans_Word);
				}
				
				
				
				//Number_Translation
				temp_num_Trans = entry[i].Number_Translation;
				entry[i].Number_Translation = entry[j].Number_Translation;
				entry[j].Number_Translation = temp_num_Trans;
				
				//Number_For_Translation
				temp_num_FTrans = entry[i].Number_For_Translation;
				entry[i].Number_For_Translation = entry[j].Number_For_Translation;
				entry[j].Number_For_Translation = temp_num_FTrans;
				
				//sorted
				temp_num_sort = entry[i].Sorted;
				entry[i].Sorted = entry[j].Sorted;
				entry[j].Sorted = temp_num_sort;
				
			}	
		}
	}
	
}

/*
	This Function sorts the translations alphabetically (according to their ASCII values)
	
	@param (int) i is use for looping 
	@param (int) j is use for looping 
	@param (int) g is use to temporarily put the number of translation in every entry
	@param (char) temp[20] is use for temporarily put entry language
	@param (char) temp2[20] is use for temporarily put entry word
	
	
*/
void String_Sorting(int *num) // translation sorting
{
	int i, j;
	char temp[20]; 
	char temp2[20];
	int g;
	
	
	g = entry[*num].Number_Translation;

	for(i = 0; i < (g  - 1); i++)
	{
		for (j= i+1; j < g ; j++)
		{
			if(strcmp(entry[*num].translate[i].Trans_Language, entry[*num].translate[j].Trans_Language) > 0)
			{
				strcpy(temp, entry[*num].translate[i].Trans_Language );
				strcpy(temp2, entry[*num].translate[i].Trans_Word );
				
				strcpy(entry[*num].translate[i].Trans_Language, entry[*num].translate[j].Trans_Language );
				strcpy(entry[*num].translate[i].Trans_Word, entry[*num].translate[j].Trans_Word );
				
				strcpy(entry[*num].translate[j].Trans_Language, temp );
				strcpy(entry[*num].translate[j].Trans_Word, temp2 );
			}
		}
	}	
} 

/*
	This Function put entries to the program, if user input has the same entry within the program
	the function will display all same entry as user input.
	
	@param (int) choiceAE is the choice for the user to input the new entry or not
	@param (int) choiceQ is the choice for the user to input the another pair or not
	@param (int) k is use for looping
	@param (int) SLength is use indicating the length of the entry language
	@param (int) WFound is use for indicating if program has seen the same entry 
	@param (char) UInput_Language stores the language user has input
	@param (char) UInput_Word stores the word user has input
	
	
*/

void Add_Entry(int *Entry_NImport)
{
	
	int choiceAE;
	int choiceQ;
	int k;
	
	int SLength;
	int WFound = 0;
	char UInput_Language[20];
	char UInput_Word[20];
	
	

	

			printf("\n");
			printf("Enter the Language and Word Pair\n");
			printf("Enter Language: ");
			scanf("%s", &UInput_Language);
			printf("Enter Word: ");
			scanf("%s", &UInput_Word);
			
	
		printf("\t\t\t\t Wait for a few Seconds");
		system("cls");
		
		printf("\n");
		printf("============== All Entries ==============\n");
		printf("Language \t\t Translation\n\n");
		
		if (*Entry_NImport == 0)
		{
			printf("\n");
			printf("*There is no Entry with the given word*\n\n\n\n");
			printf("--------------------------------------------\n\n");
		}
		else if (*Entry_NImport >= 1)
		{
			//checking if there is an existing entry
			for (k = 0; k < *Entry_NImport; k++)
			{
				SLength = strlen(entry[k].Language);
				
				
				
				if((strcmp(entry[k].Word, UInput_Word)) == 0)
				{
					WFound = 1;
					
					if (SLength < 7)
						{
							printf("%s \t\t\t %s \n", entry[k].Language, entry[k].Word);
								
						}
					else if (SLength >= 7)
						{
							printf("%s \t\t %s \n", entry[k].Language, entry[k].Word);
						}
					
					printf("--------------------------------------------\n");
					
				}
				
			}
			
			
			
			if (WFound == 0)
			{
				printf("\n");
				printf("*There is no Entry with the given word*\n\n\n\n");
				printf("--------------------------------------------\n\n");
			}
			
		} 	
			//asking the user if this is a new entry
			printf("\n");
			printf("Is this a new entry?\n");
			printf("[1] YES\n");
			printf("[2] NO\n");
			printf("Enter Number: ");
			scanf("%d", &choiceAE);
		
				
			
		if(choiceAE == 1)
			{
				
				printf("\t\t\t\t Wait for a few Seconds\n");
				system("cls");
				do
				{
				
					printf("\n");
					printf("=====Enter Language and Word=====\n");
					printf("Enter Language: ");
					scanf("%s", entry[*Entry_NImport].Language);
					printf("Enter Word: ");
					scanf("%s", entry[*Entry_NImport].Word);
					
					entry[*Entry_NImport].Entry = *Entry_NImport + 1; // updating number of entry; entry[k].Entry
				
					strcpy(entry[*Entry_NImport].translate[0].Trans_Language,entry[*Entry_NImport].Language);
					strcpy(entry[*Entry_NImport].translate[0].Trans_Word,entry[*Entry_NImport].Word);
					
					entry[*Entry_NImport].Number_For_Translation = 1;
					entry[*Entry_NImport].Number_Translation = 1;
					
					
					
					printf("\n\n");
					printf("Do you want to enter another pair?\n");
					printf("[1] YES\n");
					printf("[2] NO\n");
					printf("Enter Number: ");
					scanf("%d", &choiceQ);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
					*Entry_NImport = *Entry_NImport + 1;
					
				}while (choiceQ != 2);
		
			}
			
		else if (choiceAE == 2)
			{
				printf("\n\n=====press any key to go back to Manage Data Menu=====");
			
				getch();
				printf("\t\t\t\t Wait for a few Seconds");
				system("cls");
			}	
	
		
	
}

/*
	This Function put translation to the desired entry, function will display all same entries as user input
	translation that has 
	
	@param (char) UInput_Language stores the language user has input
	@param (char) UInput_Language stores the word user has input
	@param (int) k is use for looping
	@param (int) l is for storing the number of translaion
	@param (int) t for storing the number for translaion
	@param (int) WFound indicates if program has seen a same entry
	@param (int) Found indicates how many you have found with the same entry
	@param (int) g is user input for entry number
	@param (int) SLength is use indicating the length of the entry language
	@param (int) Num_FEntry indicates number with the same entry
	@param (int) choiceAT is the choice for the user to input new translation to the same entry
*/
void Add_Translations(int *Entry_Import)
{
	char UI_Language[20]; 
	char UI_Word[20]; 
	
	
	int k; 
	int l; 
	int t; 
	
	int g; // user input for entry number
	int WFound = 0;
	int Found = 0;
	int SLength; //string length of Language
	
	int Num_FEntry; // number of entry found
	int choiceAT; //choice for additional translation 
	
		printf("Enter the Language and Word Pair\n");
		printf("Enter Language: ");
		scanf("%s", &UI_Language);
		printf("Enter Translation: ");
		scanf("%s", &UI_Word);
	
	

	do
	{	
	
			printf("\t\t\t\t Wait for a few Seconds");
			system("cls");
			
			printf("\n");
			printf("============== All Entries ==============\n");
			printf("Language \t\t Translation\n\n");
			
			if (*Entry_Import != 0)
			{
				for (k = 0; k < *Entry_Import; k++)
				{
					SLength = strlen(entry[k].Language);
					
					
					
					if(((strcmp(entry[k].Word, UI_Word)) == 0) && ((strcmp(entry[k].Language, UI_Language)) == 0))
					{
						WFound = 1;
						
						if (SLength < 7)
							{
								printf("%s \t\t\t %s \n", entry[k].Language, entry[k].Word);
									
							}
						else if (SLength >= 7)
							{
								printf("%s \t\t %s \n", entry[k].Language, entry[k].Word);
							}
						
					
						
						printf("\n");
						printf("Entry %d\n", entry[k].Entry);
						printf("--------------------------------------------\n");
						Found = 1;
						Num_FEntry++;
					
					}
					
				}
			
				if (WFound == 1)
				{	
					do 
					{
						if ( l == 0)
						{
							
							printf("Enter the Number Entry: ");
							scanf("%d", &g);
							t = entry[g-1].Number_For_Translation;
						//	t = 0;
							
						}
						
						if (entry[g-1].Number_For_Translation != 10)
						{
							
						
							t = entry[g-1].Number_For_Translation;
							
							printf("\n");
							printf("Enter Language: ");
							scanf("%s", entry[g-1].translate[t].Trans_Language);
							printf("Enter Word: ");
							scanf("%s", entry[g-1].translate[t].Trans_Word);
							WFound = 0;
				
							
							if (entry[g-1].Number_Translation >= 1)
							{
								l = entry[g-1].Number_Translation;
								entry[g-1].Number_Translation = l + 1;
							}
							else //if (entry[g-1].Number_Translation == NULL)
							{
								l = 1;
								entry[g-1].Number_Translation = l;
							}
							
							t++;
							
							entry[g-1].Number_For_Translation = t;
								
								do 
								{
									printf("\n\n");
									printf("Do you want to enter another translation to the same entry?\n");
									printf("[1] YES\n");
									printf("[2] NO\n");
									printf("Enter Number: ");
									scanf("%d", &choiceAT);
									printf("\t\t\t\t Wait for a few Seconds");
									system("cls");
									
									if ((choiceAT < 1) || (choiceAT > 2))
										{
											printf("Please pick on the given numbers\n");
										}
										
										
								} while((choiceAT < 1) || (choiceAT > 2) );
							
							if ((choiceAT == 1) && (entry[g-1].Number_For_Translation == 10))
							{
								printf("\n===============================================================\n");
								printf("Message: You have exceeded the number of Translation (10)\n");
								printf("===============================================================\n");
							}
							
						}
						
						else if (entry[g-1].Number_For_Translation >= 10)
						{
							printf("\n===============================================================\n");
							printf("Message: You have exceeded the number of Translation (10)\n");
							printf("===============================================================\n");
						}
				
					} while ((choiceAT != 2) && (entry[g-1].Number_For_Translation != 10)) ;
				}	
					WFound = 0;
				
			}
			else if (*Entry_Import == 0)
			{
				printf("\n");
				printf("*There is no Existing Entry with the given Language and Word*\n\n\n\n");
				printf("--------------------------------------------\n\n\n");
				
				printf("Message: Use \"Add Entry\" option in the Manage Data Menu\n");
		
				
				WFound = 0;
			}
		
	} while (WFound != 0);
	
	if  (Found == 0)
	{
		printf("\n");
		printf("*There is no Existing Entry with the given Language and Word*\n\n\n\n");
		printf("--------------------------------------------\n\n\n");
		
		printf("Message: Use \"Add Entry\" option in the Manage Data Menu\n");
	}
	
	if (WFound == 0)
		{
	
			printf("\n\n=====press any key to go back to Manage Data Menu=====");
			getch();
			printf("\t\t\t\t Wait for a few Seconds");
			system("cls");
		}	
		
}

/*
	This Function deletes an entry that the user wants 
	
	@param (int) SLength1 indicates length of entry language
	@param (int) SLength_Trans1 indicates length of the tranlation language
	@param (int) i is indicate the number of page
	@param (int) k is use for looping
	@param (int) j is use for looping
	@param (int) l is use for looping
	@param (int) g is to store number of entry
	@param (int) p is use to store number of *Entry_NImport
	@param (int) choice is ask what the user wants to do (go next, previous,exit)
	@param (int) choice2 is the choice if the user wants to keep looking or not
	@param (int) pos is number of entry to delete
	@param (int) ok indicates if it goes throught the loop
	
*/
void Delete_Entry(int *Entry_NImport)
{
	int SLength1, SLength_Trans1;
	int i = 0;
	int j,k, l;
	int g; 
	int p;
	int point; 
	int choice, choice2;
	int pos = 1; 
	int ok = 0;
	
	do
		{
			if (i >= 0 )
			{
				
			printf("\n");
			printf("=========================================\n");	
			printf("Language \t\tTranslation\n");
			printf("=========================================\n\n");
					
				point = i;
		
				p = *Entry_NImport;
				Entry_Sorting(&p);
				String_Sorting(&point);
				entry[i].Sorted = 1;
				
				SLength1 = strlen(entry[i].Language);
						
						if (entry[i].Number_For_Translation >= 1)
						{
							for (k = 0; k < entry[i].Number_For_Translation; k++)
							{
								SLength_Trans1 = strlen(entry[i].translate[k].Trans_Language);
								if (SLength_Trans1 < 7 )
								{
									printf("%s \t\t\t %s \n", entry[i].translate[k].Trans_Language, entry[i].translate[k].Trans_Word);
								}
								else  if (SLength_Trans1 >= 7 ) 
								{
									printf("%s \t\t %s \n", entry[i].translate[k].Trans_Language, entry[i].translate[k].Trans_Word);
								}
							}
							
						}
						else if (entry[i].Number_For_Translation == 0)
						{
							if (SLength1 < 7 )
							{
								printf("%s \t\t\t %s \n", entry[i].Language, entry[i].Word);
									
							}
							else if (SLength1 >= 7 ) 
							{
								printf("%s \t\t %s \n", entry[i].Language, entry[i].Word);
								
							}
							
						}
						
						printf("\n");
						g = i + 1;
						printf("Entry %d\n", g);	
					
						if (entry[i].Number_For_Translation >= 1)
						{
							printf("Entered Entry:\n");	
							printf("%s \t %s\n", entry[i].Language, entry[i].Word);
						}
				
				printf("--------------------------------------------\n");
			
				do 
				{
					printf("What to do?\n");
					printf("[1] Go to Next\n");
					printf("[2] Go to Previous\n");
					printf("[3] Delete Entry\n");
					printf("[4] Exit\n");
					printf("Enter Number: ");
					scanf("%d", &choice);
					printf("--------------------------------------------\n");
					
					
					if ((choice < 1) || (choice > 4))
					{
						printf("Message: Please pick on the given numbers\n\n");
					}
					
				}while((choice < 1) || (choice > 4));
				
				printf("\t\t\t\t Wait for a few Seconds");
				system("cls");
				
					if (choice == 1)
					{
						i++;
						
					}
					else if (choice == 2)
					{
						i--;
					}
					else if (choice == 3)
					{
						
						printf("\n\n");
						printf("===========================================\n");
						printf("Warning: The maximum entry is %d\n\n", *Entry_NImport);
						printf("Enter the number of entry to delete: ");
						scanf("%d", &pos);
							
						for (l = pos - 1; l < *Entry_NImport; l++)
							{
								entry[l].Entry = entry[l +1].Entry - 1;
								entry[l].Number_For_Translation = entry[l + 1].Number_For_Translation;
								entry[l].Number_Translation = entry[l + 1].Number_Translation;
								entry[l].Sorted = entry[l + 1].Sorted;
								
								strcpy(entry[l].Language, entry[l + 1].Language);
								strcpy(entry[l].Word, entry[l + 1].Word);
								
								for(j = 0; j < 10; j++)
								{
									strcpy(entry[l].translate[j].Trans_Language, entry[l + 1].translate[j].Trans_Language);
									strcpy(entry[l].translate[j].Trans_Word, entry[l + 1].translate[j].Trans_Word);
								}
							}
							
							*Entry_NImport = *Entry_NImport - 1;
							ok = 1;	
					}
				
				printf("\n");
				
				if (i > *Entry_NImport)
				{
					printf("=======================================\n\n");
					printf("Message: There is no next entry\n\n");
					printf("=======================================\n\n");
				
					do 
					{
						printf("Do you want to continue looking?\n");
						printf("[1] YES\n");
						printf("[2] NO\n");  
						printf("Enter Number: ");
						scanf("%d", &choice2);
						printf("--------------------------------------------\n");
						
						
						if ((choice2 < 1) || (choice2 > 2))
						{
							printf("Message: Please pick on the given numbers\n\n");
						}
						
						
					}while((choice2 < 1) || (choice2 > 2));
					
					if (choice2 == 1)
					{
						i--;
						printf("\t\t\t\t Wait for a few Seconds");
						system("cls");	
					}
					
				}
				else if (i < 0) 
				{
					printf("=======================================\n\n");
					printf("Message: There is no previous entry\n\n");
					printf("=======================================\n\n");
					
					do 
					{
						printf("Do you want to continue looking?\n");
						printf("[1] YES\n");
						printf("[2] NO\n");  
						printf("Enter Number: ");
						scanf("%d", &choice2);
						printf("--------------------------------------------\n");
						
						
						if ((choice2 < 1) || (choice2 > 2))
						{
							printf("Message: Please pick on the given numbers\n\n");
						}
						
						
					}while((choice2 < 1) || (choice2 > 2));
					
					if (choice2 == 1)
					{
						i++;
						printf("\t\t\t\t Wait for a few Seconds");
						system("cls");	
					}
				}
			}
			 		
		}
		while( (choice != 4 && choice2 != 2) && (pos > 0 && pos < *Entry_NImport) && (ok != 1) ); 

			
	if((pos <= 0) || (pos > *Entry_NImport))
		{
			printf("\n\n");
			printf("===============================================\n\n");
			printf("Message: You have entered an invalid number.\n\n");
			printf("===============================================\n\n");
		}
		
	printf("=====press any key to go back to Manage Data Menu=====");	
	getch();	
		
}

/*
	This Function a translation within  an entry, if all translation has been deleted then all entry is deleted 
	
	@param (int) SLength1 indicates length of entry language
	@param (int) SLength_Trans1 indicates length of the tranlation language
	@param (int) i is indicate the number of page
	@param (int) k is use for looping
	@param (int) j is use for looping
	@param (int) l is use for looping
	@param (int) g is to store number of entry
	@param (int) point indicates if it has been sorted
	@param (int) choice is ask what the user wants to do (go next, previous,exit)
	@param (int) choice2 is the choice if the user wants to keep looking or not
	@param (int) entry_num is entry number
	@param (int) num use for mapping
	@param (int) pos_trans is the position of translation
	@param (int) Nok_entry indicates if the user has inputed a valid entry number
	@param (int) Nok_trans indicates if the user has inputed a valid translation number
	@param (int) choiceTP is the choice to proceed
	@param (int) choiceTP_exit is the choice to continue looking
	
	
*/

void Delete_Translation(int *Entry_NImport)
{
	int SLength1, SLength_Trans1;
	int i = 0;
	int j,k, l; 
	int g; 
	int p;
	int point; // pointer to sort
	int choice, choice2;
		
	int ok = 0;
	int entry_num; // entry number
	int num; // for mapping
	int pos_trans; // position of trans
	int Nok_entry;
	int Nok_trans;
	int choiceTP; 
	int choiceTP_exit; 

	
	do
	{
		if (i >= 0 )
		{
			
		printf("\n");
		printf("===================================================\n");	
		printf("No. \tLanguage \t\tTranslation\n");
		printf("===================================================\n");
			
	
			point = i;
	
				p = *Entry_NImport;
				Entry_Sorting(&p);
				String_Sorting(&point);
				entry[i].Sorted = 1;

			SLength1 = strlen(entry[i].Language);
					
					if (entry[i].Number_For_Translation >= 1)
					{
						for (k = 0; k < entry[i].Number_For_Translation ; k++)
						{
							SLength_Trans1 = strlen(entry[i].translate[k].Trans_Language);
							if (SLength_Trans1 < 7 )
							{
								printf("%d \t%s \t\t\t %s \n", k + 1, entry[i].translate[k].Trans_Language, entry[i].translate[k].Trans_Word);
							}
							else  if (SLength_Trans1 >= 7 ) 
							{
								printf("%d \t%s \t\t %s \n", k + 1, entry[i].translate[k].Trans_Language, entry[i].translate[k].Trans_Word);
							}
						}
						
					}
					else if (entry[i].Number_For_Translation == 0)
					{
						if (SLength1 < 7 )
						{
							printf("%d \t%s \t\t\t %s \n", k + 1, entry[i].Language, entry[i].Word);
								
						}
						else if (SLength1 >= 7 ) 
						{
							printf("%d \t%s \t\t %s \n", k + 1, entry[i].Language, entry[i].Word);
							
						}
						
					}
					
					printf("\n");
					g = i + 1;
					printf("Entry %d\n", g);	
				
					if (entry[i].Number_For_Translation >= 1)
					{
						printf("Entered Entry:\n");	
						printf("%s \t %s\n", entry[i].Language, entry[i].Word);
					}
			
			printf("--------------------------------------------\n");
		
			do 
			{
				printf("What to do?\n");
				printf("[1] Go to Next\n");
				printf("[2] Go to Previous\n");
				printf("[3] Delete Translation\n");
				printf("[4] Exit\n");
				printf("Enter Number: ");
				scanf("%d", &choice);
				printf("--------------------------------------------\n");
				
				
				if ((choice < 1) || (choice > 4))
				{
					printf("Message: Please pick on the given numbers\n\n");
				}
				
			}while((choice < 1) || (choice > 4));
			
			printf("\t\t\t\t Wait for a few Seconds");
			system("cls");
			
				if (choice == 1)
				{
					i++;
					
				}
				else if (choice == 2)
				{
					i--;
				}
				else if (choice == 3)
				{
					
					printf("\n\n");
					printf("===========================================\n");
					printf("Warning: The maximum entry is %d\n\n", *Entry_NImport);
					printf("Enter the Number of Entry of Translation: ");
					scanf("%d", &entry_num);
					
					if (entry_num <= 0 || entry_num > *Entry_NImport)
					{
						Nok_entry = 1;
					}
					
					if (Nok_entry == 0)
					{
						
							
						printf("\t\t\t\t Wait for a few Seconds");
						system("cls");
						
						printf("\n");
						
						num = entry_num - 1;
						
						
						
						do
						{
						
							if(entry[num].Number_For_Translation >= 1)
							{
								printf("\n");
								printf("===================================================\n");	
								printf("No. \tLanguage \t\tTranslation\n");
								printf("===================================================\n");
								
								for (k = 0; k < entry[num].Number_For_Translation; k++)
								{
									SLength_Trans1 = strlen(entry[num].translate[k].Trans_Language);
									
									if (SLength_Trans1 < 7 )
									{
										printf("%d \t%s \t\t\t %s \n", k + 1, entry[num].translate[k].Trans_Language, entry[num].translate[k].Trans_Word);
									}
									else  if (SLength_Trans1 >= 7 ) 
									{
										printf("%d \t%s \t\t %s \n", k + 1, entry[num].translate[k].Trans_Language, entry[num].translate[k].Trans_Word);
									}
								}
							}
							else if (entry[num].Number_For_Translation == 0)
							{
								printf("\n");
								printf("===================================================\n");	
								printf("No. \tLanguage \t\tTranslation\n");
								printf("===================================================\n");
								
								k = 0;
								
								if (SLength1 < 7 )
								{
									printf("%d \t%s \t\t\t %s \n", k + 1, entry[num].Language, entry[num].Word);
										
								}
								else if (SLength1 >= 7 ) 
								{
									printf("%d \t%s \t\t %s \n", k + 1, entry[num].Language, entry[num].Word);
									
								} 
								
							}	
							printf("\n");
							printf("Entered Entry:\n");	
							printf("%s \t %s\n", entry[num].Language, entry[num].Word);
							printf("--------------------------------------------\n");
							printf("\n");
							printf("Message: Do not Delete the Entered Entry\n");
							printf("Enter the Number of the Translation to be Deleted: ");
							scanf("%d", &pos_trans);
						
							
							
							if (pos_trans == 0 || pos_trans > entry[num].Number_Translation + 1)
							{
								printf("\n\n");
								printf("=============================================================\n\n");
								printf("Message: You have entered an invalid number for Translation.\n\n");
								printf("=============================================================\n\n");
								
								do 
								{
									printf("Do you want to proceed deleting translation?\n");
									printf("[1] YES\n");
									printf("[2] NO\n");  
									printf("Enter Number: ");
									scanf("%d", &choiceTP_exit);
									printf("--------------------------------------------\n");
									
									
									if ((choiceTP_exit < 1) || (choiceTP_exit > 2))
									{
										printf("Message: Please pick on the given numbers\n\n");
									}
									else if (choiceTP_exit == 1)
									{
										printf("\t\t\t\t Wait for a few Seconds");
										system("cls");
									}
						
								}while((choiceTP_exit < 1) || (choiceTP_exit > 2));
							
							}
							else if (pos_trans > 0 || pos_trans < entry[num].Number_Translation + 1)
							{
						
						
								for(l = pos_trans - 1; l < entry[num].Number_Translation + 1; l++)
								{
									strcpy(entry[num].translate[l].Trans_Language,entry[num].translate[l + 1].Trans_Language);  
									strcpy(entry[num].translate[l].Trans_Word,entry[num].translate[l + 1].Trans_Word);
								}
								
								entry[num].Number_Translation--;
								entry[num].Number_For_Translation--;
							
								if (entry[num].Number_Translation != 0)
								{
								
									do 
									{
										printf("\n");
										printf("========================================================================\n");
										printf("Do you want to proceed deleting translation on the same entry?\n");
										printf("[1] YES\n");
										printf("[2] NO\n");  
										printf("Enter Number: ");
										scanf("%d", &choiceTP);
										printf("--------------------------------------------\n");
										
										
										if ((choiceTP < 1) || (choiceTP > 2))
										{
											printf("Message: Please pick on the given numbers\n\n");
										}
										else if (choiceTP == 1)
										{
											printf("\t\t\t\t Wait for a few Seconds");
											system("cls");
										}
										
									}while ((choiceTP < 1) || (choiceTP > 2));
								}
								
								if (entry[num].Number_Translation  == 0)
								{
									printf("\t\t\t\t Wait for a few Seconds");
									system("cls");
									printf("============================================\n\n");
									printf("Message: You have deleted the whole entry\n\n");
									printf("============================================\n\n");
									
									for (l = num; l < *Entry_NImport; l++)
									{
										entry[l].Entry = entry[l + 1].Entry - 1;
										entry[l].Number_For_Translation = entry[l + 1].Number_For_Translation;
										entry[l].Number_Translation = entry[l + 1].Number_Translation;
										entry[l].Sorted = entry[l + 1].Sorted;
										
										strcpy(entry[l].Language, entry[l + 1].Language);
										strcpy(entry[l].Word, entry[l + 1].Word);
										
										for(j = 0; j < 10; j++)
										{
											strcpy(entry[l].translate[j].Trans_Language, entry[l + 1].translate[j].Trans_Language);
											strcpy(entry[l].translate[j].Trans_Word, entry[l + 1].translate[j].Trans_Word);
										}
									}
									
									*Entry_NImport = *Entry_NImport - 1;
									choiceTP = 2;
									
								}
							}
							
								
						} while((choiceTP_exit != 2) && (choiceTP !=2));
						
						
					}
					
				}
			
			printf("\n");
			
			if (i >= *Entry_NImport)
			{
				printf("=======================================\n\n");
				printf("Message: There is no next entry\n\n");
				printf("=======================================\n\n");
				
				do 
				{
					printf("Do you want to continue looking?\n");
					printf("[1] YES\n");
					printf("[2] NO\n");  
					printf("Enter Number: ");
					scanf("%d", &choice2);
					printf("--------------------------------------------\n");
					
					
					if ((choice2 < 1) || (choice2 > 2))
					{
						printf("Message: Please pick on the given numbers\n\n");
					}
					
					
				}while((choice2 < 1) || (choice2 > 2));
				
				if (choice2 == 1)
				{
					i--;
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");	
				}
				
			}
			else if (i < 0) 
			{
				printf("=======================================\n\n");
				printf("Message: There is no previous entry\n\n");
				printf("=======================================\n\n");
				
				do 
				{
					printf("Do you want to continue looking?\n");
					printf("[1] YES\n");
					printf("[2] NO\n");  
					printf("Enter Number: ");
					scanf("%d", &choice2);
					printf("--------------------------------------------\n");
					
					
					if ((choice2 < 1) || (choice2 > 2))
					{
						printf("Message: Please pick on the given numbers\n\n");
					}
					
					
				}while((choice2 < 1) || (choice2 > 2));
				
				if (choice2 == 1)
				{
					i++;
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");	
				}
			}
		}
		 		
	}
	while( (choice != 4 && choice2 != 2) && (Nok_entry == 0 && choiceTP_exit != 2) && (ok != 1) && (choiceTP != 2)); 
		
			
	if(Nok_entry == 1)
		{
			printf("\n\n");
			printf("========================================================\n\n");
			printf("Message: You have entered an invalid number for Entry.\n\n");
			printf("========================================================\n\n");
		}

		
	printf("=====press any key to go back to Manage Data Menu=====");	
	getch();
}

/*
	This Function a displays all entries alphabetically (according to their ASCII value
	
	@param (int) SLength1 indicates length of entry language
	@param (int) SLength_Trans1 indicates length of the tranlation language
	@param (int) i is indicate the number of page
	@param (int) k is use for looping
	@param (int) j is use for looping
	@param (int) l indicates *Entry_NImport
	@param (int) g indicates the entry number
	@param (int) choice is ask what the user wants to do (go next, previous,exit)
	@param (int) choice2 is the choice if the user wants to keep looking or not
*/
void Display_All_Entries(int *Entry_NImport) 
{
	int SLength1, SLength_Trans1;

	int i = 0;
	int j,k;
	int g,l;
	int point; // pointer to sort
	int choice, choice2;


	if(*Entry_NImport > 0 )	
	{
		do
		{
			if (i >= 0 )
			{
				
				printf("\n");
				printf("=========================================\n");	
				printf("Language \t\tTranslation\n");
				printf("=========================================\n\n");
				
				point = i;
				l = *Entry_NImport;
				Entry_Sorting(&l);
				String_Sorting(&point);
				entry[i].Sorted = 1;
		
				SLength1 = strlen(entry[i].Language);
		
						if (entry[i].Number_For_Translation >= 1)
						{
							for (k = 0; k < entry[i].Number_For_Translation; k++)
							{
								SLength_Trans1 = strlen(entry[i].translate[k].Trans_Language);
								
								if (SLength_Trans1 < 7 )
								{
									printf("%s \t\t\t %s \n", entry[i].translate[k].Trans_Language, entry[i].translate[k].Trans_Word);
								}
								else if (SLength_Trans1 >= 7 ) 
								{
									printf("%s \t\t %s \n", entry[i].translate[k].Trans_Language, entry[i].translate[k].Trans_Word);
								}
							}
							
						}
						else if (entry[i].Number_For_Translation == 0)
						{
							if (SLength1 < 7 )
							{
								printf("%s \t\t\t %s \n", entry[i].Language, entry[i].Word);
									
							}
							else if (SLength1 >= 7 )
							{
								printf("%s \t\t %s \n", entry[i].Language, entry[i].Word);
								
							}
							
						}
						
						printf("\n");
						g = i + 1;
						printf("Entry %d \n", g);
						
						if (entry[i].Number_For_Translation >= 1)
						{
							printf("Entered Entry:\n");	
							printf("%s \t %s\n", entry[i].Language, entry[i].Word);
						}
						
				printf("--------------------------------------------\n");
			
				do 
				{
					printf("What to do?\n");
					printf("[1] Go to Next\n");
					printf("[2] Go to Previous\n");  
					printf("[3] Exit\n");
					printf("Enter Number: ");
					scanf("%d", &choice);
					printf("--------------------------------------------\n");
					
					
					if ((choice < 1) || (choice > 3))
					{
						printf("Message: Please pick on the given numbers\n\n");
					}
					
				}while((choice < 1) || (choice > 3));
				
				printf("\t\t\t\t Wait for a few Seconds");
				system("cls");
				
					if (choice == 1)
					{
						i++;
						
					}
					else if (choice == 2)
					{
						i--;
					}
				
				printf("\n");
				
				if (i >= *Entry_NImport)
				{
					printf("=======================================\n\n");
					printf("Message: There is no next entry\n\n");
					printf("=======================================\n\n");
					
					do 
					{
						printf("Do you want to continue looking?\n");
						printf("[1] YES\n");
						printf("[2] NO\n");  
						printf("Enter Number: ");
						scanf("%d", &choice2);
						printf("--------------------------------------------\n");
						
						
						if ((choice2 < 1) || (choice2 > 2))
						{
							printf("Message: Please pick on the given numbers\n\n");
						}
						
						
					}while((choice2 < 1) || (choice2 > 2));
					
					if (choice2 == 1)
					{
						i--;
						printf("\t\t\t\t Wait for a few Seconds");
						system("cls");	
					}
					
				}
				else if (i < 0) 
				{
					printf("=======================================\n\n");
					printf("Message: There is no previous entry\n\n");
					printf("=======================================\n\n");
					
					do 
					{
						printf("Do you want to continue looking?\n");
						printf("[1] YES\n");
						printf("[2] NO\n");  
						printf("Enter Number: ");
						scanf("%d", &choice2);
						printf("--------------------------------------------\n");
						
						
						if ((choice2 < 1) || (choice2 > 2))
						{
							printf("Message: Please pick on the given numbers\n\n");
						}
						
						
					}while((choice2 < 1) || (choice2 > 2));
					
					if (choice2 == 1)
					{
						i++;
						printf("\t\t\t\t Wait for a few Seconds");
						system("cls");	
					}
				}
			}
			 		
		}
		while((choice !=3) && (choice2 != 2));
	}	
	else if (*Entry_NImport == 0)
	{
		printf("\n\n");
		printf("=======================================\n\n");
		printf("There is no Entry to Display\n\n");
		printf("=======================================\n\n");
		
		printf("=====press any key to go back to Manage Data Menu=====");
		getch();
	}
	
	
}

/*
	This Function shows all entries with the same word as user input
	
	@param (char) Input_Word user input for word to search for 
	@param (int) WFound indicates if a word has been found
	@param (int) SLength indicates length of translation language
	@param (int) number is use for looping
	@param (int) r is use for looping
	@param (int) b is use for looping
	@param (int) g indicates the page number
	@param (int) choice_SW indicates what to do next
	@param (int) WFound_Word indicates if a word has been found
	@param (int) Found indicates if a word has been found
	@param (int) point is use for the number sort
	@param (int) l is use for the number sort
*/


void Search_Word(int *Entry_NImport)
{
	char Input_Word[20];
	int WFound = 0;
	int SLength;
	
	
	int number = 0; 
	int r, b; 
	int g = 1; 
	
	int choice_SW = 0;
	int WFound_Word = 0; 
	int Found = 0;
	int point,l; 
	
	
	
	
	
	printf("Enter The Word: ");
	scanf("%s", &Input_Word);
	
	do
	{
		
			do 			
			{
			
						l = *Entry_NImport;
						Entry_Sorting(&l);
						point = number;
						String_Sorting(&point);
						entry[number].Sorted = 1;
					
				if (choice_SW == 0 || choice_SW == 1)
				{
					for (b = 0; b < entry[number].Number_For_Translation + 1 ; b++)
					{
						if( ((strcmp(entry[number].translate[b].Trans_Word, Input_Word)) == 0 ) || (strcmp(entry[number].Word, Input_Word)) == 0 )
						{
							
							WFound_Word = 1;
								
						} //end
					}
					
					if (WFound_Word == 0)
					{
						
						number++;
						
					}
				}
				else if (choice_SW == 2)
				{
					for (b = 0; b < entry[number].Number_For_Translation + 1 ; b++)
					{
						if( ((strcmp(entry[number].translate[b].Trans_Word, Input_Word)) == 0 ) || (strcmp(entry[number].Word, Input_Word)) == 0 )
						{
							
							WFound_Word = 1;
								
						} //end
					}
					
					if (WFound_Word == 0)
					{
						number--;
					}
				}
				
			} while ((WFound_Word != 1) && (number < *Entry_NImport));
			

		
		if	(WFound_Word == 1)
		{
			WFound = 1;
			

		printf("\n");
		printf("=========================================\n");	
		printf("Language \t\tTranslation\n");
		printf("=========================================\n\n");
								
		for (r = 0; r < entry[number].Number_For_Translation + 1 ; r++)
				{
					SLength = strlen (entry[number].translate[r].Trans_Language);
					
					if (SLength < 7 )
						{
							printf("%s \t\t\t %s \n", entry[number].translate[r].Trans_Language, entry[number].translate[r].Trans_Word);
						}
					else  if (SLength >= 7 )
						{
							printf("%s \t\t %s \n", entry[number].translate[r].Trans_Language, entry[number].translate[r].Trans_Word);
						}
				}
				
			printf("\n\n");	
			printf("page %d\n",g);
			printf("Entered Entry:\n");	
			printf("%s \t %s\n", entry[number].Language, entry[number].Word);
			WFound_Word = 0;
			printf("--------------------------------------------\n\n");
			
			do 
			{
				printf("What to do?\n");
				printf("[1] Go to Next\n");
				printf("[2] Go to Previous\n");  
				printf("[3] Exit\n");
				printf("Enter Number: ");
				scanf("%d", &choice_SW);
				printf("--------------------------------------------\n");
				
				
				if ((choice_SW < 1) || (choice_SW > 3))
				{
					printf("Message: Please pick on the given numbers\n\n");
				}
				
			}while((choice_SW < 1) || (choice_SW > 3));
				
					
				
			if (choice_SW == 1) 
			{
				number++;
				g++;
			}
			else if (choice_SW == 2) 
			{
				number--;
				g--;
			}
			printf("\t\t\t\t Wait for a few Seconds");
				system("cls");
			
			
			printf("\n");
		}
		
	} while ((number < *Entry_NImport ) && (number >= 0));
	
	if (choice_SW == 1) 
	{
		printf("========================================================\n\n");
		printf("Message: There are no Matching Words\n");
		printf("         You have exceeded the Inputed Entries\n\n");
		printf("========================================================\n\n");
	}
	else if (choice_SW == 2) 
	{
		printf("========================================================\n\n");
		printf("Message: You have Reach 0\n\n");
		printf("========================================================\n\n");
	}
	else if (choice_SW == 0) 
	{
		printf("\n\n");
		printf("========================================================\n\n");
		printf("Message: There are no Matching Words in the Given Entries\n\n");
		printf("========================================================\n\n");
	}
	
	printf("\n\n=====press any key to go back to Manage Data Menu=====");
	getch();
	printf("\t\t\t\t Wait for a few Seconds");
	system("cls");
		


}

/*
	This Function shows all entries with the same translation and word as user input (page by page)
	
	@param (char) Input_Word user input for word to search for 
	@param (char) Input_Language user input for language to search for 
	@param (int) WFound indicates if a word has been found
	@param (int) SLength indicates length of translation language
	@param (int) number is use for looping
	@param (int) r is use for looping
	@param (int) b is use for looping
	@param (int) g indicates the page number
	@param (int) choice_SW indicates what to do next
	@param (int) WFound_Word indicates if a word has been found
	@param (int) Found indicates if a word has been found
	@param (int) point is use for the number sort
	@param (int) l is use for the number sort
*/
void Search_Translation(int *Entry_NImport)
{
	char Input_Word[20];
	char Input_Language[20];
	int WFound = 0;
	int SLength;
	
	
	int number = 0; 
	int tran = 0;
	int r, b; 
	int g = 1; 
	
	int choice_SW = 0;
	int WFound_Word = 0; 
	int Found = 0;
	int point,l; 
	
	
	
	
	printf("Enter The Language to Search: ");
	scanf("%s", &Input_Language);
	printf("Enter The Word to Search: ");
	scanf("%s", &Input_Word);
	printf("\t\t\t\t Wait for a few Seconds");
	system("cls");
	
	
	do
	{
			do 			
			{
				
			
						l = *Entry_NImport;
						Entry_Sorting(&l);
						point = number;
						String_Sorting(&point);
						entry[number].Sorted = 1;
				
				if (choice_SW == 0 || choice_SW == 1)
				{
					for (b = 0; b < entry[number].Number_For_Translation + 1 ; b++)
					{
						if(( strcmp(entry[number].translate[b].Trans_Word, Input_Word) == 0)  && (strcmp(entry[number].translate[b].Trans_Language, Input_Language)) == 0)
				
						{
							WFound_Word = 1;
								
						} 
					}
					
					if (WFound_Word == 0)
					{
						
						number++;
						
					}
				}
				else if (choice_SW == 2)
				{
					for (b = 0; b < entry[number].Number_For_Translation + 1 ; b++)
					{
						if( (((strcmp(entry[number].translate[b].Trans_Word, Input_Word)) == 0 ) || (strcmp(entry[number].Word, Input_Word)) == 0 ) &&
						(((strcmp(entry[number].translate[b].Trans_Language, Input_Language)) == 0) || (strcmp(entry[number].Language, Input_Language) ) == 0));
						{
							
							WFound_Word = 1;
								
						} 
					}
					
					if (WFound_Word == 0)
					{
						number--;
					}
				}
				
			} while ((WFound_Word != 1) && (number < *Entry_NImport));
			
		
		
		if	(WFound_Word == 1)
		{
			WFound = 1;
			

		printf("\n");
		printf("=========================================\n");	
		printf("Language \t\tTranslation\n");
		printf("=========================================\n\n");
								
		for (r = 0; r < entry[number].Number_For_Translation + 1 ; r++)
				{
					SLength = strlen (entry[number].translate[r].Trans_Language);
					
					if (SLength < 7 )
						{
							printf("%s \t\t\t %s \n", entry[number].translate[r].Trans_Language, entry[number].translate[r].Trans_Word);
						}
					else  if (SLength >= 7 )
						{
							printf("%s \t\t %s \n", entry[number].translate[r].Trans_Language, entry[number].translate[r].Trans_Word);
						}
				}
				
			printf("\n\n");	
			printf("page %d\n",g);
			printf("Entered Entry:\n");	
			printf("%s \t %s\n", entry[number].Language, entry[number].Word);
			WFound_Word = 0;
			printf("--------------------------------------------\n\n");
			
			do 
			{
				printf("What to do?\n");
				printf("[1] Go to Next\n");
				printf("[2] Go to Previous\n");  
				printf("[3] Exit\n");
				printf("Enter Number: ");
				scanf("%d", &choice_SW);
				printf("--------------------------------------------\n");
				
				
				if ((choice_SW < 1) || (choice_SW > 3))
				{
					printf("Message: Please pick on the given numbers\n\n");
				}
				
			}while((choice_SW < 1) || (choice_SW > 3));
				
					
				
			if (choice_SW == 1) 
			{
				number++;
				g++;
			}
			else if (choice_SW == 2) 
			{
				number--;
				g--;
			}
			printf("\t\t\t\t Wait for a few Seconds");
				system("cls");
			
			
			printf("\n");
		}
		
	} while ((number < *Entry_NImport ) && (number >= 0));
	
	if (choice_SW == 1) 
	{
		printf("========================================================\n\n");
		printf("Message: There are no Matching Words\n");
		printf("         You have exceeded the Inputed Entries\n\n");
		printf("========================================================\n\n");
	}
	else if (choice_SW == 2) 
	{
		printf("========================================================\n\n");
		printf("Message: You have Reach 0\n\n");
		printf("========================================================\n\n");
	}
	else if (choice_SW == 0) 
	{
		printf("\n\n");
		printf("============================================================================\n\n");
		printf("Message: There are no Matching Translation Pair in the Given Entries\n\n");
		printf("============================================================================\n\n");
	}
	
	printf("\n\n=====press any key to go back to Manage Data Menu=====");
	getch();
	printf("\t\t\t\t Wait for a few Seconds");
	system("cls");
	
}
/*
	This Function exports all the entries and its translation into a text file,
	file name will be user input
	
	
	@param (int) i is use for looping
	@param (int) j is use for looping
	@param FILE *fp is the file variable
	@param (int) SLength indicates length of translation language
	@param (char) filename user input for file name to export
	
	
*/
void Export(int *Entry_NImport )
{
	int i; 
	int j;
	FILE *fp;
	int SLength;
	char filename[30];
	do 
	{
		printf("\n\n");
		printf("==========================================\n\n");
		printf("Enter Name of File(no spaces): ");
		scanf("%s", &filename);
		
		SLength = strlen(filename);
		
		if (SLength > 30)
		{
			printf("Message: You have Exceeded the Number of Characters(30 characters)");
			printf("\n\n=====press any key to go Enter File Name again=====");
			getch();
			printf("\t\t\t\t Wait for a few Seconds");
			system("cls");
		}
		
	}while (SLength > 30);
	
	strcat(filename,".txt");

	
	
	fp = fopen(filename, "w");
	
	
	for (i = 0; i < *Entry_NImport; i++)
	{
		if (entry[i].Sorted == 0)
		{
			
			
			for(j = 0; j < entry[i].Number_For_Translation; j++)
			{
				fprintf(fp,"%s: %s\n", entry[i].translate[j].Trans_Language,entry[i].translate[j].Trans_Word);
			}
			
			
		}
		else if (entry[i].Sorted == 1)
		{
			for(j = 0; j < entry[i].Number_For_Translation + 1; j++)
				{
					fprintf(fp,"%s: %s\n", entry[i].translate[j].Trans_Language,entry[i].translate[j].Trans_Word);
				}
					
		}
		
		fprintf(fp,"\n");
	}
	
	printf("\n\n");
	printf("=================================================\n\n");
	printf("Message: File Exported Successfully\n\n");
	printf("=================================================\n\n");

	printf("\n\n=====press any key to go back to Manage Data Menu=====");
	fclose(fp);
	getch();
	
}

/*
	This Function imports all entries of the text file into the entries of the program
	
	@param FILE *fp is the file variable
	@param (char) filename_search user input for file name to import
	@param (int) Import_Exit use to indicate if import exiting
	@param (char) words[50] use to store the read string in the text file
	@param (int) read_line indicates what line is read
	@param (int) num_trans indicates the number of translation
	@param (int) pair indicates the number of pairs
	@param (int) line indicates the line number
	@param (int) num_words indicates the number of words tokenize from user input
	@param (int) choice_Entry indicates if the user wants to put the entry along with its translation
	@param (int) i is use for looping
	@param (int) j is use for looping
	@param (int) k is use for looping
	@param (int) g is use for looping
	@param (int) num_entry indicates number of entry
*/
void Import(int *Entry_NImport) // not yet finish
{
	
	FILE *fp;
	char filename_search[30];
	int Import_Exit;
	
	char words[50];
	int read_line;
	
	int num_trans = 0;
	int pair = 0;
	int line = 0;
	int num_words;
	
	int choice_Entry;
	int i, j, k,g;

	int num_entry = 1;
	
	
	
	do
	{
	
		printf("\n\n");
		printf("Enter the Name of the Text File: ");
		scanf("%s", &filename_search);
		
		strcat(filename_search,".txt");
		
		fp = fopen(filename_search, "r");
		
		if (fp == NULL)
		{
			printf("\n");
			printf("==========================================\n\n");
			printf("Message: There is no Existing Text File.\n\n");
			printf("==========================================\n\n");	
		
		
			do
			{
			
				printf("\n");
				printf("Do you still want to continue?\n");
				printf("[1] YES\n");
				printf("[2] NO\n");  
				printf("Enter Number: ");
				scanf("%d", &Import_Exit);
				printf("--------------------------------------------\n");
				
				if ((Import_Exit < 1) || (Import_Exit > 2))
					{
						printf("Message: Please pick on the given numbers\n\n");
					}
			}while ((Import_Exit < 1) || (Import_Exit > 2)); 
			
			printf("\t\t\t\t Wait for a few Seconds");
			system("cls");
		}
		
		
		fclose(fp);
	}while ((fp == NULL) && (Import_Exit != 2));
	
	printf("\t\t\t\t Wait for a few Seconds");
	system("cls");
			
	if (fp != NULL)
	{
		fp = fopen(filename_search, "r");
		
		do 
		{
			fgets(words, 50, fp);
			if (feof(fp))
			{
				//do nothing
				
			}
			else 
			{
				
				strcpy(RFile[read_line].Read_File_Line, words);	
				read_line++;
				
			}
			
		}while (!feof(fp));
		
		
		
		for (line = 0; line < read_line; line++)
			{
				
				if (strcmp(RFile[line].Read_File_Line, "\n") == 0)
				{
					Structure[pair].num_trans = num_trans;
					pair++;
					
					
					num_trans = 0;
				}
				else 
				{
					token(line,num_trans,pair);
					num_trans++;
					
				}
				
			}
		
		
		for (i = 0; i < pair; i++)
		{
			for (j = 0; j < Structure[i].num_trans; j++)
			{
		
			printf("%s: %s\n", Structure[i].Translations[j].Read_Gets_Language, Structure[i].Translations[j].Read_Gets_Translation);
			}
			printf("==========================\n");
			
			
			do
			{
			
				printf("\n");
				printf("Do you want to add this as entry?\n");
				printf("[1] YES\n");
				printf("[2] NO\n");  
				printf("Enter Number: ");
				scanf("%d", &choice_Entry);
				printf("--------------------------------------------\n");
				
				if ((choice_Entry < 1) || (choice_Entry > 2))
					{
						printf("Message: Please pick on the given numbers\n\n");
					}
			}while ((choice_Entry < 1) || (choice_Entry > 2));	
			
			if (choice_Entry == 1)
			{
				k = *Entry_NImport + 1;
				
				strcpy(entry[*Entry_NImport].Language, Structure[i].Translations[0].Read_Gets_Language);
				strcpy(entry[*Entry_NImport].Word, Structure[i].Translations[0].Read_Gets_Translation);
				
				entry[*Entry_NImport].Entry = *Entry_NImport + 1;
				
				for (g = 0; g < Structure[i].num_trans; g++)
				{
					strcpy(entry[*Entry_NImport].translate[g].Trans_Language, Structure[i].Translations[g].Read_Gets_Language );
					strcpy(entry[*Entry_NImport].translate[g].Trans_Word, Structure[i].Translations[g].Read_Gets_Translation );
				}
				
				entry[*Entry_NImport].Number_Translation = Structure[i].num_trans;
				entry[*Entry_NImport].Number_For_Translation = Structure[i].num_trans;
				
				*Entry_NImport = k;
			}
			
			
			printf("\t\t\t\t Wait for a few Seconds");
			system("cls");	
			

		}
		
			
		
		printf("\n\n");
		printf("==========================================\n\n");
		printf("Message: You have Reach the End of the File.\n\n");
		printf("==========================================\n\n");	
		
		printf("\n\n=====press any key to go back to Manage Data Menu=====");	
		getch();

		
		printf("\t\t\t\t Wait for a few Seconds");
		system("cls");	
			
	     
		
		fclose(fp);
	}
}

/*
	This Function is used to search for the translation for the translate in translate menu
	
	@param (int) i is use for looping
	@param (int) j is use for looping
	@param (int) k is use for looping
	@param (int) g is use for looping
	@param (int) l is use for looping
	@param (int) found indicates that a translation has been found
*/
void Search_Translate(char Input_Language[20], char translate[20], int num_pair,  int num_words)
{
	int i,j,k,l;
	int g;
	int found;
	
	
				
	for (k = 0; k < num_words; k++)
	{
		for(i = 0; i < num_pair; i++)
		{
			for (j = 0; j < Structure[i].num_trans; j++)
			{
				
				if(strcmp(Input_Language ,Structure[i].Translations[j].Read_Gets_Language) == 0)
				{
					
					if(strcmp(Word[k].Word, Structure[i].Translations[j].Read_Gets_Translation) == 0)
					{
						
						for (l = 0; l < Structure[i].num_trans; l++)
						{
							if(strcmp(translate, Structure[i].Translations[l].Read_Gets_Language) == 0)
							{
								strcpy(Word[k].Translated_Word, Structure[i].Translations[l].Read_Gets_Translation);
								found = 1;
								Word[k].Found_Translation = found;
								
							}
						}
					}
					
				}
			}
		}
	}
	
}

/*
	This Function is used to search for the translation for the translate in translate menu
	
	@param (int) choiceTM choice to exit or translate
	@param (int) choiceTF choice to continue to input filename
	@param (int) choiceAnother choice to input another sentence to translate
	@param (char) Input_Language[20] user input language of sentence
	@param (char) Input_Sentence[150] user input sentence to translate
	@param (char) translate[20] user input laguage to translate to
	@param (char) filename_search[30] file name to search for
	@param (char) words[50] use to store the read string in the text file
	@param (int) read_line indicates what line is read
	@param (int) i is use for looping
	@param (int) j is use for looping
	@param (int) num_trans indicates the number of translation
	@param (int) pair indicates the number of pairs
	@param (int) line indicates the line number
	@param (int) num_words indicates the number of words tokenize from user input
*/

void Translate_Menu()
{
	int choiceTM;
	int choiceTF; 
	int choiceAnother;
	
	char Input_Language[20]; 
	char Input_Sentence[150]; 
	char translate[20]; 
	
	char filename_search[30]; 
	FILE *fp;
	

	char words[50];
	int read_line = 0;
	int i,j;
	
	int num_trans = 0;
	int pair = 0;
	int line = 0;
	int num_words;	
	
	
	do
	{
		printf("\n\n");
		printf("Enter the Name of the Text File: ");
		scanf("%s",filename_search);
		
		strcat(filename_search,".txt");
		
		fp = fopen(filename_search, "r");
		
		if (fp == NULL)
		{
			printf("\n");
			printf("==========================================\n\n");
			printf("Message: There is no Existing Text File.\n\n");
			printf("==========================================\n\n");	
		
		
			do
			{
			
				printf("\n");
				printf("Do you still want to continue?\n");
				printf("[1] YES\n");
				printf("[2] NO\n");  
				printf("Enter Number: ");
				scanf("%d", &choiceTF);
				printf("--------------------------------------------\n");
				
				if ((choiceTF < 1) || (choiceTF > 2))
					{
						printf("Message: Please pick on the given numbers\n\n");
					}
			}while ((choiceTF < 1) || (choiceTF > 2));
			
			printf("\t\t\t\t Wait for a few Seconds");
			system("cls");
		}
		fclose(fp);
	}while ((fp == NULL) && (choiceTF != 2));
	
	
	if (fp != NULL)
	{
		fclose(fp);
		
		printf("\t\t\t\t Wait for a few Seconds");
		system("cls");
		do
		{
		fp = fopen(filename_search, "r");
			printf("Translate Menu:\n");
			printf("[1] Translate\n");
			printf("[2] Exit\n");  
			printf("Enter Number: ");
			scanf("%d", &choiceTM);
			fgetc(stdin);
			printf("--------------------------------------------\n");
			
			
			if ((choiceTM < 1) || (choiceTM > 2))
			{
				printf("Message: Please pick on the given numbers\n\n");
			}
		}
		while((choiceTM < 1) || (choiceTM > 2));
		
		if (choiceTM == 1)
		{
			
			
			printf("Enter the Language of the sentence: ");
			scanf("%s", &Input_Language);
			printf("Enter the Language You Want to Translate to: ");
			scanf("%s", &translate);
			fgetc(stdin);
			printf("\n");
			do 
			{
				num_words = 0;
				printf("Enter Sentence: ");
				fgets(Input_Sentence, sizeof(Input_Sentence), stdin);
			
				Tokenization(Input_Sentence,&num_words);
				
			
			
				
				
				do 
				{
					fgets(words, 50, fp);
					if (feof(fp))
					{
						//do nothing
						
					}
					else 
					{
						
						strcpy(RFile[read_line].Read_File_Line, words);	
						read_line++;
						
					}
					
				}while (!feof(fp));
				
				for (line = 0; line < read_line; line++)
				{
					if (strcmp(RFile[line].Read_File_Line, "\n") == 0)
					{
						Structure[pair].num_trans = num_trans;
						pair++;
						
						
						num_trans = 0;
					}
					else 
					{
						token(line,num_trans,pair);
						num_trans++;
						
					}
					
				}
				
				
				Search_Translate(Input_Language, translate, pair, num_words);
				
				printf("Translation: ");
				
				for (i = 0; i < num_words; i++)
				{
					if (Word[i].Found_Translation == 0)
					{
						printf("%s ",Word[i].Word);
					}
					else if (Word[i].Found_Translation == 1)
					{
						printf("%s ",Word[i].Translated_Word);
					}
				}
				
				do
				{
				
					printf("\n\n");
					printf("=====================================================================================\n\n");
					printf("Do you want to translate again with the same language and translate language?\n");
					printf("[1] YES\n");
					printf("[2] NO\n");  
					printf("Enter Number: ");
					scanf("%d", &choiceAnother);
					fgetc(stdin);
					printf("--------------------------------------------\n");
					
					if ((choiceAnother < 1) || (choiceAnother > 2))
						{
							printf("Message: Please pick on the given numbers\n\n");
						}
						
				} while (choiceAnother < 1 || choiceAnother > 2);
				
				if (choiceAnother == 1)
				{
					for(i = 0; i < num_words; i++)
					{
						strcpy(Word[i].Word, "\0");
						strcpy(Word[i].Translated_Word, "\0");
						Word[i].Found_Translation = 0;
						strcpy(Input_Sentence, "\0");
					}
					
				}
				printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				
				
			}while(choiceAnother != 2);
			
				fclose(fp);	
			
		fclose(fp);	
			
		}
		else if (choiceTM == 2)
		{
			for(i = 0; i < num_words; i++)
			{
				strcpy(Word[i].Word, "\0");
				strcpy(Word[i].Translated_Word, "\0");
				Word[i].Found_Translation = 0;
				strcpy(Input_Sentence, "\0");
				
			} 
			
			for (i = 0; i < pair; i++)
			{
				for (j = 0; j < num_trans; j++)
				{
					Structure[i].num_trans = 0;
					strcpy(Structure[i].Translations[j].Read_Gets_Language, "\0");
					strcpy(Structure[i].Translations[j].Read_Gets_Translation, "\0");
					strcpy(Structure[i].Translations[j].pair, "\0");
				}
			}
			
			for (i = 0; i < read_line; i++)
			{
				strcpy(RFile[read_line].Read_File_Line, "\0");
				
			}
			
			 num_trans = 0;
			 pair = 0;
			 line = 0;
			 num_words = 0;
		}
		
	}
	
	printf("\n\n=====press any key to go back to Main Menu=====");
	getch();

}

int Main_Menu(int choice)
	{
		
		do
		{
			printf("\n");
			printf("Main Menu:\n");
			printf("[1] Manage Data Menu\n");
			printf("[2] Translate Menu\n"); 
			printf("[3] Exit\n"); 
			printf("Enter Number: ");
			scanf("%d", &choice);
			printf("--------------------------------------------\n");
			
			
			if ((choice < 1) || (choice > 3))
			{
				printf("Message: Please pick on the given numbers\n\n");
			}
		}
		while((choice < 1) || (choice > 3));
			
	return choice; 	
	}
	
int Manage_Data_Menu(int choice2)
	{
		do
		{
			printf("\n");
			printf("Manage Data Menu:\n");
			printf("[1] Add Entry\n");
			printf("[2] Add Translations\n");
			printf("[3] Delete Entry\n");
			printf("[4] Delete Translation\n");
			printf("[5] Display All Entries\n");
			printf("[6] Search Word\n");
			printf("[7] Search Translation\n");
			printf("[8] Export\n");
			printf("[9] Import\n");
			printf("[10] Exit\n");
			printf("Enter Number: ");
			scanf("%d", &choice2);
			printf("--------------------------------------------\n");
			
			if ((choice2 < 1) || (choice2 > 10))
			{
				printf("Message: Please pick on the given numbers\n\n");
			}
		}
		while((choice2 < 1) || (choice2 > 10));
			
	return choice2; 	
	}

	

int main()
{
	int choice, choice2; //choice = Translate Menu; choice2 = Main Menu
	int choiceAE; // choiceAE = Add Entry Choice
	int choiceTM;
	int i;
	int j;

	
	int Import_Num = 0; //see if the use have import a file 
	int Entry_Non_Import = 0; // entry for non import, pointer
	int p;
	
	
	
	do
	{
		
	choice = Main_Menu(choice);	
	
		if (choice == 1)
		{
			do
			{		
			
			printf("\n");
			printf("\t\t\t\t Wait for a few Seconds\n");
			system("cls");
			choice2 = Manage_Data_Menu(choice2);
			
				if (choice2 == 1) // Add Entry
				{	
					system("cls");
					Add_Entry(&Entry_Non_Import);
					
			
				}
				else if (choice2 == 2) // Add Translations
				{
					
					Add_Translations(&Entry_Non_Import);	
						
				}
				else if (choice2 == 3) // Delete Entry
				{
					
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
					Delete_Entry(&Entry_Non_Import);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				}
				else if (choice2 == 4) // Delete Translation
				{
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
					Delete_Translation(&Entry_Non_Import);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				}
				else if (choice2 == 5) // Display All Entries
				{	
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				//	Entry_Sorting(&Entry_Non_Import);
					Display_All_Entries(&Entry_Non_Import);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				}
				else if (choice2 == 6) // Search Word
				{
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
					Search_Word(&Entry_Non_Import);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				}
				else if (choice2 == 7) // Search Translation
				{
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
					Search_Translation(&Entry_Non_Import);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				}
				else if (choice2 == 8) // Export
				{
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
					Export(&Entry_Non_Import);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				}
				else if (choice2 == 9) // Import
				{
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
					Import(&Entry_Non_Import);
					printf("\t\t\t\t Wait for a few Seconds");
					system("cls");
				}
				else if (choice2 == 10) // exit
				{
					
					for (i = 0; i < Entry_Non_Import; i++)
					{
						if(entry[i].Sorted == 1)
						{
							for (j=0; j < entry[i].Number_For_Translation + 1; j++)
							{
								strcpy(entry[i].translate[j].Trans_Language,"\0");
								strcpy(entry[i].translate[j].Trans_Word,"\0");
							}
						}
						else if (entry[i].Sorted == 0)
						{
							for (j=0; j < entry[i].Number_For_Translation; j++)
							{
								strcpy(entry[i].translate[j].Trans_Language,"\0");
								strcpy(entry[i].translate[j].Trans_Word,"\0");
							}
						}
						
						
						entry[i].Entry = 0;
						entry[i].Number_For_Translation = 0;
						entry[i].Number_Translation = 0;
						entry[i].Sorted = 0;
						
						strcpy(entry[i].Language,"\0");
						strcpy(entry[i].Word,"\0");
					} 
					
					Entry_Non_Import = 0;
				//	*/
					
					printf("\t\t\t\t Wait for a few Seconds\n");
					system("cls");
				}
				
				
				printf("\n");
			}while(choice2 != 10);
		}
		else if (choice == 2)
		
			{
				printf("\n");
				printf("\t\t\t\t Wait for a few Seconds\n");
				system("cls");
				printf("\n");
				Translate_Menu();
				printf("\t\t\t\t Wait for a few Seconds\n");
				system("cls");
				
			}
	
	}
	while((choice == 1) || (choice == 2));

	


	return 0;
}

