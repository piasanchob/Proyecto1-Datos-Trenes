#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#include "claseUsuario.cpp"
#include "claseAdmin.cpp"






int main(){
	Usuario user;
	int number;
	Admin admin;
	cout<<"Bienvenido!";
	cout<<" "<<endl; 
	cout<<"Si desea ingresar como usuario digite 1, si desea ingresar como administrador digite 2 ";
	cin >> number;
	if (number == 1){ //aquí hay que validar si usuario existe 
		user.usuariomenu();
	}
	
	if (number == 2){
		admin.adminmenu();
	}
	cin.get();
	return 0;
}
	
	

