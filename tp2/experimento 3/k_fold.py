import numpy as np
from sklearn.model_selection import KFold
clases = ["../datosEntrenamiento/ImagenesCaras/s1/",
"../datosEntrenamiento/ImagenesCaras/s2/",
"../datosEntrenamiento/ImagenesCaras/s3/",
"../datosEntrenamiento/ImagenesCaras/s4/",
"../datosEntrenamiento/ImagenesCaras/s5/",
"../datosEntrenamiento/ImagenesCaras/s6/",
"../datosEntrenamiento/ImagenesCaras/s7/",
"../datosEntrenamiento/ImagenesCaras/s8/",
"../datosEntrenamiento/ImagenesCaras/s9/",
"../datosEntrenamiento/ImagenesCaras/s10/",
"../datosEntrenamiento/ImagenesCaras/s11/",
"../datosEntrenamiento/ImagenesCaras/s12/",
"../datosEntrenamiento/ImagenesCaras/s13/",
"../datosEntrenamiento/ImagenesCaras/s14/",
"../datosEntrenamiento/ImagenesCaras/s15/",
"../datosEntrenamiento/ImagenesCaras/s16/",
"../datosEntrenamiento/ImagenesCaras/s17/",
"../datosEntrenamiento/ImagenesCaras/s18/",
"../datosEntrenamiento/ImagenesCaras/s19/",
"../datosEntrenamiento/ImagenesCaras/s20/",
"../datosEntrenamiento/ImagenesCaras/s21/",
"../datosEntrenamiento/ImagenesCaras/s22/",
"../datosEntrenamiento/ImagenesCaras/s23/",
"../datosEntrenamiento/ImagenesCaras/s24/",
"../datosEntrenamiento/ImagenesCaras/s25/",
"../datosEntrenamiento/ImagenesCaras/s26/",
"../datosEntrenamiento/ImagenesCaras/s27/",
"../datosEntrenamiento/ImagenesCaras/s28/",
"../datosEntrenamiento/ImagenesCaras/s29/",
"../datosEntrenamiento/ImagenesCaras/s30/",
"../datosEntrenamiento/ImagenesCaras/s31/",
"../datosEntrenamiento/ImagenesCaras/s32/",
"../datosEntrenamiento/ImagenesCaras/s33/",
"../datosEntrenamiento/ImagenesCaras/s34/",
"../datosEntrenamiento/ImagenesCaras/s35/",
"../datosEntrenamiento/ImagenesCaras/s36/",
"../datosEntrenamiento/ImagenesCaras/s37/",
"../datosEntrenamiento/ImagenesCaras/s38/",
"../datosEntrenamiento/ImagenesCaras/s39/",
"../datosEntrenamiento/ImagenesCaras/s40/",
"../datosEntrenamiento/ImagenesCaras/s41/"]

# k = 2  4 conjuntos
# k = 3 if len(X_test) == 3 de test
# k = 2 entran todos
# k = 2 entran todos
# k = 2 entran todos
# k = 2 entran todos
# k = 2 entran todos
# k = 2 entran todos

k = 3
for i in range(0,1):
    # for i in range(1,11):
    #     print str(clases[i])+str(i)+".pgm"
    X = np.array(range(1,11))
    y = np.array(range(1,11))
    kf = KFold(n_splits=k)
    kf.get_n_splits(X,y,groups)
    for train_index, test_index in kf.split(X):
        print("TRAIN:", train_index, "TEST:", test_index)
        X_train, X_test = X[train_index], X[test_index]

        print "TRAIN:"
        for j in range(0,len(X_train)):
            print str(clases[i])+str(X_train[j])+".pgm" + " "+ "clase "+ str(i+1)
        print "TEST:"
        for j in range(0,len(X_test)):
            print str(clases[i])+str(X_test[j])+".pgm" +" "+ "clase "+ str(i+1)
# from sklearn.model_selection import GroupKFold
# X = np.array(range(1,11))
# y = np.array(range(1,11))
# groups = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9,10])
# group_kfold = GroupKFold(n_splits=5)
# group_kfold.get_n_splits(X, y, groups)
# print(group_kfold)
# for train_index, test_index in group_kfold.split(X, y, groups):
#     print("TRAIN:", train_index, "TEST:", test_index)
#     X_train, X_test = X[train_index], X[test_index]
#     y_train, y_test = y[train_index], y[test_index]
#     print X_train
#     print X_test
#     print y_train
#     print y_test
