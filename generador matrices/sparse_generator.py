# import sparse module from SciPy package
from scipy import sparse
# import uniform module to create random numbers
from scipy.stats import uniform
# import NumPy
import numpy as np
#import random
import random as rand

#tamanio de la matriz
n = 10
#densidad en la cantidad de elementos
p= 0.2
#genera un vector de elementos consecutivos
# np.arange(2)

#  np.random.choice (2 es el tamanio de un np.arange(2),1 es la cantidad de elementos que vamos a tomar del conjunto generado
#por np.arange(2), en este caso es solo uno, P = [1,0] es la probabilidad que le vamos a dar a cada elemento)
#de esta forma, estamos generando una distribucion no uniforme, en este caso particular la probabilidad de que salga
#el primer elemento es 1 y el segundo 0 , la funcion devuelve un array con el conjunto resultado del tamanio del segundo argumento
#en este ejemplo devuelve solo un elemento en el vector
# a = np.random.choice(2, 1, p=[1, 0])

cantidadElementos = 0
for i in range(1,n+1):
    for j in range(1,n+1):
        a = np.random.choice(2, 1, p=[1-p,p])
        if int(a) != 0:
            coordenada = str(i) + " " + str(j)
            cantidadElementos = cantidadElementos +1
            print coordenada
print cantidadElementos
