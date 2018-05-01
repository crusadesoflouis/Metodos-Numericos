import numpy as np
import csv
with open('datos.csv', 'wb') as csvfile:
    fieldnames = ['Tamanio', 'Cantidad_Elementos', 'Densidad','Tiempo']
    base = csv.DictWriter(csvfile, fieldnames=fieldnames)
    base.writeheader()
    f = open("out.txt","r")
    g = open("median.txt","w")
    for i in range(50,1550,50):
        tamanio = f.readline()
        g.write(tamanio)
        for j in [0.05,0.1,0.2,0.3]:
            CantidadElementos = f.readline()
            densidad = f.readline()
            g.write(CantidadElementos)
            g.write(densidad)
            resultados = []
            for k in range(0,10):
                resultados.append(float(f.readline()))
            mean = np.mean(resultados)
            g.write(str(mean)+"\n")
            base.writerow({'Tamanio': tamanio,'Cantidad_Elementos': CantidadElementos,'Densidad':densidad, 'Tiempo': mean})
