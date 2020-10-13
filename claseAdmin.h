#include <iostream>
using namespace std;

class Admin{
	public:
	void adminmenu();
	int Insertar();
	int Eliminar();
	int Modificar();
	int registrarTrenes();
	int consultarCiudades();
	int consultarConexiones();
	int consultarTrenes();
	int consultarPrecios();
	int consultarRutas();
	int consultarPaises();
	int ultimoIngreso();
	int ultimoEliminado();
	int asientosDisponibles();
	
};

void Admin::adminmenu(){
	int numberadmin;
	cout<<"Mantenimiento de Base de Datos";
	cout<<" "<<endl;
	cout<<"1. Insertar";
	cout<<" "<<endl;
	cout<<"2. Eliminar";
	cout<<" "<<endl;
	cout<<"3. Modificar";
	cout<<" "<<endl;
	cout<<"4. Registrar Trenes";
	cout<<" "<<endl;
	cout<<"Reportes";
	cout<<" "<<endl;
	cout<<"5. Consultar Paises";
	cout<<" "<<endl;
	cout<<"6. Consultar Precios";
	cout<<" "<<endl;
	cout<<"7. Consultar Conexiones";
	cout<<" "<<endl;
	cout<<"8. Consultar Ciudades";
	cout<<" "<<endl;
	cout<<"9. Consultar Rutas";
	cout<<" "<<endl;
	cout<<"10. Consultar Trenes";
	cout<<" "<<endl;
	cout<<"11. Ultimo ingresado";
	cout<<" "<<endl;
	cout<<"12. Ultimo eliminado";
	cout<<" "<<endl;
	cout<<"13. Numero de asientos disponibles";
	cout<<" "<<endl;
	//cout<<"8. Regresar"; al final de cada funcion hay que poner usuariomenu()
	cout<<"14. Salir";
	cout<<" "<<endl;
	cout<<"Digite una opcion ";
	cin >> numberadmin;
	if (numberadmin == 1){
		Insertar();
	}
	if (numberadmin == 2){
		Eliminar();
	}
	if (numberadmin == 3){
		Modificar();
	}
	if (numberadmin == 4){
		registrarTrenes();
    }
    if (numberadmin == 5){
		consultarPaises();
	}
	if (numberadmin == 6){
		consultarPrecios();
	}
	if (numberadmin == 7){
		consultarConexiones();
	}
	if (numberadmin == 8){
		consultarCiudades();
	}
	if (numberadmin == 9){
		consultarRutas();
    }
    if (numberadmin == 10){
		consultarTrenes();
    }
    if (numberadmin == 11){
		ultimoIngreso();
    }
    if (numberadmin == 12){
		ultimoEliminado();
    }
    if (numberadmin == 13){
		asientosDisponibles();
    }
    if (numberadmin == 14){
		exit(0);
    }
}
    


int Admin::Insertar(){
	cout<<"1";
	return 1;
}
int Admin::Eliminar(){
	cout<<"2";
	return 2;
}
int Admin::Modificar(){
	cout<<"3";
	return 3;
}
int Admin::registrarTrenes(){
	cout<<"4";
	return 4;
}
int Admin::consultarPaises(){
	cout<<"5";
	return 5;
}
int Admin::consultarCiudades(){
	cout<<"8";
	return 8;
}
int Admin::consultarConexiones(){
	cout<<"7";
	return 8;
}
int Admin::consultarTrenes(){
	cout<<"10";
	return 10;
}
int Admin::consultarPrecios(){
	cout<<"6";
	return 6;
}
int Admin::asientosDisponibles(){
	cout<<"13";
	return 13;
}
int Admin::consultarRutas(){
	cout<<"9";
	return 9;
}
int Admin::ultimoIngreso(){
	cout<<"11";
	return 11;
}
int Admin::ultimoEliminado(){
	cout<<"12";
	return 12;
}



