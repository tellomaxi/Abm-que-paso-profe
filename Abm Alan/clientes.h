typedef struct
{
int codigoCliente;
char nombre[51];
char sexo[20];
char tel[30];
int isEmpty;

}eClientes;

typedef struct
{

int id;
char descripcion[51];

}eCategoria;

typedef struct
{
int codigo;
char descripcion[51];
int importe;
int idCategoria;

}eJuegos;


void inicializarClientes(eClientes lista[], int tam);

void cargarCategorias(eCategoria categorias[], int tamc);

void listarCategorias(eCategoria categorias[], int tam);

int buscarLibre(eClientes lista[], int tam);

int buscarCliente(eClientes lista[], int tam, int codigo);

void altaCliente(eClientes lista[], int tam,int* pId);

void bajaCliente(eClientes listado[], int tam);

void mostrarCliente (eClientes clienteAmostrar);

void mostrarClientes (eClientes listado[], int tam);

void modificaCliente(eClientes listado[], int tam);

int menu();

void hardCordearJuegos(eJuegos juegos[], int tamjuegos);

void listarJuegos(eJuegos arraydejuegos[], int tamj);

void hardCordearClientes(eClientes arraydeclientes[], int tamclientes);

void ordenarClientesPorSexoYnombre(eClientes arraydeclientes[], int tamc);
