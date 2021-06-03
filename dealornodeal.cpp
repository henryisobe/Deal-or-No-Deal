//Deal or no Deal game
//Henry Isobe
//using Samuel D. Bradley's equation for the banker's offer

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

//cases class, probably would've been better if it had more variables but it worked
class cases
{
public:
	int casenum;
	float value;

	cases(int casenum, float value)
	{
		this->casenum = casenum;
		this->value = value;
	}
};

//prints the cases
//it was difficult to program because you have to print line by line instead of by chunks or boxes
void printcases(vector<cases> casesvector, vector<int> chosen)
{
	int i, j, verify;
	int temp;
	verify = 1;
	vector<float> monies{0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};

	//top row

	cout<<"           -------      -------      -------      -------      -------      -------"<<endl;
	cout<<"          |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
	cout<<"      ";
	for(i=0; i<6; i++)
	{
		for(j=0; j<chosen.size(); j++)
		{
			if((i+21) == chosen.at(j))
			{
				verify = 0;
			}
		}
		if(verify == 1)
		{
			cout<<"    |   "<<(i+21)<<"  |";
			verify = 1;
		}
		else
		{
			cout<<"    |       |";
			verify = 1;
		}
	}
	cout<<"\n          |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
 	cout<<"           -------      -------      -------      -------      -------      -------"<<endl;
 	cout<<"\n";

 	//3rd row

	cout<<"     -------      -------      -------      -------      -------      -------      -------"<<endl;
	cout<<"    |	    |    |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
	for(i=0; i<7; i++)
	{
		for(j=0; j<chosen.size(); j++)
		{
			if((i+14) == chosen.at(j))
			{
				verify = 0;
			}
		}
		if(verify == 1)
		{
			cout<<"    |   "<<(i+14)<<"  |";
			verify = 1;
		}
		else
		{
			cout<<"    |       |";
			verify = 1;
		}
	}
	cout<<"\n    |	    |    |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
 	cout<<"     -------      -------      -------      -------      -------      -------      -------"<<endl;
 	cout<<"\n";

	//2nd row

 	cout<<"     -------      -------      -------      -------      -------      -------      -------"<<endl;
	cout<<"    |	    |    |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
	for(i=0; i<7; i++)
	{
		for(j=0; j<chosen.size(); j++)
		{
			if((i+7) == chosen.at(j))
			{
				verify = 0;
			}
		}
		if(verify == 1)
		{
			if(i>2)
			{
				cout<<"    |   "<<(i+7)<<"  |";
				verify = 1;
			}
			else
			{
				cout<<"    |   "<<(i+7)<<"   |";
				verify = 1;
			}
		}
		else
		{
			if(i>2)
			{
				cout<<"    |       |";
				verify = 1;
			}
			else
			{
				cout<<"    |       |";
				verify = 1;
			}
		}
	}
	cout<<"\n    |	    |    |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
 	cout<<"     -------      -------      -------      -------      -------      -------      -------"<<endl;
	cout<<"\n";

 	//bottom row

	cout<<"           -------      -------      -------      -------      -------      -------"<<endl;
	cout<<"          |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
	cout<<"      ";
	for(i=0; i<6; i++)
	{
		for(j=0; j<chosen.size(); j++)
		{
			if((i+1) == chosen.at(j))
			{
				verify = 0;
			}
		}
		if(verify == 1)
		{
			cout<<"    |   "<<(i+1)<<"   |";
			verify = 1;
		}
		else
		{
			cout<<"    |       |";
			verify = 1;
		}
	}
	cout<<"\n          |       |    |       |    |       |    |       |    |       |    |       |"<<endl;
 	cout<<"           -------      -------      -------      -------      -------      -------"<<endl;
 	cout<<"\n";

 	//printing out the remaining money values
 	//push_back() puts new input in new next index of vector
 	cout<<"                                    Remaining Money Values"<<endl;
 	for(i=0; i<26; i++)
 	{
 		for(j=0; j<chosen.size(); j++)
		{
			if(monies.at(i) == casesvector.at(chosen.at(j)-1).value && j != 0)
			{
				verify = 0;
			}
		}
		if(verify == 1)
		{
			cout<<" | "<<monies.at(i);
		}
		else
		{
			cout<<" |     ";
		}
 		verify = 1;
 		if(i == 15)
 		{
 			cout<<" |\n";
 		}
 	}
 	cout<<" |"<<endl;
}

//loading function to create tension. uses Sleep() to stall 
void printloading()
{	
	cout<<"\n                                            *";
 	Sleep(1500);
 	cout<<" *";
 	Sleep(1500);
	cout<<" *";
 	Sleep(1500);
}

//function for banker
//remember that chosen has to be -1 to match correct index
float brokercall(vector<float> randmoneyvalues, vector<int> chosen)
{
	int i, j, verify;
	float newoffer, E, C, M;
	float sum;
	int alreadychosen = 0;
	float temp;
	sum = 0;

	//finding the value of E, the arithmetic mean of all remaining values
	for(i=1; i<=26; i++)
	{
		for(j=0; j<chosen.size(); j++)
		{
			if(i == chosen.at(j))
			{
				alreadychosen = 1;
			}
		}
		if(alreadychosen == 0)
		{
			sum = sum + randmoneyvalues.at(i-1);
		} 
		alreadychosen = 0;
	}
	E = sum/(26-chosen.size());

	//finding the value of C, the number of cases remaining
	C = 26 - chosen.size();

	//finding the value of M, the maximum value on the board (remember to start index at 1 since 0th index is the first chosen case and you don't want to include that info into the game)
	//first we order the chosen numbers from index 1 to end
	//We need to do this to earse the correct numbers without going out of range
	for(i=1; i<chosen.size(); i++)
	{
		for(j=i; j<chosen.size(); j++)
		{
			if(chosen.at(i) < chosen.at(j))
			{
				temp = chosen.at(i);
				chosen.at(i) = chosen.at(j);
				chosen.at(j) = temp;
			}
		}
	}
	//now we start erasing the values from the correct index
	for(i=1; i<chosen.size(); i++)
	{
		randmoneyvalues.erase(randmoneyvalues.begin() + (chosen.at(i)-1));
	}

	//now we find the largest number in the random money vector and set M equal to it
	for(i=0; i<26-chosen.size(); i++)
	{
		if(randmoneyvalues.at(0) < randmoneyvalues.at(i))
		{
			randmoneyvalues.at(0) = randmoneyvalues.at(i);
		}
	}
	M = randmoneyvalues.at(0);

	//formula for the offer given by banker
	newoffer = 12275.30 + (0.748 * E) - (2714.74 * C) - (0.04 * M) + (0.0000006986 * E * E) + (32.623 * C * C);

	if(newoffer < 0)
	{
		newoffer = newoffer * -1;
	}

	return newoffer;
}

int main()
{
	//seed for random function
	srand(time(NULL));

	//All variables for setting up the game
	int i, j, x, choice;
	int verify, count, deal;
	float offer;
	string dond;

	//creates vector of numbers from 1 to 26 in random order
	vector<int> randnum;
	verify = 1;
	count = 1;
	x = rand() % 26 + 1;
	randnum.push_back(x);
	while(count < 26)
	{
		x = rand() % 26 + 1;

		for(i=0; i<count; i++)
		{
			if(x == randnum.at(i))
			{
				verify = 0;
			}
		}
		if(verify != 0)
		{
			randnum.push_back(x);
			count++;
		}
		verify = 1;	
	}

    //Vector of all the money values in deal or no deal
    vector<float> moneyvalues;
    moneyvalues.push_back(1000000);
    moneyvalues.push_back(750000);
    moneyvalues.push_back(500000);
    moneyvalues.push_back(400000);
    moneyvalues.push_back(300000);
    moneyvalues.push_back(200000);
    moneyvalues.push_back(100000);
    moneyvalues.push_back(75000);
    moneyvalues.push_back(50000);
    moneyvalues.push_back(25000);
    moneyvalues.push_back(10000);
    moneyvalues.push_back(5000);
    moneyvalues.push_back(1000);
    moneyvalues.push_back(750);
    moneyvalues.push_back(500);
    moneyvalues.push_back(400);
    moneyvalues.push_back(300);
    moneyvalues.push_back(200);
    moneyvalues.push_back(100);
    moneyvalues.push_back(75);
    moneyvalues.push_back(50);
    moneyvalues.push_back(25);
    moneyvalues.push_back(10);
    moneyvalues.push_back(5);
    moneyvalues.push_back(1);
    moneyvalues.push_back(0.01);

    //creating all cases and putting them into a vector of cases
    vector<cases> casesvector;
	cases case1(1, moneyvalues.at(randnum.at(0)-1));
	casesvector.push_back(case1);
	cases case2(2, moneyvalues.at(randnum.at(1)-1));
	casesvector.push_back(case2);
	cases case3(3, moneyvalues.at(randnum.at(2)-1));
	casesvector.push_back(case3);
	cases case4(4, moneyvalues.at(randnum.at(3)-1));
	casesvector.push_back(case4);
	cases case5(5, moneyvalues.at(randnum.at(4)-1));
	casesvector.push_back(case5);
	cases case6(6, moneyvalues.at(randnum.at(5)-1));
	casesvector.push_back(case6);
	cases case7(7, moneyvalues.at(randnum.at(6)-1));
	casesvector.push_back(case7);
	cases case8(8, moneyvalues.at(randnum.at(7)-1));
	casesvector.push_back(case8);
	cases case9(9, moneyvalues.at(randnum.at(8)-1));
	casesvector.push_back(case9);
	cases case10(10, moneyvalues.at(randnum.at(9)-1));
	casesvector.push_back(case10);
	cases case11(11, moneyvalues.at(randnum.at(10)-1));
	casesvector.push_back(case11);
	cases case12(12, moneyvalues.at(randnum.at(11)-1));
	casesvector.push_back(case12);
	cases case13(13, moneyvalues.at(randnum.at(12)-1));
	casesvector.push_back(case13);
	cases case14(14, moneyvalues.at(randnum.at(13)-1));
	casesvector.push_back(case14);
	cases case15(15, moneyvalues.at(randnum.at(14)-1));
	casesvector.push_back(case15);
	cases case16(16, moneyvalues.at(randnum.at(15)-1));
	casesvector.push_back(case16);
	cases case17(17, moneyvalues.at(randnum.at(16)-1));
	casesvector.push_back(case17);
	cases case18(18, moneyvalues.at(randnum.at(17)-1));
	casesvector.push_back(case18);
	cases case19(19, moneyvalues.at(randnum.at(18)-1));
	casesvector.push_back(case19);
	cases case20(20, moneyvalues.at(randnum.at(19)-1));
	casesvector.push_back(case20);
	cases case21(21, moneyvalues.at(randnum.at(20)-1));
	casesvector.push_back(case21);
	cases case22(22, moneyvalues.at(randnum.at(21)-1));
	casesvector.push_back(case22);
	cases case23(23, moneyvalues.at(randnum.at(22)-1));
	casesvector.push_back(case23);
	cases case24(24, moneyvalues.at(randnum.at(23)-1));
	casesvector.push_back(case24);
	cases case25(25, moneyvalues.at(randnum.at(24)-1));
	casesvector.push_back(case25);
	cases case26(26, moneyvalues.at(randnum.at(25)-1));
	casesvector.push_back(case26);

	//insert the value of each case into a vector for the banker to use.
	vector<float> randmoneyvalues;
	randmoneyvalues.push_back(case1.value);
	randmoneyvalues.push_back(case2.value);
	randmoneyvalues.push_back(case3.value);
	randmoneyvalues.push_back(case4.value);
	randmoneyvalues.push_back(case5.value);
	randmoneyvalues.push_back(case6.value);
	randmoneyvalues.push_back(case7.value);
	randmoneyvalues.push_back(case8.value);
	randmoneyvalues.push_back(case9.value);
	randmoneyvalues.push_back(case10.value);
	randmoneyvalues.push_back(case11.value);
	randmoneyvalues.push_back(case12.value);
	randmoneyvalues.push_back(case13.value);
	randmoneyvalues.push_back(case14.value);
	randmoneyvalues.push_back(case15.value);
	randmoneyvalues.push_back(case16.value);
	randmoneyvalues.push_back(case17.value);
	randmoneyvalues.push_back(case18.value);
	randmoneyvalues.push_back(case19.value);
	randmoneyvalues.push_back(case20.value);
	randmoneyvalues.push_back(case21.value);
	randmoneyvalues.push_back(case22.value);
	randmoneyvalues.push_back(case23.value);
	randmoneyvalues.push_back(case24.value);
	randmoneyvalues.push_back(case25.value);
	randmoneyvalues.push_back(case26.value);

	//Creating a vector of all the cases that have been chosen
	vector<int> chosen;

	//starting the game
	//Welcome sign and player picks their case
	cout<<"\n                                *****************************\n                                Welcome to Deal or No Deal!!!\n                                *****************************\n\n"<<endl;
	printcases(casesvector, chosen);
 	cout<<"\n                                Choose your case!   Case: #";
 	cin>>choice;
 	chosen.push_back(choice);
 	cout<<"\n                    You have chosen case number "<<choice<<"! Let's start the game!!!"<<endl;
 	printloading();
 	cout<<"\n"<<endl;

 	//Initiates all the variables for the game
 	int choicesleft = 6;
 	count = 24;
 	deal = 0;

 	//starting the game loop that ends when someone chooses deal
 	//not using for loops or variable i so that for loops could be used within the main while loop
 	while(count > 0)
 	{
 		//if statement for if user chooses deal or no deal
 		if(deal == 0 && count > 0)
 		{
 			//round info and prints out cases
 			cout<<"\n                                *****************************\n                                      Deal or No Deal!!!\n                                *****************************\n"<<endl;
 			printcases(casesvector, chosen);
 			cout<<"\n                       You will need to choose "<<choicesleft<<" cases for round "<<(7-choicesleft)<<endl;
 			printloading();

 			//iterates through rounds, this will have the grunt of the game play
 			//will also show user what was in the case that they choose each time
 			//user chooses their case for the round
 			for(i=0; i<choicesleft; i++)
 			{

 				cout<<"\n                                *****************************\n                                      Deal or No Deal!!!\n                                *****************************\n"<<endl;
 				
 				printcases(casesvector, chosen);

				cout<<"\n                    You have "<<choicesleft-i<<" choice(s) left. Choose a case!   Case: #";
 				cin>>choice;

 				//checks to see if the choice is acceptable
 				verify = 1;
 				while(verify == 1)
 				{
 					verify = 0;
 					if(choice < 0 || choice > 26)
 					{
 						verify = 1;
 					}
 					for(j=0; j<chosen.size(); j++)
 					{
 						if(choice == chosen.at(j))
 						{
 							verify = 1;
 						}
 					}
 					if(verify == 1)
 					{
 						cout<<"               That is not an acceptable choice, please enter a new choice."<<endl;
 						cout<<"                                          Case: #";
 						cin>>choice;
 					}
 				}

 				chosen.push_back(choice);
 				cout<<"\n                              The case you have chosen contains"<<endl;
 				printloading();
 				cout<<"\n                                            $"<<casesvector.at(chosen.at(chosen.size()-1)-1).value<<" !"<<endl;
 				printloading();
 				
 				//subtracting counters for game
 				count--;
 			}

 			//Logic for banker, gets the offer
 			offer = brokercall(randmoneyvalues, chosen);

 			//dealer gives offer
 			cout<<"\n                                       Ring~";
 			Sleep(1000);
 			cout<<" Ring~";
 			Sleep(1000);
 			cout<<" Ring~"<<endl;
 			cout<<"\n                   Looks like the banker is calling to make you an offer!"<<endl;
 			cout<<"                                         His offer is:";
 			Sleep(3000);
 			cout<<"\n                                           $"<<offer<<endl;
 			cout<<"\n                          Now the question is... DEAL OR NO DEAL!?!?!"<<endl;
 			cout<<"                           (Type ""1"" for DEAL    or    ""0"" for NO DEAL)"<<endl; 
 			cout<<"\n                                            Answer: ";
 			cin>>deal;

 			if(choicesleft > 1)
 			{
 				choicesleft--;
 			}
 		}
 		else
 		{
 			break;
 		}
 	}

 	//end of the game
 	//two scenarios, one where player says deal, and one where they run out of cases
 	if(deal == 1)
 	{
 		cout<<"                        Congratulations! You are leaving with $"<<offer<<endl;
 		printloading();
 		cout<<"\n                      Before you leave, let's see what was in your case!"<<endl;
 		printloading();
 		cout<<"\n                                   Your case contained $"<<casesvector.at(chosen.at(0)-1).value<<endl;
 		if(casesvector.at(0).value > offer)
 		{
 			cout<<"                                       Better luck next time!"<<endl;
 		}
 		else
 		{
 			cout<<"                                  Thank you for playing\n";
 			Sleep(500);
 			cout<<"                                      Deal";
 			Sleep(500);
 			cout<<" or";
 			Sleep(500);
 			cout<<" No Deal!"<<endl;
 		}
 	}
 	else
 	{
 		cout<<"                           Let's see what is inside your case!"<<endl;
 		printloading();
 		cout<<"                              Your case contained $"<<casesvector.at(chosen.at(0)-1).value<<endl;
 		if(casesvector.at(0).value < offer)
 		{
 			cout<<"                             Better luck next time."<<endl;
 		}
 		else
 		{
 			cout<<"                                  Thank you for playing\n";
 			Sleep(500);
 			cout<<"                                      Deal";
 			Sleep(500);
 			cout<<" or";
 			Sleep(500);
 			cout<<" No Deal!!!"<<endl;
 		}
 	}
	return 0;
}

