import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

f = open("arbol_0.25.txt.out2","r")
g = open("arbol_0.50.txt.out2","r")
h = open("arbol_0.75.txt.out2","r")
p_25 = f.readline()
p_50 = g.readline()
p_75 = h.readline()
elementos = range(0,6)

print p_25
print p_50
print p_75
print elementos

arbol_25 = []
arbol_50 = []
arbol_75 = []


for i in range(0,6):
    arbol_25.append(float(f.readline()))
    arbol_50.append(float(g.readline()))
    arbol_75.append(float(h.readline()))
print arbol_25
print arbol_50
print arbol_75

df = pd.DataFrame({'x_i': elementos,'P=0.25': arbol_25, 'P=0.50':arbol_50, 'P=0.75':arbol_75})
plt.clf()
df.plot(x='x_i',logy=False)
plt.ylabel('Ranking')
plt.title('Arbol')
plt.show()





f = open("completo_0.25.txt.out2","r")
g = open("completo_0.50.txt.out2","r")
h = open("completo_0.75.txt.out2","r")
p_25 = f.readline()
p_50 = g.readline()
p_75 = h.readline()
elementos = range(0,8)

print p_25
print p_50
print p_75
print elementos

arbol_25 = []
arbol_50 = []
arbol_75 = []


for i in range(0,8):
    arbol_25.append(float(f.readline()))
    arbol_50.append(float(g.readline()))
    arbol_75.append(float(h.readline()))
print arbol_25
print arbol_50
print arbol_75

df = pd.DataFrame({'x_i': elementos,'P=0.25': arbol_25, 'P=0.50':arbol_50, 'P=0.75':arbol_75})
plt.clf()
df.plot(x='x_i',logy=False)
plt.ylabel('Ranking')
plt.title('Completo')
plt.show()



f = open("completo_con_nodo_0.25.txt.out2","r")
g = open("completo_con_nodo_0.50.txt.out2","r")
h = open("completo_con_nodo_0.75.txt.out2","r")
p_25 = f.readline()
p_50 = g.readline()
p_75 = h.readline()
elementos = range(0,10)

print p_25
print p_50
print p_75
print elementos

arbol_25 = []
arbol_50 = []
arbol_75 = []


for i in range(0,10):
    arbol_25.append(float(f.readline()))
    arbol_50.append(float(g.readline()))
    arbol_75.append(float(h.readline()))
print arbol_25
print arbol_50
print arbol_75

df = pd.DataFrame({'x_i': elementos,'P=0.25': arbol_25, 'P=0.50':arbol_50, 'P=0.75':arbol_75})
plt.clf()
df.plot(x='x_i',logy=False)
plt.ylabel('Ranking')
plt.title('Completo con nodo')
plt.show()




f = open("no_conexo_0.25.txt.out2","r")
g = open("no_conexo_0.50.txt.out2","r")
h = open("no_conexo_0.75.txt.out2","r")
p_25 = f.readline()
p_50 = g.readline()
p_75 = h.readline()
elementos = range(0,8)

print p_25
print p_50
print p_75
print elementos

arbol_25 = []
arbol_50 = []
arbol_75 = []


for i in range(0,8):
    arbol_25.append(float(f.readline()))
    arbol_50.append(float(g.readline()))
    arbol_75.append(float(h.readline()))
print arbol_25
print arbol_50
print arbol_75

df = pd.DataFrame({'x_i': elementos,'P=0.25': arbol_25, 'P=0.50':arbol_50, 'P=0.75':arbol_75})
plt.clf()
df.plot(x='x_i',logy=False)
plt.ylabel('Ranking')
plt.title('no conexo')
plt.show()




f = open("todos_apuntan_0.25.txt.out2","r")
g = open("todos_apuntan_0.50.txt.out2","r")
h = open("todos_apuntan_0.75.txt.out2","r")
p_25 = f.readline()
p_50 = g.readline()
p_75 = h.readline()
elementos = range(0,6)

print p_25
print p_50
print p_75
print elementos

arbol_25 = []
arbol_50 = []
arbol_75 = []


for i in range(0,6):
    arbol_25.append(float(f.readline()))
    arbol_50.append(float(g.readline()))
    arbol_75.append(float(h.readline()))
print arbol_25
print arbol_50
print arbol_75

df = pd.DataFrame({'x_i': elementos,'P=0.25': arbol_25, 'P=0.50':arbol_50, 'P=0.75':arbol_75})
plt.clf()
df.plot(x='x_i',logy=   False)
plt.ylabel('Ranking')
plt.title('todos apuntan')
plt.show()
