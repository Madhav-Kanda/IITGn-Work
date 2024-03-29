# -*- coding: utf-8 -*-
"""Q5_test.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/19fLBYgrxvEcH2qfm0URlFaLuEUyLMibB
"""
import warnings
warnings.filterwarnings('ignore')
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from preprocessing.polynomial_features import PolynomialFeatures
from linearRegression.linear_regression import LinearRegression
import os.path
from os import path

# if not path.exists('Plots/Question5/'):
#     os.makedirs('Plots/Question5/')

# TODO : Write here
np.random.seed(10)
degree=[1,3,5,7,9]
N=[]

for i in range(60,100,4):
    N.append(i)
mag_theta_d=[]
for n in N:
    print(n)
    mag_theta=[]
    x = np.array([i*np.pi/180 for i in range(60,300,2)])
    y = 3*x + 8 + np.random.normal(0,3,len(x))
    for d in degree:
        X=[]
        poly = PolynomialFeatures(d)
        for i in range(len(x)):
            X.append(poly.transform([x[i]]))
        X=pd.DataFrame(X)
        y=pd.Series(y)
        X=X.iloc[:,1:]
        LR = LinearRegression(fit_intercept=True)
        LR.fit_SVD(X, y) 
        theta=LR.coef_
        norm=np.linalg.norm(theta) 
        mag_theta.append(norm)
    mag_theta_d.append(mag_theta)

plt.figure()
for i in range(len(N)):
    plt.semilogy(degree,mag_theta_d[i],label='N='+str(N[i])+" No of samples")
plt.legend()
plt.title("Magnitude of theta vs Degree with varying samples")
plt.xlabel("Degree")
plt.ylabel("log(|theta|")
plt.show()