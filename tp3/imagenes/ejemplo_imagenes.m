%% leo imagen de entrada
close all, clear all;
I = imread('1.pgm');
figure,imshow(I),title('Imagen original');

%% agrego ruido (uniforme o gausiano)
sr = 32; % rango del ruido uniforme en [-sr,sr], o std=sr para el ruido gausiano
%IR = double(I) + 2*sr*(rand(size(I))-0.5); % uniforme
IR = double(I) + sr*randn(size(I)); % gausiano
IR = uint8(IR);

%% agrego ruido
tipo_de_ruido = 'uniforme';
if strcmp(tipo_de_ruido,'salt&pepper')
    IR = imnoise(I,'salt & pepper');
elseif strcmp(tipo_de_ruido,'uniforme')
    sr = 64; % a partir de 64 (aprox) el filtrado vale la pena
    IR = double(I) + randi([-sr,sr], size(I));
    IR = uint8(IR);
elseif strcmp(tipo_de_ruido, 'gaussiano')
    IR = imnoise(I,'gaussian');
elseif strcmp(tipo_de_ruido, 'speckle')
    IR = imnoise(I,'speckle');
else
    IR = zeros(size(I));
end

IR = uint8(IR);

figure,imshow(IR),title(['Imagen ruidosa. Tipo de ruido = ' tipo_de_ruido]);
