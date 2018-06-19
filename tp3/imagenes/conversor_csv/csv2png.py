from numpy import genfromtxt
import scipy.misc
import sys
import os
import csv
import pydicom
from tifffile import imsave
if len(sys.argv) < 3:
    print("Correr python csv_converter.py <carpeta_imagenes> <carpeta_output>.")
    print("Por ejemplo: python csv_converter.py imagenes/ imagenes_convertidas/")
    exit(0)
input_folder = sys.argv[1]
output_folder = sys.argv[2]
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
    scipy.misc.imsave(file+'.png', my_data)
    # imsave('test.tif', my_data)
