import cv2
import numpy as np

def aplicar_dilatacion(imagen, kernel):
    dilatada = cv2.dilate(imagen, kernel, iterations=1)
    return dilatada

def aplicar_erosion(imagen, kernel):
    erosionada = cv2.erode(imagen, kernel, iterations=1)
    return erosionada

def aplicar_hit_or_miss(imagen, kernel):
    transformacion = cv2.morphologyEx(imagen, cv2.MORPH_HITMISS, kernel)
    return transformacion

def aplicar_canny(imagen, umbral_min, umbral_max):
    bordes = cv2.Canny(imagen, umbral_min, umbral_max)
    return bordes

def segmentar_flechas(imagen_binaria):
    # Definir el kernel
    kernel = np.array([[0, 1, 0],
                       [1, 1, 1],
                       [0, 1, 0]], dtype=np.uint8)

    # Aplicar dilatación para resaltar las características de las flechas
    # La dilatacion hace que la imagen se expanda en los pixeles correspondientes al kernel y se rellene con 1's si al menos un pixel del kernel es 1 
    dilatada = aplicar_dilatacion(imagen_binaria, kernel)

    # Aplicar erosión para eliminar ruido
    # El proceso de la erosion consiste en aplicar el kernel a la imagen y si todos los pixeles del kernel son 1, entonces el pixel central se mantiene, de lo contrario se elimina
    # En este caso, se aplica el kernel a la imagen dilatada para eliminar el ruido y mantener las flechas
    erosionada = aplicar_erosion(dilatada, kernel)

    # Definir el kernel para Hit or Miss
    # Hit or Miss se realiza con un kernel de 3x3 con 1's en los píxeles que se quieren detectar y -1's en los píxeles que no se quieren detectar
    # Este kernel se aplica a la imagen erosionada para detectar las flechas y eliminar el resto de la imagen (incluyendo el ruido) 
    kernel_hitmiss = np.array([[0, 1, 0], [1, 1, 1], [0, 1, 0]], int)

    # Aplicar Hit or Miss para identificar las flechas
    flechas = aplicar_hit_or_miss(erosionada, kernel_hitmiss)

    # Aplicar Canny para detectar bordes
    umbral_min = 100
    umbral_max = 250
    bordes = aplicar_canny(erosionada, umbral_min, umbral_max)

    # Mostrar las imágenes resultantes
    cv2.imshow('Dilatada', dilatada)
    cv2.imwrite('dilatada.jpg',dilatada)
    cv2.imshow('Erosionada', erosionada)
    cv2.imwrite('erosionada.jpg',erosionada)
    cv2.imshow('HitOrMiss', flechas)
    cv2.imwrite('HitOrMiss.jpg',flechas)
    cv2.imshow('Bordes (Canny)', bordes)
    cv2.imwrite('bordesCanny.jpg',bordes)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Cargar la imagen binarizada de las flechas
imagen_binaria = cv2.imread('imagen_corregida.png', 0)  # Asegúrate de que 'imagen_binaria.png' existe y está en el directorio actual
# Segmentar las flechas
segmentar_flechas(imagen_binaria)
