import numpy as np
import matplotlib.pyplot as plt
import csv
from sklearn.metrics import accuracy_score
from sklearn.metrics import recall_score
from sklearn.metrics import precision_score



acurracy    =  []
recall      =  []
precision   =  []

for k in range(1,6):
    true = []
    pred = []
    acy_prom = []
    recl_prom = []
    prec_prom = []
    with open('test_elements_'+str(k)+'.csv', 'rb') as csvfile:
        reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
        try:
            row = reader.next()
            while True:
                true.append(int(row[1]))
                row = reader.next()
        except StopIteration:
            print ""
    with open('result_'+str(k)+'.csv', 'rb') as csvfile:
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


print np.mean(acurracy)
print np.mean(recall)
print np.mean(precision)


# recall.append(np.mean(recl_prom))
# precision.append(np.mean(prec_prom))
# acurracy.append(np.mean(acy_prom))

        # acurracy.append(np.mean(acy_prom))
# print acurracy.reverse()
# print recall.reverse()
# print precision.reverse()



N = 5
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
ax.set_xlabel('fold')
ax.set_xticks(ind+width)
ax.set_xticklabels( ('1', '2', '3', '4', '5') )
ax.legend( (rects1[0], rects2[0], rects3[0]), ('acurracy', 'precision', 'recall') )
plt.show()
