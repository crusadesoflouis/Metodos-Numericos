%% leo imagen de entrada
close all, clear all;
I = imread('lena.pgm');
figure,imshow(I),title('Imagen original');

%% agrego ruido (uniforme o gausiano)
sr = 32; % rango del ruido uniforme en [-sr,sr], o std=sr para el ruido gausiano
%IR = double(I) + 2*sr*(rand(size(I))-0.5); % uniforme
IR = double(I) + sr*randn(size(I)); % gausiano
IR = uint8(IR);

%% agrego ruido
tipo_de_ruido = 'gaussiano';
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

%% calculo psnr de la imagen ruidosa
[p,m] = psnr(I, IR);

fprintf('Calidad imagen ruidosa.\n');
fprintf('PSNR=%g, ECM=%g\n',p,m);

%% Filtro la imagen usando la descomposicion en valores singulares
A = double(IR);
maxIte = 20;
tol = 1e-5;
%
[U,S,V] = svd(A);

%% Chequeo la descomposicion en valores singulares
difS = A - U*S*V';
min(min(difS))
max(max(difS))

%% Me quedo con los k autovec/autoval más importantes
Uk = zeros(size(U));
Vk = zeros(size(V));
Sk = zeros(size(S));

k = 50;

Uk(:,1:k) = U(:,1:k);
Vk(:,1:k) = V(:,1:k);
Sk(1:k,1:k) = S(1:k,1:k);

%% Reconstruyo I usando la descomposición en valores singulares
IF = Uk*Sk*Vk';
IF = uint8(IF);

figure,imshow(IF),title('Imagen reconstruida');
% figure, imagesc(IF), colormap(gray); % para mostrar sin convertir a unit8

%% Calculo psnr de la imagen filtrada
[p,m] = psnr(I, IF);

fprintf('Calidad imagen filtrada.\n');
fprintf('PSNR=%g, ECM=%g\n',p,m);

%% Tarea:
% 1) Variar el k y medir psnr
% 2) Agregar distintas cantidades de ruido
% 3) En una misma figura graficar psnr en función de k para una mimsma
% imagen con 3 ruidos distintos
% 3) Sacar conclusiones

n = length(V);

for k=1:n
   
    % TODO
    
end
