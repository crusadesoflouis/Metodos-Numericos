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
    acy_prom  = []
    recl_prom = []
    prec_prom = []
    for iteracion in range(1,11):
        true = []
        pred = []
        menos = 10-k
        with open('k_'+str(k)+'_test_'+str(menos)+'_it'+str(iteracion)+'.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    true.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""

                with open('k_'+str(k)+'_pred_'+str(menos)+'_it'+str(iteracion)+'.csv', 'rb') as csvfile:
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
    # print acy_prom
    # print recl_prom
    # print prec_prom
    acurracy.append(np.mean(acy_prom))
    recall.append(np.mean(recl_prom))
    precision.append(np.mean(prec_prom))

print acurracy.reverse()
print recall.reverse()
print precision.reverse()



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
ax.set_ylabel('% [0,1]')
ax.set_xlabel('Cantidad Imagenes de Entrenamiento')
ax.set_xticks(ind+width)
ax.set_xticklabels( ('9', '8', '7', '6', '5', '4', '3', '2', '1') )
ax.legend( (rects1[0], rects2[0], rects3[0]), ('acurracy', 'precision', 'recall') )
plt.show()


# with open('1_elements_1.csv', 'rb') as csvfile:
#     reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
#     try:
#         row = reader.next()
#         while True:
#             true_1.append(int(row[1]))
#             row = reader.next()
#     except StopIteration:
#         print ""
#         with open('1_result_1.csv', 'rb') as csvfile:
#             reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
#             try:
#                 row = reader.next()
#                 while True:
#                     pred_1.append(int(row[1]))
#                     row = reader.next()
#             except StopIteration:
#                 print ""
#
# acy_score = []
# acy_score.append(accuracy_score(true_1, pred_1))
# acy_score.append(accuracy_score(true_2, pred_2))
# acy_score.append(accuracy_score(true_3, pred_3))
# acy_score.append(accuracy_score(true_4, pred_4))
# acy_score.append(accuracy_score(true_5, pred_5))
# acy_score.append(accuracy_score(true_6, pred_6))
# acy_score.append(accuracy_score(true_7, pred_7))
# acy_score.append(accuracy_score(true_8, pred_8))
# acy_score.append(accuracy_score(true_9, pred_9))
# print "lista de acurracy "
# print acy_score
#
# prec_score = []
# prec_score.append(precision_score(true_1, pred_1, average='macro'))
# prec_score.append(precision_score(true_2, pred_2, average='macro'))
# prec_score.append(precision_score(true_3, pred_3, average='macro'))
# prec_score.append(precision_score(true_4, pred_4, average='macro'))
# prec_score.append(precision_score(true_5, pred_5, average='macro'))
# prec_score.append(precision_score(true_6, pred_6, average='macro'))
# prec_score.append(precision_score(true_7, pred_7, average='macro'))
# prec_score.append(precision_score(true_8, pred_8, average='macro'))
# prec_score.append(precision_score(true_9, pred_9, average='macro'))
#
# print " lista de precision "
# print prec_score
# rcll_score = []
# rcll_score.append(recall_score(true_1, pred_1, average='macro'))
# rcll_score.append(recall_score(true_2, pred_2, average='macro'))
# rcll_score.append(recall_score(true_3, pred_3, average='macro'))
# rcll_score.append(recall_score(true_4, pred_4, average='macro'))
# rcll_score.append(recall_score(true_5, pred_5, average='macro'))
# rcll_score.append(recall_score(true_6, pred_6, average='macro'))
# rcll_score.append(recall_score(true_7, pred_7, average='macro'))
# rcll_score.append(recall_score(true_8, pred_8, average='macro'))
# rcll_score.append(recall_score(true_9, pred_9, average='macro'))
#
# print " lista de recall"
# print rcll_score
#
#
#
#
#
#
# # graficador de barras
#
# N = 9
# ind = np.arange(N)  # the x locations for the groups
# width = 0.27       # the width of the bars
# fig = plt.figure()
# ax = fig.add_subplot(111)
# yvals = acy_score
# rects1 = ax.bar(ind, yvals, width, color='#424147')
# zvals = prec_score
# rects2 = ax.bar(ind+width, zvals, width, color='#72bac3')
# kvals = rcll_score
# rects3 = ax.bar(ind+width*2, kvals, width, color='#de511c')
# ax.set_ylabel('%')
# ax.set_xlabel('Cantidad Imagenes de Entrenamiento')
# ax.set_xticks(ind+width)
# ax.set_xticklabels( ('9', '8', '7', '6', '5', '4', '3', '2', '1') )
# ax.legend( (rects1[0], rects2[0], rects3[0]), ('acurracy', 'precision', 'recall') )
# plt.show()
