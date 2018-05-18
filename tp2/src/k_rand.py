import numpy as np
import csv
k = 5
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

        with open('5_elements_0.csv', 'wb') as csvfile:
            writer_test = csv.writer(csvfile, delimiter=',',quotechar='|', quoting=csv.QUOTE_MINIMAL)
            with open('5_elements_1.csv', 'wb') as csvfile:
                writer_traine = csv.writer(csvfile, delimiter=',',quotechar='|', quoting=csv.QUOTE_MINIMAL)
                if rand:
                    for i in range(0,len(matrix)):
                        a = []
                        a = np.random.choice(matrix[i], k,replace=False)
                        for j in range(0,len(a)):
                            writer_traine.writerow([a[j],str(i+1),''])
                        for j in range(0,len(a)):
                            matrix[i].remove(a[j])
                        for j in range(0,len(matrix[i])):
                            writer_test.writerow([matrix[i][j],str(i+1),''])
                else:
                    for i in range(0,len(matrix)):
                        a = []
                        for j in range(0,k):
                            a.append(matrix[i][j])
                        for j in range(0,len(a)):
                            matrix[i].remove(a[j])
                        for j in range(0,len(a)):
                            writer_traine.writerow([a[j],str(i+1),''])
                        for j in range(0,len(matrix[i])):
                            writer_test.writerow([matrix[i][j],str(i+1),''])
