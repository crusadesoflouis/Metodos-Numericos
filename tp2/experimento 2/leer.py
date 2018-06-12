import numpy as np
import matplotlib.pyplot as plt
import csv
from sklearn.metrics import accuracy_score
from sklearn.metrics import recall_score
from sklearn.metrics import precision_score
true_9 = []
pred_9 = []
true_8 = []
pred_8 = []
true_7 = []
pred_7 = []
true_6 = []
pred_6 = []
true_5 = []
pred_5 = []
true_4 = []
pred_4 = []
true_3 = []
pred_3 = []
true_2 = []
pred_2 = []
true_1 = []
pred_1 = []
with open('9_elements_9.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_9.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('9_result_9.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_9.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""

with open('8_elements_8.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_8.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('8_result_8.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_8.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""
with open('7_elements_7.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_7.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('7_result_7.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_7.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""
with open('6_elements_6.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_6.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('6_result_6.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_6.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""
with open('5_elements_5.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_5.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('5_result_5.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_5.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""
with open('4_elements_4.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_4.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('4_result_4.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_4.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""
with open('3_elements_3.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_3.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('3_result_3.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_3.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""
with open('2_elements_2.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_2.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('2_result_2.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_2.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""
with open('1_elements_1.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
    try:
        row = reader.next()
        while True:
            true_1.append(int(row[1]))
            row = reader.next()
    except StopIteration:
        print ""
        with open('1_result_1.csv', 'rb') as csvfile:
            reader = csv.reader(csvfile,delimiter= ',', quotechar='|')
            try:
                row = reader.next()
                while True:
                    pred_1.append(int(row[1]))
                    row = reader.next()
            except StopIteration:
                print ""

acy_score = []
acy_score.append(accuracy_score(true_1, pred_1))
acy_score.append(accuracy_score(true_2, pred_2))
acy_score.append(accuracy_score(true_3, pred_3))
acy_score.append(accuracy_score(true_4, pred_4))
acy_score.append(accuracy_score(true_5, pred_5))
acy_score.append(accuracy_score(true_6, pred_6))
acy_score.append(accuracy_score(true_7, pred_7))
acy_score.append(accuracy_score(true_8, pred_8))
acy_score.append(accuracy_score(true_9, pred_9))
print "lista de acurracy "
print acy_score

prec_score = []
prec_score.append(precision_score(true_1, pred_1, average='macro'))
prec_score.append(precision_score(true_2, pred_2, average='macro'))
prec_score.append(precision_score(true_3, pred_3, average='macro'))
prec_score.append(precision_score(true_4, pred_4, average='macro'))
prec_score.append(precision_score(true_5, pred_5, average='macro'))
prec_score.append(precision_score(true_6, pred_6, average='macro'))
prec_score.append(precision_score(true_7, pred_7, average='macro'))
prec_score.append(precision_score(true_8, pred_8, average='macro'))
prec_score.append(precision_score(true_9, pred_9, average='macro'))

print " lista de precision "
print prec_score
rcll_score = []
rcll_score.append(recall_score(true_1, pred_1, average='macro'))
rcll_score.append(recall_score(true_2, pred_2, average='macro'))
rcll_score.append(recall_score(true_3, pred_3, average='macro'))
rcll_score.append(recall_score(true_4, pred_4, average='macro'))
rcll_score.append(recall_score(true_5, pred_5, average='macro'))
rcll_score.append(recall_score(true_6, pred_6, average='macro'))
rcll_score.append(recall_score(true_7, pred_7, average='macro'))
rcll_score.append(recall_score(true_8, pred_8, average='macro'))
rcll_score.append(recall_score(true_9, pred_9, average='macro'))

print " lista de recall"
print rcll_score






# graficador de barras

N = 9
ind = np.arange(N)  # the x locations for the groups
width = 0.27       # the width of the bars
fig = plt.figure()
ax = fig.add_subplot(111)
yvals = acy_score
rects1 = ax.bar(ind, yvals, width, color='#424147')
zvals = prec_score
rects2 = ax.bar(ind+width, zvals, width, color='#72bac3')
kvals = rcll_score
rects3 = ax.bar(ind+width*2, kvals, width, color='#de511c')
ax.set_ylabel('%')
ax.set_xlabel('Cantidad Imagenes de Entrenamiento')
ax.set_xticks(ind+width)
ax.set_xticklabels( ('9', '8', '7', '6', '5', '4', '3', '2', '1') )
ax.legend( (rects1[0], rects2[0], rects3[0]), ('acurracy', 'precision', 'recall') )
plt.show()
