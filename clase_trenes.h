//clase lista trenes

class nodo_trenes{
	public:
		
		nodo_trenes(string codtren, string nombretipotren) //constructor tipo de trenes
		{
			codigo_tren = codtren;
			nombre_tipo:
			nombre_tipo_tren = nombretipotren;
			
			
			siguiente = NULL;
			anterior = NULL;
		}
	
		nodo_trenes(string codtipotren, string codtren, string nombretren, string numasientos, string codruta) // constructor trenes
		{
			codigo_tipo_tren = codtipotren;
			codigo_tren = codtren;
			nombre_tren = nombretren;
			numero_asientos = numasientos;
			codigo_ruta = codruta;	
			
			siguiente = NULL;
		} 
	
		nodo_trenes(string codtipotren, string codtren, string codruta, string codpais, string codciud, string codpais2, string codciud2, string precio) // constructor rutas
		{
			codigo_tipo_tren = codtipotren;
			codigo_tren = codtren;
			codigo_ruta = codruta;
			codigo_pais_origen = codpais;
			codigo_ciudad_origen = codciud;
			codigo_pais_destino = codpais2;
			codigo_ciudad_destino = codciud2;
			precio = precio;		
		}
		
			string codigo_tipo_tren;
			string codigo_tren;
			string codigo_ruta;
			string codigo_pais_origen;
			string codigo_ciudad_origen;
			string codigo_pais_destino;
			string codigo_ciudad_destino;
			string precio;
			string numero_asientos;
			
			string nombre_tipo_tren;
			string nombre_tren;
			
			nodo_trenes *siguiente;
			nodo_trenes *anterior;

	friend class lista;
	friend class insercion;
};

typedef nodo_trenes *pnodo_;
