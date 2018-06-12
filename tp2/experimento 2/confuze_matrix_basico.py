import itertools
import numpy as np
import matplotlib.pyplot as plt
import csv
from sklearn import svm, datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix

# import some data to play with
# iris = datasets.load_iris()
# X = iris.data
# y = iris.target
class_names = range(1,42)
#
# # Split the data into a training set and a test set
# X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)
#
# # Run classifier, using a model that is too regularized (C too low) to see
# # the impact on the results
# classifier = svm.SVC(kernel='linear', C=0.01)
# y_pred = classifier.fit(X_train, y_train).predict(X_test)


def plot_confusion_matrix(cm, classes,
                          normalize=False,
                          title='Confusion matrix',
                          cmap=plt.cm.Blues):
    """
    This function prints and plots the confusion matrix.
    Normalization can be applied by setting `normalize=True`.
    """
    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
        print("Normalized confusion matrix")
    else:
        print('Confusion matrix, without normalization')
    print(cm)
    plt.figure(figsize=(20,10))
    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    fmt = '.2f' if normalize else 'd'
    # thresh = cm.max() / 2.
    # for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
    #     plt.text(j, i, format(cm[i, j], fmt),
    #              horizontalalignment="center",
    #              color="white" if cm[i, j] > thresh else "black")

    plt.tight_layout()
    plt.ylabel('True label')
    plt.xlabel('Predicted label')



acurracy    =  []
recall      =  []
precision   =  []

for k in range(1,10):
    acy_prom  = []
    recl_prom = []
    prec_prom = []
    iteracion = 5
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

    # Compute confusion matrix
    cnf_matrix = confusion_matrix(true, pred)
    np.set_printoptions(precision=2)

    # Plot non-normalized confusion matrix
    plt.figure()
    plot_confusion_matrix(cnf_matrix, classes=class_names,
                          title='Matriz de confusion para '+str(k)+' Imagenes de entrenamiento')

    # Plot normalized confusion matrix
    # plt.figure()
    # plot_confusion_matrix(cnf_matrix, classes=class_names, normalize=True,
    # title='Normalized confusion matrix')

    plt.savefig(str(k)+'_variable_plot.png')
    # plt.show()
