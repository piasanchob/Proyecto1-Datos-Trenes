#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#include "claseUsuario.h"
#include "claseAdmin.h"
#include <fstream>
#include "clase_lista.h"

/*Aquí llamo a los archivos*/

std::fstream archivo_administradores("Administradores.txt");
std::fstream archivo_ciudades("Ciudades.txt"); 
std::fstream archivo_conexiones("Conexiones.txt");
std::fstream archivo_paises("Paises.txt"); 
std::fstream archivo_rutas("Rutas.txt"); 
std::fstream archivo_tipotren("TipoTren.txt"); 
std::fstream archivo_trenes("Trenes.txt"); 
std::fstream archivo_usuarios("Usuarios.txt"); 


lista lista_administradores; //circular
lista lista_ciudades; // doble circular
lista lista_conexiones; // doble
lista lista_paises; // doble circular
lista lista_rutas; // simple
lista lista_tipotren; // doble
lista lista_trenes; // simple
lista lista_ususarios; // doble


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
	
	

