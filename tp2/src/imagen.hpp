#ifndef _imagen_h__

#include <math.h>
#include "../ppmloader/ppmloader.cpp"

using namespace std;

typedef unsigned char uchar;

class imagen{
  public:
    imagen(string nombre, int identificador){
      id = identificador;
      ruta = nombre;
      datos = NULL;
      width = 0;
      height = 0;
      PPM_LOADER_PIXEL_TYPE pt = PPM_LOADER_PIXEL_TYPE_INVALID;
      LoadPPMFile(&datos, &width, &height, &pt, ruta.c_str());
      
    }

    void guardar(){
    	SavePPMFile("prueba.ppm",datos,width,height,pt,NULL);
    }

    ~imagen(){
      //delete [] datos;
    }

    int getId(){
      return id;
    }

    string getPath(){
      return ruta;
    }

    double distancia(imagen img){
      double respuesta = 0;
      for (size_t i = 0; i < this->tamanio(); i++) {
        respuesta += (img.datos[i]-this->datos[i])*(img.datos[i]-this->datos[i]);
      }
      return sqrt(respuesta);
    }

    int tamanio(){
      return height*width;
    }

    double* data(){
      return datos;
    }

  private:
    string ruta;
    double datos;
    int height;
    int width;
    int id;
    PPM_LOADER_PIXEL_TYPE pt;

  protected:

};

#endif
