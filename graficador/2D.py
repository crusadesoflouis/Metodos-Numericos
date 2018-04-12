import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
elementos = range(50,1550,50)
TamanioMatriz = []
CantidadElementos = []
Tiempo = []
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
        if j == 0.3:
            Tiempo.append(float(time))
            CantidadElementos.append(int(elements))
df = pd.DataFrame({'elementos': elementos,'Tiempo': Tiempo, 'CantidadElementos':CantidadElementos})
plt.clf()
df.plot(x='elementos',logy=True)
plt.ylabel('Tiempo (microsegundos)')
plt.show()
