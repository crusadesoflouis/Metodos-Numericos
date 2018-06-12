import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d
import math
f = open('estandar.txt','r')
KN = []
longitud = int(f.readline())
f.readline()
longitud = longitud -5;
for i in range(0,longitud):
    KN.append(int(f.readline()))
elementos = range(0, longitud*5,5)

complejidad = [0 + (2**n) for n in range(0,longitud)]
print "elementos"
print len(elementos)
print elementos
print "KN: "
print len(KN)
print KN
print len(complejidad)
print complejidad
df2 = pd.DataFrame()
df2['elementos'] = elementos
df2['Tiempo'] = KN
df2['Complejidad 2^n'] = complejidad
sns.jointplot(df2['Complejidad 2^n'], df2['Tiempo'], kind="reg")
sns.plt.show()
