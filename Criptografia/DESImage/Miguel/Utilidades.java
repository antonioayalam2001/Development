/****************************************************
*                                                   *
*   Metodo Principal del Cifrador por Bloques DES   *
*   Integrantes                                     *
*       Mora Ayala Jose Antonio                     *
*       Torres Carrillo Josehf Miguel Angel         *
*       Tovar Jacuinde Rodrigo                      *
*   Grupo                                           *
*       3CM13                                       *
*                                                   *
****************************************************/

//Importamos las Bibliotecas necesarias para inicializar nuestra GUI
import javax.crypto.*;
import javax.crypto.spec.*;
import javax.swing.*;
import javax.imageio.ImageIO;

import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.image.BufferedImage;

//Clase principal para ejecutar nuestros metodos para iniciar el proceso de
//cifrado o descifrado
public class Utilidades {

    //Metodo que obtiene la direccion de nuestro archivo
    //devuelve una cadena con la direccion de nuestro archivo
    public static String obtenerDireccionArchivo () throws Exception {

        //Creamos una variable del tipo JFileChooser para abrir nuestro archivo
        JFileChooser fc = new JFileChooser();

            //Con nuestro objeto lo que haremos sera abrir un cuadro de 
            //busqueda para abrir nuestro archivo, la ubicacion de apertura
            //de este dialogo sera la carpeta raiz de nuestro proyecto
            fc.setCurrentDirectory(new File(System.getProperty("user.dir")));

            //Finalmente mandamos a llamar nuestro metodo para abrir el dialogo
            //de apertura de nuestro archivo
            fc.showOpenDialog(null);

        //Finalmente mandamos la direccion de nuestro archivo transformandola
        //en una cadena de texto
        return fc.getSelectedFile().toString();
    }

    //Metodo que sirve para leer la informacion de nuestro archivo
    //recibe como parametro la direccion de la ubicacion de nuestro archivo
    //y retorna la informacion de nuestro archivo
    public static byte[] leerArchivo (String direccionArchivo) throws Exception {

        //Primero creamos un objeto de tipo File para abrir nuestro archivo
        //en la ubicacion dado como parametro
        File archivo = new File(direccionArchivo);

        //Una vez que tenemos nuestro archivo lo uq haremos sera crear un
        //objeto de tipo bufferedImage para guardar la informacion del archivo
        //en un buffer
        BufferedImage img = ImageIO.read(archivo);
        
        //Posteriromente lo que haremos sera crear una variable que 
        //nos servira para convertir los datos de nuestro archivo en un
        //array de bytes
        ByteArrayOutputStream byteArray = new ByteArrayOutputStream();

        //Escribiremos en nuestro arreglo de bytes los datos contenidos en 
        //nuestra variable img indicando el formato de nuestra imagen, escribiendolo
        //en nuestro array de bites
        ImageIO.write(img, "bmp", byteArray);

        //Finalmente lo que haremos es comprobar que todos los datos dentro de nuestro
        //array se hayan escrito en nuestra variable con el metodo flush
        byteArray.flush();

        //Finalmente lo uqe haremos sera crear nuestra variable de tipo bytes
        //que retornara los bytes de nuestro archivo, para ello lo que haremos sera
        //convertir los datos de nuestro arreglo byteArray a bytes como tal para
        //ser escritos en nuestra variable
        byte[] imgBytes = byteArray.toByteArray();

        //Finalmente cerramos nuestro flujo de datos ya que no lo necesitamos
        byteArray.close();

        //Desplegamos un mensaje de que el proceso se ejecuto correctamente
        JOptionPane.showMessageDialog(null, "Archivo Leido Correctamente");

        //Finalmente retornamos el arreglo de bytes obtenido en nuestro metodo
        return imgBytes;
    }

    //Metodo que cifra o descifra el texto que contenga nuestro archivo
    //recibe como parametros los datos de la iamgen que queremos cifrar/descifrar
    //recibe el texto de la llave que usaremos ademas del vector de inicializacion
    //tambien recibe el metodo de cifrado/des cifrado por bloques que utilizaremos
    //recibe una cadena de texto que indica si estamos cifrando o decifrando
    //finalmente recibe el nombre de archivo original
    public static void cifradoDescifrado (byte[] bmpBytes, String llave, String vInicializacion, String modo, String cOrD, String nombreArchivo) throws Exception {

        //Creamos una variable de tipo arreglo de bytes que tendra el tamano total
        //de los datos del archivo de la imagen
        byte[] bytesArchivo = new byte[(int)bmpBytes.length];

        //Posteriormente lo que haremos sera crear otro arreglo de bytes que tendra
        //el tamano total de bytes del archivo sin contar los 4 bytes iniciales
        //de la cabecera de un archivo bmp
        byte[] bytesCifrarDescifrar = new byte[(int)bmpBytes.length - 54];

        //Lo que haremos sera mediante un ciclo for copiar los datos de nuestra
        //archivo de imagen en nuestros 2 arreglos
        for (int i = 0, j = 0; i < bmpBytes.length; i++) {
            
            //Si aun no superamos los 54 bytes de la cabecera lo que haremos sera
            //copiar estos datos en nuestra variable bytesArchivo
            if (i < 54) bytesArchivo[i] = bmpBytes[i];

            //Si ya superamos nuestros 54 bytes lo que haremos sera copiar los datos
            //que no forman parte de la cabecera en nuestro arreglo bytesCifrarDescifrar
            else bytesCifrarDescifrar[j++] = bmpBytes[i];
        }

        //Ahora lo que haremos sera generar los bytes para nuestra llave usando
        //el metodo SecretKey, que recibe como parametros los bytes de la llave
        //ingresada por el usuario, en caso de que la llave tenga mas caracteres
        //lo que haremos sera obtener los primero 8 bytes de esta, posteriormente
        //lo que haremos sera indicar el metodo de cifrado para el cual se usara
        //la llave ingresada
        SecretKeySpec key = new SecretKeySpec(llave.getBytes(),  0, 8, "DES");

        //Inicializamos un objeto Cipher que indicara el modo de cifrado o 
        //descifrado que ejecutaremos
        Cipher cipher = Cipher.getInstance(modo);

        //En caso de que el modo de operacion sea igual a ECB haremos lo siguiente
        if (modo.equals("DES/ECB/NoPadding")) {

            //Si lo que vamos a hacer es cifrar lo que haremos sera mandar el 
            //metodo init en modo cifrar con la llave generada
            if (cOrD.equals("Cifrar")) 
                cipher.init(Cipher.ENCRYPT_MODE, key);

            //En caso contrario si lo que haremos es descifrar ejecutaremos
            //el metodo init con el modo de Descifrado
            if (cOrD.equals("Descifrar")) 
                cipher.init(Cipher.DECRYPT_MODE, key);       
        }
        else{

            //En caso de que el modo de no sea ECB lo que haremos sera crear
            //un objeto de tipo IvParameterSpec para inicializar nuestro vector
            //para ello mandaremos a nuestro objeto nuestro vector en forma de bytes
            IvParameterSpec vector = new IvParameterSpec(vInicializacion.getBytes());

            //En caso de que queramos cifrar lo que haremos sera mandar a llamar
            //nuestro metodo init en modo cifrado con nuestra llave ademas de 
            //nuestro vector de inicializacion
            if (cOrD.equals("Cifrar")) 
                cipher.init(Cipher.ENCRYPT_MODE, key, vector);

            //Si lo que haremos es descifrar ejecutaremos el metodo init
            //con el modo de descifrado junto con la llave y nuestro vector
            if (cOrD.equals("Descifrar")) 
                cipher.init(Cipher.DECRYPT_MODE, key, vector);
        }

        //Ya que tenemos nuestros metodos iniciados lo que haremos es obtener
        //los datos cifrados con el metodo doFinal y los almacenaremos en nuestro
        //areglo de bytesProcesados
        byte[] bytesProcesados = cipher.doFinal(bytesCifrarDescifrar);

        //Ya que tenemos los bytes procesados lo uqe haremos sera juntar estos
        //bytes en nuestro arreglo de bytesArchivo que de momento tiene
        //tiene la cabecera de nuestro archivo de imagen
        for (int i = 54, j = 0; i < bmpBytes.length ; i++) {
            bytesArchivo[i] = bytesProcesados[j++];
        }

        //En caso de que nuestro metodo sea para cifrar lo que haremos sera 
        //lo siguiente para el nombre de neustro archivo
        if (cOrD.equals("Cifrar")){
            
            //Dependiendo del modo de operacion lo que haremos sera mandar
            //a nuestro metodo de escriirArchivo, los bytes cifrados de nuestro
            //archivo concatenado con nuestra cabecera, ademas de que el nombre 
            //sera igual al nombre del archivo original mas _e y el modo de 
            //operacion correpondiente
            if ( modo.equals("DES/ECB/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_eECB.bmp");
            if ( modo.equals("DES/CBC/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_eCBC.bmp");
            if ( modo.equals("DES/CFB/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_eCFB.bmp");
            if ( modo.equals("DES/OFB/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_eOFB.bmp");

            //En caso de que el proceso se haya realizado correctamente lo que haremos
            //seram andar un mensaje de que el proceso se realizaco satisfactoriamente
            JOptionPane.showMessageDialog(null, "Cifrado Realizado Correctamente");
        }

        //En caso contrario si lo que haremos es descifrar haremos lo siguiente
        if (cOrD.equals("Descifrar")){

            //Dependiendo del modo de operacion lo que haremos sera mandar a llamar
            //a nuestro metodo de escribir archivo y dependiendo del modo de operacion
            //en nombre del archivo sera igual a _d mas el modo de operacion
            if ( modo.equals("DES/ECB/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_dECB.bmp");
            if ( modo.equals("DES/CBC/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_dCBC.bmp");
            if ( modo.equals("DES/CFB/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_dCFB.bmp");
            if ( modo.equals("DES/OFB/NoPadding") )
                escribirArchivo(bytesArchivo, nombreArchivo + "_dOFB.bmp");

            //En caso de que el proceso se haya realizado correctamente lo que haremos
            //seram andar un mensaje de que el proceso se realizaco satisfactoriamente
            JOptionPane.showMessageDialog(null, "Descifrado Realizado Correctamente");
        }
    }

    //Metodo que escribe la imagen cifrada o descifrada
    //recibe como parametros los bytes del archivo cifrado o descifrado
    //recibe el nombre del archivo que tendra al final
    public static void escribirArchivo (byte[] bytesArchivo, String nombre) throws Exception {

        //Creamos un objeto del tipo File con el nombre de nuestro archivo
        File nombreArchivo = new File(nombre);

        //Una vez creado nuestro archivo lo que haremos sera crear un flujo de
        //de entrada del tipo buteArray con los datos del archivo cifrado o descifrado
        InputStream entrada = new ByteArrayInputStream(bytesArchivo);

        //Posteriormente lo que haremos sera convertir los byte en formato de objeto
        //de imagen
        BufferedImage bytesConvertidos = ImageIO.read(entrada);

        //Finalmente lo que haremos sera mediante el metodo write es escribir
        //los datos alojados en nuestra variable bytesConvertidos en nuestro 
        //archivo con el nombre que le asignamos anteriormente
        ImageIO.write(bytesConvertidos, "bmp", nombreArchivo);
    }
}