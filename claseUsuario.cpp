#include <iostream>
using namespace std;



class Usuario{
	public:
	void usuariomenu();
	int consultarPaises();
	int consultarCiudades();
	int consultarConexiones();
	int consultarTrenes();
	int consultarPrecios();
	int consultarAsientos();
	int consultarRutas();
	
};

int Usuario::consultarPaises(){
	cout<<"1";
	return 1;
}
int Usuario::consultarCiudades(){
	 cout<<"2";
	 return 2;
}
int Usuario::consultarConexiones(){
	cout<<"3";
	return 3;
}
int Usuario::consultarTrenes(){
	cout<<"4";
	return 4;
}
int Usuario::consultarPrecios(){
	cout<<"5";
	return 5;
}
int Usuario::consultarAsientos(){
	cout<<"6";
	return 6;
}
int Usuario::consultarRutas(){
	cout<<"7";
	return 7;
}

void Usuario::usuariomenu(){
	int numberusuario;
	cout<<"1. Consultar Paises";
	cout<<" "<<endl;  
	cout<<"2. Consultar Ciudades";
	cout<<" "<<endl;  
	cout<<"3. Consultar Conexiones";
	cout<<" "<<endl;  
	cout<<"4. Consultar Trenes";
	cout<<" "<<endl;  
	cout<<"5. Consultar Precios";
	cout<<" "<<endl;  
	cout<<"6. Consultar numero de asientos disponibles";
	cout<<" "<<endl;  
	cout<<"7. Consultar Rutas";
	cout<<" "<<endl;  
	//cout<<"8. Regresar"; al final de cada funcion hay que poner usuariomenu()
	cout<<"8. Salir";
	cout<<" "<<endl;  
	cout<<"Digite una opcion ";
	cin >> numberusuario;
	if (numberusuario == 1){
		consultarPaises();
	}
	if (numberusuario == 2){
		consultarCiudades();
	}
	if (numberusuario == 3){
		consultarConexiones();
	}
	if (numberusuario == 4){
		consultarTrenes();
    }
    if (numberusuario == 5){
		consultarPrecios();
	}
	if (numberusuario == 6){
		consultarAsientos();
	}
	if (numberusuario == 7){
		consultarRutas();
	}
	if (numberusuario == 8){
		exit(0);
	}
}



