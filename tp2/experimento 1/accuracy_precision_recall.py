import numpy as np
from sklearn.metrics import accuracy_score
from sklearn.metrics import recall_score
from sklearn.metrics import precision_score
y_true = [1, 2, 3, 4, 2, 2]
y_pred = [1, 2, 3, 4, 2, 1]
print "accuracy_score"
print accuracy_score(y_true, y_pred)
print "recall scrore"
print recall_score(y_true, y_pred, average='macro')
print "precision score "
print precision_score(y_true, y_pred, average='macro')
