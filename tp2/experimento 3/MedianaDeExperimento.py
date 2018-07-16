import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
f = open("time_out.txt","r")

corrida = []
for k in range(1,10):
    Apromediar = []
    trash = f.readline()
    for iteration in range(0,10):
        trash = f.readline()
        trash = f.readline()
        trash = f.readline()
        trash = f.readline()
        Apromediar.append(float(f.readline()))
    # print corrida.append(np.median(Apromediar))
    corrida.append(np.mean(Apromediar))
print corrida

Caras_entrenamiento = range(1,10)

df = pd.DataFrame({'Caras_entrenamiento': Caras_entrenamiento,'corrida':corrida})
plt.clf()
df.plot(x='Caras_entrenamiento')
plt.ylabel('Tiempo (Segundos)')
plt.show()
