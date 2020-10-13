//Clase lista destinos (ciudades, paises, conexiones)


class nodo_destinos{
	public:
		
		nodo_destinos(string codpais, string nombrepais) // constructor de nodos de paises
		{
			codigo_pais = codpais;
			nombre_pais = nombrepais;
			
			siguiente = NULL;
			anterior = NULL;
			ciudad = NULL;
		}
		
		
		nodo_destinos(string codpais, string codciud, string nombreciudad) // constructor de nodos de ciudades
		{
			codigo_pais = codpais;
			codigo_ciudad = codciud;
			nombre_ciudad = nombreciudad;
			
			siguiente = NULL;
			anterior = NULL;
			pais = NULL;
			conexion = NULL;
		}
		
		
		nodo_destinos(string codpais, string codciud, string codconex, string codpais2, string codciud2, string tiempo) // constructor de nodo de conexiones
		{
			codigo_pais_origen = codpais;
			codigo_ciudad_origen = codciud;
			codigo_conexion = codconex;
			codigo_pais_destino = codpais2;
			codigo_ciudad_destino = codciud2;
			tiempo = tiempo;
			
			siguiente = NULL;
			anterior = NULL;
			ciudad = NULL;
		}
		
		
			nodo_destinos *siguiente;
			nodo_destinos *anterior;
			nodo_destinos *ciudad;
			nodo_destinos *pais;
			nodo_destinos *conexion;
			
			string codigo_pais;
			string codigo_ciudad;
			string codigo_conexion;
			string codigo_pais_origen;
			string codigo_ciudad_origen;
			string codigo_pais_destino;
			string codigo_ciudad_destino;
			string tiempo;
			
			string nombre_pais;
			string nombre_ciudad;
			
			friend class lista;
			//friend class insercion;
			
};

typedef nodo_destinos *pnodo_destinos;


