#include "matrix.h"

double EPSILON = 1e-10;

random_device randomDevice;
mt19937 generator(randomDevice());

double dame_ruido(int distribucion, double param1, double param2) {

    uniform_real_distribution<double> unif(param1, param2);  // rango [param1,param2]
    std::normal_distribution<double> norm(param1, param2);      // (mean,desvStandart)
    std::poisson_distribution<int> poisson(param1);             // lambda = param 1
    double x = 0;
    switch (distribucion) {
        case 0:
            x = norm(randomDevice);
            break;
        case 1:
            x = unif(randomDevice);
            break;
        case 2:
            x = poisson(randomDevice);
            break;
    }
    return x;
}

matrix matrix::copiar_con_ruido(int tipo_ruido, double param1, double param2) {
    matrix B(dame_filas(), dame_columnas());
    for (size_t i = 0; i < dame_filas(); i++) {
        for (size_t j = 0; j < dame_columnas(); j++) {
            double valor = dame_elem_matrix(i, j);
            //TODO redondear a enteros en esta funcion
            valor = valor + dame_ruido(tipo_ruido, param1, param2);
            B.agregar_elemento(i, j, valor);
        }
    }
    return B;
}

unsigned long int matrix::media_matrix(){
  unsigned long int sumatoria = 0;
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      sumatoria += matriz[i][j];
    }
  }
  return sumatoria/(filas*columnas);
}

//funciones auxiliares
double norma_euclidea_cuadrada(matrix &A, matrix &B) {
    matrix R(1, 1);
    R.multiplicacion(A, B);
    return R.dame_elem_matrix(0, 0);
}

double norma_2(matrix &A) {
    assert(A.dame_columnas() == 1);
    double sumatoria = 0;
    for (size_t i = 0; i < A.dame_filas(); i++) {
        sumatoria = sumatoria + pow(A.dame_elem_matrix(i, 0), 2);
    }
    return sqrt(sumatoria);
}

matrix crear_canonico(uint filas, uint i) {
    matrix a(filas, 1);
    a.agregar_elemento(i, 0, 1);
    return a;
}

double matrix::metodo_potencia(matrix &x, int repeticiones, matrix &autovector) {
    matrix v = x;
    unsigned int i = 0;
    double autovalor = 0;
    do {

        autovector.multiplicacion((*this), v);
        autovector.normalizar_2();
        v = autovector;

        matrix transpuesta_v = v.trasponer();
        double norma_cuadrada = norma_euclidea_cuadrada(transpuesta_v, v);

        matrix C((*this).dame_filas(), 1);
        C.multiplicacion((*this), v);
        matrix D(1, 1);
        D.multiplicacion(transpuesta_v, C);

        autovector = v;

        D.division_escalar(norma_cuadrada);
        autovalor = D.dame_elem_matrix(0, 0);
        ++i;
    } while (i < repeticiones && !verificacion(autovector, autovalor));

    return autovalor;
}

// constructor de una matrix de tamaño n llena de ceros

matrix::~matrix() {}

  matrix::matrix(string matrizArchivo, string dimensionArchivo){
  fstream archivo_matriz;
  fstream archivo_dimension;
  archivo_matriz.open(matrizArchivo);
  archivo_dimension.open(dimensionArchivo);
  archivo_dimension >> filas;
  columnas = 1;
  string valor;
    matriz.resize(filas);
    for (size_t i = 0; i < filas; i++) {
      for (size_t j = 0; j < columnas; j++) {
        if(j != columnas - 1){
          getline (archivo_matriz,valor, ',' );
          matriz[i].push_back((double) atof(valor.c_str()));
        }else{
          getline (archivo_matriz,valor, '\n' );
          matriz[i].push_back((double) atof(valor.c_str()));
        }
      }
    }
    archivo_matriz.close();
    archivo_dimension.close();
 }


matrix::matrix(unsigned int filas, unsigned int columnas) {

    matriz.resize(filas);
    for (unsigned int i = 0; i < filas; i++) {
        matriz[i].resize(columnas);
    }
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            matriz[i][j] = 0;
        }
    }
    this->filas = filas;
    this->columnas = columnas;
}

matrix::matrix(string nombreArchivo) {
    fstream archivo;
    archivo.open(nombreArchivo);
    uchar *data = NULL;
    int width = 0;
    int height = 0;
    PPM_LOADER_PIXEL_TYPE pt = PPM_LOADER_PIXEL_TYPE_INVALID;
    LoadPPMFile(&data, &width, &height, &pt, nombreArchivo.c_str());
    columnas = width;
    filas = height;
    matriz.resize(filas);
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            matriz[i].push_back((double) data[(columnas * i) + j]);
        }
    }
    archivo.close();
}

matrix matrix::reducir_tamano() {
    matrix res(filas / 2, columnas / 2);
    for (uint i = 0; i < filas; i += 2) {
        for (uint j = 0; j < columnas; j += 2) {
            double suma = matriz[i][j] + matriz[i + 1][j] + matriz[i][j + 1] + matriz[i + 1][j + 1];
            //TODO: PREGUNTAR MATIAS CASTEO A INT.
            res.agregar_elemento(i / 2, j / 2, suma / 4);
        }
    }
    return res;
}

matrix matrix::discretizacion() {
    auto n = (int) sqrt(dame_columnas());
    matrix A(dame_filas(), (dame_columnas() / 2));
    for (uint i = 0; i < dame_filas(); ++i) {
        for (uint j = 0; j < dame_columnas(); j += 2) {
            A.agregar_elemento(i, j / 2, (dame_elem_matrix(i, j) + dame_elem_matrix(i, j + 1)));
        }
    }
    matrix B(dame_filas(), dame_columnas() / 4);
    for (uint i = 0; i < A.dame_filas(); ++i) {
        for (uint j = 0; j < n / 2; j++) {
            for (uint k = 0; k < n / 2; ++k) {
                B.agregar_elemento(i, (n / 2) * j + k,
                                   A.dame_elem_matrix(i, n * j + k) + A.dame_elem_matrix(i, (n * j) + k + (n / 2)));
            }
        }
    }
    return B;
}


unsigned int matrix::dame_filas() {
    return this->filas;
}

unsigned int matrix::dame_columnas() {
    return this->columnas;
}

matrix matrix::trasponer() {
    matrix traspuesta = matrix(this->columnas, this->filas);
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            traspuesta.agregar_elemento(j, i, dame_elem_matrix(i, j));
        }
    }
    return traspuesta;
}


void matrix::division_escalar(double escalar) {
    //cout << escalar << "\n";
    //assert(abs(escalar) > EPSILON);
    for (size_t i = 0; i < dame_filas(); i++) {
        for (size_t j = 0; j < dame_columnas(); j++) {
            double division = dame_elem_matrix(i, j) / escalar;
            agregar_elemento(i, j, division);
        }
    }
}


void matrix::multiplicacion_escalar(double escalar) {
    //cout << escalar << "\n";
    //assert(abs(escalar) > EPSILON);
    for (size_t i = 0; i < dame_filas(); i++) {
        for (size_t j = 0; j < dame_columnas(); j++) {
            double division = dame_elem_matrix(i, j) * escalar;
            agregar_elemento(i, j, division);
        }
    }
}

double producto_interno(matrix &A, matrix &B, unsigned int fila, unsigned int columna) {
    double resultado = 0;
    for (size_t i = 0; i < A.dame_columnas(); i++) {
        resultado = resultado + A.dame_elem_matrix(fila, i) * B.dame_elem_matrix(i, columna);
    }
    return resultado;
}

void matrix::multiplicacion(matrix &A, matrix &B) {
    assert(A.dame_columnas() == B.dame_filas());
    for (size_t i = 0; i < this->dame_filas(); i++) {
        for (size_t j = 0; j < this->dame_columnas(); j++) {
            this->agregar_elemento(i, j, producto_interno(A, B, i, j));
        }
    }
}

void matrix::mostrar() {
    std::cout << '\n';
    for (unsigned int i = 0; i < filas; i++) {
        for (unsigned int j = 0; j < columnas; j++) {
            std::cout << dame_elem_matrix(i, j) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

double matrix::dame_elem_matrix(unsigned int fila, unsigned int columna) {
    return matriz[fila][columna];
}


void matrix::agregar_elemento(uint fila, uint columna, double elemento) {
    if (abs(elemento) < EPSILON) {
        matriz[fila][columna] = 0;
    } else {
        matriz[fila][columna] = elemento;
    }
}


void matrix::normalizar_2() {
    assert(columnas == 1);
    double norma = norma_2(*this);
    division_escalar(norma);
}

bool matrix::verificacion(matrix autovector, double autovalor) {
    matrix a(autovector.dame_filas(), 1);
    a.multiplicacion((*this), autovector),
            autovector.multiplicacion_escalar(autovalor);
    return autovector.comparar(a);
}

bool matrix::comparar(matrix &b) {
    matrix a(*this);
    a.restar(b);
    a.absoluto();
    for (size_t i = 0; i < a.dame_filas(); i++) {
        for (size_t j = 0; j < a.dame_columnas(); j++) {
            double elemento = a.dame_elem_matrix(i, j);
            if (elemento >= EPSILON) {
                return false;
            }
        }
    }
    return true;
}

void matrix::restar(matrix &A) {
    assert(dame_filas() == A.dame_filas());
    assert(dame_columnas() == A.dame_columnas());
    for (size_t i = 0; i < dame_filas(); i++) {
        for (size_t j = 0; j < dame_columnas(); j++) {
            double elemento = A.dame_elem_matrix(i, j);
            elemento = dame_elem_matrix(i, j) - elemento;
            agregar_elemento(i, j, elemento);
        }
    }
}

void matrix::suma(matrix &A) {
    assert(dame_filas() == A.dame_filas());
    assert(dame_columnas() == A.dame_columnas());
    for (size_t i = 0; i < dame_filas(); i++) {
        for (size_t j = 0; j < dame_columnas(); j++) {
            double elemento = A.dame_elem_matrix(i, j);
            elemento = dame_elem_matrix(i, j) + elemento;
            agregar_elemento(i, j, elemento);
        }
    }
}


void matrix::absoluto() {
    for (size_t i = 0; i < dame_filas(); i++) {
        for (size_t j = 0; j < dame_columnas(); j++) {
            double elemento = abs(dame_elem_matrix(i, j));
            agregar_elemento(i, j, elemento);
        }
    }
}

void matrix::deflacion(matrix &autovector, double autovalor) {
    autovector.normalizar_2();
    matrix autovector_traspuesto = autovector.trasponer();
    matrix B(dame_filas(), dame_columnas());
    B.multiplicacion(autovector, autovector_traspuesto);
    B.multiplicacion_escalar(autovalor);
    restar(B);
}


void matrix::generacion_U_D(matrix &U, matrix &D, int alfa) {
    assert(dame_filas() == dame_columnas());
    assert(dame_filas() == U.dame_columnas());
    assert(U.dame_filas() == U.dame_columnas());
    assert(D.dame_filas() == D.dame_columnas());
    assert(D.dame_filas() == U.dame_columnas());

    matrix autovector(dame_filas(), 1);
    matrix x_0(dame_filas(), 1);
    for (size_t j = 0; j < x_0.dame_filas(); j++) {
        x_0.agregar_elemento(j, 0, 1);
    }
    x_0.normalizar_2();
    double autovalor;
    int i = 0;
    bool salir = true;
    while (i < alfa && salir) {
        //genera vector random
        // TODO: hacer un vector inicial con la media de la matriz
        autovalor = this->metodo_potencia(x_0, 500, autovector);
        //si no son parecidos, cambiamos la semilla del vector
        //hacer deflacion
        if (sqrt(autovalor) > EPSILON) {
            U.rellenar_columna_con_vector(i, autovector);
            D.agregar_elemento(i, i, autovalor);
            this->deflacion(autovector, autovalor);
            cout << i << endl;
            i++;
        } else {
            salir = false;
        }
    }
}

void matrix::rellenar_columna_con_vector(uint columna, matrix &V) {
    //asume que X (this) viene ya traspuesto
    //cout << "filas de V " << V.dame_filas() << "filas de this " << this->dame_filas() << endl;
    V.normalizar_2();
    assert(V.dame_columnas() == 1);
    assert(V.dame_filas() == dame_filas());
    for (size_t i = 0; i < dame_filas(); i++) {
        agregar_elemento(i, columna, V.dame_elem_matrix(i, 0));
    }
}

//devuelve una matrix de nxm
void matrix::conversionUaV(matrix &V, matrix &D, matrix &U) {
    for (size_t i = 0; i < U.dame_columnas(); i++) {
        matrix e_i = crear_canonico(V.dame_filas(), i);
        // e_i.mostrar();
        matrix v_i(V.dame_filas(), 1);
        v_i.multiplicacion(V, e_i);
        // u_i.mostrar();
        // D.mostrar();
        double d_i_i = D.dame_elem_matrix(i, i);
        // std::cout << "d " << d_i_i<<'\n';
        // mostrar();
        matrix u_i(dame_filas(), 1);
        u_i.multiplicacion((*this), v_i);
        // v_i.mostrar();
        u_i.division_escalar(d_i_i);
        //v_i.normalizar_2();
        U.rellenar_columna_con_vector(i, u_i);
    }
}

//crear la matriz de valores singulares
void matrix::matriz_Sigma(matrix &D) {
    for (size_t i = 0; i < this->dame_filas(); i++) {
        this->agregar_elemento(i, i, sqrt(abs(D.dame_elem_matrix(i, i))));
    }
}

int matrix::dame_rango() {
    int rango = 0;
    for (size_t i = 0; i < this->dame_filas(); i++) {
        if (this->dame_elem_matrix(i, i) != 0) {
            rango++;
        }
    }
    return rango;
}

//recibe U^t, S, V normal,
void matrix::SCML(matrix &U, matrix &S, matrix &V, matrix &b) {
    double lamda = 0;
    for (uint i = 0; i < U.dame_filas(); ++i) {
        lamda = producto_interno(U, b, i, 0);
        lamda = lamda / S.dame_elem_matrix(i, i);
        matrix e_i = crear_canonico(V.dame_columnas(), i);
        // e_i.mostrar();
        matrix v_i(V.dame_filas(), 1);
        v_i.multiplicacion(V, e_i);
        v_i.multiplicacion_escalar(lamda);
        suma(v_i);
    }
}

void matrix::Cuadrados_Minimos(matrix &b, matrix &res) {

    matrix B_t = trasponer();
    //B_t.mostrar();

    matrix A(B_t.dame_filas(), dame_columnas());
    A.multiplicacion(B_t, *this);
    matrix D(A.dame_filas(), A.dame_columnas());
    matrix V(A.dame_filas(), A.dame_columnas());
    A.generacion_U_D(V, D, A.dame_columnas());

    //D.mostrar();
    //U.mostrar();

    matrix S(D.dame_filas(), D.dame_columnas());
    S.matriz_Sigma(D);
    //S.mostrar();

    matrix U(dame_filas(), S.dame_rango());

    cout << "conversionUaV" << endl;
    conversionUaV(V, S, U);
    //V.mostrar();

    //U.mostrar();
    U = U.trasponer();

    cout << "fase solucion" << endl;
    res.SCML(U, S, V, b);
}

double matrix::ECM(matrix &vel_discreta) {
    double res = 0;
    restar(vel_discreta);
    matrix vector_error_t(1, dame_filas());
    vector_error_t = trasponer();
    res = producto_interno(vector_error_t, *this, 0, 0);
    res = res / dame_filas();
    return res;
}


vector<vector<double>> matrix::dameMatriz() {
    return matriz;
}

void matrix::pasar_vector_matriz(vector<double> &velocidades) {
    for (uint i = 0; i < dame_filas(); ++i) {
        matriz[i][0] = velocidades[i];
    }
}

void matrix::pasar_matriz_vector(matrix &imagen_ori) {
    for (uint i = 0; i < imagen_ori.dame_filas(); ++i) {
        for (uint j = 0; j < imagen_ori.dame_columnas(); ++j) {
            matriz[(imagen_ori.dame_filas() * i) + j][0] = imagen_ori.dame_elem_matrix(i, j);
        }
    }
}

void matrix::guardarEnImagen(string nombreArchivo) {
    double min = matriz[0][0];
    double max = matriz[0][0];
    for (int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j){
            if (min > matriz[i][j]){
                min = matriz[i][j];
            }
            if (max < matriz[i][j]){
                max = matriz[i][j];
            }
        }
    }
    double diferencia = max-min;
    for (int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j){
            matriz[i][j] -= min;
            matriz[i][j] /= diferencia;
            matriz[i][j] *= 255;
        }
    }
    PPM_LOADER_PIXEL_TYPE pt = PPM_LOADER_PIXEL_TYPE_GRAY_8B;
    auto *datos = new uchar[filas * columnas];
    for (uint i = 0; i < filas; ++i) {
        for (uint j = 0; j < columnas; ++j) {
            datos[(columnas * i) + j] = (uchar) matriz[i][j];
        }
    }
    SavePPMFile(nombreArchivo.c_str(), datos, sqrt(filas), sqrt(filas), pt);
}

void matrix::archivoCSV(string nombreArchivo) {
    fstream archivo(nombreArchivo, ios::out);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (j != 0) {
                archivo << ",";
            }
            archivo << matriz[i][j];
        }
        archivo << endl;
    }
    archivo.close();
}


void matrix::vector_matriz(matrix &imagen_ori) {
    int n = filas;
    int resto = 0;
    for (int i = 0; i < imagen_ori.dame_filas(); ++i) {
        resto = i / n;
        matriz[resto][i - (n * resto)] = imagen_ori.dame_elem_matrix(i, 0);
    }
}
