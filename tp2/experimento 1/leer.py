import numpy as np
import matplotlib.pyplot as plt
import csv
from sklearn.metrics import accuracy_score
from sklearn.metrics import recall_score
from sklearn.metrics import precision_score



acurracy    =  []
recall      =  []
precision   =  []

for k in range(1,10):
    print k
    true = []
    pred = []
    acy_prom = []
    recl_prom = []
    prec_prom = []
    with open('true_'+str(k)+'.csv', 'rb') as csvfile:
        reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
        try:
            row = reader.next()
            while True:
                true.append(int(row[1]))
                row = reader.next()
        except StopIteration:
            print ""
    with open(str(k)+'_pred.csv', 'rb') as csvfile:
        reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
        try:
            row = reader.next()
            while True:
                pred.append(int(row[1]))
                row = reader.next()
        except StopIteration:
            print ""
        acy_prom.append(accuracy_score(true, pred))
        recl_prom.append(precision_score(true,pred, average='macro'))
        prec_prom.append(recall_score(true, pred, average='macro'))

        print acy_prom
        print recl_prom
        print prec_prom
        acurracy.append(acy_prom[0])
        recall.append(recl_prom[0])
        precision.append(prec_prom[0])


# print "acurracy"

acurracy.reverse()
recall.reverse()
precision.reverse()
print acurracy
print recall
print precision


# print np.mean(acurracy)
# print np.mean(recall)
# print np.mean(precision)

N = 9
ind = np.arange(N)  # the x locations for the groups
width = 0.27       # the width of the bars
fig = plt.figure()
ax = fig.add_subplot(111)
yvals = acurracy
rects1 = ax.bar(ind, yvals, width, color='#424147')
zvals = precision
rects2 = ax.bar(ind+width, zvals, width, color='#72bac3')
kvals = recall
rects3 = ax.bar(ind+width*2, kvals, width, color='#de511c')
ax.set_ylabel('%')
ax.set_xlabel('cantidad de elementos de entrenamiento')
ax.set_xticks(ind+width)
ax.set_xticklabels( ('9', '8', '7', '6', '5','4', '3', '2', '1') )
ax.legend( (rects1[0], rects2[0], rects3[0]), ('acurracy', 'precision', 'recall') )
plt.show()
#
