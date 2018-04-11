import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np

Complete = []
Path = []
Bipartite = []
Star = []

longitud = 50
Complete = [0 + (2**n) for n in range(0,longitud)]
Path = [0 + (n**10) for n in range(0,longitud)]
Bipartite = [0 + (5*n) for n in range(0,longitud)]
Star = [0 + (n**2) for n in range(0,longitud)]

elementos = range(0,longitud)


# print len(Complete)
# print len(Path)
# print len(Bipartite)
# print len(Star)
# print len(elementos)
print Star
print Path

df = pd.DataFrame({'elementos': elementos,'Complete':Complete,'Path':Path,'Bipartite':Bipartite,'Star': Star})
plt.clf()
df.plot(x='elementos',logy=True)
plt.ylabel('Tiempo (microsegundos)')
plt.show()
