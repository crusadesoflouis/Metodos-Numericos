import numpy as np
import csv
k = 2
rand = True
matrix = [[] for i in range(41)]
with open('test.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            pathid = int(row[1])-1
            matrix[pathid].append(row[0])
            row = reader.next()
    except StopIteration:

        with open('k_elements_traine.csv', 'wb') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',quotechar='|', quoting=csv.QUOTE_MINIMAL)
            if rand:
                for i in range(0,len(matrix)):
                    a = np.random.choice(matrix[i], k,replace=False)
                    for j in range(0,len(a)):
                        writer.writerow([a[j],str(i+1),''])
            else:
                for i in range(0,len(matrix)):
                    for j in range(0,k):
                        writer.writerow([matrix[i][j],str(i+1),''])
