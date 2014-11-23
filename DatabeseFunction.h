#include<iostream>
#include<Graphics.hpp>
#include<Window.hpp>
#include<sqlite3.h> //biblioteka odpowiadaj¹ca za obs³uge sqllite
#include<string>
#include<list>
#include"Users.h";


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace users;


namespace database{


	sqlite3 *db;  //zmienna oznaczajaca baze
	string ID, nazwa, login, haslo; //zmienna pomocnicza do przekazywania danych miêdzy wskaŸnikami 
	
	int CzyInsert; // zmienna mowiaca ktora opercja bedzie wykonywana

	list<User> Users; //lista przechowujaca uzytkownikow
	list<User>::iterator j; // iterator do listy


	//dodatkowa  metoda sprawdzajaca czy jest obiekt o podanym loginie w liscie obiektow
	 bool CzyJestLogin(list<User> UsersParam, std::string Szukanylogin); 
	 User gracz(ID ,nazwa, login, haslo);


	//funkcja statyczna wywo³ywana przy ka¿dym zapytaniu
	static int callback(void *NotUsed, int argc, char **argv, char **azColName){

		if(CzyInsert==0){
			// pêtla popbieraj¹ca dane ze wszystkich kolumn
		   for(int i=0; i<argc; i++){

			   if(i == 0)
				   ID =argv[i];
			   if(i == 1)
				   nazwa =argv[i];
			   if(i == 2)
				   login =argv[i];
			   if(i == 3)
				   haslo =argv[i];
				  		    
			 }
		   if(!CzyJestLogin(Users, login)){
			    //dodwanie u¿ytkowników do listy
			   gracz.ID =ID;
			    gracz.Nazwa = nazwa;
				gracz.Login =login;
				gracz.Haslo = haslo;

			   Users.push_back(gracz);
		   }

		}
		else{

		   for(int i=0; i<argc; i++){

				  		    
			 }
		
		}
		
		   return 0;
	}	




		 bool CzyJestLogin(list<User> UsersParam, std::string Szukanylogin){

			
			for (j = UsersParam.begin(); j != UsersParam.end(); j++)
				  {
								
					 if((*j).Login ==Szukanylogin)
						return 1;
				}

			 return 0;
		 }

}