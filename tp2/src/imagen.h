#ifndef _imagen_h__

#include <math.h>
#include <string>
#include <vector>
#include "ppmloader.h"

using namespace std;

typedef unsigned char uchar;

class imagen{
  public:
    imagen(string nombre, int identificador){
      id = identificador;
      ruta = nombre;
      uchar *data = NULL;
      width = 0;
      height = 0;
      PPM_LOADER_PIXEL_TYPE pt = PPM_LOADER_PIXEL_TYPE_INVALID;
      LoadPPMFile(&data, &width, &height, &pt, ruta.c_str());
      for (int i = 0; i < width*height; ++i){
        datos.push_back((float)data[i]);
      }
      // delete [] data;
    }

    ~imagen(){
    }

    int getId(){
      return id;
    }

    string getPath(){
      return ruta;
    }

    float distancia(imagen img){
      float respuesta = 0;
      for (unsigned int i = 0; i < this->tamanio(); i++) {
        respuesta += (img.datos[i]-this->datos[i])*(img.datos[i]-this->datos[i]);
      }
      return sqrt(respuesta);
    }

    unsigned int tamanio(){
      return height*width;
    }

    vector<float> data(){
      return datos;
    }

    void setData(vector<vector<float>> M_datos){
      height = M_datos.size();
      width = M_datos[0].size();
      for (unsigned int i = 0; i < M_datos.size(); ++i){
        for (unsigned int j = 0; j < M_datos[i].size(); ++j){
          datos[i+j] = M_datos[i][j];
        }
      }
    }

    void calcularXRaya(vector<float> mu,int cantidadDeImagenes){
      for(unsigned int i = 0; i < this->tamanio(); ++i){
        datos[i] = (datos[i]-mu[i])/sqrt(cantidadDeImagenes-1);
      }
    }

  private:
    string ruta;
    vector<float> datos;
    int height;
    int width;
    int id;
    PPM_LOADER_PIXEL_TYPE pt;

  protected:

};

#endif
