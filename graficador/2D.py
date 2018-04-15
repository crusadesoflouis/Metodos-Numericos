import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
elementos = range(50,1550,50)
TamanioMatriz = []
CantidadElementos = []
Tiempo05 = []
Tiempo10 = []
Tiempo20 = []
Tiempo30 = []
Densidad= []
f = open("median.txt","r")
for i in range(50,1550,50):
    size = f.readline()
    TamanioMatriz.append(int(size))
    for j in [0.05,0.1,0.2,0.3]:
        elements = f.readline()
        density = f.readline()
        time = f.readline()
        Densidad.append(float(density))
        #puseha solo los elementos de una densidad particular
        # Tiempo.append(float(time))
        # CantidadElementos.append(int(elements))
        if j == 0.05:
            Tiempo05.append(float(time))
        if j == 0.1:
            Tiempo10.append(float(time))
        if j == 0.2:
            Tiempo20.append(float(time))
        if j == 0.3:
            Tiempo30.append(float(time))
df = pd.DataFrame({'elementos': elementos,'d:05%': Tiempo05, 'd:10%':Tiempo10, 'd:20%':Tiempo20, 'd:30%':Tiempo30})
plt.clf()
df.plot(x='elementos',logy=True)
plt.ylabel('Tiempo (Segundos)')
plt.show()
