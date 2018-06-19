%% leo imagen de entrada
close all, clear all;
I = dicomread('image-000022.dcm');
figure,imshow(I),title('Imagen original');
