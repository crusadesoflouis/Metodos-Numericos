from numpy import genfromtxt
import scipy.misc
import sys
import os
import csv
import pydicom
from tifffile import imsave
if len(sys.argv) < 2:
    print("Correr python csv2png.py <carpeta_imagenes>.")
    print("Por ejemplo: python csv2png.py csv/")
    print("Aclaracion: las imagenes van a estar en el directorio pasado como parametro")
    exit(0)
input_folder = sys.argv[1]
# output_folder = sys.argv[2]
def createFileList(myDir, format='.csv'):
    fileList = []
    for root, dirs, files in os.walk(myDir, topdown=False):
        for name in files:
            if name.endswith(format):
                fullName = os.path.join(root, name)
                fileList.append(fullName)
    return fileList
myFileList = createFileList(input_folder,".csv")
for file in myFileList:
    print(file)
    my_data = genfromtxt(file, delimiter=',')
    save_path = "pgm/"
    scipy.misc.imsave(file[:-4]+'.pgm', my_data)
