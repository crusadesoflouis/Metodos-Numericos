import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

desvio   = []
ecm      = []
f = open("ecm.txt","r")
trash = f.readline()
for i in range(0,20250,250):
    desvio_S = float(f.readline())
    error = float(f.readline())
    desvio.append(desvio_S)
    ecm.append(error)
print desvio
print ecm
df = pd.DataFrame({'desvio': desvio,'ECM':ecm})
# plt.clf()
df.plot(x='desvio', logy = True)
plt.ylabel('ECM')
plt.title('Experimento Con Distribucion Normal')
# with 2 rows and 1 column. Since this subplot will overlap the
# first, the plot (and its axes) previously created, will be removed
# plt.subplot(211)
# plt.subplot(212, facecolor='y') # creates 2nd subplot with yellow background
plt.show()


alfa   = []
ecm         = []
# f = open("ecm.txt","r")
trash = f.readline()
for i in range(0,20250,250):
    desvio_S = float(f.readline())
    error = float(f.readline())
    alfa.append(desvio_S)
    ecm.append(error)
print alfa
print ecm
df = pd.DataFrame({'alfa': alfa,'ECM':ecm})
# plt.clf()
df.plot(x='alfa', logy = True)
plt.ylabel('ECM')
plt.title('Experimento Con Distribucion Uniforme')
# with 2 rows and 1 column. Since this subplot will overlap the
# first, the plot (and its axes) previously created, will be removed
# plt.subplot(211)
# plt.subplot(212, facecolor='y') # creates 2nd subplot with yellow background
plt.show()
